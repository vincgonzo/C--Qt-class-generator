#include <QApplication>
#include <QtWidgets>

#include "ClassGenerator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget wind;
    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;

    QVBoxLayout *layoutMain = new QVBoxLayout;

    // Options layout
    QGroupBox *gpBox = new QGroupBox("Class Definition", &wind);
    QRadioButton *header_include = new QRadioButton("Protéger le header contre les inclusions multiples.");
    QRadioButton *construct_def = new QRadioButton("Créer un constructeur par défaut.");
    QRadioButton *destruct = new QRadioButton("Générer un destructeur.");

    header_include->setChecked(true);

    QVBoxLayout *layoutDef = new QVBoxLayout;
    layoutDef->addWidget(header_include);
    layoutDef->addWidget(construct_def);
    layoutDef->addWidget(destruct);

    // Attrib def section to group
    //gpBox->setLayout(layoutDef);


    QGroupBox *gpBoxOpt = new QGroupBox("Options", &wind);
    QFormLayout *layoutForm = new QFormLayout;
    layoutForm->addRow("Votre &nom", nom);
    layoutForm->addRow("Votre &prénom", prenom);
    layoutForm->addRow("Votre &age", age);

    // Container injections
    //gpBoxOpt->setLayout(layoutForm);

    layoutMain->addLayout(layoutDef);
    layoutMain->addLayout(layoutForm);

    wind.setLayout(layoutMain);
    wind.show();
    //QWidget::connect(bouton, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));

    return app.exec();
}
