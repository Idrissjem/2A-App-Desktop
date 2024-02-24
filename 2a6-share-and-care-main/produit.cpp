#include "produit.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include<iostream>
#include<QString>
#include "notification.h"
#include <QSystemTrayIcon>
#include <QString>
using namespace std ;

Produit::Produit() : m_id(0), m_quantite(0)
{
}

Produit::Produit(int id ,  const QString &Nom_p, int Quantite, const QString &Description, const QDate &Date_p)
    :m_id(id), m_nom_p(Nom_p), m_quantite(Quantite), m_description(Description), m_date_p(Date_p)
{
}

bool Produit::create()
{

QString id= QString::number(m_id) ;
        QSqlQuery query;

        query.prepare("INSERT INTO PRODUIT (ID_PRODUIT, NOM_P, QUANTITE, DESCRIPTION, DATE_P) "
                      "VALUES (?, ?, ?, ?, ?)");
        query.addBindValue(m_id);
        query.addBindValue(m_nom_p);
        query.addBindValue(m_quantite);
        query.addBindValue(m_description);
        query.addBindValue(m_date_p);
 return query.exec();




}
QSqlQueryModel* Produit::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel();



    model->setQuery("SELECT* FROM PRODUIT");


           model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_P"));

           model->setHeaderData(2, Qt::Horizontal,QObject::tr("QUANTITE"));

           model->setHeaderData(3, Qt::Horizontal,QObject::tr("DESCRIPTION"));

           model->setHeaderData(4, Qt::Horizontal,QObject::tr("DATE_P"));


           return model;



}
bool Produit:: supprimer(int id)
{

    QSqlQuery query;
        query.prepare("DELETE FROM PRODUIT WHERE ID_PRODUIT=:id");
        query.bindValue(":id", id);
        if (query.exec()) {
            if (query.numRowsAffected() > 0) {
                qDebug() << "Deleted row with ID_PRODUIT =" << id;
                return true;
            } else {
                qDebug() << "Row with ID =" << id << "does not exist";
                return false;
            }
        } else {
            qDebug() << "Error deleting row with ID_PRODUIT =" << id << ":" << query.lastError().text();
            return false;
        }

}
bool Produit::modifier(const QString &nom_p, int quantite, const QString &description, const QDate &date_p, int id)
{
    // Prepare the SQL query
      QSqlQuery query;
      query.prepare("UPDATE PRODUIT SET NOM_P = ?, QUANTITE = ?, DESCRIPTION = ?, DATE_P = ? WHERE ID_PRODUIT = ?");

      // Bind the parameters to the query
      query.bindValue(0, nom_p);
      query.bindValue(1, quantite);
      query.bindValue(2, description);
      query.bindValue(3, date_p.toString(Qt::ISODate));
      query.bindValue(4, id);

      // Execute the query and return true if successful, false otherwise
      return query.exec();
  }


bool Produit::RechercheParCIN(int id_rech)
{
    QSqlQuery query;
    //QSqlRecord CIN = query.record();
    QString str= QString::number(id_rech);

    query.prepare("SELECT * FROM PRODUIT WHERE ID_PRODUIT=:id_rech");
    query.bindValue(":id_rech",str);
    query.exec();

    if (query.next())
    {
        return true;
         qDebug()<<"id existe";

    }
    else
    {
        qDebug()<<"id n'existe pas";
        return false;
    }

}


QSqlQueryModel *Produit ::afficherparQTE(int id)
    {
    QSqlQueryModel * model= new QSqlQueryModel();

     QString str= QString::number(id);

    QSqlQuery *q = new QSqlQuery;
     q->prepare("SELECT * from PRODUIT where ID_PRODUIT LIKE '%"+str+"%'");
      q->addBindValue(str);
       q->exec();
         model->setQuery(*q);

        return model;
    }
QSqlQueryModel* Produit ::trierParCIN()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUIT ORDER BY QUANTITE ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_PRODUIT"));

    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM_P"));
     model->setHeaderData(2,Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DESCRIPTION"));


    model->setHeaderData(4,Qt::Horizontal, QObject::tr("DATE_P"));



    return model;
}
QSqlQueryModel* Produit ::trierParID()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUIT ORDER BY ID ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID_PRODUIT"));

    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM_P"));
     model->setHeaderData(2,Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DESCRIPTION"));


    model->setHeaderData(4,Qt::Horizontal, QObject::tr("DATE_P"));



    return model;
}
QSqlQueryModel* Produit ::trierParNOM()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUIT ORDER BY NOM_P ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));

    model->setHeaderData(1,Qt::Horizontal, QObject::tr("NOM_P"));
     model->setHeaderData(2,Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("DESCRIPTION"));


    model->setHeaderData(4,Qt::Horizontal, QObject::tr("DATE_P"));



    return model;
}

QSqlQueryModel* Produit::afficherR(){

    QSqlQueryModel* model=new QSqlQueryModel();



    model->setQuery("SELECT* FROM RECETTE");


           model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM_R"));

           model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID"));



           return model;



}



