#ifndef DODAWANIE_H
#define DODAWANIE_H

#include <QDialog>

namespace Ui {
class Dodawanie;
}

class Dodawanie : public QDialog
{
    Q_OBJECT

public:
    explicit Dodawanie(QWidget *parent = 0);
    ~Dodawanie();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dodawanie *ui;
};

#endif // DODAWANIE_H
