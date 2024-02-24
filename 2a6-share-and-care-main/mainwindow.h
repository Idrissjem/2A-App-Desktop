
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Evenement.h"
#include "resto_coeur.h"
#include "avis.h"
//#include "arduino.h"
#include <QMessageBox>

#include<QMessageBox>
#include <QMainWindow>
#include"produit.h"
#include "arduino.h"


#include "magasin.h"
#include <QSortFilterProxyModel>

#include "personnel.h"
#include "participation.h"
#include "login.h"
#include "arduinoo.h"
#include "arduinof.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QSortFilterProxyModel *proxy;
    QSortFilterProxyModel *proxyP;
    ~MainWindow();

private slots:
    void on_pushButton_23_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_8_clicked();

    void on_pb_ajouter_clicked();

    void on_pushButton_ajouter_rc_clicked();

    void on_pushButton_avi_rc_clicked();

    void on_pushButton_modif_rc_clicked();

    void on_pb_supprimer_rc_clicked();

    void on_pushButton_triID_rc_clicked();

    void on_pushButton_triloc_rc_clicked();

    void on_pushButton_triNom_rc_clicked();

    void on_le_rech_id_rc_textChanged(const QString &arg1);

    void on_le_rech_nom_rc_textChanged(const QString &arg1);

    void on_le_rech_loc_rc_textChanged(const QString &arg1);

    QVector<double> statistiques();
    void makePlot();

    void on_pushButton_stat_rc_clicked();

    void on_pb_ajouter_event_clicked();

    void on_pb_modifier_event_clicked();

    void on_pb_supprimer_event_clicked();

    void on_pushButton_rechercher_event_clicked();

    void on_tableView_2_event_clicked(const QModelIndex &index);

    void on_pb_ajouter_produit_clicked();

    void on_pushButton_rechercher_produit_clicked();

    void on_pushButton_loadTable_produit_clicked();

    void on_pushButton_edit_produit_clicked();

    void on_pb_supprimer_produit_clicked();

    void on_pushButton_pdf_produit_clicked();

    void on_checkBox_toggled(bool checked);

    void on_checkBox_2_toggled(bool checked);

    void on_checkBox_3_toggled(bool checked);

    void on_pushButton_confirmer_clicked();

    void on_pushButton_notif_recette_clicked();

    void on_pushButton_rechercher_9_clicked();

    void on_pb_ajouter_4_clicked();

    void on_pb_alert_produit_clicked();

    void on_pushButton_stat_produit_clicked();

    void on_pb_ajouter_magasin_clicked();

    void show_tables();

    void on_pb_modifier_magasin_clicked();

    void on_pushButton_rechercher_magasin_clicked();

    void on_lineEdit_rechercher_magasin_textChanged(const QString &arg1);

    void on_pushButton_pdf_magasin_clicked();

    void on_pushButton_stat_magasin_clicked();

    void on_tableView_magasin_activated(const QModelIndex &index);

    void on_pb_supprimer_magasin_clicked();

    void on_pb_ok_magasin_clicked();

    void show_tables_perso();

    void on_lineEdit_rechercher_2_textChanged(const QString &arg1);

    void on_pb_ajouter_Perso_clicked();

    void on_pb_supprimer_Perso_clicked();

    void on_pb_modifier_Perso_clicked();

    void on_tableView_3_clicked(const QModelIndex &index);

    void on_pb_stat_Perso_clicked();

    void on_tableView_magasin_clicked(const QModelIndex &index);

    void on_tableView_magasin_doubleClicked(const QModelIndex &index);

    void on_lineEdit_rechercher_3prso_textChanged(const QString &arg1);

    void on_pb_login_clicked();

    bool sign_up(QString pwd,QString email);
    bool sign_in(QString uname,QString pwd);

    void on_pb_ajouter_magasin_2_clicked();

    void on_pb_participer_persoEV_clicked();

    void on_pushButton_comment_rc_clicked();

private:
    Ui::MainWindow *ui;
    resto_coeur rc;
    avis avi;
    Evenement e;
    Evenement Eve;
   int selected=0;
  // Arduino A;
    QByteArray data;
    Produit m_produit;

    Magasin Etmp;
    int selected2=0;
    QRegExp chaine_regex,mail_regex,salaire_regex;
     Arduino a; //magasin

    Personnel tmpPersonnel ;
    Personnel tmpP;
    QRegExp chaine2_regex,email_regex,salaire2_regex;
    int selected3=0;
    int page=0;
 QString dataf;
 void update_label();
 arduinoo ar;
 arduinof af;

};

#endif // MAINWINDOW_H
