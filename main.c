#include "mxc_device.h"
#include "i2c.h"
#include "ssd1306.h"  // Include your SSD1306 driver header file

// I2C configuration for the OLED
#define I2C_BUS MXC_I2C1  // Assuming I2C1 is used
#define SSD1306_ADDR 0x3C // Common I2C address for SSD1306

void i2c_init(void) {
    mxc_i2c_req_t i2c_req = {
        .i2c = I2C_BUS,
        .addr = SSD1306_ADDR,
        .speed = MXC_I2C_FAST,
    };
    
    MXC_I2C_Init(I2C_BUS, 1, 0);
    MXC_I2C_SetFrequency(I2C_BUS, MXC_I2C_FAST_MODE);
    MXC_I2C_SetTimeout(I2C_BUS, MXC_I2C_TIMEOUT_50KHZ);
    MXC_I2C_MasterTransaction(&i2c_req);
}

void ssd1306_init(void) {
    ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_ADDR);
    ssd1306_clear_display();
}

void display_message(const char* message) {
    ssd1306_clear_display();
    ssd1306_set_textsize(1);
    ssd1306_set_textcolor(WHITE);
    ssd1306_set_cursor(0, 0);
    ssd1306_print(message);
    ssd1306_display();
}
