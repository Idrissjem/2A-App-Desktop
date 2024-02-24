#ifndef PRODUITT_H
#define PRODUITT_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>


class produitt
{
public:
    produitt();
     produitt(int,int,QString,QString);
     int getid_produit();
     int getquantite();
     QString getnom_p();
     QString getdescription();
     void setid_produit(int);
     void setquantite(int);
     void setnom_p(QString);
     void setdescription(QString);

     int fetch_quantite(int uname);
     bool update(int, int);


private:
    int id_produit, quantite;
    QString nom_p,description;

};

#endif // PRODUIT_H
