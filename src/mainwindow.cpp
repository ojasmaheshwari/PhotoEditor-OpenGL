#include "mainwindow.h"
#include "openglwidget.h"
#include "ui_mainwindow.h"
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

void MainWindow::LoadImage() {
    std::string filePath = loadFile();
    if (m_OpenGLWidget->isHidden())
        m_OpenGLWidget->show();
    if (m_ChooseButton->isVisible())
        m_ChooseButton->hide();

    m_OpenGLWidget->LoadImage(filePath);

    m_OpenGLWidget->resize(m_OpenGLWidget->width() + 1, m_OpenGLWidget->height() + 1);
}

void MainWindow::on_ChooseFileBtn_clicked()
{
    LoadImage();
}


void MainWindow::on_actionOpen_triggered()
{
    LoadImage();
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

