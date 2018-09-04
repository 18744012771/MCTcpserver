#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpserver.h"
#include <QThread>
#include "connectionpool.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sendcomboBox->clear();
    ui->stopcomboBox->clear();
    ui->sendcomboBox->addItem("-1");
    ui->stopcomboBox->addItem("-1");
    ip2socketHash.insert(QString("-1"),-1);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete ser;
}

void MainWindow::on_listen_clicked()
{
    ser= new TcpServer(this) ;
    ser->listen(QHostAddress::Any,8080);
    ui->read->setText("listen--->");
    connect(ser,&TcpServer::connectClient,[=](const int port , const QString &ip ,const quint16 socketDescriptor){

        qDebug()<<port<<ip<<socketDescriptor;
        if(ip2socketHash.find(ip)!=ip2socketHash.end())
             return;
        ip2socketHash.insert(ip,socketDescriptor);
       //String ip1=ip;
        //p1=ip1.section(":",2,2);
        ui->sendcomboBox->addItem(ip);
        ui->stopcomboBox->addItem(ip);
        ui->read->append(ip+"connect");

    });
//子线程内容无法send到主线程
    connect(ser,&TcpServer::readData,[=](const int port,const QString &ip, quint16 socketdescriptor, const QByteArray  str){
        //ui->read->setText( str);

        qDebug()<<"aaa"<<QThread::currentThread();
        //this->str=ip;
        qDebug()<< str;
        auto s="ip: "+ip.section(":",3,3).toUtf8() + " port: " + QByteArray::number(port) + "socket: " +QByteArray::number(socketdescriptor) + "\n str:" +str;
        ui->read->append(s);



        // 从数据库连接池里取得连接
        QSqlDatabase db = ConnectionPool::openConnection();
        qDebug() << "In thread run():" << db.connectionName();

        QSqlQuery query(db);
        //qDebug() <<this->currentThreadId();
        query.exec(QString("insert into pool values('%1')").arg(QString(s)));
        //query.exec("SELECT * FROM run");

//        while (query.next()) {
//            qDebug() << query.value(0).toString();
//        }

        // 连接使用完后需要释放回数据库连接池
        ConnectionPool::closeConnection(db);

    });
}

void MainWindow::on_stop_clicked()
{

  QString send_i=ui->stopcomboBox->currentText();
   qDebug()<<"stop"<<send_i<<ip2socketHash[send_i];
   emit //ser->sentDisConnect(-1);
   ser->sentDisConnect(ip2socketHash[send_i]);//disConTcp(-1);
   qDebug()<<"stop";
   //与server的disConTcp(-1) connect

   ip2socketHash.remove(send_i);
   ui->sendcomboBox->clear();
   ui->stopcomboBox->clear();
   ui->sendcomboBox->addItems(ip2socketHash.keys());
   ui->stopcomboBox->addItems(ip2socketHash.keys());
}

void MainWindow::on_send_clicked()
{
    QString writeLine= ui->write->toPlainText();
    qDebug()<<"on_send_clicked()"<<writeLine;
    //emit sentData(writeLine.toUtf8().data(),-1);

    QString send_i=ui->sendcomboBox->currentText();;
    qDebug()<<send_i<<ip2socketHash[send_i];
    emit ser->sentData(writeLine.toUtf8().data(),ip2socketHash[send_i]);
}
