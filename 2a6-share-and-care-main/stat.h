
#ifndef STAT_H
#define STAT_H

#include <QDialog>
#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QSqlQuery>

using namespace std;
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class stat;
}

class stati : public QDialog
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
    int Statistique_partie2() ;
    int Statistique_partie3() ;
    int Statistique_partie4() ;

    void paintEvent(QPaintEvent *) ;
    ~stati();

private slots:
    void on_pushButton_clicked();

private:
    Ui::stat *ui;
};

#endif // STAT_H



