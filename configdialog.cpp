// configdialog.cpp
#include "configdialog.h"
#include <QSpinBox>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QVBoxLayout>

ConfigDialog::ConfigDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Mängu seaded");

    rowsSpin_  = new QSpinBox(this);
    colsSpin_  = new QSpinBox(this);
    minesSpin_ = new QSpinBox(this);

    rowsSpin_->setRange(5, 40);
    colsSpin_->setRange(5, 40);
    rowsSpin_->setValue(10);
    colsSpin_->setValue(10);

    // miinide maksimum = kõik ruudud − 1
    auto updateMax = [this](){
        minesSpin_->setMaximum(rowsSpin_->value()*colsSpin_->value() - 1);
    };
    updateMax();
    connect(rowsSpin_,  &QSpinBox::valueChanged, this, updateMax);
    connect(colsSpin_,  &QSpinBox::valueChanged, this, updateMax);

    minesSpin_->setValue(10);

    auto *form = new QFormLayout;
    form->addRow("Read:",    rowsSpin_);
    form->addRow("Veerud:",  colsSpin_);
    form->addRow("Miinid:",  minesSpin_);

    auto *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                                         Qt::Horizontal, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto *v  = new QVBoxLayout(this);
    v->addLayout(form);
    v->addWidget(buttons);
}

int ConfigDialog::rows()  const { return rowsSpin_->value();  }
int ConfigDialog::cols()  const { return colsSpin_->value();  }
int ConfigDialog::mines() const { return minesSpin_->value(); }
