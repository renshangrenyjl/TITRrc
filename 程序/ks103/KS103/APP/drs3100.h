#ifndef __DRS3100_H
#define __DRS3100_H 			   
void DRS3100_getPoint24(unsigned char *p);
void iic_ack(void);
void iic_nack(void);
void iic_delay(void);
void iic_start(void);
void iic_stop(void);
void iic_start(void);
void iic_send_byte(unsigned char txd);
unsigned char iic_wait_ack(void);
unsigned char iic_read_byte(unsigned char ack);
#endif

