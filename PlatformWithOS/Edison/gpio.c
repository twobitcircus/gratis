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

// device tree base GPIO
// dts files from:  https://github.com/nomel/beaglebone

// OS:
//   root@beaglebone:~# uname -a; lsb_release -a
//   Linux beaglebone 3.8.13 #1 SMP Thu Sep 12 10:27:06 CEST 2013 armv7l GNU/Linux
//   Distributor ID: Angstrom
//   Description:    Angstrom GNU/Linux v2012.12 (Core edition)
//   Release:        v2012.12
//   Codename:       Core edition



#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <err.h>

#include "gpio.h"


// GPIO control information
mraa_gpio_context gpio_contexts[64];
mraa_spi_context spi;


// set up access to the GPIO and PWM
bool GPIO_setup() {
  mraa_init();
  fprintf(stdout, "MRAA Version: %s\n", mraa_get_version());

  spi = mraa_spi_init(0);
  mraa_spi_mode(spi, MRAA_SPI_MODE3);

  mraa_gpio_context pwm_context = mraa_gpio_init(14);
  mraa_gpio_dir(pwm_context, MRAA_GPIO_OUT);
  mraa_gpio_write(pwm_context, 1);

  //mraa_gpio_context cs1_context = mraa_gpio_init(9);
  //mraa_gpio_dir(cs1_context, MRAA_GPIO_OUT);
  //mraa_gpio_write(cs1_context, 1);


  return true;
}

// revoke access to GPIO and PWM
bool GPIO_teardown() {
  mraa_deinit();
  return true;
}

void GPIO_mode(GPIO_pin_type pin, GPIO_mode_type mode) {

  // just in time configure pins
  if (gpio_contexts[pin] == NULL) {
    fprintf(stderr, "enabling pin %d!\n", pin);
    gpio_contexts[pin] = mraa_gpio_init(pin);
    if (gpio_contexts[pin] == NULL) {
      fprintf(stderr, "initialize pin %d failed\n", pin);
      return;
    }
  }

  switch (mode) {
  default:
  case GPIO_INPUT:
    fprintf(stderr, "mode IN\n");
    mraa_gpio_dir(gpio_contexts[pin], MRAA_GPIO_IN);
    break;

  case GPIO_OUTPUT:
    fprintf(stderr, "mode OUT\n");
    mraa_gpio_dir(gpio_contexts[pin], MRAA_GPIO_OUT);
    break;

  case GPIO_PWM:  // only certain pins allowed
    fprintf(stderr, "mode PWM\n");
    // no-op
    break;
  }
}


int GPIO_read(int pin) {
  return mraa_gpio_read(gpio_contexts[pin]);
}


void GPIO_write(GPIO_pin_type pin, int value) {
  mraa_gpio_write(gpio_contexts[pin], value);
}

// only affect PWM if correct pin is addressed
void GPIO_pwm_write(int pin, uint32_t value) {
  return;
}


