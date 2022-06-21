#ifndef MESSAGER_H
#define MESSAGER_H
#include <QErrorMessage>

class Messager : public QString {
    Q_OBJECT
public:
    Messager (QString msg, QWidget* parent=0);
public slots:
    void shout();

private:
    QWidget* m_parent;
    QErrorMessage* message;

};

#endif // MESSAGER_H
