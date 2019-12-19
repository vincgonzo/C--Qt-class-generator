#include <QApplication>
#include <QtWidgets>

#include "ClassGenerator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ClassGenerator wind;
    wind.show();
    //QWidget::connect(bouton, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));

    return app.exec();
}
