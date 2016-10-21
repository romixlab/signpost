#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include "console.h"
#include "gpio.h"
#include "i2c_master_slave.h"
#include "timer.h"
#include "tock.h"

#define STROBE 4
#define RESET 5
#define POWER 6

#define LED3 8
#define LED4 9
#define LED1 10
#define LED2 11

#define UCSD_AQ_I2C_ADDR 0x35

#define BUFLEN 32

static bool fired = false;
static uint8_t uart_rx_buf[BUFLEN];
void uart_rx_callback (
		__attribute__ ((unused)) int len,
		__attribute__ ((unused)) int y,
		__attribute__ ((unused)) int z,
		__attribute__ ((unused)) void* userdata) {
	fired = true;
}

static void blink(unsigned duration_ms) {
	gpio_clear(LED1);
	gpio_clear(LED2);
	gpio_clear(LED3);
	delay_ms(duration_ms);
	gpio_set(LED1);
	gpio_set(LED2);
	gpio_set(LED3);
}

int main () {
	// LEDs used for debug only
	gpio_enable_output(LED1);
	gpio_enable_output(LED2);
	gpio_enable_output(LED3);
	gpio_enable_output(LED4);
	// Active low, clear all to start
	gpio_set(LED1);
	gpio_set(LED2);
	gpio_set(LED3);
	gpio_set(LED4);

	// Photon sends properly formatted packets, so use the same buffer to
	// receive UART and send I2C messages

	// Set buffer for I2C messages
	i2c_master_slave_set_master_write_buffer(uart_rx_buf, BUFLEN);

	// Set out slave address (though we don't listen)
	i2c_master_slave_set_slave_address(UCSD_AQ_I2C_ADDR);

	// Debug: Blink on boot
	blink(1000);

	while (1) {
		getauto(uart_rx_buf, BUFLEN, uart_rx_callback, NULL);
		yield_for(&fired);
		fired = false; // feels like yield_for should do this

		// Debug: Quick blink every packet
		blink(10);

		// Forward on the payload
		//     1 - UCSD_AQ_I2C_ADDR
		//     2 - Message Type
		//   3-4 - CO2 ppm
		//   5-8 - VOC_PID_ppb
		//  9-12 - VOC_IAQ_ppb
		// xx-xx -
		i2c_master_slave_write_sync(0x22, 12);
	}
}
