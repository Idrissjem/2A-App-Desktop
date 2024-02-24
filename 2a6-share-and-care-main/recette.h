#ifndef RECETTE_H
#define RECETTE_H
#include<QString>
#include<iostream>
#include <QString>
#include <QDate>
#include<QSqlQueryModel>

using namespace  std ;

class recette
{
public:
    recette();
    recette(int id,   QString &nom ) ;
    int getid(){return  r_id ; } ;
    QString getnom(){return r_nom ; }

    void setnom(QString nom) {r_nom=nom ;}
    void setId(int id) { r_id = id; }

    bool create_r() ;
private:
    int r_id ;
    QString r_nom ;
};

#endif // RECETTE_H
