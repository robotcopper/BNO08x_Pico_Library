#ifndef UTILS_H
#define UTILS_H
#include <cstdio>
#include <math.h>
#include "hardware/i2c.h"
#include "hardware/gpio.h"

namespace CONFIG {

    inline uint I2C_TIMEOUT_US = 5000;

    constexpr uint I2C_BAUD_RATE = 100 * 1000; // 100kHz
    constexpr uint I2C_SDA_PIN = PICO_DEFAULT_I2C_SDA_PIN; // GP4 pin 6;
    constexpr uint I2C_SCL_PIN = PICO_DEFAULT_I2C_SCL_PIN; // GP5 pin 7;

    constexpr uint8_t BNO08X_ADDR = 0x4A;

}

extern volatile bool ESCdelayInProgress;
extern volatile bool ESCirqTriggered;

void initI2C(i2c_inst_t* &i2c_port, bool force_recovery);

void handleI2CError(i2c_inst_t* &i2c_port);

void i2cBusRecovery(uint sda_pin, uint scl_pin);

float wrap_pi(const float heading);

bool reserved_addr(uint8_t addr);

void scan_i2c_bus();
void initMotorMonitorPins();

void handlerMotorController(uint gpio, uint32_t events);

bool non_blocking_delay_us(uint32_t delay_us);

void toggleMotorSleepPin();

#endif // UTILS_H
