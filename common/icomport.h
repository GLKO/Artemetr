#pragma once

#include "iobserver.h"

class IComPort : public Publisher
{
public:
    virtual void sendMessage(const char *msg) = 0;
    virtual const char *readMessage() = 0;
    virtual ~IComPort() {}
};
