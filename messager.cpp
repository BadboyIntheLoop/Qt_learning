#include "messager.h"

Messager::Messager(QString msg, QWidget *parent) : m_parent(parent) {
    message = new QErrorMessage(parent);
    parent->setObjectName(msg);
}

void Messager::shout(){
    message->showMessage(objectName());
}
