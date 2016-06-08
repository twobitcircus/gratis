// Copyright 2013-2015 Pervasive Displays, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
// express or implied.  See the License for the specific language
// governing permissions and limitations under the License.


#if !defined(EPD_IO_H)
#define EPD_IO_H 1
#include <mraa.h>

#define panel_on_pin  13
#define border_pin    20
#define discharge_pin 25
#define reset_pin     0
#define busy_pin      33

#define pwm_pin       (-1) // sysfs pin GP13     // arduino 5

#define SPI_DEVICE    "/dev/spidev5.1"
#define SPI_BPS       8000000

#endif

/*
const int Pin_PANEL_ON = 5;
const int Pin_BORDER = 10;
const int Pin_DISCHARGE = 4;
const int Pin_PWM = 5;    // Not used by COG v2
const int Pin_RESET = 6;
const int Pin_BUSY = 7;
const int Pin_EPD_CS = 8;
const int Pin_FLASH_CS = 9;
const int Pin_SW2 = 12;
const int Pin_RED_LED = 13;
*/
