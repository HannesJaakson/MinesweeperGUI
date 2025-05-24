#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <vector>
#include "Laud.h"
#include "ruudunupp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *vanem = nullptr);
    ~MainWindow();

private slots:
    void avaRuut(int rida, int veerg);      // vasak klikk
    void lülitaLipp(int rida, int veerg);   // parem klikk

private:
    void uuendaRuut(int rida, int veerg);
    void uuendaKõik(bool näitaMiinid = false);
    void mängLäbi(bool võit);

    Ui::MainWindow *ui;
    Laud laud;
    QGridLayout *paigutus{nullptr};
    std::vector<std::vector<RuuduNupp*>> nupud;
};

#endif // MAINWINDOW_H

