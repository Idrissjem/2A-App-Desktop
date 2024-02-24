
#include "avis.h"
#include <QSystemTrayIcon>

avis::avis()
{

}

avis::avis(int b,QString c)
{

    idRC=b;
    av=c;

}

bool avis::ajouter(int i)
{
    QSqlQuery query;

    QString res2 = QString::number(i);


    query.prepare("INSERT INTO avis_rc(ID_COEUR,AVIS)""VALUES (:IDRC,:avis)");


    query.bindValue(":avis",av);
    query.bindValue(":IDRC",res2);

    return query.exec();
}


QSqlQueryModel * avis::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM avis_rc");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_avis"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("id_coeur"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("avis"));


    return model;
}
void avis::notification_ajoutavis()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("avis: ","commentaire ajoute ",QSystemTrayIcon::Information,15000);
}
