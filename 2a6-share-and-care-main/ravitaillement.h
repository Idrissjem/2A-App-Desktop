#ifndef RAVITAILLEMENT_H
#define RAVITAILLEMENT_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>



class ravitaillement
{
public:

    ravitaillement();
    ravitaillement(int);

    int getid_mag();
    void setid_mag(int);

    bool ajouter(int id_mag);
    bool update(int id_mag, int id_produit,int quan);

private:
     int id_mag;


};

#endif // RAVITAILLEMENT_H
