#pragma once
#include "Gyro.h"

/*
* 该陀螺仪为瑞芬科技的TL740D
*/

class TL740D_Class : public Gyro_Class
{
  public:
	TL740D_Class() : Gyro_Class() {}
	~TL740D_Class() = default;

	void Read_Data(void) override;	//读传感器数据
	bool Analyze_Data(void) override; //解析数据
  private:
	int32_t BCD2DEC(const uint8_t *source); //将TL740返回的BCD编码的数转换成十进制
};