#include "mainwindow.h"
#include "ui_mainwindow.h"

//for opening and writing in the file
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>

//class declaration to add font to the notepad
#include<QFontDialog>
#include<QFont>
//class declaration to add color to notepad
#include<QColorDialog>
#include<QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    //to reset the path
    file_path_="";
    //to clear the text edit
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    //getopenfilename is the method called and file_name is the name of the varible
QString file_name=QFileDialog::getOpenFileName(this,"open the file");
QFile file(file_name);

//we have globally declared the file_path to file_name
file_path_=file_name;


//condition if the file is not opening
//2 flag are to be set here readonly and text
if(!file.open(QFile::ReadOnly | QFile::Text)){
    QMessageBox::warning(this,"..","file not open");
    return;
}

//to read from the file
QTextStream in(&file);
QString text=in.readAll();
ui->textEdit->setText(text);
file.close();

}


void MainWindow::on_actionSave_triggered()
{
    //getopenfilename is the method called and file_name is the name of the varible

//QString file_name=QFileDialog::getSaveFileName(this,"open the file");

QFile file(file_path_);
//condition if the file is not opening
//2 flag are to be set here readonly and text

//here change the flag to write only
if(!file.open(QFile::WriteOnly | QFile::Text)){
    QMessageBox::warning(this,"..","file not open");
    return;
}

//to read from the file

QTextStream out(&file);
//it will read everything which you have written in the textedit and push it into the out
QString text=ui->textEdit->toPlainText();

//paste everything into the out
out<<text;
file.flush();
file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    //getopenfilename is the method called and file_name is the name of the varible
QString file_name=QFileDialog::getSaveFileName(this,"open the file");

QFile file(file_name);

file_path_=file_name;


//condition if the file is not opening
//2 flag are to be set here readonly and text

//here change the flag to write only
if(!file.open(QFile::WriteOnly | QFile::Text)){
    QMessageBox::warning(this,"..","file not open");
    return;
}

//to read from the file

QTextStream out(&file);
//it will read everything which you have written in the textedit and push it into the out
QString text=ui->textEdit->toPlainText();

//paste everything into the out
out<<text;
file.flush();
file.close();
}



void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}
//actionRedo
//actionAbout_Notepad
void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString about_text;
    about_text="PBL Project-->Creating an Notepad from C++ QT framework \n";
    about_text+="(c) Notepad (R)";

    QMessageBox::about(this,"About Notepad",about_text);
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    //with the qfontdialog , we will select the font and assign it to the variable font
    //there is a static method getfont()
    //this method will take two argument
    //this-->it is the parent
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else return;
}




void MainWindow::on_actionColor_triggered()
{
    QColor color=QColorDialog ::getColor(Qt::white,this,"Choose color");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);
    }
}


void MainWindow::on_actionBackground_triggered()
{

    QColor color=QColorDialog ::getColor(Qt::white,this,"Choose color");
    if(color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);
    }
}


void MainWindow::on_actionBackground_Scree_color_triggered()
{
    QColor color=QColorDialog ::getColor(Qt::white,this,"Choose color");
    if(color.isValid()){
        ui->textEdit->setPalette(QPalette(color));
    }
}

