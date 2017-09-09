#ifndef DGLOCATE_H
#define DGLOCATE_H

#include <QWidget>
#include <QLabel>
#include <QGeoPositionInfoSource>
#include <QGeoSatelliteInfoSource>

//! [0]
class DGLocate : public QWidget
{
    Q_OBJECT

public:
    explicit DGLocate(QWidget *parent = 0);
    //~DGLocate();

private slots:
    void positionUpdated(const QGeoPositionInfo &gpsPos);

private:
    //QGeoSatelliteInfoSource* m_posSource;
    QGeoPositionInfoSource* m_posSource;
    QLabel *label;
};
//! [0]

#endif
