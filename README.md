# teensy_MCUX

This code is for porting Teensy 4.0 to MCUXpresso and running MCUXpresso codes on it

These codes are examples for the i.MX RT 1060 Eval board modified to run on teensy 4.0 .

Details related to the modifications are posted on the pjrc forum. 

Link:https://forum.pjrc.com/threads/57568-Teensy-4-compatible-hex-files-using-MCUXpresso-IDE?

## Example codes

* LED Blink code blinks LED and sends Serial debugging data on pin 24(LPUART1 TX 115200 baud default). 

* Ethernet Library demonstrates the basic working of the Wiznet W5100 chip and teensy SPI interface (Limited to 8Mhz Clock for Wiznet W5100). This code is for testing purposes only and does not have any Protocol funtionality other than basic interfacing with W5x00.

* Wiznet API file impliments DNS, DHCP, HTTP Server and more using the API provided by the W5100 manufacturer.
