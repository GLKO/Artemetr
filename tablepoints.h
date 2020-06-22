#pragma once

#include <QList>

#include "point.h"


class TabelPoints
{
public:
    TabelPoints();

    bool hasNextCheckPoint() const;
    const Point nextCheckPoint() const;
    void currentCheckIs( bool checkResult );

    bool hasNextTargetPoint() const;
    Point nextTargetPoint();

private:
//    void getPackList();
    QList<Point> _packList;

    QList<Point> _packsForCheck;

    void getTargetPoints();
    QList<Point> _targetPoints;
};