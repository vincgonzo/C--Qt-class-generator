#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

#include <QtWidgets>

class CodeGenerator : public QDialog
{
    Q_OBJECT
    public:
        CodeGenerator(QString &code, QWidget *parent);

    signals:

    private:
        QTextEdit *m_code_generate;
        QPushButton *m_close;
};

#endif // CODEGENERATOR_H
