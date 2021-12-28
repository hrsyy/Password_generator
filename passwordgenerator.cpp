#include "passwordgenerator.h"
#include "ui_passwordgenerator.h"

#include <QMessageBox>

PasswordGenerator::PasswordGenerator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PasswordGenerator)
{
    ui->setupUi(this);
}

PasswordGenerator::~PasswordGenerator()
{
    delete ui;
}


void PasswordGenerator::on_Generate_clicked()
{
    int passwordLength = ui->PasswordSize->toPlainText().toInt();

    if(passwordLength <= 0)
    {
        QMessageBox::critical(this, tr("Ошибка: "), tr("Введите числовое значение в поле 'Размер пароля'"));
    }

    QString allSymbols = "abcdefghijklmnopqrstuvwxyz";

    if(ui->UppercaseLetters->isChecked())
    {
        allSymbols += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }

    if(ui->Numbers->isChecked())
    {
        allSymbols += "1234567890";
    }

    if(ui->SpecialSymbols->isChecked())
    {
        allSymbols += "%*()?@#$~_-=+[]{}";
    }

    if(ui->Spaces->isChecked())
    {
        allSymbols += "      ";
    }

    ui->GeneratedPassword->clear();
    ui->GeneratedPassword->setText(randomizeSymbols(allSymbols, passwordLength));
}


QString PasswordGenerator::randomizeSymbols(QString allSymbols, int passwordLength)
{
    char countValue;
    int SA_Length = allSymbols.length();
    QString result;
    int i;

    for (i = 0; i < passwordLength; i++ )
    {
        countValue = 0 +(rand() % SA_Length);
        result += allSymbols[countValue];
    }

    return result;
}

//Clear "Generated password" field
void PasswordGenerator::on_Clear_clicked()
{
    ui->GeneratedPassword->clear();
}


//Copying all symbols from the "Generated password" field
void PasswordGenerator::on_Copy_clicked()
{
    ui->GeneratedPassword->selectAll();
    ui->GeneratedPassword->copy();

    QTextCursor cursor = ui->GeneratedPassword->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->GeneratedPassword->setTextCursor(cursor);
}

