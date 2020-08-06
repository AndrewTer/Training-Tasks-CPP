#include "tableswindow.h"
#include "ui_tableswindow.h"
#include "mainwindow.h"

TablesWindow::TablesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TablesWindow)
{
    ui->setupUi(this);

    fillComboboxWithAListOfTables();
}

TablesWindow::~TablesWindow()
{
    delete ui;
}

// Событие нажатия на кнопку разрыва соединения с базой данных
void TablesWindow::on_pushButtonpushButton_db_disconnect_clicked()
{
    MainWindow *mw = new MainWindow;

    // Разрыв соединения с базой данных
    QSqlDatabase::removeDatabase(mw->getDB().connectionName());

    // Отображения окна подключения к базе данных
    mw->show();
    this->hide();
}

// Метод получения списка таблиц БД и занесения его в combobox
bool TablesWindow::fillComboboxWithAListOfTables()
{
    QSqlQuery query_select_all_tables;

    if (query_select_all_tables.exec("SELECT table_name FROM information_schema.tables WHERE table_schema NOT IN ('information_schema','pg_catalog')"))
    {
        while (query_select_all_tables.next())
        {
            QString table_name = query_select_all_tables.value(0).toString();
            ui->comboBox_tables_list->addItem(table_name);
        }

        return false;
    }

    return false;
}
