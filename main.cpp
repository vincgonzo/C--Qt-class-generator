#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include "ClassGenerator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget wind;
    // Options layout
    QGroupBox *gpBox = new QGroupBox("Class Definition", &wind);
    QGroupBox *gpBoxOpt = new QGroupBox("Options", &wind);

    QRadioButton *header_include = new QRadioButton("Protéger le header contre les inclusions multiples.");
    QRadioButton *construct_def = new QRadioButton("Créer un constructeur par défaut.");
    QRadioButton *destruct = new QRadioButton("Générer un destructeur.");

    header_include->setChecked(true);

    QVBoxLayout *vboxOpt = new QVBoxLayout;
    vboxOpt->addWidget(header_include);
    vboxOpt->addWidget(construct_def);
    vboxOpt->addWidget(destruct);



    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;


    QFormLayout *layout = new QFormLayout;
    layout->addRow("Votre nom", nom);
    layout->addRow("Votre prénom", prenom);
    layout->addRow("Votre âge", age);

    // Container injections
    gpBox->setLayout(vboxOpt);

    gpBoxOpt->setLayout(layout);

    wind.show();
    //QWidget::connect(bouton, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));

    return app.exec();
}
