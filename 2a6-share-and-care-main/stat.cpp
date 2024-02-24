#include "stat.h"
#include "ui_stat.h"
#include <QPainter>


stati::stati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stat)
{
    ui->setupUi(this);
}

stati::~stati()
{
    delete ui;
}


int stati::Statistique_partie2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * FROM PRODUIT where NOM_P like 'lait' ") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PRODUIT where NOM_P like 'pate'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;



}
int stati::Statistique_partie4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from PRODUIT where NOM_P like 'couscous'") ;
    while(requete.next())
    {
            count++ ;
    }

return count ;


}
void stati::paintEvent(QPaintEvent *)
{

    int b=Statistique_partie2();
    cout<<b<<endl ;
    int c=Statistique_partie3();
    cout<<c<<endl ;
    int d=Statistique_partie4();
    cout<<d<<endl ;

        float s2= b*100 ;
        float s3=c*100;
        float nb = b+c+d ;
        float q2 ;
        q2 = s2/nb ;
        float q3;
        q3=s3/nb;
        float y  ;
        y = (q2*360)/100 ;
        float m;
        m= (q3*360)/100;
        float z  ;
        z=360-(y+m) ;
    QPainter painter(this);
    QRectF size=QRectF(50,50,this->width()-500,this->width()-500);

    painter.setBrush(Qt::blue);
    painter.drawPie(size,0,16*y);
    ui->label_2->setText("lait") ;
    painter.setBrush(Qt::yellow);
    painter.drawPie(size,16*y,16*m);
    ui->label_3->setText("couscous") ;
    painter.setBrush(Qt::green);
    painter.drawPie(size,16*(m+y),16*z);
    ui->label_4->setText("tomate") ;

}

void stati::on_pushButton_clicked()
{
    hide();
}
