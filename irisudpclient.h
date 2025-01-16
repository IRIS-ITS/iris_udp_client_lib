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

/**
 * @brief Connects the UDP client to the specified server.
 * 
 * @param client_ip The IP address of the client.
 * @param client_port The port number of the client.
 * @param server_ip The IP address of the server.
 * @param server_port The port number of the server.
 * @param rx_buffer The buffer to store received data.
 * @param connect_msg The message to send to the server.
 */
void UDPClient_Connect(uint8_t client_ip[4], uint16_t client_port,
						uint8_t server_ip[4], uint16_t server_port,
                        uint8_t *rx_buffer, char *connect_msg,
						void (*callback_funct)(void));

void UDPClient_Send(char *data, uint8_t data_len);

#endif /* INC_IRIS_UDP_CLIENT_H */
