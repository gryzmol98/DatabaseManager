#ifndef POROWNAJ_H
#define POROWNAJ_H

#include <QDialog>

namespace Ui {
class Porownaj;
}

class Porownaj : public QDialog
{
    Q_OBJECT

public:
    explicit Porownaj(QWidget *parent = 0);
    ~Porownaj();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Porownaj *ui;
};

#endif // POROWNAJ_H
