#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include<QSqlQueryModel>
#include<QMessageBox>
#include <QApplication>
#include <QSqlQuery>


class Evenement
{
public:
  Evenement();
  Evenement(int,QString,int,QString,int);

  //Getters
  int getid();
  int getdatee();
  int getcontact();
  QString getdescription();
  QString getlieux();


  //Setters
  void setid(int);
  void setdatee(int);
  void setcontact(int);
  void setdescription(QString);
  void setlieux(QString);



  //Les fonctions
  bool ajouter();
  QSqlQueryModel *afficher();
  bool supprimer(int);
  // Déclaration de la méthode rechercher
  bool modifier(int);
  bool rechercher(int);
  QSqlQueryModel *chercher(int);
  QSqlQueryModel * rechercher(QString valeur);


private:
    int id,datee,contact;
    QString description ,lieux;
};



#endif // EVENEMENT_H
