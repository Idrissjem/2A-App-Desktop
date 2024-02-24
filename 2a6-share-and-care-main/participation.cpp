#include "participation.h"

participation::participation()
{

}


bool participation::ajouter(int id_perso,int id_event)

{
    QSqlQuery query;

            query.prepare("INSERT INTO participation (id_perso , id_event) "
                          "VALUES (:id_perso, :id_event)");
            query.bindValue(":id_perso",id_perso);
             query.bindValue(":id_event",id_event);

      return query.exec();
}

// modifier ravii
bool participation::update(int id_perso, int id_event)

    {
        QSqlQuery query;
        QString res = QString::number(id_perso);
        QString res1 = QString::number(id_event);


        query.prepare("UPDATE participation SET id_event='"+res1+"' WHERE id_perso='"+res+"' ;");

        return query.exec();
    }
