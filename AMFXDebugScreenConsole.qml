import QtQuick 2.0

Item {
    id:root        
    anchors.fill: parent
    property int maxlines: 20
    property int fontPixelSize: 8
    property bool welcomeMessageEnabled: true
    property string welcomeMessage: "Hello this is ax demonstration of your debugger..... enjoy!"
    Component.onCompleted: {
        if (root.welcomeMessageEnabled) console.log(welcomeMessage)
    }

    ListModel{
        id:debugModel
        onDataChanged: debugView.positionViewAtEnd()
    }
    
    Component {
        id: debugMessageDelegate 
        Item {
            height: root.height / root.maxlines
            width: root.width
            y:root.height - height
            Rectangle{
                anchors.fill:parent
                color:"#00000000"
                opacity: parent.y / root.height
                Text {
                    anchors.fill: parent
                    text:debugMessage
                    color:textColor
                    font.pixelSize: root.fontPixelSize
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }

            }
                            
        }
        
    }
    
    
    ListView {
        id:debugView
        anchors.fill: parent
        model:debugModel
        delegate:debugMessageDelegate
        interactive: false
    }
    function debugViewAdd(aString, aColor){
        if (debugModel.count == 0 ){
            var index
            for(index=0;index<root.maxlines-1;index++)
                debugModel.append({"debugMessage":"","textColor":aColor})
        }
        
        debugModel.append({"debugMessage":aString,"textColor":aColor})
        if (debugModel.count > root.maxlines) {
            debugModel.remove(0,1)
        }
        debugView.currentIndex = debugModel.count - 1
        debugView.positionViewAtEnd()
    }
}
