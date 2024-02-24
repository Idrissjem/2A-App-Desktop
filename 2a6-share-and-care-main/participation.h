#ifndef PARTICIPATION_H
#define PARTICIPATION_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>

class participation
{
public:
    participation();




    int getid_perso();
    void setid_perso(int);

    bool ajouter(int id_perso,int id_event);
    bool update(int id_perso, int id_event);

private:
     int id_perso;


};

#endif // PARTICIPATION_H
