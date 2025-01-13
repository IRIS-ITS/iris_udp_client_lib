/*
 * irisudpclient.h
 *
 *  Created on: Jan 11, 2025
 *      Author: ARNN5115 & Controllertech
 */

#ifndef INC_IRIS_UDP_CLIENT_H
#define INC_IRIS_UDP_CLIENT_H


#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"

#include "stdio.h"
#include "string.h"

void UDPClient_Connect(uint8_t client_ip[4], uint16_t client_port,
						uint8_t server_ip[4], uint16_t server_port,
                        uint8_t *rx_buffer);

static void UDPClient_Send(char *data, uint8_t data_len);

#endif /* INC_IRIS_UDP_CLIENT_H */