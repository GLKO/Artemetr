#include "camera.h"
#include "icomport.h"
#include "keywords.h"

#include <QString>
#include <QDebug>


namespace PC {

void convertToMessage(const Point point, char *msg);
Point *convertToPoint( const char *message);


Camera::Camera()
{

}

void Camera::move(Point newPos)
{
    char message[commandSize] = {0};
    convertToMessage(newPos, message);
    _port->sendMessage( message );
}

void Camera::moveX(int x)
{}

void Camera::moveY(int y)
{}

int Camera::currentX() const
{
    return _currentPosition.X;
}

int Camera::currentY() const
{
    return _currentPosition.Y;
}

Point Camera::currentPos() const
{
    return _currentPosition;
}

void Camera::updateSub()
{
    if (_port != nullptr) {
        const char *message = _port->readMessage();
        Point *newPosition = convertToPoint(message);
        if (newPosition != nullptr) {
            _currentPosition = *newPosition;
            delete newPosition;
//            qDebug() << _currentPosition.X << ' ' << _currentPosition.Y;
            notifySubscribers();
        }
    }
}

void Camera::setComPort(IComPort *port)
{
    _port = port;
}


/////////////////// -- Converting -- ///////////////////////////

void convertToMessage(const Point point, char *msg)
{
    *msg = moveTo;
    ++msg;
    int16_t *x = reinterpret_cast<int16_t *>(msg);
    int16_t *y = reinterpret_cast<int16_t *>(msg+2);
    *x = static_cast<int16_t>(point.X);
    *y = static_cast<int16_t>(point.Y);
}

Point *convertToPoint( const char *message)
{
    if ( message[0] == currentPosition ){
        int16_t x = *reinterpret_cast<const int16_t *>( message+xPos );
        int16_t y = *reinterpret_cast<const int16_t *>( message+yPos );
        return new Point{x,y};
    }
    return nullptr;
}

}



