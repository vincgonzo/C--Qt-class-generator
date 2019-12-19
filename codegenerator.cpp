#include "Codegenerator.h"

CodeGenerator::CodeGenerator(QString &code, QWidget *parent = 0) : QDialog(parent)
{
    m_code_generate = new QTextEdit();
    m_code_generate->setPlainText(code);
    m_code_generate->setReadOnly(true);
    m_code_generate->setFont(QFont("Courier"));
    m_code_generate->setLineWrapMode(QTextEdit::NoWrap);

    m_close = new QPushButton("m_close");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(m_code_generate);
    layoutPrincipal->addWidget(m_close);

    resize(350, 450);
    setLayout(layoutPrincipal);

    connect(m_close, SIGNAL(clicked()), this, SLOT(accept()));
}
