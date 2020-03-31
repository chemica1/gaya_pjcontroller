#include "pjwidget.h"
#include "ui_pjwidget.h"
#include "projector.h"
#include <QString>
#include <string>
using namespace std;



pjWidget::pjWidget(int id,qint16 _pid, QString _ip, quint16 _port, pjProtocol _protocol, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pjWidget)
{
    ui->setupUi(this);
    //create projector
    proj = new Projector(_ip, _port, _protocol, this);
    // set projector ID
    pid = _pid;

    string str0 = to_string(id);
    string str1 = to_string(id);
    string str2 = "Ctrl+";
    string str3 = str2 + str1;
    string str4 = "Alt+";
    string str5 = str4 + str0;

    char *ch;
    ch = (char*)str3.c_str();
    char *ch2;
    ch2 = (char*)str5.c_str();

    ui->on->setShortcut(tr(ch));
    ui->off->setShortcut(tr(ch2));

    connect(proj, SIGNAL(sigSocketConnected()), this, SLOT(pjConnected()));
    connect(proj, SIGNAL(sigSocketDisconnected()), this, SLOT(pjDisconnected()));
    // 램프 상태 모니터링
    connect(proj, SIGNAL(checkLampStatus1()), this, SLOT(updateLampStatus1()));
    connect(proj, SIGNAL(checkLampStatus2()), this, SLOT(updateLampStatus2()));
    connect(proj, SIGNAL(checkLampStatus3()), this, SLOT(updateLampStatus3()));
    connect(proj, SIGNAL(checkLampStatus4()), this, SLOT(updateLampStatus4()));

    // 프로젝터 연결이 끊겼을경우
    connect(this, SIGNAL(sigPjDisconnected()), this, SLOT(reconnect()));
}

pjWidget::~pjWidget()
{
    delete proj;
    delete ui;
}

void pjWidget::setProjectorName(QString pjName)
{
    ui->selector->setText(pjName);
}

void pjWidget::selectProjector(bool checked)
{
    ui->selector->setChecked(checked);
}


bool pjWidget::isSelected()
{
    return ui->selector->isChecked();
}

QAbstractSocket::SocketState pjWidget::socketState()
{
    return proj->socketState();
}

void pjWidget::connection(QString ip, quint16 port)
{
    proj->connection(ip, port);
}

void pjWidget::closeConnection()
{
    proj->closeConnection();
}

QString pjWidget::getIp()
{
    return proj->ipAddr;
}

quint16 pjWidget::getPort()
{
    return proj->portNum;
}

void pjWidget::shutterOn()
{
    proj->shutterOn();
}

void pjWidget::shutterOff()
{
    proj->shutterOff();
}

void pjWidget::patternOn()
{
    proj->patternOn();
}

void pjWidget::patternOff()
{
    proj->patternOff();
}

void pjWidget::powerOn()  //왼쪽
{
    ui->label->setText(proj->powerOn());
}

void pjWidget::powerOff()
{
    ui->label->setText(proj->powerOff());
}

void pjWidget::patternNext()
{
    proj->pgUpKey();
}

void pjWidget::patternPrev()
{
    proj->pgDownKey();
}



// SLOTS -----------------------------


void pjWidget::on_on_clicked()
{
    ui->label->setText(proj->powerOn());
}

void pjWidget::on_off_clicked()
{
    ui->label->setText(proj->powerOff());
}

void pjWidget::pjConnected()
{
    // set green icon
    ui->online_icon->setPixmap(QPixmap(":/icons/img/ok.png"));
    ui->label->setText(getIp()+"  connected!");
    emit sigPjConnected(); //아직 연결하지 않은 signal
}

void pjWidget::pjDisconnected()
{
    // set red icon
    ui->online_icon->setPixmap(QPixmap(":/icons/img/ko.png"));
    ui->label->setText(getIp()+"  Disconnected!");
    emit sigPjDisconnected();
}

void pjWidget::updateLampStatus1()
{
    ui->label->setText("Lamp on");
}

void pjWidget::updateLampStatus2()
{
    ui->label->setText("Cooling lamp");
}


void pjWidget::updateLampStatus3()
{
    ui->label->setText("Warm-up lamp");
}

void pjWidget::updateLampStatus4()
{
    ui->label->setText("Lamp off");
}

void pjWidget::reconnect()
{
    QTimer::singleShot(10*1000,this,SLOT(reconnectSlot()));

}

void pjWidget::reconnectSlot()
{
    proj->connection(proj->ipAddr, proj->portNum);
}



