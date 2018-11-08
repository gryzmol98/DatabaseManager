#ifndef AKTUALIZACJA_H
#define AKTUALIZACJA_H

#include <QDialog>

namespace Ui {
class Aktualizacja;
}

class Aktualizacja : public QDialog
{
    Q_OBJECT

public:
    explicit Aktualizacja(QWidget *parent = 0);
    ~Aktualizacja();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Aktualizacja *ui;
};

#endif // AKTUALIZACJA_H
