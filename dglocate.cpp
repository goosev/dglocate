#include <QtWidgets>
#include <QGeoPositionInfoSource>
#include <QGeoSatelliteInfoSource>

#include "dglocate.h"

//! [0]
DGLocate::DGLocate(QWidget *parent)
    : QWidget(parent)
{
    label = new QLabel(this);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);
    setLayout(layout);

    //m_posSource = QGeoSatelliteInfoSource::createDefaultSource(this);
    m_posSource = QGeoPositionInfoSource::createDefaultSource(0);
    m_posSource->setPreferredPositioningMethods(QGeoPositionInfoSource::AllPositioningMethods);
    if (m_posSource == 0) {
        label->setText("No Position Source created!");
    } else {
        m_posSource->setUpdateInterval(1000);
        connect(m_posSource, SIGNAL(positionUpdated(QGeoPositionInfo)),
            this, SLOT(positionUpdated(QGeoPositionInfo)));
        m_posSource->startUpdates();
    }
}
//! [0]

//! [1]
void DGLocate::positionUpdated(const QGeoPositionInfo &gpsPos)
{
    double lng, lat;
    QGeoCoordinate coord = gpsPos.coordinate();
    lng = coord.longitude();
    lat = coord.latitude();
    if (gpsPos.isValid()) {
        label->setText("longitude="+QString::number(lng)+"\n""latitude="+QString::number(lat)+"\n");
    } else
    {
        label->setText("Position error");
    }
}
//! [1]

