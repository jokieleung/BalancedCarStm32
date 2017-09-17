#include "stm32f10x.h"
#include "sys.h"
  
u8 Way_Angle=2;                             //��ȡ�Ƕȵ��㷨��1����Ԫ��  2��������  3�������˲� 
u8 Flag_Qian,Flag_Hou,Flag_Left,Flag_Right,Flag_sudu=2; //����ң����صı���
u8 Flag_Stop=1,Flag_Show=1;                 //ֹͣ��־λ�� ��ʾ��־λ Ĭ��ֹͣ ��ʾ��
int Encoder_Left,Encoder_Right;             //���ұ��������������
int Moto1,Moto2;                            //���PWM���� Ӧ��Motor�� ��Moto�¾�	
int Temperature;                            //��ʾ�¶�
int Voltage;                                //��ص�ѹ������صı���
float Angle_Balance,Gyro_Balance,Gyro_Turn; //ƽ����� ƽ�������� ת��������
float Show_Data_Mb;                         //ȫ����ʾ������������ʾ��Ҫ�鿴������
u32 Distance;                               //���������
u8 delay_50,delay_flag,Bi_zhang=0,PID_Send,Flash_Send;  //��ʱ�͵��εȱ���
float Acceleration_Z;                       //Z����ٶȼ�
float Balance_Kp=520,Balance_Kd=1.3,Velocity_Kp=20,Velocity_Ki=20/200.0;//PID����	//15
/*�Ѵﵽƽ��Ч��������V1.0��By Jokie:
debug note(23/8/2017):Balance_Kp=520,Balance_Kd=1.3,Velocity_Kp=20,Velocity_Ki=20/200.0;
*/
//�ҳ����ҵ�����Ե�����pwm�������ȷ
u16 PID_Parameter[10],Flash_Parameter[10];  //Flash������� 
int main(void)
  { 
		delay_init();	    	            //=====��ʱ������ʼ��	
		uart_init(128000);	            //=====���ڳ�ʼ��Ϊ
		JTAG_Set(JTAG_SWD_DISABLE);     //=====�ر�JTAG�ӿ�
		JTAG_Set(SWD_ENABLE);           //=====��SWD�ӿ� �������������SWD�ӿڵ���
		LED_Init();                     //=====��ʼ���� LED ���ӵ�Ӳ���ӿ�
	  KEY_Init();                     //=====������ʼ��
		MY_NVIC_PriorityGroupConfig(2);	//=====�ж����ȼ�����
    MiniBalance_PWM_Init(7199,0);   //=====��ʼ��PWM 10KHZ������������� �����ʼ������ӿ� 
//		uart3_init(9600);               //=====����3��ʼ��  ����ͨ��
    Encoder_Init_TIM2();            //=====�������ӿ�
    Encoder_Init_TIM4();            //=====��ʼ��������2
//		Adc_Init();                     //=====adc��ʼ��
    IIC_Init();                     //=====IIC��ʼ��
    MPU6050_initialize();           //=====MPU6050��ʼ��	
    DMP_Init();                     //=====��ʼ��DMP 
//    OLED_Init();                    //=====OLED��ʼ��	    
//		TIM3_Cap_Init(0XFFFF,72-1);	    //=====��������ʼ��
	  MiniBalance_EXTI_Init();        //=====MPU6050 5ms��ʱ�жϳ�ʼ��
    while(1)
	   {
//		    if(Flag_Show==0)          //ʹ��MiniBalance APP��OLED��ʾ��
//					{
//							APP_Show();	
//							oled_show();          //===��ʾ����
//					}
//					else                      //ʹ��MiniBalance��λ�� ��λ��ʹ�õ�ʱ����Ҫ�ϸ��ʱ�򣬹ʴ�ʱ�ر�app��ز��ֺ�OLED��ʾ��
//					{
//				      DataScope();          //����MiniBalance��λ��
//					}	
//			 printf("while(1)\r\n");
				  delay_flag=1;	
					delay_50=0;
					while(delay_flag);	     //ͨ��MPU6050��INT�ж�ʵ�ֵ�50ms��׼��ʱ	
	   } 
}

