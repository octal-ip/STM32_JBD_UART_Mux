# STM32_JBD_UART_Mux
This project provides Platform.io code for building firmware for a STM32F103, allowing a JBD BMS to communicate with both its Bluetooth adaptor and an external ESP for data logging and configuration.

All serial communication from the Bluetooth adaptor or ESP is forwarded to the BMS.
All data from the BMS is forwarded to both the Bluetooth adaptor and ESP. Simple!
