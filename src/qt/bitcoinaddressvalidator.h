// Copyright (c) 2011-2020 The AustraliaCash Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_BITCOINADDRESSVALIDATOR_H
#define BITCOIN_QT_BITCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class AustraliaCashAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AustraliaCashAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** AustraliaCash address widget validator, checks for a valid bitcoin address.
 */
class AustraliaCashAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AustraliaCashAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // BITCOIN_QT_BITCOINADDRESSVALIDATOR_H
