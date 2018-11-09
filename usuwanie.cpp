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

    con.openConnection();

    if(!con.openConnection()){
        QMessageBox::about(this,"Nie połączono z bazą!","Błąd połączenia.");
    }
    else{
            QSqlQuery removeQry;
            if(ui->lineEdit->text() == ""){
            QMessageBox::about(this,"Błąd.","Brak wartości, spróbuj ponownie.");
            }
            else if(ui->lineEdit->text() != ""){
                removeQry.prepare("delete from Ranking where KOD = :kod");
                removeQry.bindValue(":kod",ui->lineEdit->text());
                removeQry.exec();
                QMessageBox::about(this,"Usunięto.","Wartości usunieto");
            }         

    }
    ui->lineEdit->setText("");

}
