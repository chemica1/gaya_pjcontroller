#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projector.h"
#include <QVBoxLayout>
#include <QCoreApplication>
#include <QShortcut>


namespace VP
{
    QStringList ip_list = {};
    QStringList name_list = {};
    QStringList time_list = {};
    QTime end_time;
    int flag = 0;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //create a vertical layout for a set of projectors UI
    QVBoxLayout *pjLayout = new QVBoxLayout();
    pjLayout->setSpacing(0);
    pjLayout->setMargin(0);
    Get_Setting();

    // for each projector
    for(int i = 0; i < 10; i++)
    {
        QString ip = VP::ip_list[i];                            //"192.168.200." + QString::number(11+i); //panasonic 4352 //파나소닉 pjlink할려면 로긴 비번 해제해야됨
        pjPanel.append(new pjWidget(i, i, ip, 4352, EPSON));     // create new projector UI panel //lan = 3629 // pjlink = 4352
        pjLayout->addWidget(pjPanel[i]);                      // add panel to the layout ///pjlink 할때 utf나 ascii 둘다 가능하더라...
        pjPanel[i]->setProjectorName(VP::name_list[i]);

    }
    ui->pjCommands->setLayout(pjLayout); // add the layout to the central widget in mainwindow
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setPixmap(QPixmap(":/icons/img/huliac.png").scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selection_connect_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        if(pjPanel[i]->isSelected())
        {
            pjPanel[i]->connection(pjPanel[i]->getIp(), pjPanel[i]->getPort());
        }
    }
}

void MainWindow::on_selection_shutter_on_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        for(int i = 0; i < 10; i++)
        {
            if(pjPanel[i]->isSelected())
            {
                if(pjPanel[i]->socketState() == QAbstractSocket::ConnectedState)
                {
                    pjPanel[i]->shutterOn();
                }
                else
                {
                    ui->statusBar->showMessage("Warning : problem sending command to projector #" + QString::number(i) + " !", 5000);
                }
            }
        }
    }
}

void MainWindow::on_selection_shutter_off_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        if(pjPanel[i]->isSelected())
        {
            if(pjPanel[i]->socketState() == QAbstractSocket::ConnectedState)
            {
                pjPanel[i]->shutterOff();
            }
            else
            {
                ui->statusBar->showMessage("Warning : problem sending command to projector #" + QString::number(i) + " !", 5000);
            }
        }
    }
}

void MainWindow::on_selection_power_on_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        if(pjPanel[i]->isSelected())
        {
            if(pjPanel[i]->socketState() == QAbstractSocket::ConnectedState)
            {
                pjPanel[i]->powerOn();
            }
            else
            {
                ui->statusBar->showMessage("Warning : problem sending command to projector #" + QString::number(i) + " !", 5000);
            }
        }
    }
}

void MainWindow::on_selection_power_off_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        if(pjPanel[i]->isSelected())
        {
            if(pjPanel[i]->socketState() == QAbstractSocket::ConnectedState)
            {
                pjPanel[i]->powerOff();
            }
            else
            {
                ui->statusBar->showMessage("Warning : problem sending command to projector #" + QString::number(i) + " !", 5000);
            }
        }
    }
}

void MainWindow::on_select_all_toggled(bool checked)
{
    for(int i = 0; i < 10; i++)
    {
        pjPanel[i]->selectProjector(checked);
    }
}

void MainWindow::on_selection_pattern_on_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        if(pjPanel[i]->isSelected())
        {
            if(pjPanel[i]->socketState() == QAbstractSocket::ConnectedState)
            {
                pjPanel[i]->patternOn();
            }
            else
            {
                ui->statusBar->showMessage("Warning : problem sending command to projector #" + QString::number(i) + " !", 5000);
            }
        }
    }
}

void MainWindow::on_selection_pattern_off_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        if(pjPanel[i]->isSelected())
        {
            if(pjPanel[i]->socketState() == QAbstractSocket::ConnectedState)
            {
                pjPanel[i]->patternOff();
            }
            else
            {
                ui->statusBar->showMessage("Warning : problem sending command to projector #" + QString::number(i) + " !", 5000);
            }
        }
    }
}

void MainWindow::on_selection_patternNext_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        if(pjPanel[i]->isSelected())
        {
            if(pjPanel[i]->socketState() == QAbstractSocket::ConnectedState)
            {
                pjPanel[i]->patternNext();
            }
            else
            {
                ui->statusBar->showMessage("Warning : problem sending command to projector #" + QString::number(i) + " !", 5000);
            }
        }
    }
}

void MainWindow::on_selection_patternPrev_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        if(pjPanel[i]->isSelected())
        {
            if(pjPanel[i]->socketState() == QAbstractSocket::ConnectedState)
            {
                pjPanel[i]->patternPrev();
            }
            else
            {
                ui->statusBar->showMessage("Warning : problem sending command to projector #" + QString::number(i) + " !", 5000);
            }
        }
    }
}

// ACTIONS SLOTS --------------------------

void MainWindow::on_actionConnect_triggered()
{
    for(int i = 0; i < 10; i++)
    {
        pjPanel[i]->connection(pjPanel[i]->getIp(), pjPanel[i]->getPort());
    }
}

void MainWindow::on_actionDisconnect_triggered()
{
    for(int i = 0; i < 10; i++)
    {
        pjPanel[i]->closeConnection();
    }
    ui->statusBar->showMessage("Disconnecting projectors... Done !", 5000);
}

void MainWindow::FirstStep() //모든 프로젝터 연결
{
    this->on_actionConnect_triggered();
}

void MainWindow::SecondStep() //모든 프로젝터 on
{
    this->on_select_all_toggled(true);
    this->on_selection_power_on_clicked();
}

void MainWindow::FinalStep() //프로젝터 끄고 컴퓨터도 종료
{
    this->on_actionConnect_triggered();
    this->on_select_all_toggled(true);
    this->on_selection_power_off_clicked();
    QProcess::startDetached("shutdown -s -f -t 10");
}

void MainWindow::FinalStepTimer()
{

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(whatTimeisit()));
    timer->start(1000);

}

void MainWindow::whatTimeisit()
{

    if(VP::end_time < QTime::currentTime() && VP::flag == 0)
    {
        VP::flag = 1;
        FinalStep();
        qWarning() << "집에가자!!!";
    }
    QString hi = QTime::currentTime().toString();
    QString bye = VP::end_time.toString();
    ui->statusBar->showMessage("현재시간:" + hi + "  종료시간: " + bye, 1000);
}


void MainWindow::Get_Setting() //txt파일에서 ip와 name 가져옴
{

    QString path = QCoreApplication::applicationDirPath() + "/pj_name.txt";
    QFile pj_name(path);

       if (!pj_name.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           qWarning() << "not open file";
           return;
       } else {
               QTextStream stream(&pj_name);
               VP::name_list =  stream.readAll().split("\n");
               pj_name.close();
       }



       path = QCoreApplication::applicationDirPath() + "/pj_ip.txt";
       QFile pj_ip(path);

          if (!pj_ip.open(QIODevice::ReadOnly | QIODevice::Text))
          {
              qWarning() << "not open file";
              return;
          } else {
                  QTextStream stream(&pj_ip);
                  VP::ip_list= stream.readAll().split("\n");
                  pj_ip.close();
          }

          path = QCoreApplication::applicationDirPath() + "/pj_time.txt";
          QFile pj_time(path);

             if (!pj_time.open(QIODevice::ReadOnly | QIODevice::Text))
             {
                 qWarning() << "not open file";
                 return;
             } else {
                     QTextStream stream(&pj_time);
                     VP::time_list= stream.readAll().split(":");
                     pj_time.close();
             }

         VP::end_time = QTime(VP::time_list[0].toInt(), VP::time_list[1].toInt(), VP::time_list[2].toInt());

}

void MainWindow::on_actionPowerOnAll_triggered()
{
    this->on_actionConnect_triggered();
    this->on_select_all_toggled(true);
    this->on_selection_power_on_clicked();
}

void MainWindow::on_actionPowerOffAll_triggered()
{
    this->on_actionConnect_triggered();
    this->on_select_all_toggled(true);
    this->on_selection_power_off_clicked();
}
