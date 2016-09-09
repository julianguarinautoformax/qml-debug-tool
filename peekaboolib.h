#ifndef PEEKABOOLIB_H
#define PEEKABOOLIB_H

#include <QQuickItem>
#include <QColor>
#include <QJSValue>

class Peekaboolib:public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Peekaboolib)
    /*Q_PROPERTY(QJSValue dbgView READ dbgView)
    Q_PROPERTY(QJSValue dbgModel READ dbgModel)*/
    
public:
    Peekaboolib(QQuickItem * parent = 0);
    Q_INVOKABLE void aTest();
    
private:
    
    static void defaultCallBack(QtMsgType,const QMessageLogContext &,const QString &);
    /*QJSValue dbgModel;
    QJSValue dbgView;*/
signals:
    void debugMessage(QString aColor, QString aString);
    
    
};
extern Peekaboolib * pecker;

#endif // PEEKABOOLIB_H
