#ifndef PEEKABOOLIB_H
#define PEEKABOOLIB_H
#include <QObject>
#include "peek-a-boo-lib_global.h"


class PEEKABOOLIBSHARED_EXPORT Peekaboolib:public QObject
{
    typedef void(*PeekABooCBack)(QtMsgType,const QMessageLogContext &,const QString &);
    Q_OBJECT

private:
    PeekABooCBack m_PeekABooCallBack;
    static void defaultCallBack(QtMsgType,const QMessageLogContext &,const QString &);

public:
    Peekaboolib(PeekABooCBack, QObject * parent = Q_NULLPTR);
    Peekaboolib(QObject * parent = Q_NULLPTR);
    
};

#endif // PEEKABOOLIB_H
