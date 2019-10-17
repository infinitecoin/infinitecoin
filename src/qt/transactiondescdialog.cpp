#include "transactiondescdialog.h"
#include "ui_transactiondescdialog.h"

#include "transactiontablemodel.h"

#include <QModelIndex>

TransactionDescDialog::TransactionDescDialog(const QModelIndex &idx, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDescDialog)
{
    ui->setupUi(this);

    QString desc = idx.data(TransactionTableModel::LongDescriptionRole).toString();
    //ui->detailText->setHtml(desc);
    //WithU2018  20180322
    ui->detailText->setText(desc);
    ui->detailText->adjustSize();
    ui->detailText->setScaledContents(true);
    ui->scrollAreaWidgetContents->setMinimumSize(ui->detailText->width(),ui->detailText->height());
    ui->scrollAreaWidgetContents->setGeometry(ui->detailText->geometry());
}

TransactionDescDialog::~TransactionDescDialog()
{
    delete ui;
}
