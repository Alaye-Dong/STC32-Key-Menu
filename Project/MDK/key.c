#include "key.h"

//定义按键引脚
#define KEY1_PIN    P70
#define KEY2_PIN    P71	
#define KEY3_PIN    P72
#define KEY4_PIN    P73
//定义拨码开关引脚
#define SW1_PIN     P76
#define SW2_PIN     P75

//定义按键代号
#define KeystrokeONE 1
#define KeystrokeTWO 2
#define KeystrokeTHREE 3
#define KeystrokeFOUR 4

//拨码开关状态变量 ON为0
uint8 sw1_status;
uint8 sw2_status;

//开关状态变量
uint8 key1_status = 1;
uint8 key2_status = 1;
uint8 key3_status = 1;
uint8 key4_status = 1;

//上一次开关状态变量
uint8 key1_last_status;
uint8 key2_last_status;
uint8 key3_last_status;
uint8 key4_last_status;

//开关标志位
uint8 key1_flag;
uint8 key2_flag;
uint8 key3_flag;
uint8 key4_flag;

void Keystroke_Scan(void)
{

    //获取拨码开关状态
    sw1_status = SW1_PIN;
    sw2_status = SW2_PIN;

    //使用此方法优点在于，不需要使用while(1) 等待，避免处理器资源浪费
    //保存按键状态
    key1_last_status = key1_status;
    key2_last_status = key2_status;
    key3_last_status = key3_status;
    key4_last_status = key4_status;
    //读取当前按键状态
    key1_status = KEY1_PIN;
    key2_status = KEY2_PIN;
    key3_status = KEY3_PIN;
    key4_status = KEY4_PIN;


    //检测到按键按下之后  并放开置位标志位
    if(key1_status && !key1_last_status)    key1_flag = 1;
    if(key2_status && !key2_last_status)    key2_flag = 1;
    if(key3_status && !key3_last_status)    key3_flag = 1;
    if(key4_status && !key4_last_status)    key4_flag = 1;

    //标志位置位之后，可以使用标志位执行自己想要做的事件
    KeystrokeLabel = 0;        

    if(key1_flag)   
    {
        key1_flag = 0;//使用按键之后，应该清除标志位
        KeystrokeLabel = 1;
        BEEP = 1;
        delay_ms(5);
        BEEP = 0;
    }

    if(key2_flag)   
    {
        key2_flag = 0;//使用按键之后，应该清除标志位
        KeystrokeLabel = 2;
        BEEP = 1;
        delay_ms(5);
        BEEP = 0;
    }

    if(key3_flag)   
    {
        key3_flag = 0;//使用按键之后，应该清除标志位
        KeystrokeLabel = 3;
        BEEP = 1;
        delay_ms(5);
        BEEP = 0;        
    }

    if(key4_flag)   
    {
        key4_flag = 0;//使用按键之后，应该清除标志位
        KeystrokeLabel = 4;
        BEEP = 1;
        delay_ms(5);
        BEEP = 0;        
    }

}