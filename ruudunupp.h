#pragma once
#include <QPushButton>
#include <QMouseEvent>

//  Üks ruut/nupp (QPushButton‑i alamklass)
//  eristab vasakut ja paremat klikki ning näitab avamata/avatud olekut
//  selgete värvidega.
class RuuduNupp : public QPushButton
{
    Q_OBJECT
public:
    RuuduNupp(int rida, int veerg, QWidget *vanem = nullptr);

signals:
    void vasakKlikk(int rida, int veerg);
    void paremKlikk(int rida, int veerg);

public slots:
    void seaAvatud(bool avatud);

protected:
    void mousePressEvent(QMouseEvent *sündmus) override;

private:

    int  rida_;
    int  veerg_;
    bool avatud_{false};
};
