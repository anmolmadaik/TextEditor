#include "find.h"
#include "ui_find.h"

find::find(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::find)
{
    ui->setupUi(this);
    init();
    save();
}

find::~find()
{
    delete ui;
}


void find::on_buttonBox_accepted()
{
    save();
    accept();
}

void find::on_buttonBox_rejected()
{
    reject();
}

void find::goBack()
{
    save();
    back = true;
    accept();
}

bool find::getCaseSen() const
{
    return caseSen;
}

bool find::getBack() const
{
    return back;
}


const QString &find::getSearchText() const
{
    return searchText;
}

void find::init()
{
    QPushButton * b = new QPushButton("Back",this);
    connect(b,&QPushButton::clicked,this,&find::goBack);
    ui->buttonBox->addButton(b,QDialogButtonBox::ActionRole);
}

void find::save()
{
    searchText = ui->lineEdit->text();
    caseSen = ui->checkBox->isChecked();
    back = false;
}

