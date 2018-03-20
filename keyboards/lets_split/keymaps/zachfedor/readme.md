# Let's Split Keymap

My first ortholinear layout featuring:

- audio for startup and layer switching
- programmer-friendly symbol placement 
- one-handed numpad
- mouse control


## Flashing

In qmk's root directory, run the following commands:

```shell
# compile the hex file
make lets_split/rev2:zachfedor

# flash the Pro Micro
make lets_split/rev2:zachfedor:avrdude

# reset the Pro Micro when prompted by shorting RST and GND pins
```

