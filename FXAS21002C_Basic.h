
#ifndef FXAS21002C_BASIC_H
#define FXAS21002C_BASIC_H
//#include "I2C_device.h"
#include "i2cdevice.h"

class FXAS21002CBasic: protected i2cdevice
{
protected:
   float sensitivity;
   float gyro_offset_[3] = {2.79,-0.12,0.03};
   

public:
   FXAS21002CBasic() =default;
   FXAS21002CBasic(byte address,TwoWire *wire);

  
   void updateGyroData(float* gyro_data);
   void changeODR(int odr);
   void changeRange(int fsr);
   void loadCalibrationData(byte eeprom_address);
  

   void changePowerMode(byte mode);
   byte readPowerMode();
   void waitTill(byte mode);

};
#endif


