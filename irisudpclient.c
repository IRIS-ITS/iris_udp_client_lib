/*
 * irisudpclient.c
 *
 *  Created on: Jan 11, 2025
 *      Author: ARNN5115 & Controllertech
 */

#include "irisudpclient.h"


void UDP_Receive_Callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);

struct udp_pcb *upcb;
char *buffer;


/* IMPLEMENTATION FOR UDP CLIENT :   source:https://www.geeksforgeeks.org/udp-server-client-implementation-c/

1. Create UDP socket.
2. Send message to server.
3. Wait until response from server is received.
4. Process reply and go back to step 2, if necessary.
5. Close socket descriptor and exit.
*/

void UDPClient_Connect(uint8_t client_ip[4], uint16_t client_port,
						uint8_t server_ip[4], uint16_t server_port,
						uint8_t *rx_buffer)
{
	buffer = rx_buffer;
	
	err_t err;

	/* 1. Create a new UDP control block  */
	upcb = udp_new();

	/* Bind the block to module's IP and port */
	ip_addr_t client_ip_address;
	IP_ADDR4(&client_ip_address, client_ip[0], client_ip[1], client_ip[2], client_ip[3]);
	udp_bind(upcb, &client_ip_address, client_port);


	/* configure destination IP address and port */
	ip_addr_t server_ip_address;
	IP_ADDR4(&server_ip_address, server_ip[0], server_ip[1], server_ip[2], server_ip[3]);
	err = udp_connect(upcb, &server_ip_address, server_port);

	if (err == ERR_OK)
	{
		/* 2. Send message to server */
		UDPClient_Send("IRIS Juara Harga Mati!\n", 24);

		/* 3. Set a receive callback for the upcb */
		udp_recv(upcb, UDP_Receive_Callback, NULL);
	}
}

static void UDPClient_Send(char *data, uint8_t data_len)
{
  struct pbuf *txBuf;
  uint8_t len = data_len;

  /* allocate pbuf from pool*/
  txBuf = pbuf_alloc(PBUF_TRANSPORT, len, PBUF_RAM);

  if (txBuf != NULL)
  {
    /* copy data to pbuf */
    pbuf_take(txBuf, data, len);

    /* send udp data */
    udp_send(upcb, txBuf);

    /* free pbuf */
    pbuf_free(txBuf);
  }
}


void UDP_Receive_Callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
	/* Copy the data from the pbuf */
	strncpy (buffer, (char *)p->payload, p->len);

	/* Free receive pbuf */
	pbuf_free(p);
}
