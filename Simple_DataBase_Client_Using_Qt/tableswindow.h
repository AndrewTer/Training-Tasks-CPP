#ifndef TABLESWINDOW_H
#define TABLESWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>

namespace Ui {
class TablesWindow;
}

class TablesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TablesWindow(QWidget *parent = nullptr);
    ~TablesWindow();

    // Прототип метода получения списка таблиц БД и занесения его в combobox
    bool fillComboboxWithAListOfTables();

private slots:
    void on_pushButtonpushButton_db_disconnect_clicked();

private:
    Ui::TablesWindow *ui;
};

#endif // TABLESWINDOW_H
