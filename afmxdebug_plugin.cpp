#include "afmxdebug_plugin.h"
#include "peekaboolib.h"
#include <qqml.h>


void AFMXDebugPlugin::registerTypes(const char* uri){
    
    //@uri com.afmx.debug
    qmlRegisterType<Peekaboolib>(uri,1,0,"AFMXDebug");
    
    
}
