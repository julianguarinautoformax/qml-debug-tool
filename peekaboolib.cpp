
#include "peekaboolib.h"
#include <QDebug>

Peekaboolib * pecker = 0x0;

void Peekaboolib::defaultCallBack(QtMsgType type, const QMessageLogContext &context,const QString & msg){
    QByteArray localMsg = msg.toLocal8Bit();
    QColor aColor;
    QString aString;
    QString aColorName;
       switch (type) {
       case QtDebugMsg:
           aString = QString("Debug [%2:%3, %4]: %1\n").arg(localMsg.constData()).arg(context.file).arg(QString::number(context.line)).arg(context.function);
           fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           aColor = Qt::green;
           break;
       case QtInfoMsg:
           aString = QString("Info [%2:%3, %4]: %1\n").arg(localMsg.constData()).arg(context.file).arg(QString::number(context.line)).arg(context.function);
           fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           aColor = Qt::cyan;
           break;
       case QtWarningMsg:
           aString = QString("Warning [%2:%3, %4]: %1\n").arg(localMsg.constData()).arg(context.file).arg(QString::number(context.line)).arg(context.function);
           fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           aColor = Qt::yellow;
           break;
       case QtCriticalMsg:
           aString = QString("Critical [%2:%3, %4]: %1\n").arg(localMsg.constData()).arg(context.file).arg(QString::number(context.line)).arg(context.function);
           fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           aColor = Qt::red;
           break;
       case QtFatalMsg:
           aString = QString("Fatal [%2:%3, %4]: %1\n").arg(localMsg.constData()).arg(context.file).arg(QString::number(context.line)).arg(context.function);
           fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
           aColor = Qt::magenta;
           abort();
       }
       aColorName = aColor.name();
       emit pecker -> debugMessage(aColor.name(),aString);
}

Peekaboolib::Peekaboolib(QQuickItem* parent):
    QQuickItem(parent){
    
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

