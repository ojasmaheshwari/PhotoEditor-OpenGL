#include "mainwindow.h"
#include "openglwidget.h"
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

void MainWindow::LoadImage() {
    m_OpenGLWidget->show();
    m_ChooseButton->hide();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_OpenGLWidget = this->findChild<OpenGLWidget*>("openGLWidget");
    m_ChooseButton = this->findChild<QPushButton*>("ChooseFileBtn");
    m_OpenGLWidget->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ChooseFileBtn_clicked()
{
    std::string filePath = loadFile();
    LoadImage();
}


void MainWindow::on_actionOpen_triggered()
{
    std::string filePath = loadFile();
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

