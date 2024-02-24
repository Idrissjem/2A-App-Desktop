#ifndef RESTO_COEUR_H
#define RESTO_COEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class resto_coeur
{
public:
    resto_coeur();




    resto_coeur(int,QString,QString,QString);
    int get_id(){return id_r;}
    QString get_local(){return localisation;}
    QString get_nom(){return nom;}
    QString get_tel(){return telephone;}

    //Setters
    void set_id(int a){id_r=a;}
    void set_local(QString a){localisation=a;}
    void set_nom(QString b){nom=b;}
    void set_tel(QString f){telephone=f;}


   //other functions
    QSqlQueryModel * afficher();
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);

    //metiers
    QSqlQueryModel *tri_loc();
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel *displayClause(QString cls);
    void notification_ajoutmagasin();
    void notification_suppmagasin();
    void notification_modifmagasin();
    void notification_pdf();



private:
 int id_r;
 QString localisation;
 QString nom;
 QString telephone;

};

#endif // RESTO_COEUR_H
