#pragma once

//路径跟随（与时间无关）

#ifndef M_PI
#define M_PI 3.14159265358979323846f //圆周率	
#endif // !M_PI

//定义车体左右前后轮子之间的距离,即前右轮的坐标为(267,267)
#define DISTANCE_OF_WHEEL_X_AXES 534.0f //左右两轮在X轴上的距离为534mm
#define DISTANCE_OF_WHEEL_Y_AXES 534.0f //前后两轮在Y轴上的距离为534mm

#define WHEEL_DIAMETER 127.0f //麦克纳姆轮轮直径127mm

//定义了车轮的默认前进方向
#define FRONT_LEFTT_DEFAULT_DIR false  //前左轮默认方向
#define FRONT_RIGHT_DEFAULT_DIR true   //前右轮默认方向
#define BEHIND_LEFTT_DEFAULT_DIR false //后左轮默认方向
#define BEHIND_RIGHT_DEFAULT_DIR true  //后右轮默认方向

//定义了电机和编码器的硬件参数
#define FRONT_LEFT_MOTOR_TIM_CHANNEL 4                        //TIM2_CH4
#define FRONT_LFET_MOTOR_DIR (IO_Class(GPIOE, GPIO_Pin_13))   //前左轮方向IO
#define FRONT_LFET_MOTOR_BRAKE (IO_Class(GPIOE, GPIO_Pin_14)) //前左轮刹车IO
#define FRONT_LFET_MOTOR_STOP (IO_Class(GPIOE, GPIO_Pin_15))  //前左轮启动IO
#define FRONT_LEFT_MOTOR (FRONT_LFET_MOTOR_DIR, FRONT_LFET_MOTOR_BRAKE, FRONT_LFET_MOTOR_STOP, FRONT_LEFTT_DEFAULT_DIR, TIM2)

#define FRONT_RIGHT_MOTOR_TIM_CHANNEL 3                        //TIM2_CH3
#define FRONT_RIGHT_MOTOR_DIR (IO_Class(GPIOE, GPIO_Pin_10))   //前右轮方向IO
#define FRONT_RIGHT_MOTOR_BRAKE (IO_Class(GPIOE, GPIO_Pin_11)) //前右轮刹车IO
#define FRONT_RIGHT_MOTOR_STOP (IO_Class(GPIOE, GPIO_Pin_12))  //前右轮启动IO
#define FRONT_RIGHT_MOTOR (FRONT_RIGHT_MOTOR_DIR, FRONT_RIGHT_MOTOR_BRAKE, FRONT_RIGHT_MOTOR_STOP, FRONT_RIGHT_DEFAULT_DIR, TIM2)

#define BEHIND_LEFT_MOTOR_TIM_CHANNEL 2                        //TIM12_CH2
#define BEHIND_LFET_MOTOR_DIR (IO_Class(GPIOD, GPIO_Pin_11))   //后左轮方向IO
#define BEHIND_LFET_MOTOR_BRAKE (IO_Class(GPIOD, GPIO_Pin_12)) //后左轮刹车IO
#define BEHIND_LFET_MOTOR_STOP (IO_Class(GPIOD, GPIO_Pin_13))  //后左轮启动IO
#define BEHIND_LEFT_MOTOR (BEHIND_LFET_MOTOR_DIR, BEHIND_LFET_MOTOR_BRAKE, BEHIND_LFET_MOTOR_STOP, BEHIND_LEFTT_DEFAULT_DIR, TIM12)

#define BEHIND_RIGHT_MOTOR_TIM_CHANNEL 1                       //TIM12_CH1
#define BEHIND_RIGHT_MOTOR_DIR (IO_Class(GPIOD, GPIO_Pin_8))   //后右轮方向IO
#define BEHIND_RIGHT_MOTOR_BRAKE (IO_Class(GPIOD, GPIO_Pin_9)) //后右轮刹车IO
#define BEHIND_RIGHT_MOTOR_STOP (IO_Class(GPIOD, GPIO_Pin_10)) //后右轮启动IO
#define BEHIND_RIGHT_MOTOR (BEHIND_RIGHT_MOTOR_DIR, BEHIND_RIGHT_MOTOR_BRAKE, BEHIND_RIGHT_MOTOR_STOP, BEHIND_RIGHT_DEFAULT_DIR, TIM12)

#define FRONT_LEFTT_ENCODER (Encoder_Class(TIM1))  //前左编码器
#define FRONT_RIGHT_ENCODER (Encoder_Class(TIM8))  //前右编码器
#define BEHIND_LEFTT_ENCODER (Encoder_Class(TIM3)) //后左编码器
#define BEHIND_RIGHT_ENCODER (Encoder_Class(TIM4)) //后右编码器

//定义了编码器参数
#define ENCODER_FIX_WHEEL true       //指示编码器和轮子固连在一起
#define REDUCTION_RATIO 30           //减速比
#define ENCODER_RESOLUTION_INIT 2000 //编码器的分辨率（线数）
#if ENCODER_FIX_WHEEL
#define ENCODER_RESOLUTION ENCODER_RESOLUTION_INIT //编码器最终分辨率（线数）
#else
#define ENCODER_RESOLUTION ENCODER_RESOLUTION_INIT *REDUCTION_RATIO //编码器最终分辨率（线数）
#endif

//定义电机转速
#define MOTOR_MAX_ROTATIONL_VELOCITY 3000.0f //电机最高转速3000rpm/min
#define MOTOR_MIN_ROTATIONL_VELOCITY 100.0f  //电机最低转速100rpm/min
//定义轮子最大速度、最小速度和最大加速度
#define WHEEL_MAX_ANGULAR_VELOCITY (MOTOR_MAX_ROTATIONL_VELOCITY * 6 / REDUCTION_RATIO)          //轮子最大角速度(°/s)
#define WHEEL_MIN_ANGULAR_VELOCITY (MOTOR_MIN_ROTATIONL_VELOCITY * 6 / REDUCTION_RATIO)          //轮子最小角速度(°/s)
#define WHEEL_ANGULAR_ACCELERATION 5.0f                                                          //(5s达到最大角速度)
#define WHEEL_MAX_ANGULAR_ACCELERATION (WHEEL_MAX_ANGULAR_VELOCITY / WHEEL_ANGULAR_ACCELERATION) //轮子最大角加速度(°/s2)

#define WHEEL_MAX_LINE_VELOCITY (MOTOR_MAX_ROTATIONL_VELOCITY / 60 / REDUCTION_RATIO * WHEEL_DIAMETER * M_PI)                                //轮子最大线速度(mm/s)
#define WHEEL_MIN_LINE_VELOCITY (MOTOR_MIN_ROTATIONL_VELOCITY / 60 / REDUCTION_RATIO * WHEEL_DIAMETER * M_PI)                                //轮子最小线速度(mm/s)
#define WHEEL_LINE_VELOCITY_ACCELERATION_TIME 5.0f                                                                                         //(5s达到最大线速度)
#define WHEEL_MAX_LINE_VELOCITY_ACCELERATION ((WHEEL_MAX_LINE_VELOCITY - WHEEL_MIN_LINE_VELOCITY) / WHEEL_LINE_VELOCITY_ACCELERATION_TIME) //轮子最大线加速度(mm/s2)

//定义车体的最大线加速度、角加速度，最大最小线速度、角速度
#define AGV_MAX_LINE_ACCELERATION_ACCELERATION WHEEL_MAX_LINE_VELOCITY_ACCELERATION //即轮子最大线加速度
#define AGV_MAX_LINE_VELOCITY WHEEL_MAX_LINE_VELOCITY                               //即轮子最大线速度
#define AGV_MIN_LINE_VELOCITY WHEEL_MIN_LINE_VELOCITY                               //即轮子最小线速度

#define AGV_MAX_ANGULAR_ACCELERATION_ACCELERATION WHEEL_MAX_ANGULAR_ACCELERATION *WHEEL_DIAMETER / 2 / (DISTANCE_OF_WHEEL_X_AXES + DISTANCE_OF_WHEEL_Y_AXES) //参考运动学公式
#define AGV_MAX_ANGULAR_VELOCITY WHEEL_MAX_ANGULAR_VELOCITY *WHEEL_DIAMETER / 2 / (DISTANCE_OF_WHEEL_X_AXES + DISTANCE_OF_WHEEL_Y_AXES)                      //AGV转向时最大角速度
#define AGV_MIN_ANGULAR_VELOCITY WHEEL_MIN_ANGULAR_VELOCITY *WHEEL_DIAMETER / 2 / (DISTANCE_OF_WHEEL_X_AXES + DISTANCE_OF_WHEEL_Y_AXES)                      //AGV转向时最小角速度

#define LINE_SLOWEST_DISTANCE	20.0f	//最低速度移动20mm
#define ANGULAR_SLOWEST_DISTANCE 5.0f	//最低速度移动5°
