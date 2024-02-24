#include "resto_coeur.h"

resto_coeur::resto_coeur()
{

}
resto_coeur::resto_coeur(int a,QString b,QString c,QString d)
{
    id_r=a;
    localisation=c;
    nom=b;
    telephone=d;
}

bool resto_coeur::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id_r);


    query.prepare("INSERT INTO resto_coeur(ID_COEUR,NOM,LOCALISATION,PHONE)""VALUES (:id_r,:nom,:localisation,:telephone)");
    query.bindValue(":id_r",res);

    query.bindValue(":nom",nom);
    query.bindValue(":localisation",localisation);
    query.bindValue(":telephone",telephone);


    return query.exec();
}


QSqlQueryModel * resto_coeur::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM resto_coeur");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_coeur"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("localisation"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("phone"));

    return model;
}


bool resto_coeur::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM resto_coeur WHERE id_coeur = :id");
    query.bindValue(":id",res);
    return query.exec();
}

bool resto_coeur::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("UPDATE resto_coeur SET nom=:nom,localisation=:localisation,phone=:telephone WHERE id_coeur=:id");
    query.bindValue(":id",res);
    query.bindValue(":localisation",localisation);
    query.bindValue(":nom",nom);
    query.bindValue(":telephone",telephone);

    return query.exec();

}



//tri id

QSqlQueryModel * resto_coeur::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM resto_coeur ORDER BY id_coeur ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("phone"));
    return model;
}

//tri nom

QSqlQueryModel * resto_coeur::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM resto_coeur ORDER BY nom ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("phone"));
    return model;
}

//tri localisation

QSqlQueryModel * resto_coeur::tri_loc()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM resto_coeur ORDER BY localisation ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("phone"));
    return model;
}


//recherche
QSqlQueryModel *resto_coeur::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM resto_coeur " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_coeur"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("localisation"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("phone"));

    return model;
}

