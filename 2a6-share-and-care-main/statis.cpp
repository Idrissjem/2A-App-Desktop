#include "statis.h"
#include "ui_statis.h"

statis::statis(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statis)
{
    ui->setupUi(this);
}

statis::~statis()
{
    delete ui;
}
