
#include "peekaboolib.h"
#include <QDebug>
#include <QFileInfo>
Peekaboolib * pecker = 0x0;

QString formatContextFile(const char * file){
    
    QString aFile(file);
    QFileInfo aFileInfo(aFile);
    return aFileInfo.fileName();
    
}

QString formatContextFunction(const char * function){
    
    QString aFunction(function);
    QStringList aFunctionSignatureSplitted(aFunction.split("::"));
    aFunction = aFunctionSignatureSplitted[aFunctionSignatureSplitted.count()-1];
    QStringList aFunctionSplitted(aFunction.split("("));
    return aFunctionSplitted[0];
}

void Peekaboolib::defaultCallBack(QtMsgType type, const QMessageLogContext &context,const QString & msg){
    
    QByteArray localMsg = msg.toLocal8Bit();
    QColor aColor;
    QString aString;
    aString = QString("[%2:%3, %4]: %1\n").arg(localMsg.constData()).arg(formatContextFile(context.file)).arg(QString::number(context.line)).arg(formatContextFunction(context.function));
    if (pecker->stdVersion()) fprintf(stderr, "%s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
    
    QString aColorName;
       switch (type) {
       case QtDebugMsg:
           aColor = Qt::green;
           break;
       case QtInfoMsg:
           aColor = Qt::cyan;
           break;
       case QtWarningMsg:
           aColor = Qt::yellow;
           break;
       case QtCriticalMsg:
           aColor = Qt::red;
           break;
       case QtFatalMsg:
           aColor = Qt::magenta;
           abort();
       }
       aColorName = aColor.name();
       emit pecker -> debugMessage(aColor.name(),aString);
}

Peekaboolib::Peekaboolib(QQuickItem* parent):
    QQuickItem(parent),m_std(true){
    
    qDebug()<<"I'm installing a QDebug handler new";
    qInstallMessageHandler(defaultCallBack);
    pecker = this;
}

void Peekaboolib::aTest(){
    
    qDebug("A Debug message.");
    qInfo("An Info message.");
    qWarning("A Warning Message.");
    qCritical("A Critical Message.");

}
bool Peekaboolib::stdVersion(){
    return m_std;
}
void Peekaboolib::setStdVersion(bool value){
    m_std = value;
}


