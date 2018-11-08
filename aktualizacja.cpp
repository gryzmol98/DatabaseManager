#include "aktualizacja.h"
#include "ui_aktualizacja.h"
#include <QMessageBox>
#include "baza.h"

Aktualizacja::Aktualizacja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aktualizacja)
{
    ui->setupUi(this);
}

Aktualizacja::~Aktualizacja()
{
    delete ui;
}

void Aktualizacja::on_pushButton_clicked()
{
    this->close();
}

void Aktualizacja::on_pushButton_2_clicked()
{
    connectDatabase con;
    bool poprawne = 0 ;

    con.openConnection();

    if(ui->lineEdit->text() == ""){
        QMessageBox::about(this,"Brak kodu!","Wpisz, aby zaktualizować");
    }
    else{
            QSqlQuery editQry;


            if(ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "" && ui->lineEdit_4->text() == "" && ui->lineEdit_5->text() == ""){
                QMessageBox::about(this,"Brak wartości!","Wpisz, aby zaktualizować!");
            }


            if(ui->lineEdit_5->text()!=""){
              editQry.prepare("update Ranking set Ocena = :nowaocena where KOD = :kod");
              editQry.bindValue(":nowaocena",ui->lineEdit_5->text());
              editQry.bindValue(":kod",ui->lineEdit->text());
              poprawne = editQry.exec();
            }

            if(ui->lineEdit_4->text()!=""){
              editQry.prepare("update Ranking set Rok = :nowyrok where KOD = :kod");
              editQry.bindValue(":nowyrok",ui->lineEdit_4->text());
              editQry.bindValue(":kod",ui->lineEdit->text());
              poprawne = editQry.exec();
            }

            if(ui->lineEdit_3->text()!=""){
              editQry.prepare("update Ranking set Cena = :nowacena where KOD = :kod");
              editQry.bindValue(":nowacena",ui->lineEdit_3->text());
              editQry.bindValue(":kod",ui->lineEdit->text());
              poprawne = editQry.exec();
            }

            if(ui->lineEdit_2->text()!=""){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
              editQry.prepare("update Ranking set KOD = :nowykod where KOD = :kod");
              editQry.bindValue(":nowykod",ui->lineEdit_2->text());
              editQry.bindValue(":kod",ui->lineEdit->text());
              poprawne = editQry.exec();
            }
    }

    con.closeConnection();

    if(poprawne){
        QMessageBox::about(this,"Zaktualizowano","Wartości zaktualizowano!");
    }
    else if (ui->lineEdit->text() != ""){
        QMessageBox::about(this,"Błąd!","Bład wartości!");
    }

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}
