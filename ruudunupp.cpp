#include "ruudunupp.h"

RuuduNupp::RuuduNupp(int rida, int veerg, QWidget *vanem)
    : QPushButton(vanem), rida_{rida}, veerg_{veerg}
{
    setFlat(false); // vaikimisi on kast ruumiline, seab mitte ruumiliseks
    setFixedSize(35, 35); //Ühe nupu suurus

    QFont f = font();     // vaikefont
    f.setPointSize(20);   // märgiste suurus (numbrid, lipud, miinid)
    f.setBold(true);      // paks või mitte
    setFont(f);

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
    setEnabled(!avatud_); // avatud ruutu enam ei saa vajutada
}
