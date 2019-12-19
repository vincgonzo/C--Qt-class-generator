#include "ClassGenerator.h"

ClassGenerator::ClassGenerator()
{
    class_n = new QLineEdit;
    mother_c = new QLineEdit;

    QFormLayout *formDef = new QFormLayout;
    formDef->addRow("&Nom de la classe", class_n);
    formDef->addRow("Class &Mere", mother_c);

    QGroupBox *gpBoxDef = new QGroupBox("Class Definition");
    // Container injections
    gpBoxDef->setLayout(formDef);

    header_include = new QCheckBox("Protéger le header contre les inclusions multiples.");
    header_include->setChecked(true);
    construct_def = new QCheckBox("Créer un constructeur par défaut.");
    destruct = new QCheckBox("Générer un destructeur.");

    QVBoxLayout *layoutDef = new QVBoxLayout;
    layoutDef->addWidget(header_include);
    layoutDef->addWidget(construct_def);
    layoutDef->addWidget(destruct);

    QGroupBox *gpBoxOpt = new QGroupBox("Add Options");
    // Attrib def section to group
    gpBoxOpt->setLayout(layoutDef);


    //QCheckBox *add_comment = new QCheckBox("Ajouter des commentaires.", this);
    author_n = new QLineEdit;
    date_creation = new QDateEdit;
    date_creation->setDate(QDate::currentDate());
    comments = new QTextEdit;

    QFormLayout *formComment = new QFormLayout;
    formComment->addRow("&Author Name :", author_n);
    formComment->addRow("&Creation Date :", date_creation);
    formComment->addRow("&Describing use of Class", comments);

    gpBoxComment = new QGroupBox("Add Comments");
    gpBoxComment->setCheckable(true);
    gpBoxComment->setChecked(false);
    gpBoxComment->setLayout(formComment);


    generate_btn = new QPushButton("&Generate Class");
    quit_btn = new QPushButton("&Quitter");

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->setAlignment(Qt::AlignRight);
    btnLayout->addWidget(generate_btn);
    btnLayout->addWidget(quit_btn);

    // Layout attribution to general
    QVBoxLayout *layoutMain = new QVBoxLayout;
    layoutMain->addWidget(gpBoxDef);
    layoutMain->addWidget(gpBoxOpt);
    layoutMain->addWidget(gpBoxComment);
    layoutMain->addLayout(btnLayout);

    setLayout(layoutMain);
    setWindowTitle("My Generator Class");
    resize(450, 450);
}


void ClassGenerator::generateCode()
{
    // test
}
