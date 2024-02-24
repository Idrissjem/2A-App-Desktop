#ifndef MAGASIN_H
#define MAGASIN_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>

class Magasin
{
public:
    Magasin();
    Magasin(int,int,QString,QString,QString);
    int getid_mag();
    int getphone();
    QString getnom();
    QString getadresse();
    QString getmail();
   // QString getproduit();
    void setid_mag(int);
    void setphone(int);
    void setnom(QString);
    void setadresse(QString);
    void setmail(QString);
   // void setproduit(QString);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    bool update(int id_mag,QString nom,QString adresse,QString mail,int phone);



private:
    int id_mag, phone;
    QString nom,adresse,mail;
    //produit;


};

#endif // MAGASIN_H
