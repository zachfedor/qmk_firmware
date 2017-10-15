# Let's Split Keymap

My first ortholinear layout featuring:

- audio for startup and layer switching
- programmer-friendly symbol placement 
- one-handed numpad
- mouse control


## Flashing

In this directory, run the following commands:

```shell
# compile the hex file
make rev2-zach

# move to build directory
cd ../../../.build

# ensure your Pro Micro is in the bootloader mode
ls /dev/tty*

# flash the Pro Micro pointing at the proper /dev/tty* port
avrdude -p atmega32u4 -c avr109 -P /dev/tty.usbmodem1411 -U flash:w:lets_split_rev2_zachr.hex
```

