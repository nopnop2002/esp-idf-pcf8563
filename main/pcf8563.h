#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <stdbool.h>
#include "driver/i2c.h"

#include "i2cdev.h"

#define PCF8563_ADDR 0x51 //!< I2C address
// In () https://github.com/lewisxhe/PCF8563_Library/blob/master/src/pcf8563.h
#define PCF8563_ADDR_STATUS1 0x00
#define PCF8563_ADDR_STATUS2 0x01
#define PCF8563_SEC_REG      0x02
#define PCF8563_MIN_REG         (0x03)
#define PCF8563_HR_REG          (0x04)
#define PCF8563_DAY_REG         (0x05)
#define PCF8563_WEEKDAY_REG     (0x06)
#define PCF8563_MONTH_REG       (0x07)
#define PCF8563_YEAR_REG        (0x08)
#define PCF8563_ALRM_MIN_REG    (0x09)
#define PCF8563_SQW_REG         (0x0D)
#define PCF8563_TIMER1_REG      (0x0E)
#define PCF8563_TIMER2_REG      (0x0F)

#define PCF8563_VOL_LOW_MASK    (0x80)
#define PCF8563_minuteS_MASK    (0x7F)
#define PCF8563_HOUR_MASK       (0x3F)
#define PCF8563_WEEKDAY_MASK    (0x07)
#define PCF8563_CENTURY_MASK    (0x80)
#define PCF8563_DAY_MASK        (0x3F)
#define PCF8563_MONTH_MASK      (0x1F)
#define PCF8563_TIMER_CTL_MASK  (0x03)

#define PCF8563_ALARM_AF        (0x08)
#define PCF8563_TIMER_TF        (0x04)
#define PCF8563_ALARM_AIE       (0x02)
#define PCF8563_TIMER_TIE       (0x01)
#define PCF8563_TIMER_TE        (0x80)
#define PCF8563_TIMER_TD10      (0x03)

#define PCF8563_NO_ALARM        (0xFF)
#define PCF8563_ALARM_ENABLE    (0x80)
#define PCF8563_CLK_ENABLE      (0x80)

enum {
    PCF8563_CLK_32_768KHZ,
    PCF8563_CLK_1024KHZ,
    PCF8563_CLK_32HZ,
    PCF8563_CLK_1HZ,
    PCF8563_CLK_MAX
};

uint8_t bcd2dec(uint8_t val);
uint8_t dec2bcd(uint8_t val);
esp_err_t pcf8563_init_desc(i2c_dev_t *dev, i2c_port_t port, gpio_num_t sda_gpio, gpio_num_t scl_gpio);
esp_err_t pcf8563_reset(i2c_dev_t *dev);
esp_err_t pcf8563_set_time(i2c_dev_t *dev, struct tm *time);
esp_err_t pcf8563_get_time(i2c_dev_t *dev, struct tm *time);
// New functions: Need additional testing
uint8_t check_err(esp_err_t res, uint8_t * data, uint16_t size, char * op);

uint8_t pcf8563_get_flags(i2c_dev_t *dev);                // Gets and clears Flags
void pcf8563_set_clock_out(i2c_dev_t *dev, uint8_t mode); // Not tested
void pcf8563_set_timer(i2c_dev_t *dev, uint8_t val, uint8_t freq); // Sets an interrupt
void pcf8563_enable_timer(i2c_dev_t *dev);
esp_err_t pcf8563_enable_clock(i2c_dev_t *dev, uint8_t freq);

uint8_t pcf8563_get_timer(i2c_dev_t *dev);
esp_err_t pcf8563_set_alarm(i2c_dev_t *dev, struct tm *time);
esp_err_t pcf8563_enable_alarm(i2c_dev_t *dev);

#ifdef __cplusplus
}
#endif
