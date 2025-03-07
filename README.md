Create a Mouse Jiggler using a Digispark device or a similar microcontroller.

Edit the ..\libraries\DigisparkMouse\usbconfig.h file to modify the USB identifier.

Update the following two lines with your desired values:

For Vendor ID: #define USB_CFG_VENDOR_ID 0x??, 0x??

For Device ID: #define USB_CFG_DEVICE_ID 0x??, 0x??

To convert the VID (Vendor ID) and PID (Product ID) to Little Endian format, simply swap the byte order:

Example (Logitech Logi Bolt Receiver):

Original VID: 0x046D
Little Endian: 0x6D, 0x04

Original PID: 0xC548
Little Endian: 0x48, 0xC5

The updated lines will look like this:

#define USB_CFG_VENDOR_ID 0x6D, 0x04
#define USB_CFG_DEVICE_ID 0x48, 0xC5

Save the ..\libraries\DigisparkMouse\usbconfig.h file, then compile and upload the mousejiggler.ino code to your Digispark or a similar device with Micronucleus firmware.

Enjoy your Mouse Jiggler!
