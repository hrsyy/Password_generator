#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PasswordGenerator; }
QT_END_NAMESPACE

class PasswordGenerator : public QMainWindow
{
    Q_OBJECT

public:
    PasswordGenerator(QWidget *parent = nullptr);
    ~PasswordGenerator();

private slots:
    QString randomizeSymbols(QString allSymbols, int passwordLength);

   // void ShowWeakPasswords();

    void on_Generate_clicked();

    void on_Clear_clicked();

    void on_Copy_clicked();

private:
    Ui::PasswordGenerator *ui;
};
#endif // PASSWORDGENERATOR_H
