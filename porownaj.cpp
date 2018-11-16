#include "porownaj.h"
#include "ui_porownaj.h"
#include <QMessageBox>
#include "baza.h"

Porownaj::Porownaj(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Porownaj)
{
    ui->setupUi(this);
}

Porownaj::~Porownaj()
{
    delete ui;
}

void Porownaj::on_pushButton_2_clicked()
{
     this->close();
}

void Porownaj::on_pushButton_clicked()
{
    connectDatabase con;
    con.openConnection();

    QSqlQueryModel* databaseModel = new QSqlQueryModel;

    QSqlQuery*  compareQry = new QSqlQuery(con.ranking);



    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()==""){
        QMessageBox::warning(this,"Brak kodu!","Wpisz, aby porównać");
}
    else{

       if(ui->comboBox->currentText() == "Cena"){

           compareQry->prepare("select KOD, Model, Cena from Ranking where KOD = :kod or KOD = :kod2;");
            compareQry->bindValue(":kod",ui->lineEdit->text());
            compareQry->bindValue(":kod2",ui->lineEdit_2->text());
            compareQry->exec();
        }
       else if (ui->comboBox->currentText() == "Ocena")
       {
           compareQry->prepare("select KOD, Model, Ocena from Ranking where KOD = :kod or KOD = :kod2;");
            compareQry->bindValue(":kod",ui->lineEdit->text());
            compareQry->bindValue(":kod2",ui->lineEdit_2->text());
            compareQry->exec();
       }
       else if(ui->comboBox->currentText() == "Rok")
       {
           compareQry->prepare("select KOD, Model, Rok from Ranking where KOD = :kod or KOD = :kod2;");
            compareQry->bindValue(":kod",ui->lineEdit->text());
            compareQry->bindValue(":kod2",ui->lineEdit_2->text());
            compareQry->exec();
       }
       else
       qDebug() << compareQry->lastError();

    }

    databaseModel->setQuery(*compareQry);
        ui->tableView->setModel(databaseModel);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

