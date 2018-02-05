#include "justpaysendconfig.h"
#include "ui_justpaysendconfig.h"

#include "bitcoinunits.h"
#include "guiconstants.h"
#include "init.h"
#include "optionsmodel.h"
#include "walletmodel.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QSettings>

JustPaysendConfig::JustPaysendConfig(QWidget* parent) : QDialog(parent),
                                                        ui(new Ui::JustPaysendConfig),
                                                        model(0)
{
    ui->setupUi(this);

    connect(ui->buttonBasic, SIGNAL(clicked()), this, SLOT(clickBasic()));
    connect(ui->buttonHigh, SIGNAL(clicked()), this, SLOT(clickHigh()));
    connect(ui->buttonMax, SIGNAL(clicked()), this, SLOT(clickMax()));
}

JustPaysendConfig::~JustPaysendConfig()
{
    delete ui;
}

void JustPaysendConfig::setModel(WalletModel* model)
{
    this->model = model;
}

void JustPaysendConfig::clickBasic()
{
    configure(true, 1000, 2);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("JustPaysend Configuration"),
        tr(
            "JustPaysend was successfully set to basic (%1 and 2 rounds). You can change this at any time by opening JUSTPAY's configuration screen.")
            .arg(strAmount));

    close();
}

void JustPaysendConfig::clickHigh()
{
    configure(true, 1000, 8);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("JustPaysend Configuration"),
        tr(
            "JustPaysend was successfully set to high (%1 and 8 rounds). You can change this at any time by opening JUSTPAY's configuration screen.")
            .arg(strAmount));

    close();
}

void JustPaysendConfig::clickMax()
{
    configure(true, 1000, 16);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("JustPaysend Configuration"),
        tr(
            "JustPaysend was successfully set to maximum (%1 and 16 rounds). You can change this at any time by opening JUSTPAY's configuration screen.")
            .arg(strAmount));

    close();
}

void JustPaysendConfig::configure(bool enabled, int coins, int rounds)
{
    QSettings settings;

    settings.setValue("nJustPaysendRounds", rounds);
    settings.setValue("nAnonymizeJustPayAmount", coins);

    nJustPaysendRounds = rounds;
    nAnonymizeJustPayAmount = coins;
}
