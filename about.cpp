#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    ui->name->setText(QApplication::applicationName());
    ui->version->setText(QApplication::applicationVersion());
    ui->org->setText(QApplication::organizationName());
    ui->url->setText(QApplication::organizationDomain());
}

about::~about()
{
    delete ui;
}

void about::on_buttonBox_accepted()
{
    accept();
}

