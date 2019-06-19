// Copyright (c) 2016-2019 The Gulden developers
// Authored by: Willem de Jonge (willem@isnapp.nl)
// Distributed under the GULDEN software license, see the accompanying
// file COPYING

#include "extendwitnessdialog.h"
#include <qt/_Gulden/forms/ui_extendwitnessdialog.h>

#include "wallet/wallet.h"
#include "gui.h"

#define LOG_QT_METHOD LogPrint(BCLog::QT, "%s\n", __PRETTY_FUNCTION__)

ExtendWitnessDialog::ExtendWitnessDialog(const QStyle *_platformStyle, QWidget *parent)
: QFrame( parent )
, ui( new Ui::ExtendWitnessDialog )
, platformStyle( _platformStyle )
{
    ui->setupUi(this);

    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));
    connect(ui->extendButton, SIGNAL(clicked()), this, SLOT(extendClicked()));
}

ExtendWitnessDialog::~ExtendWitnessDialog()
{
    delete ui;
}

void ExtendWitnessDialog::cancelClicked()
{
    LOG_QT_METHOD;

    Q_EMIT dismiss(this);
}

void ExtendWitnessDialog::extendClicked()
{
    LOG_QT_METHOD;

    if(QDialog::Accepted == GUI::createDialog(this, "Confirm extending", tr("Extend"), tr("Cancel"), 600, 360, "ExtendWitnessConfirmationDialog")->exec())
    {
        pactiveWallet->BeginUnlocked(_("Wallet unlock required to extend witness"), [=](){

            // TODO: execute extend and dismiss dialog on succes, or alert user on failure

            pactiveWallet->EndUnlocked();
            Q_EMIT dismiss(this);
        });
    }
}