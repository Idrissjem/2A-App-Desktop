
#include "Evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QVariant>
#include<QMessageBox>
#include <QApplication>

Evenement::Evenement()
{
id=0; datee=0; contact=0;
description=" ";lieux=" ";
}

Evenement::Evenement(int id,QString description,int datee,QString lieux,int contact)
{
    this->id=id;
    this->datee=datee;
    this->contact=contact;
    this->description=description;
    this->lieux=lieux;

}
//Getters
int Evenement::getid(){return id;}
int Evenement::getdatee(){return datee;}
int Evenement::getcontact(){return contact;}
QString Evenement::getdescription(){return description;}
QString Evenement::getlieux(){return lieux;}

//Setters
void Evenement::setid(int id){this->id=id;}
void Evenement::setdatee(int datee){this->datee=datee;}
void Evenement::setcontact(int contact){this->contact=contact;}
void Evenement::setdescription(QString description){this->description=description;}
void Evenement::setlieux(QString lieux){this->lieux=lieux;}


bool Evenement::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Evenement (id, datee, contact, description, lieux) "
                  "VALUES (:id, :datee, :contact, :description, :lieux)");
    query.bindValue(":id", id);
    query.bindValue(":datee", datee);
    query.bindValue(":contact", contact);
    query.bindValue(":description", description);
    query.bindValue(":lieux", lieux);

    return query.exec();
}
//if(!controleSaisie())               // Vérifie si la saisie est valide
        //return false;




QSqlQueryModel* Evenement::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();


        model->setQuery("SELECT * FROM evenement");
           model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEE"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("Contact"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("Description"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("Lieux"));

   return model;
   }
bool Evenement::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from Evenement where id= :id ");
query.bindValue(":id", res);

return    query.exec();
}


bool Evenement::rechercher(int id)
{
    // Requête SQL pour récupérer les informations du evenement avec l'identifiant id
    QSqlQuery query;
    query.prepare("SELECT * FROM evenement WHERE id = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.first()) {
        // Si le evenement est trouvé, on met à jour les attributs de l'objet courant
        this->setid(query.value("id").toInt());
              this->setdatee(query.value("datee").toDouble());
              this->setcontact(query.value("contact").toDouble());
              this->setdescription(query.value("description").toString());
              this->setlieux(query.value("lieux").toString());
    }
    return false;
}
QSqlQueryModel *Evenement::chercher(int id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QString str ;

    if(id== NULL){
        str="SELECT * FROM  evenement";
    }

         str="select * from evenement where id ="+QString::number(id);
        model->setQuery(str);

        return model;

}



bool Evenement::modifier(int id)
{
    QSqlQuery query;
           QString res=QString::number(id);
            QString ress=QString::number(datee);



             query.prepare("UPDATE evenement "" SET datee=:datee, contact=:contact , description=:description, lieux=:lieux where ID=:id ");


                   query.bindValue(":id", res);
                   query.bindValue(":datee", ress);
                   query.bindValue(":contact", contact);
                   query.bindValue(":descreption", description);
                   query.bindValue(":lieux", lieux);



               return query.exec();
}
QSqlQueryModel* Evenement::rechercher(QString valeur)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM evenement WHERE id LIKE :valeur or numPiste LIKE :valeur or longueur LIKE :valeur or largeur LIKE :valeur or type LIKE :valeur");
    valeur = "%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    return model;
}







