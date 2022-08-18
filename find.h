#ifndef FIND_H
#define FIND_H

#include <QDialog>
#include <QPushButton>
namespace Ui {
class find;
}

class find : public QDialog
{
    Q_OBJECT

public:
    explicit find(QWidget *parent = nullptr);
    ~find();


    const QString &getSearchText() const;


    bool getBack() const;

    bool getCaseSen() const;

private slots:


    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void goBack();

private:
    Ui::find *ui;
    QString searchText;
    bool caseSen;
    bool back;

    void init();
    void save();

};

#endif // FIND_H
