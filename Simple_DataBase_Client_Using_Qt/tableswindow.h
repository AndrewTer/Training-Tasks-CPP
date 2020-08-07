#ifndef TABLESWINDOW_H
#define TABLESWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QString>
#include <QtSql/QSqlTableModel>

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

    // Прототип метода получения данных выбранной таблицы БД
    void fillTableViewWithTheCurrentTableData(QString table_name);

private slots:
    void on_pushButtonpushButton_db_disconnect_clicked();
    void on_comboBox_tables_list_currentTextChanged(const QString &arg1);

private:
    Ui::TablesWindow *ui;
};

#endif // TABLESWINDOW_H
