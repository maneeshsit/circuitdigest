#include "mxc_device.h"
#include "dma.h"
#include "nvic_table.h"
#include "i2s.h"
#include "ofdm.h"

// OFDM Transmit function
void ofdm_transmit(const char* password) {
    // Convert password to OFDM signal and transmit via I2S
    uint8_t* ofdm_signal = ofdm_modulate(password);
    i2s_transmit(ofdm_signal, sizeof(ofdm_signal));
}

// OFDM Receive function
void ofdm_receive(char* buffer) {
    // Receive the OFDM signal via I2S
    uint8_t ofdm_signal[MAX_SIGNAL_SIZE];
    i2s_receive(ofdm_signal, sizeof(ofdm_signal));
    
    // Demodulate the signal to retrieve the password
    ofdm_demodulate(ofdm_signal, buffer);
}

void access_control_system() {
    while (1) {
        capture_image();
        int person_id = recognize_face();
        
        if (person_id != -1) {
            printf("Recognized person ID: %d\n", person_id);
            ofdm_transmit("password_request");
            char received_password[16];
            ofdm_receive(received_password);
            
            if (strcmp(received_password, "expected_password") == 0) {
                printf("Access granted\n");
            } else {
                printf("Access denied\n");
            }
        } else {
            printf("Unknown person\n");
        }
        
        MXC_Delay(MSEC(1000));
    }
}

int main(void) {
    setup();
    access_control_system();
    return 0;
}
