/*步态参数设置*/
#include "gait_param.h"

//当前生效PID参数
LegGain Gait_Gains = {15.0f, 0.3f, 20.0f, 0.05f};

//各状态PID参数表（明确大小END+1）
LegGain state_gait_gains[END+1] = {
    //{kp_pos, kd_pos， kp_spd, kd_spd}，
    {15.0f, 0.3f, 20.0f, 0.05f},  // NORMAL
    {18.0f, 0.5f, 16.0f, 0.08f},  // CLIMBING
    {12.0f, 0.2f, 22.0f, 0.03f},  // TURN_LEFT
    {12.0f, 0.2f, 22.0f, 0.03f},  // TURN_RIGHT
    {14.0f, 0.4f, 18.0f, 0.06f},  // WALK
    {10.0f, 0.15f, 25.0f, 0.02f},  // TROT
    {20.0f, 0.8f, 12.0f, 0.1f},  // BRIDGE
    {22.0f, 1.0f, 10.0f, 0.15f},  // STOP
    {15.0f, 0.3f, 20.0f, 0.05f},  // RELEASE
    {16.0f, 0.4f, 18.0f, 0.06f},  // JUMP_GROUND
    {16.0f, 0.4f, 18.0f, 0.06f},  // JUMP_UPHILL
    {18.0f, 0.5f, 15.0f, 0.08f},  // START
    {15.0f, 0.3f, 20.0f, 0.05f},  // END
};

//当前生效轨迹参数
Cycloid_Generator_Param_t gait_params = {20.0f, 0.0f, 3.0f, 0.00f, 0.25f, 0.3f};
// typedef struct
//    {
//        float body_height;    //身体到地面的距离 (cm)
//        float step_length;    //一步的距离 (cm)
//        float up_amp;         //上部振幅y (cm)
//        float down_amp;       //下部振幅 (cm)
//        float flight_percent; //摆动相百分比(%)
//        float freq;           //一步的频率 (Hz)
//    } Cycloid_Generator_Param_t;

Cycloid_Generator_Param_t state_gait_params[END + 1] = {
	  // NORMAL
    {16.0f, 0.0f, 0.00f, 0.00f, 0.0f, 0.1f},    
                                               
		// CLIMBING 爬坡
    {20.3f, 7.30f, 6.50f, 0.1f, 0.3f, 3.5f}, 
		//{18.0f, 10.00f, 3.3f, 0.0f, 0.25f, 1.0f},
		
		 // TURN_LEFT 
    {20.0f, 7.0f, 2.5f, 2.00f, 0.25f, 3.0f},
		
		// TURN_RIGHT
    {20.0f, 7.0f, 2.5f, 2.00f, 0.25f, 3.0f},       
		
		// WALK
		{20.3f, 7.30f, 6.50f, 0.1f, 0.45f, 3.5f}, 

		// TROT（低趴）
    {13.99f, 6.00f, 2.5f, 0.1f, 0.5f, 3.5f},   
		
		
		// BRIDGE闪光黑子
    {19.0f, 10.00f, 3.3f, 0.1f, 0.4f, 0.7f}, 
                                            
		// STOP    
    {20.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f},   
		
    {NAN, NAN, NAN, NAN, NAN, NAN},           // RELASE
    {NAN, NAN, NAN, NAN, NAN, NAN},           // JUMP_GROUND
    {NAN, NAN, NAN, NAN, NAN, NAN},           // JUMP_UPHILL
    {NAN, NAN, NAN, NAN, NAN, NAN},           // START
    {NAN, NAN, NAN, NAN, NAN, NAN},           // END
};

//四腿独立参数（运行时）
DetachedParam detached_params;

//四腿独立参数预设表
DetachedParam state_detached_params[4] = {
    //TROT（索引0）
    {                                           // TROT 对角小跑
     {21.0f, 14.0f, 3.00f, 2.00f, 0.25f, 4.0f}, //   {21.0, 12.0, 3.00, 2.00, 0.25, 4.0}
     {21.0f, 14.0f, 3.00f, 2.00f, 0.25f, 4.0f},
     {21.0f, 14.0f, 3.00f, 2.00f, 0.25f, 4.0f},
     {21.0f, 14.0f, 3.00f, 2.00f, 0.25f, 4.0f}},

    {                                          // CLIMBING	爬坡
     {16.0f, 9.0f, 3.00f, 1.00f, 0.25f, 3.6f}, //小步子可以迈上去
     {16.0f, 9.0f, 3.00f, 1.00f, 0.25f, 3.6f},
     {18.0f, 9.0f, 3.00f, 1.00f, 0.25f, 3.6f},
     {18.0f, 9.0f, 3.00f, 1.00f, 0.25f, 3.6f}},
    {
        {22.0f, 7.00f, 4.0f, 2.00f, 0.28f, 3.0f}, // TURN_LEFT
        {22.0f, 7.00f, 4.0f, 2.00f, 0.28f, 3.0f}, // TURN_LEFT
        {22.0f, 7.00f, 4.0f, 2.00f, 0.28f, 3.0f}, // TURN_LEFT
        {22.0f, 7.00f, 4.0f, 2.00f, 0.28f, 3.0f}  // TURN_LEFT
    },
    {
        {22.0f, 7.00f, 4.0f, 2.00f, 0.28f, 3.0f}, // TURN_RIGHT
        {22.0f, 7.00f, 4.0f, 2.00f, 0.28f, 3.0f}, // TURN_RIGHT
        {22.0f, 7.00f, 4.0f, 2.00f, 0.28f, 3.0f}, // TURN_RIGHT
        {22.0f, 7.00f, 4.0f, 2.00f, 0.28f, 3.0f}  // TURN_RIGHT
    },

};

//遥控调参默认值
DetachedParam RcDetachedParam = {
    {21.0f, 0.0f, 3.00f, 2.00f, 0.25f, 3.2f},
    {21.0f, 0.0f, 3.00f, 2.00f, 0.25f, 3.2f},
    {21.0f, 0.0f, 3.00f, 2.00f, 0.25f, 3.2f},
    {21.0f, 0.0f, 3.00f, 2.00f, 0.25f, 3.2f}};
//系统状态
Robohorse_State NowState = STOP; //当前运行状态
Robohorse_Direction NowDir = POSITIVE;

Stanford_Type_Lite_Data_t Gait_Data[4]; // 步态数据
Cycloid_Generator_t Cycloid_Gen[4]; // 摆线生成器
float Aim_Angle[8]; //目标角度，单位为弧度rad
volatile uint8_t Is_Aim_Angle_Get = 0; //是否已经获得到目标角度
float Last_Time = 0.0f; //上次计算时间
uint8_t Mode_Change_Flag = 1; //模式切换标志

