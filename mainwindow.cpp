#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <filesystem>
#include <iostream>
#include <QVBoxLayout>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <qobject.h>

std::string MainWindow::loadFile() {
    std::string cwd = std::filesystem::current_path().string();
    auto filePath = QFileDialog::getOpenFileName(this,
                                                 tr("Open Image"), cwd.c_str(), tr("Image Files (*.png *.jpg *.bmp)"));
    return filePath.toStdString();
}

void MainWindow::SetOpenGLFrame() {
    auto mainFrame = this->findChild<QVBoxLayout*>("MainFrame");
    QOpenGLWidget widget((QWidget*)mainFrame);

    mainFrame->addWidget(&widget);

}

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

void MainWindow::on_ChooseFileBtn_clicked()
{
    std::string filePath = loadFile();
    SetOpenGLFrame();
}


void MainWindow::on_actionOpen_triggered()
{
    std::string filePath = loadFile();
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

