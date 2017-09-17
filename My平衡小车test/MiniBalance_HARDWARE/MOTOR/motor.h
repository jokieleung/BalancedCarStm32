#ifndef __MOTOR_H
#define __MOTOR_H
#include <sys.h>	 
  /**************************************************************************
作者：平衡小车之家
我的淘宝小店：http://shop114407458.taobao.com/
**************************************************************************/
#define PWMA   TIM1->CCR1  //PA8
#define AIN2   PBout(10)							//IN2		0	B15
#define AIN1   PBout(14)							//IN1		1
#define BIN1   PBout(13)							//IN4		1
#define BIN2   PBout(12)							//IN3		0		前进
#define PWMB   TIM1->CCR4  //PA11
void MiniBalance_PWM_Init(u16 arr,u16 psc);
void MiniBalance_Motor_Init(void);
#endif
