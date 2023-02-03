#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include <QDebug>
#include<QMessageBox>
#include<QFileDialog>
#include<QDir>
#include<QVector>
#include<QString>
#include<string>
#include<string.h>
#include "follower.h"
#include "followers.h"
#include "post.h"
#include "posts.h"
#include "user.h"
#include "users.h"
#include "comperession_decompression.h"
#include "formating.h"
#include "Json_Minyfying_Validation_Correction.h"
static QString pathformat;
static QString file_name;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{

    //QMessageBox::about(this, "Validation",isValid(file_name));
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    isValid(file_name.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);

    file.close();
    outputfile.close();


}


void MainWindow::on_pushButton_5_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    formating(file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);

    file.close();
    outputfile.close();


}


void MainWindow::on_pushButton_3_clicked()
{
    QString filter="Text File (*.txt);; XML File (*.xml)";
    file_name=QFileDialog::getOpenFileName(this,"open a file","c://",filter);
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text)){
        QMessageBox::warning(this,"Error","file not open");
    }
    QTextStream in(&file);
    QString text =in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();

}


void MainWindow::on_plainTextEdit_blockCountChanged(int newBlockCount)
{

}


void MainWindow::on_pushButton_4_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    compress(file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}


void MainWindow::on_pushButton_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    decode(file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}


void MainWindow::on_pushButton_6_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    toJson(file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}





void MainWindow::on_pushButton_8_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    correct(file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}


void MainWindow::on_pushButton_7_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    minify(file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}


void MainWindow::on_pushButton_9_clicked()
{
    QString word;
    word = ui -> lineEdit_3 -> text();
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    suggest(word.toStdString(),file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}


void MainWindow::on_pushButton_10_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    maxi_number_of_followers(file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}


void MainWindow::on_pushButton_11_clicked()
{
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    mostConnected(file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}

void MainWindow::on_pushButton_12_clicked()
{
    QString word;
    word = ui -> lineEdit -> text();
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    find_post(word.toStdString() , file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();

}



void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_pushButton_13_clicked()
{
    QString word;
    QString word1;
    word = ui -> lineEdit_2 -> text();
    word1 = ui -> lineEdit_4 -> text();
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly |QFile::Text))
    {
        return;
    }
    pathformat=QFileDialog::getSaveFileName(this,"enter file name to save.","c://");
    mutual(word.toStdString(), word1.toStdString(), file_name.toStdString(),pathformat.toStdString());
    QFile outputfile(pathformat);
    if(!outputfile.open(QFile::ReadOnly |QFile::Text))
    {
        QString valid="file can't be opened ";
        ui->plainTextEdit->setPlainText(valid);

    }
    QTextStream ts(&outputfile);
    QString data =ts.readAll();
    ui->plainTextEdit->setPlainText(data);
    file.close();
    outputfile.close();
}


void MainWindow::on_lineEdit_3_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{

}


void MainWindow::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{

}

