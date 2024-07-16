# BNO08x Raspberry Pi Pico RP2040 Library

This library is a refactoring of [Mark Mellors](https://github.com/markmellors)' work who made the BNO08x IMU compatible with the Raspberry Pi Pico RP2040.

## Description

This library was designed to work in I2C with the BNO08x.
By default the i2c0 and th GP4 and GP5 are used in this project.

## Installation

To use this library, clone the repository into your Raspberry Pi Pico RP2040 project directory:

```bash
git clone https://github.com/robotcopper/BNO08x_Pico_Library.git
```

Then include it in your project's CMakeLists.txt file:

```cmake
add_subdirectory(
	BNO08x_Pico_Library
)

target_link_libraries(main
    BNO08x_Pico_Library
)
```

## Usage

Here's a simple example demonstrating how to use the library to initialize the sensor and read orientation data:

```cpp
#include "bno08x.h"

i2c_inst_t* i2c_port0;
initI2C(i2c_port0, false);
//set up IMU
while (IMU.begin(CONFIG::BNO08X_ADDR, i2c_port0)==false) {
    printf("BNO08x not detected at default I2C address. Check wiring. Freezing\n");
    scan_i2c_bus();
    sleep_ms(1000);
}
IMU.enableRotationVector();

while (true) {

    float yaw = 0.0f;

    if (IMU.getSensorEvent() == true) {
        if (IMU.getSensorEventID() == SENSOR_REPORTID_ROTATION_VECTOR) {
            yaw = IMU.getYaw();
        }
    }

    printf("Yaw: %.2f rad\n", yaw);

}

```

## Credits and Contributions

1. **Original Developer: SparkFun** :
   - Nathan Seidle @ SparkFun Electronics
   - Date: December 28, 2017

   &nbsp;&nbsp;&nbsp;&nbsp; **Adjustments** :
   - Pete Lewis @ SparkFun Electronics
   - Date: June 2023
   - To incorporate the CEVA Sensor Hub Driver: [CEVA SH2](https://github.com/ceva-dsp/sh2)

   &nbsp;&nbsp;&nbsp;&nbsp; **Links** :
   - Link to SparkFun_BNO08x_Arduino_Library GitHub repository: [SparkFun_BNO08x_Arduino_Library](https://github.com/sparkfun/SparkFun_BNO08x_Arduino_Library)

2. **Porting** :
   - **Use of External Code** :
        - Code from Adafruit BNO08x Arduino Library by Bryan Siepert for Adafruit Industries: [Adafruit_BNO08x](https://github.com/adafruit/Adafruit_BNO08x)
        - Use of I2C and SPI read/write functions and code from Adafruit BusIO library: [Adafruit_BusIO](https://github.com/adafruit/Adafruit_BusIO)
   - Ported by [Mark Mellors](https://github.com/markmellors) for use on RP2040