QT       += core gui sql charts printsupport serialport  multimedia multimediawidgets widgets  network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Evenement.cpp \
    arduino.cpp \
    arduinof.cpp \
    arduinoo.cpp \
    avis.cpp \
    connection.cpp \
    login.cpp \
    magasin.cpp \
    main.cpp \
    mainwindow.cpp \
    notification.cpp \
    participation.cpp \
    personnel.cpp \
    produit.cpp \
    produitt.cpp \
    qcustomplot.cpp \
    ravitaillement.cpp \
    recette.cpp \
    resto_coeur.cpp \
    smtp.cpp \
    stat.cpp

HEADERS += \
    Evenement.h \
    arduino.h \
    arduinof.h \
    arduinoo.h \
    avis.h \
    connection.h \
    login.h \
    magasin.h \
    mainwindow.h \
    metier.h \
    notification.h \
    participation.h \
    personnel.h \
    produit.h \
    produitt.h \
    qcustomplot.h \
    ravitaillement.h \
    recette.h \
    resto_coeur.h \
    smtp.h \
    stat.h

FORMS += \
    login.ui \
    mainwindow.ui \
    stat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
