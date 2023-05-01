#include "v2ui.h"

#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    v2Ui w;
    w.setWindowTitle("v2parsa");
    w.show();
    return a.exec();
}
