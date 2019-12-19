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
    QLineEdit *class_n,  *mother_c, *author_n;
    QDateEdit *date_creation;
    QTextEdit *comments;
    QCheckBox *header_include, *construct_def, *destruct;

    QGroupBox *gpBoxComment;
    QPushButton *generate_btn, *quit_btn;
};

#endif // CLASSGENERATOR_H
