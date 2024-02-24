#ifndef LOGIN_H
#define LOGIN_H
#include"mainwindow.h"
#include <QDialog>
//#include "arduino.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
public:
    bool sign_up(QString pwd,QString email);
    bool sign_in(QString uname,QString pwd);

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:



  void on_pb_login_clicked();
  void update_label();
  void on_pb_on_clicked();

  void on_pb_off_clicked();

  void on_pb_plus_clicked();

  void on_pb_moin_clicked();
  void on_pushButton_clicked();

private:
    Ui::login *ui;
    login *log;
    QByteArray data; // variable contenant les données reçues

 //   Arduino A; // objet temporaire
        QByteArray datafinal; // variable contenant les données reçues
        QString dataf;
};

#endif // LOGIN_H
