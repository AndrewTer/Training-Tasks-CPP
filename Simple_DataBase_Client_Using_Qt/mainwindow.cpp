#include "mainwindow.h"
#include "ui_mainwindow.h"

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

// Событие нажатия на кнопку подключения к базе данных
void MainWindow::on_pushButton_db_connect_clicked()
{
    host_name = ui->lineEdit_host_name->text();
    database_name = ui->lineEdit_database_name->text();
    user_name = ui->lineEdit_user_name->text();
    database_password = ui->lineEdit_database_password->text();

    if (host_name != "" && database_name != "" && user_name != "" && database_password != "")
    {
        // Вызов метода подключения к БД
        if (connectDB())
        {

        }
    } else
        ui->label_error_message->setText("Следует заполнить все поля ввода!");
}

// Метод подключения к БД
bool MainWindow::connectDB()
{
    db_students = QSqlDatabase::addDatabase("QPSQL");
    db_students.setHostName(host_name);
    db_students.setDatabaseName(database_name);
    db_students.setUserName(user_name);
    db_students.setPassword(database_password);

    if(!db_students.open())
    {
        ui->label_error_message->setText("Не удалось подключиться к БД!");
        return false;
    }

    ui->lineEdit_host_name->setText("");
    ui->lineEdit_database_name->setText("");
    ui->lineEdit_user_name->setText("");
    ui->lineEdit_database_password->setText("");

    return true;
}
