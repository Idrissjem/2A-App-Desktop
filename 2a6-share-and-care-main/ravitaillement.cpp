#include "ravitaillement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QString>

ravitaillement::ravitaillement()
{
   id_mag=0;
}
ravitaillement::ravitaillement(int id_mag)
{this->id_mag=id_mag;}

int ravitaillement::getid_mag(){return id_mag;}
void ravitaillement::setid_mag(int id_mag){this->id_mag=id_mag;}


//ajouter ravi
bool ravitaillement::ajouter(int id_mag)

{
    QSqlQuery query;

            query.prepare("INSERT INTO RAVITAILLEMENT (id_mag) "
                          "VALUES (:id_mag)");
            query.bindValue(":id_mag",id_mag);

      return query.exec();
}

// modifier ravii
bool ravitaillement::update(int id_mag, int id_produit,int quan)

    {
        QSqlQuery query;
        QString res = QString::number(id_mag);
        QString res1 = QString::number(id_produit);
        QString res2 = QString::number(quan);

        query.prepare("UPDATE RAVITAILLEMENT SET id_produit='"+res1+"',quantite='"+res2+"' WHERE id_mag='"+res+"' ;");

        return query.exec();
    }
