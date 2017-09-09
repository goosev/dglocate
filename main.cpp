#include <QApplication>
#include "dglocate.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DGLocate locate;
    locate.show();
    return app.exec();
}
