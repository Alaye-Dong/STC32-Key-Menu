#ifndef _KEY_H_
#define _KEY_H_

#include "headfile.h"

//拨码开关状态变量
extern uint8 sw1_status;
extern uint8 sw2_status;

//开关状态变量
extern uint8 key1_status ;
extern uint8 key2_status ;
extern uint8 key3_status ;
extern uint8 key4_status ;

//上一次开关状态变量
extern uint8 key1_last_status;
extern uint8 key2_last_status;
extern uint8 key3_last_status;
extern uint8 key4_last_status;

//开关标志位
extern uint8 key1_flag;
extern uint8 key2_flag;
extern uint8 key3_flag;
extern uint8 key4_flag;

extern uint8 KeystrokeLabel;


void Keystroke_Scan(void);

#endif