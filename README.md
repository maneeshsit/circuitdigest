# circuitdigest
**Code for Face recognition and acoustic NFC based access control system concept**
To implement an access control system that combines face recognition and OFDM-based acoustic data transmission on the MAX78000 Feather development board, this solution will leverage the MAX78000 microcontroller's Convolutional Neural Network (CNN) accelerator for efficient face recognition and peripherals for handling audio input and output.
To set up the MAX78000 Feather development environment by installing the IDE and the necessary drivers and the Maxim Integrated SDK.
This setup integrates advanced technologies for biometric face recognition and secure communication using acoustic signals,
Highlights of the Access Control System:

Convolutional Neural Network (CNN) Accelerator:
Facilitates fast image recognition using neural network processing.
CMOS VGA Image Sensor:
Captures images, likely used for face recognition.
Digital Microphone:
Enables acoustic communication or NFC (Near Field Communication) through sound waves.
Acoustic NFC:
Provides access control via sound-based NFC technology, potentially communicating with devices acoustically for identification or authentication.
LiPo Charger:
Power management feature to recharge a LiPo (Lithium Polymer) battery, making the system portable.
Micro SD Card Slot:
Stores captured images for later processing or access control logs and images.
Serial Terminal for LCD or OLED Display:
Can interface with a display module, such as LCD or OLED, for visual feedback or system monitoring.

Below are the steps for implementing the solution.

Steps:
Implementing Face Recognition Using the CNN Accelerator.
Implementing OFDM-Based Acoustic Data Transmission (Dhwani).
Setup the SSD1306 OLED Display, adding the SSD1306 Library.
Integrating the OLED Display in the Access Control System.
Compiling and Uploading the Code.
Testing the implementation and making necessary changes to the code and redeploying the code.
Attached is the circuit diagram for the MAX78000 Feather development board with the following components:
128x64 OLED Display (SSD1306) (using I2C communication)
Camera Module (connected to the MAX78000 for face recognition)
Microphone/Speaker (for Dhwani OFDM-based communication)

Below is the description of the component's connection.
Circuit Diagram Connections:

1. MAX78000 Feather Board:

Power the board using USB (VCC) or an external 3.3V source.
GND is the ground connection.

2. OLED Display (SSD1306):

SCL (I2C Clock): Connect to SCL pin on the MAX78000 (usually on pin D2 or another I2C-compatible pin).
SDA (I2C Data): Connect to SDA pin on the MAX78000 (usually on pin D3 or another I2C-compatible pin).
VCC: Connect to 3.3V on the MAX78000.
GND: Connect to GND on the MAX78000.

3. Camera Module:

If using a MAX78000 compatible camera module (e.g., Arducam or OV7670):
Camera Data Pins: Connect the camera data pins to the respective GPIO pins on the MAX78000 for data transfer.
Camera Power (VCC): Connect to 3.3V from the MAX78000.
Camera GND: Connect to GND on the MAX78000.
Camera I2C (if needed): Connect SCL and SDA to the same I2C bus as the OLED.

4. Microphone (for Acoustic NFC):

Microphone Output: Connect to an ADC input pin on the MAX78000.
Microphone Power: Connect to 3.3V or VCC on the MAX78000.
Microphone GND: Connect to GND on the MAX78000.

5. Speaker (for Acoustic NFC):

Speaker Output: Connect to a PWM output pin or a DAC pin (if available) on the MAX78000 for sound generation.
Speaker Power: Connect to 3.3V or VCC.
Speaker GND: Connect to GND.

Component Pins Summary:

OLED Display (SSD1306):
SDA → MAX78000 SDA (D3).
SCL → MAX78000 SCL (D2).
VCC → MAX78000 3.3V.
GND → MAX78000 GND.
Camera Module:
Data Pins → GPIO pins on MAX78000 (e.g., P0, P1, P2...).
VCC → MAX78000 3.3V.
GND → MAX78000 GND.
I2C SDA/SCL (if applicable) → MAX78000 SDA (D3) and SCL (D2).
Microphone:
Output → ADC pin on the MAX78000.
VCC → MAX78000 3.3V.
GND → MAX78000 GND.
Speaker:
PWM/DAC Output → PWM/DAC pin on MAX78000.
VCC → MAX78000 3.3V.
GND → MAX78000 GND.

**Step 1:** Setup the SSD1306 OLED Display
Assuming we are using the I2C interface, first need to set up the I2C communication and initialize the SSD1306 display.

**Step 2: **Adding the SSD1306 Library
We need to include or write a driver for the SSD1306 OLED display. Here’s a simplified version assuming a library is available:

**Step 3:** Integrate the OLED Display in the Access Control System
Modify the access control system to display relevant messages on the OLED display:

**Explanation:
**
**I2C Initialization:** The i2c_init() function sets up the I2C communication on the MAX78000. Adjust the I2C bus and address according to your setup.

**SSD1306 Initialization: **The ssd1306_init() function initializes the OLED display and clears it.

**Displaying Messages: **The display_message() function prints messages to the OLED display.

**Access Control Integration:** In the loop() function, the OLED display shows different messages depending on the face recognition result and the received password.

**Considerations:**
Ensure the SSD1306 driver is compatible with the setup and properly linked in the project.
If OLED uses SPI instead of I2C, modify the initialization and communication functions accordingly.
