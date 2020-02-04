// Copyright (c) 2019 The DAPP developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLDAPPWIDGET_H
#define COINCONTROLDAPPWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlDappWidget;
}

class CoinControlDappWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlDappWidget(QWidget *parent = nullptr);
    ~CoinControlDappWidget();

private:
    Ui::CoinControlDappWidget *ui;
};

#endif // COINCONTROLDAPPWIDGET_H
