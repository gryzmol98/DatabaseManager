#ifndef BAZA_H
#define BAZA_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <mainwindow.h>
#include <ui_mainwindow.h>

class connectDatabase
{
public:

    QSqlDatabase ranking;

    bool openConnection(){

        ranking = QSqlDatabase::addDatabase("QSQLITE");
        ranking.setDatabaseName("C:/Users/jb816/Documents/PROJEKT/Ranking/baza/ranking.db");

     if(ranking.open())
     {
        qDebug() << "Połączono";
        return true;
     }else
     {
         qDebug() << "Nie połączono";
        return false;
     }

    }
    void closeConnection(){
        ranking.close();
        ranking.removeDatabase(QSqlDatabase::defaultConnection);
     }
  };

#endif // BAZA_H
