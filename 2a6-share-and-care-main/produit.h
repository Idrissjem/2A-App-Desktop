#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QDate>
#include<QSqlQueryModel>
class Produit
{
public:
    // Constructors
    Produit();
    Produit( int id , const QString &Nom_p, int Quantite, const QString &Description, const QDate &Date_p);

    // Getters
    int getid() const { return m_id; }
    QString getnom_p() const { return m_nom_p; }
    int getquantite() const { return m_quantite; }
    QString getdescription() const { return m_description; }
    QDate getdate_p() const { return m_date_p; }

    // Setters
    void setId(int id) { m_id = id; }
    void setNom_p(const QString &nom_p) { m_nom_p = nom_p; }
    void setQuantite(int quantite) { m_quantite = quantite; }
    void setDescription(const QString &description) { m_description = description; }
    void setDate_p(const QDate &date_p) { m_date_p = date_p; }
    QSqlQueryModel* afficher();
QSqlQueryModel* afficherR();
    // CRUD operations
    bool create();
    bool supprimer(int);
    bool modifier(const QString& nom_p, int quantite, const QString& description, const QDate& date_p, int id);
    bool RechercheParCIN(int id_rech);
    QSqlQueryModel *afficherparQTE(int id);
    QSqlQueryModel *trierParCIN();
    QSqlQueryModel *trierParID();
     QSqlQueryModel *trierParNOM();









private:
    int m_id;
    QString m_nom_p;
    int m_quantite;
    QString m_description;
    QDate m_date_p;

};

#endif // PRODUIT_H

