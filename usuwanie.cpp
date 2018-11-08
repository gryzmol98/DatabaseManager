#include "usuwanie.h"
#include "ui_usuwanie.h"
#include <QMessageBox>
#include "baza.h"
Usuwanie::Usuwanie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usuwanie)
{
    ui->setupUi(this);
}

Usuwanie::~Usuwanie()
{
    delete ui;
}

void Usuwanie::on_pushButton_clicked()
{
    this->close();
}

void Usuwanie::on_pushButton_2_clicked()
{
    connectDatabase con;
    bool usuniety;

    con.openConnection();

    if(!con.openConnection()){
        QMessageBox::about(this,"Nie połączono z bazą!","Błąd połączenia.");
    }
    else{
            QSqlQuery removeQry;
            if(ui->lineEdit->text() == ""){
            QMessageBox::about(this,"Nie znaleziono.","Wpisz poprawnie!");
            }
            else if(ui->lineEdit->text() != ""){
                removeQry.prepare("delete from Ranking where KOD = :kod");
                removeQry.bindValue(":kod",ui->lineEdit->text());
            }

            usuniety =removeQry.exec();

            if(usuniety){
                QMessageBox::about(this,"Usunięto!","Usunięto.");
            }
            else{
                QMessageBox::about(this,"Błąd.","Zła wartość, spróbuj ponownie.");
            }
    }
    ui->lineEdit->setText("");

}
