#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ChooseFileBtn_clicked();

    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    std::string loadFile();

    void SetOpenGLFrame();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
