#include "menu.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    srand(time(0));

    FenMenu menu;
    menu.show();

    return app.exec();
}
