
#ifndef AVIS_H
#define AVIS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class avis
{
public:
    avis();

    avis(int,QString);
    int get_idA(){return idA;}
    int get_idRC(){return idRC;}
    QString get_av(){return av;}


    //Setters
    void set_idA(int a){idA=a;}
    void set_idRC(int a){idRC=a;}
    void set_av(QString b){av=b;}


    //other functions
    QSqlQueryModel * afficher();
    bool ajouter(int);
    void notification_ajoutavis();

    //metiers




private:
    int idA,idRC;
    QString av;


};

#endif // AVIS_H
