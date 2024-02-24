#include "recette.h"
#include<QSqlQuery>
#include <QSqlError>
#include<QSqlQueryModel>


using namespace std ;

recette::recette() : r_id(0)
{

}
recette::recette(int id,  QString &nom)
 :r_id(id) ,r_nom(nom)
{
}
bool recette ::create_r()
{

    QString id= QString::number(r_id) ;

            QSqlQuery query;

            query.prepare("INSERT INTO RECETTE (ID, NOM_R,) "
                          "VALUES (?, ?)");
           // query.addBindValue(r_id);
            query.addBindValue(r_id);
            query.addBindValue(r_nom);



                  return query.exec() ;

}
