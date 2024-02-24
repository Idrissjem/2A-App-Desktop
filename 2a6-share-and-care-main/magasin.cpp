#include "magasin.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>
Magasin::Magasin()
{
 id_mag=0; phone=0;nom=" ";adresse=" "; mail=" ";
 //produit=" ";
}
Magasin::Magasin(int id_mag,int phone,QString nom,QString adresse,QString mail)

{this->id_mag=id_mag; this->phone=phone; this->nom=nom; this->adresse=adresse;  this->mail=mail;}
//this->produit=produit;  }

int Magasin::getid_mag(){return id_mag;}
int Magasin::getphone(){return phone;}
QString Magasin::getnom(){return nom;}
QString Magasin::getadresse(){return adresse;}
QString Magasin::getmail(){return mail;}
//QString Magasin::getproduit(){return produit;}
void Magasin::setid_mag(int id_mag){this->id_mag=id_mag;}
void Magasin::setphone(int phone){this->phone=phone;}
void Magasin::setnom(QString nom){this->nom=nom;}
void Magasin::setadresse(QString adresse){this->adresse=adresse;}
void Magasin::setmail(QString mail){this->mail=mail;}
//void Magasin::setproduit(QString produit){this->produit=produit;}

bool Magasin::ajouter()

{
    QSqlQuery query;

            query.prepare("INSERT INTO Magasin (id_mag, nom, mail, adresse, phone) "
                          "VALUES (:id_mag, :nom, :mail, :adresse, :phone)");
            query.bindValue(":id_mag",id_mag);
            query.bindValue(":nom", nom);
            query.bindValue(":mail", mail);
            query.bindValue(":adresse", adresse);
            query.bindValue(":phone", phone);
         //   query.bindValue(":produit", produit);




      return query.exec();
}
bool Magasin::supprimer(int id_mag)
{
    QSqlQuery query;
    QString res = QString::number(id_mag);
    query.prepare("Delete from Magasin where id_mag=:id_mag");
    query.bindValue(":id_mag",res);
    return query.exec();
}
QSqlQueryModel * Magasin::afficher()
{
    QSqlQueryModel * Model= new QSqlQueryModel;
         Model -> setQuery("select * from Magasin");
         Model -> setHeaderData(0,Qt::Horizontal,QObject::tr("id_mag"));
         Model -> setHeaderData(1,Qt::Horizontal,QObject::tr("mail"));
         Model -> setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
         Model -> setHeaderData(3,Qt::Horizontal,QObject::tr("adresse"));
         Model -> setHeaderData(4,Qt::Horizontal,QObject::tr("phone"));
       //  Model -> setHeaderData(5,Qt::Horizontal,QObject::tr("produit"));

         return Model;
}
bool Magasin::update(int id_mag,QString nom,QString adresse,QString mail,int phone)

    {
        QSqlQuery query;
        QString res = QString::number(id_mag);
        QString res1 = QString::number(phone);

        query.prepare("UPDATE Magasin SET nom='"+nom+"', adresse='"+adresse+"', mail='"+mail+"' ,  phone='"+res1+"' WHERE id_mag='"+res+"' ;");

        return query.exec();
    }
