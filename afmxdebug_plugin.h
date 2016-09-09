#ifndef AFMXDEBUGPLUGIN_H
#define AFMXDEBUGPLUGIN_H

#include <QQmlExtensionPlugin>

class AFMXDebugPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.afmx.debug")
public:
    void registerTypes(const char * uri);    
};

#endif // AFMXDEBUGPLUGIN_H
