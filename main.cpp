#include "configdialog.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ConfigDialog dlg;
    if (dlg.exec() != QDialog::Accepted)
        return 0;                 // kasutaja vajutas "Cancel"

    MainWindow w(dlg.rows(), dlg.cols(), dlg.mines());
    w.show();
    return a.exec();
}
