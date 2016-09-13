#ifndef PEEKABOOLIB_H
#define PEEKABOOLIB_H

#include <QQuickItem>
#include <QColor>
#include <QJSValue>

class Peekaboolib:public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(Peekaboolib)
    Q_PROPERTY(bool stdVersion READ stdVersion WRITE setStdVersion)
public:
    Peekaboolib(QQuickItem * parent = 0);
    Q_INVOKABLE void aTest();
    
    bool stdVersion();
    void setStdVersion(bool);

    
private:
    
    static void defaultCallBack(QtMsgType,const QMessageLogContext &,const QString &);
    bool m_std;    

signals:
    void debugMessage(QString aColor, QString aString);
    
    
};
extern Peekaboolib * pecker;

#endif // PEEKABOOLIB_H
