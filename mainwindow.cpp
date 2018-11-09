#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "baza.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    connectDatabase con;

    con.openConnection();


    QSqlQueryModel* databaseModel = new QSqlQueryModel;


    QSqlQuery* databaseQuery = new QSqlQuery(con.ranking);


    if(ui->comboBox->currentText() == "Kod"){

        databaseQuery->prepare("select *from Ranking where KOD = :kod;");
        databaseQuery->bindValue(":kod",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Model"){

        databaseQuery->prepare("select *from Ranking where Model = :model;");
        databaseQuery->bindValue(":model",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Cena"){

        databaseQuery->prepare("select *from Ranking where Cena = :cena;");
        databaseQuery->bindValue(":cena",ui->lineEdit->text());
        databaseQuery->exec();
    }

    else if(ui->comboBox->currentText() == "Ocena"){

        databaseQuery->prepare("select *from Ranking where Ocena = :ocena;");
        databaseQuery->bindValue(":ocena",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Rok"){

        databaseQuery->prepare("select *from Ranking where Rok = :rok ");
        databaseQuery->bindValue(":rok",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Wybierz"){

        databaseQuery->exec("select *from Ranking");
    }


    databaseModel->setQuery(*databaseQuery);
    ui->tableView->setModel(databaseModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void MainWindow::on_actionDodaj_triggered()
{
    dodaj.show();
}

void MainWindow::on_actionZmie_rekord_triggered()
{
    aktualizuj.show();
}

void MainWindow::on_actionUsu_triggered()
{
    usun.show();
}
