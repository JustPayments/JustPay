#ifndef OBFUSCATIONCONFIG_H
#define OBFUSCATIONCONFIG_H

#include <QDialog>

namespace Ui
{
class JustPaysendConfig;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class JustPaysendConfig : public QDialog
{
    Q_OBJECT

public:
    JustPaysendConfig(QWidget* parent = 0);
    ~JustPaysendConfig();

    void setModel(WalletModel* model);


private:
    Ui::JustPaysendConfig* ui;
    WalletModel* model;
    void configure(bool enabled, int coins, int rounds);

private slots:

    void clickBasic();
    void clickHigh();
    void clickMax();
};

#endif // OBFUSCATIONCONFIG_H
