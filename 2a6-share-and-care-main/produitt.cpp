#include "produitt.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>

produitt::produitt()
{
  id_produit=0; quantite=0; nom_p=" "; description=" ";
}

produitt::produitt (int id_produit ,int quantite, QString nom_p, QString description)
{this->id_produit=id_produit; this->quantite=quantite; this->nom_p=nom_p; this->description=description;}

int produitt::getid_produit(){return id_produit;}
int produitt::getquantite(){return quantite;}
QString produitt::getnom_p(){return nom_p;}
QString produitt::getdescription(){return description;}

void produitt::setid_produit(int id_produit){this->id_produit=id_produit;}
void produitt::setquantite(int quantite){this->quantite=quantite;}
void produitt::setnom_p(QString nom_p){this->nom_p=nom_p;}
void produitt::setdescription(QString description){this->description=description;}

int produitt::fetch_quantite(int uname)
{
    QSqlQuery qry;
     int pref;
    qry.prepare("SELECT * FROM  produit  WHERE id_produit=:id_produit");
    qry.bindValue(":id_produit",uname);

    qry.first();
    qry.exec();

    while(qry.next())
    {
        pref=qry.value(2).toInt();

    }
    return pref;

}

 //modifier produit
  bool produitt::update(int id_produit,int quantite)

  {
      QSqlQuery query;
      QString res = QString::number(id_produit);
      QString res1 = QString::number(quantite);


      query.prepare("update produit set quantite =:quantite where id_produit=:id_produit");
      query.bindValue(":id_produit",res);
       query.bindValue(":quantite",quantite);

      return query.exec();


  }
