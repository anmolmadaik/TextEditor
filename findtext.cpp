#include "findtext.h"
#include "ui_findtext.h"

findtext::findtext(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findtext)
{
    ui->setupUi(this);
    save();
}

findtext::~findtext()
{
    delete ui;
}

void findtext::on_buttonBox_2_accepted()
{
    save();
    accept();
}

void findtext::on_buttonBox_2_rejected()
{
    reject();
}

bool findtext::getBack() const
{
    return back;
}


bool findtext::getCaseSen() const
{
    return caseSen;
}



const QString &findtext::getSearchText() const
{
    return searchText;
}



void findtext::save()
{
    searchText = ui->lineEdit->text();
    caseSen = ui->checkBox->isChecked();
    if(ui->radioButton->isChecked()){
        back = true;
    }
    else{
        back = false;
    }
}
