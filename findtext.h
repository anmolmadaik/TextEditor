#ifndef FINDTEXT_H
#define FINDTEXT_H

#include <QDialog>
#include <QPushButton>
namespace Ui {
class findtext;
}

class findtext : public QDialog
{
    Q_OBJECT

public:
    explicit findtext(QWidget *parent = nullptr);
    ~findtext();
    const QString &getSearchText() const;


    bool getCaseSen() const;

    bool getBack() const;

private slots:
    void on_buttonBox_2_accepted();
    void on_buttonBox_2_rejected();

private:
    Ui::findtext *ui;
    QString searchText;
    bool caseSen;
    bool back;
    void save();
};

#endif // FINDTEXT_H
