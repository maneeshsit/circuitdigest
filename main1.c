#include "mxc_device.h"
#include "board.h"
#include "nvic_table.h"
#include "mxc_delay.h"
#include "camera.h"
#include "cnn.h"
#include "i2c.h"
#include "ssd1306.h"
#include "ofdm.h"

void setup() {
    // Initialize the board, camera, CNN, I2C, and OLED
    SystemInit();
    camera_init();
    cnn_init();
    cnn_load_model();
    
    i2c_init();
    ssd1306_init();
}

void loop() {
    capture_image();
    int person_id = recognize_face();
    
    if (person_id != -1) {
        char message[32];
        snprintf(message, sizeof(message), "Recognized ID: %d", person_id);
        display_message(message);
        
        ofdm_transmit("password_request");
        char received_password[16];
        ofdm_receive(received_password);
        
        if (strcmp(received_password, "expected_password") == 0) {
            display_message("Access Granted");
        } else {
            display_message("Access Denied");
        }
    } else {
        display_message("Unknown Person");
    }
    
    MXC_Delay(MSEC(1000));
}

int main(void) {
    setup();
    while (1) {
        loop();
    }
    return 0;
}
