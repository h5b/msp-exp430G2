A collection of examples targeted at TI's [MSP430 LaunchPad Revision 1.5] (http://www.ti.com/tool/msp-exp430g2#2)  
to be used with the MSP-GCC toolchain.

## Board
![MSP430 LaunchPad Rev. 1.5](https://github.com/h5b/msp-exp430G2/raw/master/doc/img/MSPExP430G2Rev15.jpg)

## Sources

* __blink_led_pwm__ implements an PWM example to flash the Green LED (PIN 1.6)  
  of the MSP430 LaunchPad. Flashing the LED is accomplished by making use of  
  Timer_A's ability two keep track of two Compare Match Values. With one being  
  used as PWM Duty Cycle and the other one to control the PWM Period.

* __blink_led_sw__ implements an example to let the Green LED (PIN 1.6) of the  
  MSP430 LaunchPad blink once per second. The delay is accomplished via  
  a software delay provided by the __\_\_delay_cycles()__ function.

* __blink_led_timerA__ implements an example in the veins of __blink_led_wdt__  
  to let the Green LED (PIN 1.6) of the MSP430 LaunchPad blink  
  once per second. Instead of utilizing the Watchdog functionality the System  
  Timer_A is configured to run in Compare Match Mode.

* __blink_led_wdt__ is an example in the veins of __blink_led_sw__  to let the  
  Green LED (PIN 1.6) of the MSP430 LaunchPad blink once per second.  
  Although using a timer-based delay which is accomplished via the builtin  
  Watchdog functionality.

* __led_pwm__ very rough example of Brightness Control of the Green LED  
  (PIN 1.6) of the MSP430 LaunchPad via PWM.  
  Timer_A is configured to run in Compare Match Mode.  
  Eventually the stepping of the PWM Duty Cycle has to be non-linear as  
  the human eye senses brightness approximately logarithmically over  
  a wide range.


## Schematics

### Board

<pre>
,--------------------------------------------------------------------.
|                             Xin   TST   1.7   2.5        GND   Vcc |
|                          [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]  [ ][ ][ ] |
|                          GND   Xout  RST   1.6      2.3     GND    |
|                                                                    |
|                                                                    |
|                                             L                      |
|                                             E                      |
|                                       S     D                      |
|                           |  |  |  |  1  |  2  |  |  |             |
|                         ,-+--+--+--+--+--+--+--+--+--+-.           |
|                         |                              |           |
|                          `         M430G2452           |           |
|                         |'                             |           |
|                         `-+--+--+--+--+--+--+--+--+--+-'           |
|                           |  L  |  |  S  |  |  |  |  |             |
|                              E        2                            |
|                              D                                     |
|                              1                                     |
|                                                                    |
|                                                                    |
|                          Vcc   Rx Tx          2.0   2.2            |
|                          [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]            |
|                             1.0            1.5                     |
`--------------------------------------------------------------------'
</pre>
