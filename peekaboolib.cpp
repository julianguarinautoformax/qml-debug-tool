
#include "peekaboolib.h"
#include <QDebug>
void Peekaboolib::defaultCallBack(QtMsgType type, const QMessageLogContext &context,const QString & msg){
    QByteArray localMsg = msg.toLocal8Bit();
       switch (type) {
       case QtDebugMsg:
           fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           break;
       case QtInfoMsg:
           fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           break;
       case QtWarningMsg:
           fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           break;
       case QtCriticalMsg:
           fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           break;
       case QtFatalMsg:
           fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           abort();
       }
}

Peekaboolib::Peekaboolib(Peekaboolib::PeekABooCBack cb, QObject * parent) : QObject(parent),m_PeekABooCallBack(cb){
    qInstallMessageHandler(m_PeekABooCallBack);
}
Peekaboolib::Peekaboolib(QObject * parent) : QObject(parent){
    qDebug()<<"I'm installing a QDebug handler new";
    m_PeekABooCallBack = defaultCallBack;
    qInstallMessageHandler(m_PeekABooCallBack);
}


