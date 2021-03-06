/*****************************************************************************

Filename    :   spi.h
Content     :   Lightweight SPI wrapper for STM32
Created     :
Authors     :   Nirav Patel
Copyright   :   Copyright 2013 Oculus VR, Inc. All Rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*****************************************************************************/

#ifndef _SPI_H_
#define _SPI_H_

#include <stdint.h>
#include "stm32f10x.h"

typedef struct spi_struct {
    SPI_TypeDef *spi_port;
    GPIO_TypeDef *gpio_port;
    uint16_t ss_pin;
    uint32_t rcc;
} spi_t, *spi_p;

void spi_init(spi_p spi, SPI_TypeDef *spi_port, uint16_t speed, uint32_t rcc, GPIO_TypeDef* gpio, uint32_t gpio_rcc, uint16_t miso, uint16_t mosi, uint16_t sck, uint16_t ss);

void spi_deinit(spi_p spi);

void spi_port_config(spi_p spi, uint16_t speed);

void spi_port_alt_config(spi_p spi, uint16_t speed);

void spi_write_raw(spi_p spi, uint8_t data);

void spi_write(spi_p spi, uint8_t reg, uint8_t data);

void spi_rw(spi_p spi, uint8_t reg, uint8_t *write_buf, uint8_t *read_buf, uint16_t len);

void spi_read(spi_p spi, uint8_t reg, uint8_t *buf, uint16_t len);

#endif /* _SPI_H_ */
