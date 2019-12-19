#ifndef CLASSGENERATOR_H
#define CLASSGENERATOR_H

#include <QApplication>
#include <QtWidgets>

class ClassGenerator : public QWidget
{
    Q_OBJECT

public:
    ClassGenerator();

private slots:
    void generateCode();

private:
    QLineEdit *m_class_n,  *m_mother_c, *m_author_n;
    QDateEdit *m_date_creation;
    QTextEdit *m_comments;
    QCheckBox *m_header_include, *m_construct_def, *m_destruct;

    QGroupBox *m_gpBoxComment;
    QPushButton *m_generate_btn, *m_quit_btn;
};

#endif // CLASSGENERATOR_H
