#include "replace.h"
#include "ui_replace.h"

replace::replace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::replace)
{
    ui->setupUi(this);
    init();
    save();
}

replace::~replace()
{
    delete ui;
}

void replace::on_buttonBox_rejected()
{
    reject();
}

bool replace::getBack() const
{
    return back;
}

void replace::init()
{
    QPushButton *btnrep = new QPushButton("Replace", this);
    QPushButton *btnrepall = new QPushButton("Replace All", this);

    ui->buttonBox->addButton(btnrep,QDialogButtonBox::ButtonRole::ActionRole);
    ui->buttonBox->addButton(btnrepall,QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnrep,&QPushButton::clicked,this,&replace::rep);
    connect(btnrepall,&QPushButton::clicked,this,&replace::repall);
}

void replace::save()
{
    searchText = ui->find->text();
    replaceText = ui->replace_2->text();
    all = false;
    if(ui->checkBox->isChecked()){
        back = true;
    }
    else{
        back = false;
    }
}

const QString &replace::getReplaceText() const
{
    return replaceText;
}

void replace::rep()
{
    save();
    accept();
}

void replace::repall()
{
    save();
    all = true;
    accept();
}

const QString &replace::getSearchText() const
{
    return searchText;
}

bool replace::getAll() const
{
    return all;
}

