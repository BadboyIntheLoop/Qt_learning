#include "widget.h"
#include "messager.h"
#include <QApplication>
#include <QString>
#include <QLabel>
#include <QDebug>
#include <QTextStream>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QObject>
#include <QAbstractButton>
//#define DEBUG

int main(int argc, char *argv[])
{
    QApplication qapp(argc, argv);
    QWidget* root_wid = new QWidget;
#ifdef DEBUG
    qDebug() << "Size of Widget: " << sizeof(root_wid) << '\n';
#endif
    QLayout* layout = new QVBoxLayout;
    root_wid->setLayout(layout);
    QTextEdit *te = new QTextEdit;
    layout->addWidget(te);

    te->setHtml("Some <b>text</b> in the <tt>QTextEdit</tt>"
                "edit window <i>please</i>?");
    QPushButton *quitBut = new QPushButton("Quit");
    layout->addWidget(quitBut);

    QPushButton *shoutBut = new QPushButton("Shout");
    layout->addWidget(shoutBut);

    Messager *msgr = new Messager("Self - Destruct Dialog \n", root_wid);
    qapp.connect(quitBut, SIGNAL(QAbstractButton::clicked()), qapp, SIGNAL(QAbstractButton::quit()));
    qapp.connect(shoutBut, SIGNAL(QAbstractButton::clicked()), qapp, SIGNAL(QAbstractButton::quit()));

    root_wid->show();
    return qapp.exec();
}
