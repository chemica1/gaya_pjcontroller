#include "projector.h"

Projector::Projector(QString _ip, quint16 _port, pjProtocol _comMode, QObject *parent) :
    QObject(parent)
{
    ipAddr = _ip;
    portNum = _port;
    comMode = _comMode;

    TcpSocket = new QTcpSocket(this);

    connect(TcpSocket, SIGNAL(connected()), this, SLOT(connected()));
    connect(TcpSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // timer to handle connexions timeout
    timer = new QTimer(this);
    timer->setInterval(20000); // 12 seconds
    connect(timer, SIGNAL(timeout()), this, SLOT(keepAlive()));
}

Projector::~Projector()
{
    TcpSocket->abort();
    delete timer;
    delete TcpSocket;
}

// COMMAND FUCNTIONS ---------------

// EPSON COMMANDS
//
// open ESC/VP.net session command
// 0x4553432F56502E6E6574100300000000
//
// power OFF : PWR OFF
// 0x505752204f46460D
//
// power ON : PWR ON
// 0x505752204F4E0D
//
// Shutter : KEY 3E
// 0x4B45592033450D
//
// ESC (Key mode) : KEY 05
// 0x4b45592030350D
//
// ESC (IR mode) : KEY 3D
// 0x4b45592033440D
//
// page UP : KEY 68
// 0x4b45592036380D
//
// page Down : KEY 69
// 0x4b45592036390D
//
// Pattern (Key mode) : KEY 1A
// 0x4b45592031410D
//
// Pattern (IR mode) : KEY 4B
// 0x4b45592034420D
//
// A/V Mute ON : MUTE ON
// 0x4d555445204f4e0D
//
// A/V Mute OFF : MUTE OFF
// 0x4d555445204f46464D
//
// ENTER : KEY 16
// 0x4b45592031360D


void Projector::patternOn()
{
    //pattern on command : "KEY 4B"
    QString command = "4b45592034420D";

    //convert string command to hexadecimal
    QByteArray cmd = QByteArray::fromHex(command.toUtf8());

    sendCommand(cmd);
}

void Projector::patternOff()
{
    //pattern off command : "ESC"
    QString command = "4b45592030350D";

    //convert string command to hexadecimal
    QByteArray cmd = QByteArray::fromHex(command.toUtf8());

    sendCommand(cmd);
}

void Projector::shutterOn()
{
    //Shutter ON command : "MUTE ON"
    QString command = "4d555445204f4e0D";

    //convert string command to hexadecimal
    QByteArray cmd = QByteArray::fromHex(command.toUtf8());

    sendCommand(cmd);
}

void Projector::shutterOff()
{
    //Shutter OFF command : "MUTE OFF"
    QString command = "4d555445204f46464D";

    //convert string command to hexadecimal
    QByteArray cmd = QByteArray::fromHex(command.toUtf8());

    sendCommand(cmd);
}

QString Projector::powerOn()
{
    //Power ON command : "PWR ON"
    QString command = "2531504f575220310d"; //pjlink = 2531504f575220310d  // lan = 505752204F4E0D
    QString textTemp="";
    QString text="";
    //convert string command to hexadecimal
    QByteArray cmd = QByteArray::fromHex(command.toUtf8());

    if(true==sendCommand(cmd)) //pjlink 전송
    {
        if(TcpSocket->waitForReadyRead((100))) //프로젝터 답장 기다림
        {
            while(TcpSocket->bytesAvailable() > 0) //purge socket buffer
            {
                textTemp=TcpSocket->readLine();
                if(!textTemp.isEmpty()) //문자열 비었나 보구
                {
                    text = textTemp.right(7);
                    textTemp.clear();
                    if(text.contains("OK")) //ok가 나오면
                    {
                        text.clear();
                        return "Power on. Successfully sent.";
                    }else if(text.contains("ERR3")) //ERR3면...
                    {
                        text.clear();
                        return "Failed to send. Please push the button later.";
                    }else //나머지 에러 출력
                    {
                        return text;
                    }
                }
            }
        }
     return "Failed to send. There is no response.";
    }else {
     return "Failed to send. please reconnect again.";
    }

}

QString Projector::powerOff()
{
    //Power OFF command : "PWR OFF"
    QString command = "2531504f575220300d"; // pjlink = 2531504f575220300d // lan = 505752204f46460D
    QString textTemp="";
    QString text="";
    //convert string command to hexadecimal
    QByteArray cmd = QByteArray::fromHex(command.toUtf8());

    if(true==sendCommand(cmd)) //pjlink 전송
    {
        if(TcpSocket->waitForReadyRead((100))) //프로젝터 답장 기다림
        {
            while(TcpSocket->bytesAvailable() > 0) //purge socket buffer
            {
                textTemp=TcpSocket->readLine();
                if(!textTemp.isEmpty()) //문자열 비었나 보구
                {
                    text = textTemp.right(7);
                    textTemp.clear();
                    if(text.contains("OK")) //ok가 나오면
                    {
                        text.clear();
                        return "Power OFF. Successfully sent.";
                    }else if(text.contains("ERR3")) //ERR3면...
                    {
                        text.clear();
                        return "Failed to send. Please push the button later.";
                    }else //나머지 에러 출력
                    {
                        return text;
                    }
                }
            }
        }
     return "Failed to send. There is no response.";
    }else {
     return "Failed to send. please reconnect again.";
   }
}

void Projector::pgUpKey()
{
    //Page Up command : KEY 68
    QString command = "4b45592036380D";

    //convert string command to hexadecimal
    QByteArray cmd = QByteArray::fromHex(command.toUtf8());

    sendCommand(cmd);
}

void Projector::pgDownKey()
{
    //Page Down command : KEY 69
    QString command = "4b45592036390D";

    //convert string command to hexadecimal
    QByteArray cmd = QByteArray::fromHex(command.toUtf8());

    sendCommand(cmd);
}


// Socket Method --------------------------------

QAbstractSocket::SocketState Projector::socketState()
{
    return TcpSocket->state();
}

bool Projector::sendCommand(QByteArray command)
{
    if (TcpSocket->state() != QAbstractSocket::ConnectedState)
    {
        qWarning() << "Can't send command : not connected !";
    }
    else
    {
        if(TcpSocket->write(command))
        {
            timer->start();
            return true;
        }
        qWarning() << "Problem sending command !";
        return false;
    }
    return false;
}

bool Projector::connection(QString &ip, quint16 port)
{
    this->TcpSocket->connectToHost(ip, port); //성공시 TcpSocket connected signal 발생-> connected slot 호출

    if(!TcpSocket->waitForConnected(100)) // 첨부터 실패하면 TcpSocket 에서 disconnected signal이 발생하지 않는듯
    {

        qWarning() << "Can't connect to : " << ip << " on port " << port;
        return false;
    }

    //open ESC/VP.net session  //lan컨트롤 요구사항
    //QString sessionCommand = "4553432F56502E6E6574100300000000";
    //QByteArray cmd = QByteArray::fromHex(sessionCommand.toUtf8());
    //sendCommand(cmd);

    return true;
}

void Projector::closeConnection()
{
    TcpSocket->abort();
}

// SLOTS -------------------------------

void Projector::connected()
{
    if(TcpSocket->waitForReadyRead((100)))
    {
        while(TcpSocket->bytesAvailable() > 0) //purge socket buffer
        {
            TcpSocket->readLine();
        }
    }
    timer->start(); //12초마다 keepalive호출
    emit sigSocketConnected(); //pjWidget에 signal보내 초록색 on, 라벨에 표시
}

void Projector::disconnected()
{
    timer->stop();
    emit sigSocketDisconnected();
}

void Projector::keepAlive()
{
    QString command = QString("2531504f5752203f0d"); // send 'POWR?' as projector need this charater as keepalive
    QByteArray cmd;
    QString textTemp="";
    QString text="";
    cmd.append(QByteArray::fromHex(command.toUtf8()));

    //--------------------램프 on 모니터링------------------------------------------
    if(true==sendCommand(cmd)) //pjlink 전송
    {
        if(TcpSocket->waitForReadyRead((100))) //프로젝터 답장 기다림
        {
            while(TcpSocket->bytesAvailable() > 0) //purge socket buffer
            {
                textTemp=TcpSocket->readLine();
                if(!textTemp.isEmpty()) //문자열 비었나 보구
                {
                    text = textTemp.right(6);
                    textTemp.clear();
                    if(text.contains("1")) emit checkLampStatus1(); //lamp on
                    else if(text.contains("2")) emit checkLampStatus2(); //lamp cooling
                    else if(text.contains("3")) emit checkLampStatus3(); //lamp warm-up
                    else if(text.contains("0")) emit checkLampStatus4(); //lamp off
                    text.clear();
                }
            }
        }
    }




    //---------------------초록색 불----------------------------
    bool connected = (TcpSocket->state() == QAbstractSocket::ConnectedState);
    if(!connected) {
        emit sigSocketDisconnected();
        timer->stop();
    }
    else {
        timer->start();
    }
}
