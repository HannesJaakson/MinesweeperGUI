// configdialog.h
#pragma once
#include <QDialog>

class QSpinBox;

class ConfigDialog : public QDialog
{
    Q_OBJECT
public:
    explicit ConfigDialog(QWidget *parent = nullptr);
    int rows()  const;
    int cols()  const;
    int mines() const;

private:
    QSpinBox *rowsSpin_;
    QSpinBox *colsSpin_;
    QSpinBox *minesSpin_;
};
