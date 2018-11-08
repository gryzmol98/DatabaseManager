#ifndef USUWANIE_H
#define USUWANIE_H

#include <QDialog>

namespace Ui {
class Usuwanie;
}

class Usuwanie : public QDialog
{
    Q_OBJECT

public:
    explicit Usuwanie(QWidget *parent = 0);
    ~Usuwanie();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Usuwanie *ui;
};

#endif // USUWANIE_H
