#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Прототип метода подключения к БД
    bool connectDB();

private slots:
    void on_pushButton_db_connect_clicked();

private:
    Ui::MainWindow *ui;

    // Название хоста
    QString host_name;

    // Название БД
    QString database_name;

    // Имя пользователя
    QString user_name;

    // Пароль от БД
    QString database_password;

    // Экземпляр подключения к БД
    QSqlDatabase db_students;
};
#endif // MAINWINDOW_H
