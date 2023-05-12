
#ifndef FXAS21002C_BASIC_H
#define FXAS21002C_BASIC_H
#include "i2cdevice.h"

class FXAS21002CBasic: protected i2cdevice
{
protected:
   float sensitivity;
   float gyro_offset_[3] = {0.075  , 0.08 , 17.87};
   

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


