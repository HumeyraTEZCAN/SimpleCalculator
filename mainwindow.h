#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

void NumPressed();
void MathButtonPressed();
void EqualButtonPressed();
void ChangeNumberSign();




void on_delete_2_clicked();


private:
    Ui::MainWindow *ui;
    QString operation154;
    QStringList operations;
};
#endif // MAINWINDOW_H
