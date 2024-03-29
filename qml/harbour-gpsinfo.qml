import QtQuick 2.0
import Sailfish.Silica 1.0
import "pages"
import "providers"

ApplicationWindow
{
    Providers {
        id: providers
    }
    initialPage: Component {
        FirstPage {
            positionSource: providers.positionSource
            compass: providers.compass
            gpsDataSource: providers.gpsDataSource
//            connect_Base: providers.connect_Base
        }
    }
    cover: CoverPage {
        positionSource: providers.positionSource
        compass: providers.compass
        gpsDataSource: providers.gpsDataSource
    }
}
