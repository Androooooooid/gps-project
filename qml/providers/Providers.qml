import QtQuick 2.0
import QtPositioning 5.2
import QtSensors 5.0
import harbour.gpsinfo 1.0
import harbour.connect_base 1.0

Item {
    id: providers
    property alias positionSource: positionSource
    property alias compass: compass
    property alias gpsDataSource: gpsDataSource
    property alias connect_Base: connect_Base
    PositionSource {
        id: positionSource
//        updateInterval: settings.updateInterval
        active: true
        nmeaSource: "/usr/share/%1/nmea/output.nmea".arg(Qt.application.name)
    }
    Compass {
        id: compass
        active: true
    }

    Connect_Base {
    id: connect_Base
    }

    GPSDataSource {
        id: gpsDataSource
        updateInterval: settings.updateInterval
        active: true
    }
}
