#include "dodawanie.h"
#include "ui_dodawanie.h"
#include "mainwindow.h"
#include <QMessageBox>

Dodawanie::Dodawanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dodawanie)
{
    ui->setupUi(this);
}

Dodawanie::~Dodawanie()
{
    delete ui;
}

void Dodawanie::on_pushButton_2_clicked()
{
    this->close();
}

void Dodawanie::on_pushButton_clicked()
{
    connectDatabase con;
    con.openConnection();

    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" || ui->lineEdit_3->text()=="" || ui->lineEdit->text()==""){

            //Empty Feild throw error.
            QMessageBox::about(this,"Niekompletne!","Wpisz wszystkie wartości.");
    }
    else{

        //Write Query to database.
        QSqlQuery writeQry;

        writeQry.prepare("insert into ranking values(:kod,:model,:cena,:ocena,:rok);");
        writeQry.bindValue(":kod",ui->lineEdit->text());
        writeQry.bindValue(":cena",ui->lineEdit_2->text());
        writeQry.bindValue(":ocena",ui->lineEdit_3->text());
        writeQry.bindValue(":rok",ui->lineEdit_4->text());
        writeQry.bindValue(":model",ui->lineEdit_5->text());


        bool written = writeQry.exec();

        if(written){
            QMessageBox::about(this,"Zaktualizowano!","Dodano do bazy.");
        }
        else{
            QMessageBox::about(this,"Bład.","Sprawdź wartości czy są poprawne!");
        }
        con.closeConnection();

        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
    }
}
