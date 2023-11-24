// Copyright (c) 2011-2014 The AustraliaCash Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef AUSTRALIACASH_QT_AUSTRALIACASHADDRESSVALIDATOR_H
#define AUSTRALIACASH_QT_AUSTRALIACASHADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class AustraliaCashAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AustraliaCashAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** AustraliaCash address widget validator, checks for a valid australiacash address.
 */
class AustraliaCashAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit AustraliaCashAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // AUSTRALIACASH_QT_AUSTRALIACASHADDRESSVALIDATOR_H
