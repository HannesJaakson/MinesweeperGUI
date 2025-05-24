#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

namespace {
//  Võid vabalt muuta laua suurust ja miinide arvu siit.
constexpr int READ   = 10;
constexpr int VEERUD = 10;
constexpr int MIINID = 10;

// Numbrite värvikaart
QString värvNumbrile(int n)
{
    switch (n) {
    case 1: return "blue";
    case 2: return "green";
    case 3: return "red";
    case 4: return "navy";
    case 5: return "maroon";
    case 6: return "teal";
    case 7: return "black";
    case 8: return "gray";
    default: return "black";
    }
}
}

MainWindow::MainWindow(QWidget *vanem)
    : QMainWindow(vanem)
    , ui(new Ui::MainWindow)
    , laud(READ, VEERUD, MIINID)
{
    ui->setupUi(this);

    // Paigutame nupud kesk‑widget'isse võrguna
    paigutus = new QGridLayout(ui->centralwidget);
    paigutus->setSpacing(0);                 // ruudud kõrvuti
    paigutus->setContentsMargins(0, 0, 0, 0);// ei mingit tühja äärt
    paigutus->setSizeConstraint(QLayout::SetFixedSize); // ruudustik ei veni
    adjustSize();                                       // kahanda aken ruudustiku järgi


    /* ★★ */ paigutus->setSizeConstraint(QLayout::SetFixedSize);
    /* ★★ */ adjustSize();


    nupud.resize(READ, std::vector<RuuduNupp*>(VEERUD, nullptr));

    for (int r = 0; r < READ; ++r) {
        for (int v = 0; v < VEERUD; ++v) {
            auto *nupp = new RuuduNupp(r, v, this);
            nupud[r][v] = nupp;
            paigutus->addWidget(nupp, r, v);

            connect(nupp, &RuuduNupp::vasakKlikk, this, &MainWindow::avaRuut);
            connect(nupp, &RuuduNupp::paremKlikk, this, &MainWindow::lülitaLipp);
        }
    }

    uuendaKõik();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::avaRuut(int r, int v)
{
    bool jätka = laud.avaRuut(r, v);
    uuendaKõik(!jätka);      // kui miin, näita kõik miinid

    if (!jätka) {
        mängLäbi(false);
        return;
    }

    if (laud.kasVõit()) {
        mängLäbi(true);
    }
}

void MainWindow::lülitaLipp(int r, int v)
{
    laud.lülitaLipp(r, v);
    uuendaRuut(r, v);
}

void MainWindow::uuendaRuut(int r, int v)
{
    char c = laud.kuva(r, v);
    auto *nupp = nupud[r][v];

    QString stiil;
    switch (c) {
    case '#': // Suletud
        nupp->setText("");
        stiil = "background:#5c5c5c; border:1px solid #3f3f3f;";
        break;
    case 'F': // Lipp
        nupp->setText("\u2691");
        stiil = "color:red; background:#5c5c5c; border:1px solid #3f3f3f;";
        break;
    case '*': // Miin
        nupp->setText("✹");
        stiil = "color:black; background:#5c5c5c; border:1px solid #3f3f3f;";
        break;
    case ' ': // Tühi avatud
        nupp->setText("");
        stiil = "background:#fafafa; border:1px solid #8f8f8f;";
        break;
    default:  // Numbrid
        nupp->setText(QString(c));
        stiil = QString("color:%1; background:#fafafa; border:1px solid #8f8f8f;")
                    .arg(värvNumbrile(c - '0'));
        break;
    }

    nupp->setStyleSheet(stiil);

    // Avatud ruut enam ei ole vajutatav
    nupp->setEnabled(c == '#' || c == 'F');
}

void MainWindow::uuendaKõik(bool näitaMiinid)
{
    for (int r = 0; r < READ; ++r) {
        for (int v = 0; v < VEERUD; ++v) {
            if (näitaMiinid && laud.onMiin(r, v)) {
                nupud[r][v]->setText("✹");
                nupud[r][v]->setStyleSheet("color:black; background:#5c5c5c; border:1px solid #3f3f3f;");
                nupud[r][v]->setEnabled(false);
            } else {
                uuendaRuut(r, v);
            }
        }
    }
}

void MainWindow::mängLäbi(bool võit)
{
    // Lukustame kõik nupud
    for (auto &rida : nupud)
        for (auto *n : rida)
            n->setEnabled(false);

    // Teade kasutajale
    QMessageBox::information(this,
                             võit ? "Võit!" : "Kaotus",
                             võit ? "Palju õnne – kõik miinid said avastatud!"
                                  : "Kahjuks avasid miini. Proovi uuesti!");
}
