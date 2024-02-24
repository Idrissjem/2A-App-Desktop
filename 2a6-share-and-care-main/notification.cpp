#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
#include"produit.h"


notification::notification()
{
    num=0;
}
notification::notification(QString titre,QString text)
{
  this->text=text;
  this->titre=titre;
}

void notification::afficher()
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/mahdi/Downloads/INTEGRATION/IntegFares/reminder.png"));


    if (!titre.isEmpty() && !text.isEmpty())
    {
        notifyIcon->show();
        notifyIcon->showMessage(titre, text, QSystemTrayIcon::Information, 35000);
    }
}
