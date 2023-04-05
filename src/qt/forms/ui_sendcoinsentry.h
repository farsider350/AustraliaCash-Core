/********************************************************************************
** Form generated from reading UI file 'sendcoinsentry.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDCOINSENTRY_H
#define UI_SENDCOINSENTRY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qt/bitcoinamountfield.h"
#include "qt/qvalidatedlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_SendCoinsEntry
{
public:
    QGridLayout *gridLayout;
    QLabel *payToLabel;
    QHBoxLayout *payToLayout;
    QValidatedLineEdit *payTo;
    QToolButton *addressBookButton;
    QToolButton *pasteButton;
    QToolButton *deleteButton;
    QLabel *labellLabel;
    QLineEdit *addAsLabel;
    QLabel *amountLabel;
    QHBoxLayout *horizontalLayoutAmount;
    AustraliaCashAmountField *payAmount;
    QCheckBox *checkboxSubtractFeeFromAmount;
    QPushButton *useAvailableBalanceButton;
    QLabel *messageLabel;
    QLabel *messageTextLabel;
    QFrame *line;

    void setupUi(QWidget *SendCoinsEntry)
    {
        if (SendCoinsEntry->objectName().isEmpty())
            SendCoinsEntry->setObjectName(QString::fromUtf8("SendCoinsEntry"));
        SendCoinsEntry->resize(729, 150);
        SendCoinsEntry->setFocusPolicy(Qt::TabFocus);
        SendCoinsEntry->setAutoFillBackground(false);
        gridLayout = new QGridLayout(SendCoinsEntry);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(12);
        gridLayout->setVerticalSpacing(8);
        gridLayout->setContentsMargins(-1, 8, -1, 4);
        payToLabel = new QLabel(SendCoinsEntry);
        payToLabel->setObjectName(QString::fromUtf8("payToLabel"));
        payToLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(payToLabel, 0, 0, 1, 1);

        payToLayout = new QHBoxLayout();
        payToLayout->setSpacing(0);
        payToLayout->setObjectName(QString::fromUtf8("payToLayout"));
        payTo = new QValidatedLineEdit(SendCoinsEntry);
        payTo->setObjectName(QString::fromUtf8("payTo"));

        payToLayout->addWidget(payTo);

        addressBookButton = new QToolButton(SendCoinsEntry);
        addressBookButton->setObjectName(QString::fromUtf8("addressBookButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/address-book"), QSize(), QIcon::Normal, QIcon::Off);
        addressBookButton->setIcon(icon);
        addressBookButton->setIconSize(QSize(22, 22));

        payToLayout->addWidget(addressBookButton);

        pasteButton = new QToolButton(SendCoinsEntry);
        pasteButton->setObjectName(QString::fromUtf8("pasteButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/editpaste"), QSize(), QIcon::Normal, QIcon::Off);
        pasteButton->setIcon(icon1);
        pasteButton->setIconSize(QSize(22, 22));

        payToLayout->addWidget(pasteButton);

        deleteButton = new QToolButton(SendCoinsEntry);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/remove"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon2);
        deleteButton->setIconSize(QSize(22, 22));

        payToLayout->addWidget(deleteButton);


        gridLayout->addLayout(payToLayout, 0, 1, 1, 1);

        labellLabel = new QLabel(SendCoinsEntry);
        labellLabel->setObjectName(QString::fromUtf8("labellLabel"));
        labellLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labellLabel, 1, 0, 1, 1);

        addAsLabel = new QLineEdit(SendCoinsEntry);
        addAsLabel->setObjectName(QString::fromUtf8("addAsLabel"));

        gridLayout->addWidget(addAsLabel, 1, 1, 1, 1);

        amountLabel = new QLabel(SendCoinsEntry);
        amountLabel->setObjectName(QString::fromUtf8("amountLabel"));
        amountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(amountLabel, 2, 0, 1, 1);

        horizontalLayoutAmount = new QHBoxLayout();
        horizontalLayoutAmount->setObjectName(QString::fromUtf8("horizontalLayoutAmount"));
        payAmount = new AustraliaCashAmountField(SendCoinsEntry);
        payAmount->setObjectName(QString::fromUtf8("payAmount"));

        horizontalLayoutAmount->addWidget(payAmount);

        checkboxSubtractFeeFromAmount = new QCheckBox(SendCoinsEntry);
        checkboxSubtractFeeFromAmount->setObjectName(QString::fromUtf8("checkboxSubtractFeeFromAmount"));

        horizontalLayoutAmount->addWidget(checkboxSubtractFeeFromAmount);

        useAvailableBalanceButton = new QPushButton(SendCoinsEntry);
        useAvailableBalanceButton->setObjectName(QString::fromUtf8("useAvailableBalanceButton"));

        horizontalLayoutAmount->addWidget(useAvailableBalanceButton);

        horizontalLayoutAmount->setStretch(1, 1);

        gridLayout->addLayout(horizontalLayoutAmount, 2, 1, 1, 1);

        messageLabel = new QLabel(SendCoinsEntry);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(messageLabel, 3, 0, 1, 1);

        messageTextLabel = new QLabel(SendCoinsEntry);
        messageTextLabel->setObjectName(QString::fromUtf8("messageTextLabel"));
        messageTextLabel->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(messageTextLabel, 3, 1, 1, 1);

        line = new QFrame(SendCoinsEntry);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        payToLabel->setBuddy(payTo);
        labellLabel->setBuddy(addAsLabel);
        amountLabel->setBuddy(payAmount);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(payTo, addressBookButton);
        QWidget::setTabOrder(addressBookButton, pasteButton);
        QWidget::setTabOrder(pasteButton, deleteButton);
        QWidget::setTabOrder(deleteButton, addAsLabel);
        QWidget::setTabOrder(addAsLabel, payAmount);

        retranslateUi(SendCoinsEntry);

        QMetaObject::connectSlotsByName(SendCoinsEntry);
    } // setupUi

    void retranslateUi(QWidget *SendCoinsEntry)
    {
        payToLabel->setText(QApplication::translate("SendCoinsEntry", "Pay &To:", nullptr));
#ifndef QT_NO_TOOLTIP
        payTo->setToolTip(QApplication::translate("SendCoinsEntry", "The AustraliaCash address to send the payment to", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        addressBookButton->setToolTip(QApplication::translate("SendCoinsEntry", "Choose previously used address", nullptr));
#endif // QT_NO_TOOLTIP
        addressBookButton->setText(QString());
#ifndef QT_NO_SHORTCUT
        addressBookButton->setShortcut(QApplication::translate("SendCoinsEntry", "Alt+A", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        pasteButton->setToolTip(QApplication::translate("SendCoinsEntry", "Paste address from clipboard", nullptr));
#endif // QT_NO_TOOLTIP
        pasteButton->setText(QString());
#ifndef QT_NO_SHORTCUT
        pasteButton->setShortcut(QApplication::translate("SendCoinsEntry", "Alt+P", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("SendCoinsEntry", "Remove this entry", nullptr));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QString());
        labellLabel->setText(QApplication::translate("SendCoinsEntry", "&Label:", nullptr));
#ifndef QT_NO_TOOLTIP
        addAsLabel->setToolTip(QApplication::translate("SendCoinsEntry", "Enter a label for this address to add it to the list of used addresses", nullptr));
#endif // QT_NO_TOOLTIP
        addAsLabel->setPlaceholderText(QApplication::translate("SendCoinsEntry", "Enter a label for this address to add it to the list of used addresses", nullptr));
        amountLabel->setText(QApplication::translate("SendCoinsEntry", "A&mount:", nullptr));
#ifndef QT_NO_TOOLTIP
        payAmount->setToolTip(QApplication::translate("SendCoinsEntry", "The amount to send in the selected unit", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        checkboxSubtractFeeFromAmount->setToolTip(QApplication::translate("SendCoinsEntry", "The fee will be deducted from the amount being sent. The recipient will receive less bitcoins than you enter in the amount field. If multiple recipients are selected, the fee is split equally.", nullptr));
#endif // QT_NO_TOOLTIP
        checkboxSubtractFeeFromAmount->setText(QApplication::translate("SendCoinsEntry", "S&ubtract fee from amount", nullptr));
        useAvailableBalanceButton->setText(QApplication::translate("SendCoinsEntry", "Use available balance", nullptr));
        messageLabel->setText(QApplication::translate("SendCoinsEntry", "Message:", nullptr));
#ifndef QT_NO_TOOLTIP
        messageTextLabel->setToolTip(QApplication::translate("SendCoinsEntry", "A message that was attached to the bitcoin: URI which will be stored with the transaction for your reference. Note: This message will not be sent over the AustraliaCash network.", nullptr));
#endif // QT_NO_TOOLTIP
        Q_UNUSED(SendCoinsEntry);
    } // retranslateUi

};

namespace Ui {
    class SendCoinsEntry: public Ui_SendCoinsEntry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDCOINSENTRY_H
