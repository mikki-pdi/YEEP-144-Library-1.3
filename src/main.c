#include "YEEP144.h"
#include "stm32h563xx.h"
#include "stm32h5xx_hal.h"
#include "YEEP144_DebugUART.h"
#include "YEEP144_BluetoothUART.h"
#include "string.h"
//IR Libraries
#include "YEEP144_I2C.h"
#include "YEEP144_GP2Y0E02B.h"
//US Libraries
#include "YEEP144_HCSR04.h"
//IR Receiver Beacon Library
#include "YEEP144_TSOP4838.h"


//Variables

int main(void){
    //Function Initializations
    YEEP144_Init();
    YEEP144_DebugUART_Init();
    YEEP144_I2C_Init();
    YEEP144_Ultrasonic1_Init();
    YEEP144_TSOP4838_Init();

    //Init code
    YEEP144_DebugUART_printf("Program Start Success!");
    YEEP144_I2C_MuxSelect(0);
    //Loop
    while(1) {
        //IR Beacon Receiver
        if(YEEP144_TSOP4838_Received()){
                uint32_t code = YEEP144_TSOP4838_Read();
                YEEP144_DebugUART_printf("IR received: %02X\r\n", code);
            }

        HAL_Delay(1000);
    }
}