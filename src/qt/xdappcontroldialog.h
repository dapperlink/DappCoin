// Copyright (c) 2017-2019 The DAPP developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef XDAPPCONTROLDIALOG_H
#define XDAPPCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "xdapp/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class XDappControlDialog;
}

class CXDappControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CXDappControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CXDappControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CXDappControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class XDappControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit XDappControlDialog(QWidget *parent);
    ~XDappControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::XDappControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CXDappControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // XDAPPCONTROLDIALOG_H
