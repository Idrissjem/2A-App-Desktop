#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "connection.h"

class Personnel
{
public:
    Personnel();
    Personnel(int,int,QString,QString,QString,int);

    int getid_PERSO();
    int getage();
    QString getnom();
    QString getprenom();
    QString getemail();
    int gettelephone();

    void setid_PERSO(int);
    void setage(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void settelephone(int);

    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int id_PERSO);
    bool modifier(int id_PERSO, QString nom,QString prenom,int age,QString email,int telephone);
    QSqlQueryModel * afficher_tri();
   // QSqlQueryModel * chercher_perso(int id_PERSO);
    QSqlQueryModel* score();
   // bool participer(QAbstractItemModel* personnelModel, QAbstractItemModel* evenementModel);

private:
    int id_PERSO,age,telephone;
    QString nom, prenom,email;
};

#endif // PERSONNEL_H
