# Arduino Busy Light

A busy light to indicate your availability stauts to co-workers. Intended to prevent unwanted interuptions. Photos at the bottom of this file.

## Build Overview

This is a basic overview based on the way I built my busy light. I used a SparkFun RedBoard for this build but an Arduino Uno would be very similar.

#### LED

The RGB led is controlled by holding the momentary switch (arcade button) for different lengths of time. You can see the various times at the top of the busy_light.ino file.

The while loop counts how long the switch has been pressed and then sets the color of the led based on that time. 

#### Wiring

[Schematic for RGB LED](schematics/rgb-led.pdf)

The LED is connected to pins 3,5,6. The rgb legs of the led are connected to the pins in this order (Red-3,Green-5,Blue-6). 

The ground pin is connected to the ground of the momentary switch, both connect to the ground on the RedBoard.

The common terminal on the switch is connected to pin 2 on the RedBoard.

![Wiring Schematic][schematic]

#### Case

The case is just a wooden box from the local craft store that I drilled some holes into for the power cord and the arcade button. I made some risers for the circuit board and the RedBoard to make room for routing wires.

#### Images

![Red Light On][red]
![Green Light On][green]
![Blue Light On][blue]
![Case Opened][case-opened]
![Case Closed][case-closed]
![Inline Power Switch][power-switch]

[schematic]:schematics/wiring-schematic.png
[red]: images/red.jpg
[green]:images/green.jpg
[blue]:images/blue.jpg
[case-opened]:images/case-opened.jpg
[case-closed]:images/case-closed.jpg
[power-switch]:images/power-switch.jpg