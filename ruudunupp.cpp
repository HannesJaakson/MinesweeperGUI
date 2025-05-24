#include "ruudunupp.h"

RuuduNupp::RuuduNupp(int rida, int veerg, QWidget *vanem)
    : QPushButton(vanem), rida_{rida}, veerg_{veerg}
{
    setFlat(true);                 // ilma süsteemi 3D‑servadeta
    setFocusPolicy(Qt::NoFocus);   // ära näita fookusraami
    setFixedSize(35, 35);          // täpselt naabriga kõrvuti

    QFont f = font();     // võta nupu vaikefont
    f.setPointSize(18);   // vali sobiv punktisuurus (nt 18 pt)
    f.setBold(true);      // rasvane, et hästi paistaks
    setFont(f);

    värskendaStiil();
}

void RuuduNupp::mousePressEvent(QMouseEvent *sündmus)
{
    if (sündmus->button() == Qt::LeftButton)
        emit vasakKlikk(rida_, veerg_);
    else if (sündmus->button() == Qt::RightButton)
        emit paremKlikk(rida_, veerg_);
}

void RuuduNupp::seaAvatud(bool avatud)
{
    avatud_ = avatud;
    setEnabled(!avatud_);          // avatud ruutu enam ei vajutata
    värskendaStiil();
}

void RuuduNupp::värskendaStiil()
{
    if (avatud_)
        setStyleSheet("background:#fafafa; border:1px solid #8f8f8f;"
                      "margin:0; padding:0; border-radius:0;");
    else
        setStyleSheet("background:#5c5c5c; border:1px solid #3f3f3f;"
                      "margin:0; padding:0; border-radius:0;");
}
