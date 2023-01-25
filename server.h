//
// Created by phyoko on 1/17/23.
//

#ifndef TCPCREATEFORBANK_SERVER_H
#define TCPCREATEFORBANK_SERVER_H

#endif //TCPCREATEFORBANK_SERVER_H


#if defined(_WIN32)
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


#include "stdio.h"
#include "string.h"