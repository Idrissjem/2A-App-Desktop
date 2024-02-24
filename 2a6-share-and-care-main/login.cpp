#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QRegularExpression>
#include<QDebug>

login::login(QWidget *parent) :
QDialog(parent),
ui(new Ui::login)
{

    ui->setupUi(this);
       /* int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
*/





ui->setupUi(this);
ui->lineEdit_password->setEchoMode(QLineEdit::Password);
}

login::~login()
{
delete ui;
}

bool login::sign_up(QString pwd,QString email)
{
QSqlQuery qry;
qry.prepare("INSERT INTO login (password,email)"
"VALUES (:password,:email)");
qry.bindValue(":password",pwd);
qry.bindValue(":email",email);
return qry.exec();

}

bool login::sign_in(QString uname,QString pwd)
{
QSqlQuery qry;
qry.prepare("SELECT * FROM login WHERE email=:email AND password=:password");
qry.bindValue(":email",uname);
qry.bindValue(":password",pwd);
return qry.exec() && qry.next();
}

void login::on_pb_login_clicked()
{
    printf("test1");

QString email = ui->lineEdit_username->text();
QString password = ui->lineEdit_password->text();
// Check if email meets the requirements
QRegularExpression email_regex("[^@]+@[^\\.]+\\..+");
bool email_verif = email_regex.match(email).hasMatch();

// Check if password meets the requirements
QRegularExpression password_regex("^(?=.*[A-Z]).{1,8}$");
bool password_verif = password_regex.match(password).hasMatch();

if (!email_verif || !password_verif) {
    QMessageBox::warning(this, tr("Connexion"), tr("Veuillez saisir un email valide et un mot de passe valide."));
    return;
}

MainWindow* a = new MainWindow();
printf("test1");
if (log->sign_in(email, password))
{
    printf("test1");

    ui->lineEdit_username->clear();
    ui->lineEdit_password->clear();
    a->show();
    printf("test1");

    close();
    printf("test1");

}
else
{
    QMessageBox::warning(this, tr("Connexion"), tr("Erreur de connexion"));
}
}




void login::update_label()
{
   /* QString data = A.read_from_arduino();
    dataf += QString::fromStdString(data.toStdString());

    if (dataf.endsWith("\r\n")) {
        dataf = dataf.left(dataf.length()-2);

        QSqlQuery query;
        query.exec("select * from login where RFID='"+dataf+"'");
        bool rfid_found = false;

        while (query.next()) {
            rfid_found = true;
            MainWindow* a = new MainWindow();
            a->show();
            this->close();
            dataf = "";

            A.close_arduino();
            //disconnect(A.getSerial(), SIGNAL(readyRead()), this, SLOT(update_label()));
        }

        if (!rfid_found) {
            QMessageBox::critical(this, "Error", "RFID not found in database.");
            dataf = "";

        }
    }*/
}





/*void login::update_label()
{
    static QString dataf; // Déclarer dataf comme statique pour conserver sa valeur entre les appels de fonction
    QString data = A.read_from_arduino();
    dataf += QString::fromStdString(data.toStdString());

    if (dataf.endsWith("\r\n")) {
        dataf = dataf.left(dataf.length()-2);

        QSqlQuery query;
        query.exec("select * from login where RFID='"+dataf+"'");
        bool rfid_found = false;

        while (query.next()) {
            rfid_found = true;
            Application* a = new Application();
            a->show();
            this->close();
            dataf = "";
            disconnect(A.getSerial(), SIGNAL(readyRead()), this, SLOT(update_label()));
            break;
        }

        if (!rfid_found) {
            QMessageBox::critical(this, "Error", "RFID not found in database.");
            dataf = "";
        }

        A.clearData();
    }
}

*/







void login::on_pb_on_clicked()
{
  //A.write_to_arduino("1"); //envoyer 1 à arduino
}

void login::on_pb_off_clicked()
{
   // A.write_to_arduino("0");  //envoyer 0 à arduino
}



void login::on_pb_plus_clicked()
{
   // A.write_to_arduino("2");   //envoyer 2 à arduino

}


void login::on_pb_moin_clicked()
{
   // A.write_to_arduino("3");  //envoyer 3 à arduino
}




void login::on_pushButton_clicked()
{
    printf("test1");

}
