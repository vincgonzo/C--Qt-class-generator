#include <QApplication>
#include <QtWidgets>

#include "ClassGenerator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget wind;
    QLineEdit *class_n = new QLineEdit;
    QLineEdit *mother_c = new QLineEdit;
    QLineEdit *author_n = new QLineEdit;
    QDateEdit *date_creation = new QDateEdit;
    QTextEdit *comments = new QTextEdit;

    QVBoxLayout *layoutMain = new QVBoxLayout;


    /**
     * @brief gpBoxDef
     */
    QGroupBox *gpBoxDef = new QGroupBox("Class Definition", &wind);
    QFormLayout *layoutForm = new QFormLayout;
    layoutForm->addRow("&Nom de la classe", class_n);
    layoutForm->addRow("Class &Mere", mother_c);

    // Container injections
    gpBoxDef->setLayout(layoutForm);

    /**
     * @brief gpBoxOpt
     */
    QGroupBox *gpBoxOpt = new QGroupBox("Add Options", &wind);
    QCheckBox *header_include = new QCheckBox("Protéger le header contre les inclusions multiples.", &wind);
    QCheckBox *construct_def = new QCheckBox("Créer un constructeur par défaut.", &wind);
    QCheckBox *destruct = new QCheckBox("Générer un destructeur.", &wind);

    header_include->setChecked(true);

    QVBoxLayout *layoutDef = new QVBoxLayout;
    layoutDef->addWidget(header_include);
    layoutDef->addWidget(construct_def);
    layoutDef->addWidget(destruct);

    // Attrib def section to group
    gpBoxOpt->setLayout(layoutDef);

    /**
     * @brief gpBoxComment
     */
    //QCheckBox *add_comment = new QCheckBox("Ajouter des commentaires.", &wind);
    QGroupBox *gpBoxComment = new QGroupBox("Add Comments", &wind);
    QFormLayout *layoutFormComment = new QFormLayout;
    layoutFormComment->addRow("Author Name :", author_n);
    layoutFormComment->addRow("Creation Date :", date_creation);
    layoutFormComment->addRow("Describing use of Class", comments);
    gpBoxComment->setLayout(layoutFormComment);


    // Layout attribution to general
    layoutMain->addWidget(gpBoxDef);
    layoutMain->addWidget(gpBoxOpt);
    layoutMain->addWidget(gpBoxComment);

    wind.setLayout(layoutMain);
    wind.show();
    //QWidget::connect(bouton, SIGNAL(clicked()), &secondeFenetre, SLOT(exec()));

    return app.exec();
}
