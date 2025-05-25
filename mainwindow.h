#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <vector>

#include "Laud.h"
#include "ruudunupp.h"

QT_BEGIN_NAMESPACE  // Qt genereerib automaatselt vastava klassi ning see on eraldi namespace all
                    //igaks juhuks, et ltida sama meetodi nimega konflikte
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int read,
                        int veerud,
                        int miinid,
                        QWidget *vanem = nullptr);
    ~MainWindow() override;

private slots:
    void avaRuut(int rida, int veerg);  // vasak klikk
    void lülitaLipp(int rida, int veerg);   // parem klikk

private:
    void uuendaRuut(int rida, int veerg);
    void uuendaKõik(bool näitaMiinid = false);
    void mängLäbi(bool võit);

    Ui::MainWindow *ui {nullptr};

    // Mängulaua andmed
    const int read_;
    const int veerud_;
    const int miinid_;
    Laud laud;

    // Graafika
    QGridLayout *paigutus {nullptr};
    std::vector<std::vector<RuuduNupp*>> nupud;
};

#endif // MAINWINDOW_H
