#ifndef REPLACE_H
#define REPLACE_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class replace;
}

class replace : public QDialog
{
    Q_OBJECT

public:
    explicit replace(QWidget *parent = nullptr);
    ~replace();

    bool getAll() const;

    const QString &getSearchText() const;

    const QString &getReplaceText() const;

    bool getBack() const;

private slots:
    void rep();
    void repall();

    void on_buttonBox_rejected();

private:
    Ui::replace *ui;
    bool all;
    bool back;
    QString searchText;
    QString replaceText;

    void init();
    void save();

};

#endif // REPLACE_H
