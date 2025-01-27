# circuitdigest
**Code for Face recognition and acoustic NFC based access control system concept**
To implement an access control system that combines face recognition and OFDM-based acoustic data transmission on the MAX78000 Feather development board, this solution leverages the MAX78000 microcontroller's Convolutional Neural Network (CNN) accelerator for efficient face recognition and peripherals for handling audio input and output.

Start by setting up the MAX78000 Feather development environment by installing the IDE and the necessary drivers and the Maxim Integrated SDK. This setup integrates advanced technologies for biometric face recognition and secure communication using acoustic signals, Highlights of the Access Control System:
**Considerations:**
Ensure the SSD1306 driver is compatible with the setup and properly linked in the project.
If OLED uses SPI instead of I2C, modify the initialization and communication functions accordingly.
