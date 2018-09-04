#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpserver.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listen_clicked();

    void on_stop_clicked();

    void on_send_clicked();

signals:
    //主动断开链接
    void disConTcp(int i);
    void sentData(const QByteArray & str,const int i);
    void readData(const int,const QString &, quint16, const QByteArray  );

private:
    Ui::MainWindow *ui;
    TcpServer *ser;
    QHash<QString,int> ip2socketHash;
    QString str;
};

#endif // MAINWINDOW_H
