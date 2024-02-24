#include "personnel.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QTableView>


Personnel::Personnel()
{
id_PERSO=0;
age=0;
nom="";
prenom="";
email="";
telephone=0;

}

Personnel::Personnel(int id_PERSO,int age,QString nom,QString prenom,QString email,int telephone)
{
this->id_PERSO=id_PERSO;
this->age=age;
this->nom=nom;
this->prenom=prenom;
this->email=email;
this->telephone=telephone;

}





bool Personnel::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO Personnel(id_PERSO, nom, prenom, age, email, telephone) "
                  "VALUES (:id, :nom, :prenom, :age, :email, :telephone)");
    query.bindValue(":id", id_PERSO);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":age", age);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);

    return query.exec();
}





QSqlQueryModel* Personnel::afficher()
{
QSqlQueryModel* model= new QSqlQueryModel();
model->setQuery("select * from Personnel");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_PERSO"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr(" email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));

    return model;
}

bool Personnel::supprimer(int id_PERSO)
{
QSqlQuery query;
QString res= QString::number(id_PERSO);
query.prepare("Delete from personnel where id_PERSO= :id_PERSO ");
query.bindValue(":id_PERSO", res);

return    query.exec();
}






bool Personnel::modifier(int id_PERSO, QString nom, QString prenom, int age, QString email, int telephone)
{
    QSqlQuery query;
    QString res = QString::number(id_PERSO);
        QString res1 = QString::number(age);
        QString res2 = QString::number(telephone);
        query.prepare("update personnel set nom='"+nom+"', prenom='"+prenom+"', email='"+email+"' ,  telephone='"+res2+"', age='"+res1+"' WHERE id_PERSO='"+res+"' ;");

        return query.exec();
    }




/*QSqlQueryModel* Personnel::score()
{
    // Créer le modèle pour les résultats de la requête SQL
    QSqlQueryModel* model = new QSqlQueryModel();

    // Créer la requête SQL pour récupérer le meilleur score avec l'id_PERSO correspondant
    QString query_str = "SELECT id_PERSO, nom, prenom, score FROM Personnel WHERE score = (SELECT MAX(score) FROM Personnel)";
    QSqlQuery query(query_str);

    // Définir le modèle comme contenant les résultats de la requête SQL
    model->setQuery(query);

    // Définir les en-têtes des colonnes du modèle
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_PERSO"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Score"));

    // Retourner le modèle pour afficher les résultats
    return model;
}

*/




/*QSqlQueryModel* Personnel::score()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Obtenir le nombre total d'événements pour chaque membre du personnel
    query.prepare("SELECT personnel.id_perso, personnel.nom, personnel.prenom, COUNT(*) as total_events FROM personnel JOIN participation ON personnel.id_perso = participation.id_perso GROUP BY personnel.id_perso ORDER BY total_events DESC LIMIT 1");
    query.exec();
    model->setQuery(query);

    return model;
}*/




/*bool Personnel::participer(QAbstractItemModel* personnelModel, QAbstractItemModel* evenementModel) {

    SELECT nom, prenom, evenement.ID_EVENT
    FROM Personnel
    INNER JOIN events ON Personnel.id_PERSO = events.IDpersonnel;

}*/


