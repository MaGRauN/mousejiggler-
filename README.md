# Create a custom Mouse Jiggler

Create a **Mouse Jiggler** using a **Digispark** device or a similar microcontroller and Arduino IDE.

> 1. On Arduino IDE click on File - Preferences.
> 
>    1.1 On "Additional Boards Manager URLs", include this address "http://digistump.com/package_digistump_index.json".
> 
>    1.2. Click on "OK".
> 
> 2. Click on Tools - Board:* - Boards Manager...
> 
>    2.1. Search and install "Digistump AVR Boards".
> 
> 3. Click Click on Tools - Board:*.
> 
>    3.1. Click on "Digistump AVR Boards" and select "Digispark(Default - 16.5mhz).
 
If you want to customize the USB device identifier displayed in device manager, edit the ..\libraries\DigisparkMouse\usbconfig.h file to modify the USB identifier.

Update the following lines with your desired values:

>For Vendor ID: #define USB_CFG_VENDOR_ID 0x??, 0x??
>
>For Device ID: #define USB_CFG_DEVICE_ID 0x??, 0x??
>
> For Vendor Name: #define USB_CFG_VENDOR_NAME     '?','?'...

The lenght of the Vendor Name: #define USB_CFG_VENDOR_NAME_LEN 2

> For Device Name: #define USB_CFG_DEVICE_NAME     '?','?'...
> 
> The lenght of the Device Name: #define USB_CFG_DEVICE_NAME_LEN 2
> 
> For Serial number: #define USB_CFG_SERIAL_NUMBER   '?','?'...

The lenght of the Serial number: #define USB_CFG_SERIAL_NUMBER_LEN   2

To convert the VID (Vendor ID) and PID (Product ID) to Little Endian format, simply swap the byte order:

Example (Logitech Logi Bolt Receiver):

> Original VID: 0x046D
> 
>Little Endian: 0x6D, 0x04

>Original PID: 0xC548
>
>Little Endian: 0x48, 0xC5

The updated lines will look like this:

>#define USB_CFG_VENDOR_ID 0x6D, 0x04
>
>#define USB_CFG_DEVICE_ID 0x48, 0xC5
>
>#define USB_CFG_VENDOR_NAME     'L','o','g','i','t','e','c','h'
>
>#define USB_CFG_VENDOR_NAME_LEN 8
>
>#define USB_CFG_DEVICE_NAME     'U','S','B',' ','R','E','C','E','I','V','E','R'
>
>#define USB_CFG_DEVICE_NAME_LEN 12
>
>#define USB_CFG_SERIAL_NUMBER   'U','S','B',' ','R','E','C','E','I','V','E','R'
>
>#define USB_CFG_SERIAL_NUMBER_LEN   12

Save the ..\libraries\DigisparkMouse\usbconfig.h file.

Compile and upload the mousejiggler.ino code to your Digispark or a similar device with Micronucleus firmware.

Use a push button on GND and PIN0 to enable or disable the jiggler.

Enjoy your Mouse Jiggler!
