#include "ClassGenerator.h"
#include "Codegenerator.h"

ClassGenerator::ClassGenerator()
{
    m_class_n = new QLineEdit;
    m_mother_c = new QLineEdit;

    QFormLayout *formDef = new QFormLayout;
    formDef->addRow("&Nom de la classe", m_class_n);
    formDef->addRow("Class &Mere", m_mother_c);

    QGroupBox *gpBoxDef = new QGroupBox("Class Definition");
    // Container injections
    gpBoxDef->setLayout(formDef);

    m_header_include = new QCheckBox("Protéger le header contre les inclusions multiples.");
    m_header_include->setChecked(true);
    m_construct_def = new QCheckBox("Créer un constructeur par défaut.");
    m_destruct = new QCheckBox("Générer un destructeur.");

    QVBoxLayout *layoutDef = new QVBoxLayout;
    layoutDef->addWidget(m_header_include);
    layoutDef->addWidget(m_construct_def);
    layoutDef->addWidget(m_destruct);

    QGroupBox *gpBoxOpt = new QGroupBox("Add Options");
    // Attrib def section to group
    gpBoxOpt->setLayout(layoutDef);


    //QCheckBox *add_comment = new QCheckBox("Ajouter des commentaires.", this);
    m_author_n = new QLineEdit;
    m_date_creation = new QDateEdit;
    m_date_creation->setDate(QDate::currentDate());
    m_comments = new QTextEdit;

    QFormLayout *formComment = new QFormLayout;
    formComment->addRow("&Author Name :", m_author_n);
    formComment->addRow("&Creation Date :", m_date_creation);
    formComment->addRow("&Describing use of Class", m_comments);

    m_gpBoxComment = new QGroupBox("Add comments");
    m_gpBoxComment->setCheckable(true);
    m_gpBoxComment->setChecked(false);
    m_gpBoxComment->setLayout(formComment);


    m_generate_btn = new QPushButton("&Generate Class");
    m_quit_btn = new QPushButton("&Quitter");

    QHBoxLayout *btnLayout = new QHBoxLayout;
    btnLayout->setAlignment(Qt::AlignRight);
    btnLayout->addWidget(m_generate_btn);
    btnLayout->addWidget(m_quit_btn);

    // Layout attribution to general
    QVBoxLayout *layoutMain = new QVBoxLayout;
    layoutMain->addWidget(gpBoxDef);
    layoutMain->addWidget(gpBoxOpt);
    layoutMain->addWidget(m_gpBoxComment);
    layoutMain->addLayout(btnLayout);

    setLayout(layoutMain);
    setWindowTitle("My Generator Class");
    resize(450, 450);

    // Slots connectors
    connect(m_quit_btn, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(m_generate_btn, SIGNAL(clicked()), this, SLOT(generateCode()));
}


void ClassGenerator::generateCode()
{
    if(m_class_n->text().isEmpty())
    {
        QMessageBox::critical(this, "Error Message", "Need a Name Class to generate it.");
        return;
    }

    QString code;

    if (m_gpBoxComment->isChecked()) // On a demandé à inclure les commentaires
    {
        code += "/*\nAuteur : " + m_author_n->text() + "\n";
        code += "Date de création : " + m_date_creation->date().toString() + "\n\n";
        code += "Rôle :\n" + m_comments->toPlainText() + "\n*/\n\n\n";
    }

    if (m_header_include->isChecked())
    {
        code += "#ifndef HEADER_" + m_class_n->text().toUpper() + "\n";
        code += "#define HEADER_" + m_class_n->text().toUpper() + "\n\n\n";
    }

    code += "class " + m_class_n->text();

    if (!m_mother_c->text().isEmpty())
    {
        code += " : public " + m_mother_c->text();
    }

    code += "\n{\n    public:\n";
    if (m_construct_def->isChecked())
    {
        code += "        " + m_class_n->text() + "();\n";
    }
    if (m_destruct->isChecked())
    {
        code += "        ~" + m_class_n->text() + "();\n";
    }
    code += "\n\n    protected:\n";
    code += "\n\n    private:\n";
    code += "};\n\n";

    if (m_header_include->isChecked())
    {
        code += "#endif\n";
    }
    code += "Class Name is : " + m_class_n->text();

    CodeGenerator *secondWind = new CodeGenerator(code, this);
    secondWind->exec();
}
