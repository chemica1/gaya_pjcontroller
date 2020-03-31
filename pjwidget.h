#ifndef PJWIDGET_H
#define PJWIDGET_H

#include <QWidget>
#include <QtGui>
#include "projector.h"
#include <QTimer>

namespace Ui {
class pjWidget;
}

class pjWidget : public QWidget
{
    Q_OBJECT

public:
    explicit pjWidget(int id, qint16 _pid, QString _ip, quint16 _port, pjProtocol _protocol, QWidget *parent = 0);
    ~pjWidget();

    qint16 pid; // projector ID

    void selectProjector(bool checked);
    bool isSelected();
    QAbstractSocket::SocketState socketState();
    void connection(QString ip, quint16 port);
    void closeConnection();
    void shutterOn();
    void shutterOff();
    void patternOn();
    void patternOff();
    void patternNext();
    void patternPrev();
    void powerOn();
    void powerOff();

    QString getIp();
    quint16 getPort();

    void updateStatus();

    void setProjectorName(QString pjName);
    void setProjectorModel(QString pjModel);

signals:
    void sigPjConnected();
    void sigPjDisconnected();

public slots:
    void pjConnected();
    void pjDisconnected();


private slots:


    void on_on_clicked();
    void on_off_clicked();
    void updateLampStatus1();
    void updateLampStatus2();
    void updateLampStatus3();
    void updateLampStatus4();
    void reconnect();
    void reconnectSlot();

private:
    Ui::pjWidget *ui;
    Projector *proj; // projector core functions
};

#endif // PJWIDGET_H
