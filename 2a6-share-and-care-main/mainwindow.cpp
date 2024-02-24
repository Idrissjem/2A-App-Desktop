
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"stat.h"
#include "notification.h"


#include "magasin.h"
#include "produitt.h"
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QtWidgets/QMessageBox>
#include <QByteArray>
#include <QFile>
#include <QFileInfo>
#include "smtp.h"
#include <QPrinter>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QUrlQuery>
#include <QDesktopServices>
#include <QChartView>
#include <QPieSeries>
#include <QtCharts>
#include <QtSql/QSqlQueryModel>
#include <QFileDialog>
#include "ravitaillement.h"
//#include "produit.h"
#include <QTextDocument>
#include <QSortFilterProxyModel>
#include<QIntValidator>
#include "login.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    ui->le_login_password->setEchoMode(QLineEdit::Password);
    show_tables_perso();
    show_tables();
    ui->tableView_2_event->setModel(e.afficher());
    ui->tableView__rc->setModel(rc.afficher());
    ui->tableView_avis_rc->setModel(avi.afficher());
    ui->le_id_event->setValidator( new QIntValidator(0, 9999999, this));
    ui->le_date_event->setValidator( new QIntValidator(0, 9999999, this));
    ui->le_contact_event->setValidator( new QIntValidator(0, 9999999, this));

    ui->le_id_magasin->setValidator(new QIntValidator (0,  9999999, this));
    ui->le_tel_magasin->setValidator(new QIntValidator (0,  9999999, this));
    ui->le_nom_magasin->setValidator(new QRegExpValidator(QRegExp("[a-z A-Z]*")));
    mail_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
    chaine_regex=QRegExp("[a-zA-Z ]{2,20}$");
    salaire_regex=QRegExp("[0-9]+$");




     ui->le_id_Perso->setValidator(new QIntValidator(0,9999999,this));
     email_regex=QRegExp("^[0-9a-zA-Z]+([0-9a-zA-Z]*[-._+])*[0-9a-zA-Z]+@[0-9a-zA-Z]+([-.][0-9a-zA-Z]+)*([0-9a-zA-Z]*[.])[a-zA-Z]{2,6}$");
         chaine2_regex=QRegExp("[a-zA-Z ]{2,20}$");
         salaire2_regex=QRegExp("[0-9]+$");
         ui->tableView_3->setModel(tmpPersonnel.afficher());
         ui->tableView_2_event->setModel(e.afficher());
          ui->stackedWidget->setCurrentIndex(5);




         // lancer la connexion à arduino+.
        /* int rete=A.connect_arduino();

            switch(rete){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }*/
            int rete2=af.connect_arduino();

               switch(rete2){
               case(0):qDebug()<< "arduino is available and connected to : "<< af.getarduino_port_name();
                   break;
               case(1):qDebug() << "arduino is available but not connected to :" <<af.getarduino_port_name();
                  break;
               case(-1):qDebug() << "arduino is not available";
               }
             QObject::connect(af.getserial(),SIGNAL(readyRead()),this,SLOT(affichageinvite()));

             int ret=af.connect_arduino(); // lancer la connexion à arduino
                 switch(ret){
                 case(0):qDebug()<< "arduino is available and connected to : "<< af.getarduino_port_name();
                     break;
                 case(1):qDebug() << "arduino is available but not connected to :" <<af.getarduino_port_name();
                    break;
                 case(-1):qDebug() << "arduino is not available";
                 }
                  QObject::connect(af.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer



}

MainWindow::~MainWindow()
{
    delete ui;


}



void MainWindow::on_pushButton_23_clicked()
{
     if(page==1)
     {ui->stackedWidget->setCurrentIndex(0);}
}


void MainWindow::on_pushButton_9_clicked()
{
    if(page==1)
    {ui->stackedWidget->setCurrentIndex(1);}
}


void MainWindow::on_pushButton_14_clicked()
{
    if(page==1)
    {ui->stackedWidget->setCurrentIndex(2);}
}


void MainWindow::on_pushButton_22_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_8_clicked()
{
    if(page==1)
    {ui->stackedWidget->setCurrentIndex(4);}
}


///////////fares

void MainWindow::on_pb_ajouter_clicked()
{
   ///////////
}

void MainWindow::on_pushButton_ajouter_rc_clicked()
{
    int t=0,id=0;
    rc.set_id(ui->le_id_rc->text().toInt());
    QString checkI=ui->le_id_rc->text();
    for (int i =0;i<checkI.size();i++)
    {

        if (checkI[i].isLetter()){id=1;}
    }
    rc.set_nom(ui->le_nom_rc->text());
    rc.set_local(ui->le_loc_rc->text());
    QString checkT=ui->le_tel_rc->text();

    for (int i =0;i<checkT.size();i++)
    {


        if (checkT[i].isLetter()){t=1;}
    }
    rc.set_tel(ui->le_tel_rc->text());
if(t==0 && id==0){
    bool test=rc.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("ajouté avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView__rc->setModel(rc.afficher());



}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
else
{
    QMessageBox::warning(nullptr, QObject::tr("telephone / ID"),
                QObject::tr("error.\n"
                            "telephone and ID must be a number."), QMessageBox::Cancel);

}
}

void MainWindow::on_pushButton_avi_rc_clicked()
{
    int id_up;

    id_up=ui->tableView__rc->model()->data(ui->tableView__rc->model()->index(ui->tableView__rc->currentIndex().row(),0)).toInt();
    avi.set_av(ui->le_com_av->text());
    avi.set_idRC(id_up);
        QString test2=ui->le_com_av->text();




                bool test=avi.ajouter(id_up);

                if (test2=="bien"){
                    af.write_to_arduino("1");
                }
                else if (test2=="mauvaise")
                {
                    af.write_to_arduino("0");
                }


                if(test)
                {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                                     QObject::tr("ajouté avec succes.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_avis_rc->setModel(avi.afficher());
            avi.notification_ajoutavis();



                }
                else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                  QObject::tr("error.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modif_rc_clicked()
{
    int id_up;
    int t=0;
    id_up=ui->tableView__rc->model()->data(ui->tableView__rc->model()->index(ui->tableView__rc->currentIndex().row(),0)).toInt();
    rc.set_nom(ui->le_modif_nom_rc->text());
    rc.set_local(ui->le_modif_loc_rc->text());
    rc.set_tel(ui->le_modif_tel_rc->text());
    QString checkT=ui->le_modif_tel_rc->text();
    for (int i =0;i<checkT.size();i++)
    {

        if (checkT[i].isLetter()){t=1;}
    }


    if(t==0 ){
        bool test=rc.modifier(id_up);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("ajouté avec succes.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView__rc->setModel(rc.afficher());



    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("error.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::warning(nullptr, QObject::tr("telephone / ID"),
                    QObject::tr("error.\n"
                                "telephone and ID must be a number."), QMessageBox::Cancel);

    }

}

void MainWindow::on_pb_supprimer_rc_clicked()
{
    int id_del;
            id_del=ui->tableView__rc->model()->data(ui->tableView__rc->model()->index(ui->tableView__rc->currentIndex().row(),0)).toInt();
            bool test=rc.supprimer(id_del);
            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("supprimé avec succes.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->tableView__rc->setModel(rc.afficher());

        }
            else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("error.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_triID_rc_clicked()
{
     ui->tableView__rc->setModel(rc.tri_id());
}

void MainWindow::on_pushButton_triloc_rc_clicked()
{
    ui->tableView__rc->setModel(rc.tri_loc());

}

void MainWindow::on_pushButton_triNom_rc_clicked()
{
    ui->tableView__rc->setModel(rc.tri_nom());

}

void MainWindow::on_le_rech_id_rc_textChanged(const QString &arg1)
{
    if(ui->le_rech_id_rc->text()!="")
    {
                QString a=ui->le_rech_id_rc->text();
                ui->tableView__rc->setModel(rc.displayClause("WHERE (id_coeur LIKE '%"+a+"%') "));
    }
    else
                ui->tableView__rc->setModel(rc.afficher());
}

void MainWindow::on_le_rech_nom_rc_textChanged(const QString &arg1)
{
    if(ui->le_rech_nom_rc->text()!="")
    {
                QString a=ui->le_rech_nom_rc->text();
                ui->tableView__rc->setModel(rc.displayClause("WHERE (nom LIKE '%"+a+"%') "));
    }
    else
                ui->tableView__rc->setModel(rc.afficher());

}

void MainWindow::on_le_rech_loc_rc_textChanged(const QString &arg1)
{
    if(ui->le_rech_loc_rc->text()!="")
    {
                QString a=ui->le_rech_loc_rc->text();
                ui->tableView__rc->setModel(rc.displayClause("WHERE (localisation LIKE '%"+a+"%') "));
    }
    else
                ui->tableView__rc->setModel(rc.afficher());
}

QVector<double> MainWindow::statistiques()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT localisation FROM resto_coeur WHERE localisation = 'nord'");
    q.exec();
    while (q.next())
    {
                stat[0]++;

    }
    q.prepare("SELECT localisation FROM resto_coeur WHERE localisation = 'sud';");
    q.exec();
    while (q.next())
    {
                stat[1]++;

    }
    q.prepare("SELECT localisation FROM resto_coeur WHERE localisation = 'est';");
    q.exec();
    while (q.next())
    {
                stat[2]++;

    }
    q.prepare("SELECT localisation FROM resto_coeur WHERE localisation = 'ouest';");
    q.exec();
    while (q.next())
    {
                stat[3]++;

    }
    q.prepare("SELECT localisation FROM resto_coeur WHERE localisation = 'centre'; ");
    q.exec();
    while (q.next())
    {
                stat[4]++;

    }
    return stat;
}

void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
                x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
                y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::statistiques());////fonction statistiques
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customplot->replot();

    // move bars above graphs and grid below bars:
    ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
    ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
    ui->customplot->xAxis->grid()->setLayer("belowmain");
    ui->customplot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6<<7;//////
    QVector<QString> labels;
    labels<<"nord"<<"ouest"<<"est"<<"sud"<<"centre";////////
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0,4);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(00, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}


void MainWindow::on_pushButton_stat_rc_clicked()
{
    ui->tabWidget_4->setCurrentIndex(2);
    ui->customplot->clearPlottables();
    MainWindow::makePlot();
    MainWindow::makePlot();
}

///////////////evennement



void MainWindow::on_pb_ajouter_event_clicked()
{
    //Récupération des informations saisies dans les 5 champs
       int id=ui->le_id_event->text().toInt();
       int datee=ui->le_date_event->text().toInt();
       int contact=ui->le_contact_event->text().toInt();
       QString description=ui->le_description_event->text();
       QString lieux=ui->le_lieux_event->text();



       //instancier l'objet de la classe Evenement
      Evenement e(id,description,datee,lieux,contact);

    //insérer l'objet evenement instancié dans la table piste
    //et récupérer la valeur de retour de query.exec()
    bool test=e.ajouter();

    //si la requete executée => QMessageBox::information
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Ajout effectué\n"
                                 "Click Cancel to exit"), QMessageBox::Cancel);

        //Actualiser le tableau apres l'ajout
        ui->tableView_2_event->setModel(e.afficher());
    }
    //si la requete non exécuté => QMessageBox::critical
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                     QObject::tr("Ajout non effectué\n"
                                 "Click Cancel to exit"), QMessageBox::Cancel);
    }

}

void MainWindow::on_pb_modifier_event_clicked()
{
    int id=ui->le_id_event->text().toInt();
    int datee=ui->le_date_event->text().toInt();
    int contact=ui->le_contact_event->text().toInt();
    QString description=ui->le_description_event->text();
    QString lieux=ui->le_lieux_event->text();


    Evenement e(id,description,datee,lieux,contact);
    bool test=e.modifier(id);
    ui->tableView_2_event->setModel(e.afficher());
 if(test){

    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
}else{
     QMessageBox::information(nullptr,QObject::tr("Not oK"),
                              QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


 }
}

void MainWindow::on_pb_supprimer_event_clicked()
{
    bool test=Eve.supprimer(selected);
    if(test)
    {
        // rafraîchissement
        ui->tableView_2_event->setModel(Eve.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                              QObject::tr("Suppression effectuée\n"
                                          "Cliquez sur Annuler pour sortir."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("Suppression non effectuée.\n"
                                       "Cliquez sur Annuler pour sortir."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_rechercher_event_clicked()
{
    // Récupérer la valeur de recherche et supprimer les espaces inutiles
    QString valeur = ui->lineEdit_rechercher_event->text().trimmed();

    // Vérifier si la valeur de recherche est vide
    if (valeur.isEmpty())
    {
        // Afficher un message d'erreur
        QMessageBox::warning(this, "Recherche", "Veuillez saisir une valeur de recherche.");
        // Quitter la fonction sans exécuter la recherche
        return;
    }

    // Appeler la fonction de recherche dans la classe Piste et récupérer le modèle de résultats
    QSqlQueryModel *model = e.rechercher(valeur);

    // Vérifier si aucun résultat n'a été trouvé
    if (model->rowCount() == 0)
    {
        // Afficher un message d'information
        QMessageBox::information(this, "Recherche", "Aucun résultat trouvé.");
    }
    else
    {
        // Créer un message avec le nombre de résultats trouvés
        QString message = QString("%1 résultat(s) trouvé(s).").arg(model->rowCount());
        // Afficher un message d'information avec le nombre de résultats trouvés
        QMessageBox::information(this, "Recherche", message);
        // Définir le modèle de résultats dans la table
        ui->tableView_2_event->setModel(model);
        // Trier les résultats par ordre croissant de l'id
        ui->tableView_2_event->sortByColumn(0, Qt::AscendingOrder);
    }
}

void MainWindow::on_tableView_2_event_clicked(const QModelIndex &index)
{
    selected = ui->tableView_2_event->model()->data(index).toInt();
}

void MainWindow::on_pb_ajouter_produit_clicked()
{
    int id =ui->le_id_produit->text().toInt() ;
    QString nom_p = ui->le_nom_produit->text();
    QString description = ui->le_description_produit->text();
    int quantite = ui->le_quant_produit->text().toInt();
    QDate date_p = ui->dateEdit_produit->date();


    // Create an instance of the Produit class
    Produit m_produit(id,nom_p, quantite, description, date_p);

    // Call the create() function to insert the data
    bool success = m_produit.create();

    if (success) {
        ui->tableView_produit->setModel(m_produit.afficher());
        // Success
        notification myNotification("Product Created", "The product has been created successfully.");
        myNotification.afficher();
        QMessageBox::information(this, tr("Success"),
                                 tr("Product created successfully."));


        // Refresh the table view
    } else {
        // Error
        QMessageBox::critical(this, tr("Error"),
                              tr("Failed to create product."));
    }

}

void MainWindow::on_pushButton_rechercher_produit_clicked()
{
    int id = ui->lineEdit_rechercher_produit->text().toInt();
       bool test=m_produit.RechercheParCIN(id);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("CIN existe"),
                        QObject::tr("CIN existe.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_produit->setModel( m_produit.afficherparQTE(id));//refresh

            ui->lineEdit_rechercher_produit->clear();

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("CIN n'existe pas"),
                        QObject::tr("CIN n'existe pas !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_rechercher_produit->clear();
}

void MainWindow::on_pushButton_loadTable_produit_clicked()
{
    QSqlQuery qry ;
    qry.prepare("select *from PRODUIT") ;
    qry.exec( ) ;
    ui->tableView_produit->setModel(m_produit.afficher() ) ;
}


void MainWindow::on_pushButton_edit_produit_clicked()
{
    bool ok;

    int id = QInputDialog::getInt(this, tr("Edit a Record"), tr("Enter the ID of the record you want to edit:"), 0, 0, 1000000, 1, &ok);
    QString dateString = QInputDialog::getText(this, tr("Edit a Record"), tr("Enter the new date of production of the product (format: yyyy-MM-dd):"), QLineEdit::Normal, "", &ok);

    if (ok) {
        QString nom_p = QInputDialog::getText(this, tr("Edit a Record"), tr("Enter the new name of the product:"), QLineEdit::Normal, QString(), &ok);
        if (ok && !nom_p.isEmpty()) {
            int quantite = QInputDialog::getInt(this, tr("Edit a Record"), tr("Enter the new quantity of the product:"), 0, 0, 1000000, 1, &ok);
            if (ok) {
                QString description = QInputDialog::getText(this, tr("Edit a Record"), tr("Enter the new description of the product:"), QLineEdit::Normal, QString(), &ok);
                if (ok) {
                    QDate date = QDate::fromString(dateString, "yyyy-MM-dd");
                    if (ok) {
                        Produit produit;
                        if (produit.modifier( nom_p, quantite, description, date,id)) {
                            QMessageBox::information(nullptr, QObject::tr("Edit Successful"), QObject::tr("Record edited successfully."), QMessageBox::Ok);
                            ui->tableView_produit->setModel(produit.afficher());
                        } else {
                            QMessageBox::critical(nullptr, QObject::tr("Edit Error"), QObject::tr("Failed to edit record."), QMessageBox::Ok);
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::on_pb_supprimer_produit_clicked()
{
    bool ok;
       int id = QInputDialog::getInt(this, tr("Delete a Record"), tr("Enter the ID of the record you want to delete:"), 0, 0, 1000000, 1, &ok);
       if (ok) {

           Produit produit;
           produit.setId(id);
           if (produit.supprimer(id)) {
               QMessageBox::information(nullptr, QObject::tr("Delete Successful"), QObject::tr("Record deleted successfully."), QMessageBox::Ok);
               ui->tableView_produit->setModel(produit.afficher());
           } else {
               QMessageBox::critical(nullptr, QObject::tr("Delete Error"), QObject::tr("Failed to delete record."), QMessageBox::Ok);
           }
       }
}

void MainWindow::on_pushButton_pdf_produit_clicked()
{
    QPdfWriter pdf("C:/Users/jihed/OneDrive/Bureau/project/PDF/PRODUIT.pdf");
    QPainter painter(&pdf);
    int i = 4000;

    painter.setPen(Qt::red);
    painter.setFont(QFont("Cambria", 30));
    painter.drawText(2000, 1400, "LISTES DES PRODUITS ");

    painter.setPen(Qt::black);
    painter.setFont(QFont("Cambria", 15));
    painter.drawRect(100, 100, 9400, 2500);
    painter.drawRect(100, 3000, 9400, 500);

    painter.setFont(QFont("Cambria", 10));
    painter.drawText(500, 3300, "ID_PRODUIT");
    painter.drawText(2000, 3300, "NOM_P");
    painter.drawText(3000, 3300, "QUANTITE ");
    painter.drawText(4000, 3300, "DESCRIPTION ");
    painter.drawText(6000, 3300, "DATE_p");

    painter.drawRect(100, 3000, 9400, 9000);

    QSqlQuery query;
    query.prepare("select * from PRODUIT");
    query.exec();
    while (query.next()) {
        painter.drawText(500, i, query.value(0).toString());
        painter.drawText(2000, i, query.value(1).toString());
        painter.drawText(3000, i, query.value(2).toString());
        painter.drawText(4000, i, query.value(3).toString());
        painter.drawText(6000, i, query.value(4).toString());
        painter.drawText(8500, i, query.value(5).toString());
       // QImage signatureImage("C:/Users/jihed/OneDrive/Bureau/project/PDF/signature.png");
      //  painter.drawImage(QRectF(500, 12000, 2000, 1000), signatureImage);
        i = i + 350;
    }



    QMessageBox::information(this, tr("PDF Enregistré!"),
                             tr("PDF Enregistré!.\nClick Cancel to exit."),
                             QMessageBox::Cancel);
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if (checked == true){
                       ui->tableView_produit->setModel(m_produit.trierParCIN());
                   } else {
                        ui->tableView_produit->setModel(m_produit.afficher());
                   }
}

void MainWindow::on_checkBox_2_toggled(bool checked)
{
    if (checked == true){
                       ui->tableView_produit->setModel(m_produit.trierParID());
                   } else {
                        ui->tableView_produit->setModel(m_produit.afficher());
                   }
}

void MainWindow::on_checkBox_3_toggled(bool checked)
{
    if (checked == true){
                       ui->tableView_produit->setModel(m_produit.trierParNOM());
                   } else {
                        ui->tableView_produit->setModel(m_produit.afficher());
                   }
}

void MainWindow::on_pushButton_confirmer_clicked()
{
    QStringList ingredientList;
            QString recipeName = ui->lineEdit_rechercher_recette->text();
            QString ingredients;

            // Get the recipe ID from the RECETTE table
            QSqlQuery query;
            query.prepare("SELECT ID_RECETTE FROM RECETTE WHERE NOM_R = :name");
            query.bindValue(":name", recipeName);
            if (query.exec() && query.next()) {
                // ...
            } else {
                qDebug() << "Recipe ID:" << query.value(0).toString();

                QMessageBox::warning(this, "Error", "Ce REcette N'existe Pas.");
                return;

            }
            int recipeId = query.value(0).toInt();


            query.prepare("SELECT NOM_P FROM PRODUIT "
                          "WHERE ID IN (SELECT ID_PRODUIT FROM G_RECETTE WHERE ID_RECETTE = :recipeId)");
            query.bindValue(":recipeId", recipeId);
            if (!query.exec()) {
                QMessageBox::warning(this, "Error", "Failed to get recipe ingredients.");
                return;
            }

            // Concatenate the ingredients into a string
            while (query.next()) {
                ingredients += query.value(0).toString() + ", ";
            }
            if (!ingredients.isEmpty()) {
                // Remove the last comma and space
                ingredients.chop(2);
            }

            // Concatenate the ingredients into a string
                ingredients = ingredientList.join(", ");
                qDebug() << "Ingredients:" << ingredientList;
               // qDebug() << "Query result:" << query.lastQuery() << query.boundValues() << query.lastError();

                // Display the ingredients in a message box
                QMessageBox::information(this, "Recipe Ingredients",
                                         "The ingredients for " + recipeName + " are: tomate , eggs , and pomme de terre " + ingredients);

}

void MainWindow::on_pushButton_notif_recette_clicked()
{
    notification myNotification("Notification Title", "you have no notification now");
    myNotification.afficher();
}

void MainWindow::on_pushButton_rechercher_9_clicked()
{
    QSqlQuery qry ;
    qry.prepare("select *from RECETTE") ;
    qry.exec( ) ;
    ui->tableView_recette->setModel(m_produit.afficherR() ) ;
}

void MainWindow::on_pb_ajouter_4_clicked()
{
    /*int result = a.connect_arduino();
    if(result == -1) {
        QMessageBox::warning(this, tr("Connection Error"), tr("Couldn't connect to the Arduino."));
    } else {
        QMessageBox::information(this, tr("Connection Successful"), tr("Connected to the Arduino."));
    }
    */
}

void MainWindow::on_pb_alert_produit_clicked()
{
   /* QSqlQuery query;

          a.write_to_arduino("1");
          */
}

void MainWindow::on_pushButton_stat_produit_clicked()
{
    stati s;
    s.exec();
}



///////////////////magasin

void MainWindow::show_tables()
{

    //permet recherche et tri
        proxy = new QSortFilterProxyModel();
        //definir la source (tableau original)
        proxy->setSourceModel(Etmp.afficher());
       //pour la recherche
        proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxy->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
        //faire tri
        proxy->setDynamicSortFilter(true);
        ui->tableView_magasin->setSortingEnabled(true);
        //remplissage tableau avec le masque
        ui->tableView_magasin->setModel(proxy);

}

void MainWindow::on_pb_ajouter_magasin_clicked()
{
    QString nom=ui->le_nom_magasin->text();
    QString mail=ui->le_mail_magasin->text();
    int phone=ui->le_tel_magasin->text().toInt();
    int id_mag=ui->le_id_magasin->text().toInt();
    QString adresse=ui->le_adresse_magasin->text();
    //controle de saisie
                      bool mail_verif = mail_regex.exactMatch(ui->le_mail_magasin->text());
                      bool cin_verif=salaire_regex.exactMatch(ui->le_id_magasin->text());
                      bool phone_verif=salaire_regex.exactMatch(ui->le_tel_magasin->text());
                      bool nom_verif=chaine_regex.exactMatch(ui->le_nom_magasin->text());
                      bool adresse_verif=chaine_regex.exactMatch(ui->le_adresse_magasin->text());
                      if(cin_verif && nom_verif && mail_verif && adresse_verif && phone_verif  )
                           {

    Magasin M(id_mag,phone,nom,adresse,mail);
    ravitaillement r;

    bool test=M.ajouter();
    r.ajouter(id_mag);
          if(test){
              Smtp* smtp = new Smtp("sarra.mezni@esprit.tn","navvyessjtthstfn", "smtp.gmail.com");
              connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
              smtp->sendMail("sarra.mezni@esprit.tn", mail , " Welcome ShareMeal ","welcome Votre Nom est " +nom +" /n " +adresse );

             ui->tableView_magasin->setModel(Etmp.afficher());
              show_tables();

              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("ajouter.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
   }       }
          else
                          //controle de saisieeeeee
          {
              QMessageBox::critical(nullptr, QObject::tr("not ok "),
                          QObject::tr("ajout failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
              if (!mail_verif){
                   QMessageBox::warning(nullptr, QObject::tr("not ok "),
                                                    QObject::tr("Email doesnt meet requirements \n"
                                                                "Click Cancel to exit."), QMessageBox::Cancel);


                      }

              if (!adresse_verif){
                   QMessageBox::warning(nullptr, QObject::tr("not ok "),
                                                    QObject::tr("Adresse doesnt meet requirements \n"
                                                                "Click Cancel to exit."), QMessageBox::Cancel);


                      }
              if (!nom_verif){
                   QMessageBox::warning(nullptr, QObject::tr("not ok "),
                                                    QObject::tr("Nom doesnt meet requirements \n"
                                                                "Click Cancel to exit."), QMessageBox::Cancel);


                      }
              if (!cin_verif){
                   QMessageBox::warning(nullptr, QObject::tr("not ok "),
                                                    QObject::tr("Identifiant doesnt meet requirements \n"
                                                                "Click Cancel to exit."), QMessageBox::Cancel);


                      }
              if (!phone_verif){
                   QMessageBox::warning(nullptr, QObject::tr("not ok "),
                                                    QObject::tr("Phone doesnt meet requirements \n"
                                                                "Click Cancel to exit."), QMessageBox::Cancel);


                      }
          }


}

void MainWindow::on_pb_modifier_magasin_clicked()
{
    int id_mag = ui->le_id_magasin->text().toInt();
    QString nom = ui->le_nom_magasin->text();
    QString mail = ui->le_mail_magasin->text();
    int phone = ui->le_tel_magasin->text().toInt();

    QString adresse= ui->le_adresse_magasin->text();



        bool test = Etmp.update(id_mag, nom, adresse, mail, phone);

        if (test)
        {
            Smtp* smtp = new Smtp("sarra.mezni@esprit.tn","navvyessjtthstfn", "smtp.gmail.com");
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
            smtp->sendMail("sarra.mezni@esprit.tn", mail , " Welcome ShareMeal ","vous avez modifier " +nom );


            ui->tableView_magasin->setModel(Etmp.afficher());
            show_tables();

            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("update.\n"
                                                 "Click Cancel to exit."),
                                     QMessageBox::Cancel);


    }

    else
    {

        QMessageBox::warning(nullptr, QObject::tr("not ok "),
                             QObject::tr("update failed \n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_rechercher_magasin_clicked()
{

}

void MainWindow::on_lineEdit_rechercher_magasin_textChanged(const QString &arg1)
{
    proxy->setFilterFixedString(arg1);
}

void MainWindow::on_pushButton_pdf_magasin_clicked()
{
    QPdfWriter pdf("C:/Users/mahdi/Downloads/INTEGRATION/IntegFares/Magasin.pdf");
        QPainter painter(&pdf);

      //  painter.fillRect(0,0,9600 ,13650,QColor(248, 246, 231));
        //chnbadel couleurr
        painter.fillRect(0,0,9600 ,13650,QColor(236, 229, 252));


       int i = 4000;

       painter.fillRect(100,100,6000,1900,QColor(245, 252, 229));

            painter.setPen(QColor(16, 127, 54));
            painter.setFont(QFont("Comic Sans MS", 30));
            painter.drawText(700,1100,"La Liste Des Magasins ");
            painter.setPen(QColor(135, 184, 147));
            painter.setFont(QFont("Comic Sans MS", 50));
            painter.drawRect(100,100,6000,1900);
            painter.drawPixmap(QRect(6500,70,3000,2200),QPixmap("C:/Users/mahdi/Downloads/INTEGRATION/IntegFares/image/Image1.png"));
          //  painter.setPen(QColor(135, 184, 147));
         //painter.setPen(QColor(170, 212, 193));

            painter.drawRect(0,3000,9600,500);
            painter.fillRect(0,3000,9600,500,QColor(245, 252, 229));
            painter.setPen(Qt::darkGreen);

            painter.setFont(QFont("Comic Sans MS", 11));
            painter.drawText(100,3300,"Identifiant");
            painter.drawText(1400,3300,"Nom");
            painter.drawText(2700,3300,"Adresse");
            painter.drawText(4800,3300,"Phone");
            painter.drawText(7000,3300,"Email");



            painter.setPen(QColor(47, 62,150));
         QString date =   "Generated on "  +   QDate::currentDate().toString("dd/MM/yyyy");
         painter.drawText(6700,2800,date);
        // painter.drawText(6500,13500,date);



            QSqlQuery query;
            query.prepare("select * from MAGASIN");
            query.exec();
            while (query.next())
            {
                painter.setPen(Qt::darkMagenta);
                painter.drawText(100,i,query.value(0).toString());
                painter.setPen(Qt::black);
                painter.drawText(1400,i,query.value(1).toString());
                painter.drawText(2700,i,query.value(2).toString());
                painter.drawText(4800,i,query.value(3).toString());
                painter.drawText(6600,i,query.value(4).toString());

                painter.setPen(QColor(47, 62,150));




               i = i + 500;
            }
            int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré! -Voulez-Vous Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                if (reponse == QMessageBox::Yes)
               {
                    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/mahdi/Downloads/INTEGRATION/IntegFares/Magasin.pdf"));
                    painter.end();
}
                if (reponse == QMessageBox::No)
                {
                     painter.end();
                }
}

void MainWindow::on_pushButton_stat_magasin_clicked()
{
    QSqlQuery query;
        query.exec("SELECT adresse FROM Magasin");

        QMap<QString, int> counts;
        int total = 0;

        while (query.next()) {
            QString type = query.value(0).toString();
            if (counts.contains(type)) {
                counts[type]++;
            } else {
                counts[type] = 1;
            }
            total++;
        }

        QPieSeries *series = new QPieSeries();
        for (auto it = counts.begin(); it != counts.end(); it++) {
            double percentage = 100 * it.value() / total;
            series->append(it.key() + QString(" (%1%)").arg(percentage, 0, 'f', 1), it.value());
        }

        QChart *chart = new QChart();

        chart->addSeries(series);
        chart->setTitle("Statistiques pour l'attribut \"adresse\"");
        series->setPieSize(0.7);
        series->setLabelsVisible();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QDialog *dialog = new QDialog();
        dialog->resize(800, 600);
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);
        dialog->setLayout(layout);

        chart->setParent(chartView);
        dialog->exec();
}

void MainWindow::on_tableView_magasin_activated(const QModelIndex &index)
{
    QString val = ui->tableView_magasin->model()->data(index).toString();
    QSqlQuery query;
    query.prepare("select * from Magasin where  id_mag ='" + val + "' ");
    if (query.exec())
    {

        while (query.next())
        {

            ui->le_id_magasin->setText(query.value(0).toString());
            ui->le_nom_magasin->setText(query.value(1).toString());
            ui->le_adresse_magasin->setText(query.value(2).toString());
            ui->le_tel_magasin->setText(query.value(3).toString());
            ui->le_mail_magasin->setText(query.value(4).toString());
            ui->le_id_rav_magasin->setText(query.value(0).toString());


        }

}

}

void MainWindow::on_pb_supprimer_magasin_clicked()
{
    //  int id_mag = ui->le_identifiant->text().toInt();
      QString nom = ui->le_nom_magasin->text();
      QString mail = ui->le_mail_magasin->text();
     // int phone = ui->le_phone->text().toInt();
      QString adresse= ui->le_adresse_magasin->text();

      //int id_mag=ui->idmagasin->text().toInt();
          bool test=Etmp.supprimer(selected2);

          if(test){
              Smtp* smtp = new Smtp("sarra.mezni@esprit.tn","navvyessjtthstfn", "smtp.gmail.com");
              connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
              smtp->sendMail("sarra.mezni@esprit.tn", mail , " Welcome ShareMeal "," suprimmer suprimer " +nom  +" /n " +adresse );


            ui->tableView_magasin->setModel(Etmp.afficher());
      show_tables();

              QMessageBox::information(nullptr, QObject::tr("ok"),
                          QObject::tr("supprimer.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("not ok "),
                          QObject::tr("supprimer failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }

}

void MainWindow::on_pb_ok_magasin_clicked()
{
    int id_mag = ui->le_id_rav_magasin->text().toInt();
    int id_produit = ui->le_idP_magasin->text().toInt();
    int quantite = ui->le_quan_magasin->text().toInt();


    ravitaillement r;
      produitt p;
      r.update(id_mag,id_produit,quantite);
      int quantite_final=quantite+p.fetch_quantite(id_produit);


      QSqlQuery query;
      QByteArray message;
      QString ch;
      int quantite_stop;
      QString res1 = QString::number(id_produit);
      query.prepare("select * from PRODUIT where id_produit= "+res1+"");
      if (query.exec())
                          {
                              while(query.next())
                              {
                               ch =query.value(1).toString();
                               quantite_stop=query.value(2).toInt();


                               if (quantite_stop <99)
                               {
                                   bool test = p.update(id_produit,quantite_final);
                                   if (test)
                                   {

                                       QMessageBox::information(nullptr, QObject::tr("ok"),
                                                                QObject::tr("update.\n"
                                                                            "Click Cancel to exit."),
                                                                QMessageBox::Cancel);


                               }

                               else
                               {

                                   QMessageBox::warning(nullptr, QObject::tr("not ok "),
                                                        QObject::tr("update failed \n"
                                                                    "Click Cancel to exit."),
                                                        QMessageBox::Cancel);
                               }

                               }
                               if (quantite_stop >99)
                               {
                                   ch="Alerte Quantite";
                                   message=ch.toUtf8();

                                   a.write_to_arduino(message) ;

                               }

                              }

                               message=ch.toUtf8();

                               a.write_to_arduino(message) ;


                             }



}
//////////////////////perso


void MainWindow::show_tables_perso()
{

    //permet recherche et tri
        proxyP = new QSortFilterProxyModel();
        //definir la source (tableau original)
        proxyP->setSourceModel(tmpP.afficher());
       //pour la recherche
        proxyP->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxyP->setFilterKeyColumn(-1); // chercher dans tout le tableau (-1) ou donner le numero de la colone
        //faire tri
        proxyP->setDynamicSortFilter(true);
        ui->tableView_3->setSortingEnabled(true);
        //remplissage tableau avec le masque
        ui->tableView_3->setModel(proxyP);

}
void MainWindow::on_lineEdit_rechercher_2_textChanged(const QString &arg1)
{
    proxyP->setFilterFixedString(arg1);
     ui->tableView_3->setModel(proxyP);
}

void MainWindow::on_pb_ajouter_Perso_clicked()
{
    int id_PERSO=ui->le_id_Perso->text().toInt();
    QString nom=ui->le_nom_Perso->text();
    QString prenom=ui->le_prenom_Perso->text();
    int age=ui->le_age_Perso->text().toInt();
    QString email=ui->le_email_Perso->text();
    int telephone=ui->le_tel_Perso->text().toInt();


                      bool id_PERSO_verif=salaire2_regex.exactMatch(ui->le_id_Perso->text());
                      bool nom_verif=chaine2_regex.exactMatch(ui->le_nom_Perso->text());
                      bool prenom_verif=chaine2_regex.exactMatch(ui->le_prenom_Perso->text());
                      bool age_verif=salaire2_regex.exactMatch(ui->le_age_Perso->text());
                      bool email_verif=email_regex.exactMatch((ui->le_email_Perso->text()));
                      bool telephone_verif=salaire2_regex.exactMatch((ui->le_tel_Perso->text()));

                      if (id_PERSO_verif && nom_verif && prenom_verif && age_verif && email_verif && telephone_verif)
                          {


    login l;

     l.sign_up(QString::number(id_PERSO),email);




                      Personnel P(id_PERSO,age,nom,prenom,email,telephone);

       bool test=P.ajouter();
       show_tables_perso();
    if(test) // si requête exécutée
    {
        // rafraîchissement
        show_tables();
         ui->tableView_3->setModel(tmpPersonnel.afficher());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("Ajout effectué\n"
                                            "Cliquez sur Annuler pour sortir."),QMessageBox::Cancel);
 }   }
    else{
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Cliquez sur Annuler pour sortir."),QMessageBox::Cancel);




          if (!email_verif){
              QMessageBox::warning(nullptr, QObject::tr("not ok "),
                                               QObject::tr("Email doesnt meet requirements \n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
              }

           if(!id_PERSO_verif){
               QMessageBox::warning(nullptr,QObject::tr("not ok"),
                                               QObject::tr("id_PERSO doesnt meet requirements\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);

           }
           if(!nom_verif){
               QMessageBox::warning(nullptr,QObject::tr("not ok"),
                                               QObject::tr("nom doesnt meet requirements\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);

           }


           if(!prenom_verif){
               QMessageBox::warning(nullptr,QObject::tr("not ok"),
                                               QObject::tr("prenom doesnt meet requirements\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);

           }


           if(!age_verif){
               QMessageBox::warning(nullptr,QObject::tr("not ok"),
                                               QObject::tr("age doesnt meet requirements\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);

           }

           if(!telephone_verif){
               QMessageBox::warning(nullptr,QObject::tr("not ok"),
                                               QObject::tr("telephone doesnt meet requirements\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);

           }
}
}

void MainWindow::on_pb_supprimer_Perso_clicked()
{
    //int id_PERSO=ui->lineEdit_id_PERSO->text().toInt();
    bool test=tmpPersonnel.supprimer(selected3);
    if(test)
    {
        // rafraîchissement
        ui->tableView_3->setModel(tmpPersonnel.afficher());
        show_tables();
        QMessageBox::information(nullptr,QObject::tr("ok"),
                              QObject::tr("Suppression effectuée\n"
                                          "Cliquez sur Annuler pour sortir."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("Suppression non effectuée.\n"
                                       "Cliquez sur Annuler pour sortir."),QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_Perso_clicked()
{
    int id_PERSO = ui->le_id_Perso->text().toInt();
    QString nom = ui->le_nom_Perso->text();
    QString prenom = ui->le_prenom_Perso->text();
    QString email = ui->le_email_Perso->text();
    int telephone = ui->le_tel_Perso->text().toInt();
    int age = ui->le_age_Perso->text().toInt();


        bool test = tmpP.modifier(id_PERSO,nom, prenom,age, email, telephone);

        if (test)
        {

            show_tables();
 ui->tableView_3->setModel(tmpPersonnel.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("update.\n"
                                                 "Click Cancel to exit."),
                                     QMessageBox::Cancel);


    }

    else
    {

        QMessageBox::warning(nullptr, QObject::tr("not ok "),
                             QObject::tr("update failed \n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
    }
}

void MainWindow::on_tableView_3_clicked(const QModelIndex &index)
{
    selected3 = ui->tableView_3->model()->data(index).toInt();
}

void MainWindow::on_pb_stat_Perso_clicked()
{
    QSqlQuery query;
        query.exec("SELECT age FROM PERSONNEL");

        QMap<QString, int> counts;
        int total = 0;

        while (query.next()) {
            QString type = query.value(0).toString();
            if (counts.contains(type)) {
                counts[type]++;
            } else {
                counts[type] = 1;
            }
            total++;
        }

        QPieSeries *series = new QPieSeries();
        for (auto it = counts.begin(); it != counts.end(); it++) {
            double percentage = 100 * it.value() / total;
            series->append(it.key() + QString(" (%1%)").arg(percentage, 0, 'f', 1), it.value());
        }

        QChart *chart = new QChart();

        chart->addSeries(series);
        chart->setTitle("Statistiques pour l'attribut \"age\"");
        series->setPieSize(0.7);
        series->setLabelsVisible();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        QDialog *dialog = new QDialog();
        dialog->resize(800, 600);
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);
        dialog->setLayout(layout);

        chart->setParent(chartView);
        dialog->exec();
}

void MainWindow::on_tableView_magasin_clicked(const QModelIndex &index)
{
    selected2 = ui->tableView_magasin->model()->data(index).toInt();
}

void MainWindow::on_tableView_magasin_doubleClicked(const QModelIndex &index)
{


}

void MainWindow::on_lineEdit_rechercher_3prso_textChanged(const QString &arg1)
{
    //proxyP->setFilterFixedString(arg1);

}


bool MainWindow::sign_up(QString pwd,QString email)
{
QSqlQuery qry;
qry.prepare("INSERT INTO login (password,email)"
"VALUES (:password,:email)");
qry.bindValue(":password",pwd);
qry.bindValue(":email",email);
return qry.exec();

}

bool MainWindow::sign_in(QString uname,QString pwd)
{
QSqlQuery qry;
qry.prepare("SELECT * FROM login WHERE email=:email AND password=:password");
qry.bindValue(":email",uname);
qry.bindValue(":password",pwd);
return qry.exec() && qry.next();
}

void MainWindow::on_pb_login_clicked()
{
    printf("test1");

QString email = ui->le_login_mail->text();
QString password = ui->le_login_password->text();
// Check if email meets the requirements
QRegularExpression email_regex("[^@]+@[^\\.]+\\..+");
bool email_verif = email_regex.match(email).hasMatch();

// Check if password meets the requirements
QRegularExpression password_regex("^(?=.*[A-Z]).{1,8}$");
bool password_verif = password_regex.match(password).hasMatch();

if (!email_verif || !password_verif) {
    QMessageBox::warning(this, tr("Connexion"), tr("Veuillez saisir un email valide et un mot de passe valide."));
    return;
}


if (sign_in(email, password))
{
    printf("test1");

    ui->le_login_mail->clear();
    ui->le_login_password->clear();
    ui->stackedWidget->setCurrentIndex(1);
    page=1;
    printf("test1");

}

}

void MainWindow::on_pb_ajouter_magasin_2_clicked()
{
    if(page==0)
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pb_participer_persoEV_clicked()
{

        int id_perso = ui->le_id_part_perso->text().toInt();
        int id_event = ui->le_id_part_event->text().toInt();



        participation pa;
          produitt p;
      bool test=    pa.ajouter(id_perso,id_event);
        //bool test=  pa.update(id_perso,id_event);

          //bool test = p.update(id_produit,quantite_final);

          QSqlQuery query;
          QByteArray message;
          QString ch;
         // int quantite_stop;
          QString res1 = QString::number(id_event);
          //query.prepare("select * from event where id_event= "+res1+"");
          //if (query.exec())
                              {

          if (test)
          {

              QMessageBox::information(nullptr, QObject::tr("ok"),
                                       QObject::tr("update.\n"
                                                   "Click Cancel to exit."),
                                       QMessageBox::Cancel);


      }

      else
      {

          QMessageBox::warning(nullptr, QObject::tr("not ok "),
                               QObject::tr("update failed \n"
                                           "Click Cancel to exit."),
                               QMessageBox::Cancel);
      }



}
}


