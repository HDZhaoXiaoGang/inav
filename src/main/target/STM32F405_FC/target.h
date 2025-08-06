/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TARGET_BOARD_IDENTIFIER "F405F"
#define USBD_PRODUCT_STRING  "STM32F405_FC"

#define LED0                    PC13
#define LED1                    PC14

#define BEEPER                  PB2
#define BEEPER_INVERTED

// *************** SPI1 MPU6500 Gyro & ACC **********************
#define USE_SPI
#define USE_SPI_DEVICE_1

#define SPI1_SCK_PIN            PA5
#define SPI1_MISO_PIN           PA6
#define SPI1_MOSI_PIN           PA7

#define USE_IMU_MPU6500
#define IMU_MPU6500_ALIGN       CW0_DEG
#define MPU6500_CS_PIN          PA4
#define MPU6500_SPI_BUS         BUS_SPI1
#define MPU6500_EXTL_PIN        PC3  // 外部中断引脚

// *************** SPI2 AT7456E OSD *****************************
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PB13
#define SPI2_MISO_PIN           PB14
#define SPI2_MOSI_PIN           PB15

#define USE_MAX7456
#define MAX7456_SPI_BUS         BUS_SPI2
#define MAX7456_CS_PIN          PB12

// *************** UART *****************************
#define USE_VCP

#define USE_UART1
#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define USE_UART2
#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3

#define USE_UART3
#define UART3_TX_PIN            PB10
#define UART3_RX_PIN            PB11

#define USE_UART4
#define UART4_TX_PIN            PC11
#define UART4_RX_PIN            PC10

#define USE_UART5
#define UART5_TX_PIN            PC12
#define UART5_RX_PIN            PD2

#define USE_UART6
#define UART6_TX_PIN            PC6
#define UART6_RX_PIN            PC7

#define SERIAL_PORT_COUNT       7

#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_CRSF  // ELRS使用CRSF协议
#define SERIALRX_UART           SERIAL_PORT_USART5  // 使用UART5连接ELRS接收机

// *************** I2C /Baro/Mag ********************
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL                PB6
#define I2C1_SDA                PB7

#define DEFAULT_I2C_BUS         BUS_I2C1

#define USE_BARO
#define BARO_I2C_BUS            BUS_I2C1
#define USE_BARO_SPL06

#define USE_MAG
#define MAG_I2C_BUS             BUS_I2C1
#define USE_MAG_QMC5883L

#define TEMPERATURE_I2C_BUS     BUS_I2C1

// *************** ADC *****************************
#define USE_ADC
#define ADC_INSTANCE                ADC1
#define ADC1_DMA_STREAM             DMA2_Stream0

#define ADC_CHANNEL_1_PIN           PC4  // VBAT
#define ADC_CHANNEL_2_PIN           PC5  // CURR

#define VBAT_ADC_CHANNEL            ADC_CHN_1
#define CURRENT_METER_ADC_CHANNEL   ADC_CHN_2

// *************** PWM输出 ************************
#define MAX_PWM_OUTPUT_PORTS       7

// *************** 备用电机控制端口 ****************
#define USE_PINIO
#define USE_PINIOBOX
#define PINIO1_PIN                  PB0  // MS1
#define PINIO2_PIN                  PB1  // MS2
#define PINIO3_PIN                  PC9  // MS3
#define PINIO4_PIN                  PA8  // MS4

// ***************  OTHERS *************************
#define DEFAULT_FEATURES        (FEATURE_TX_PROF_SEL | FEATURE_OSD | FEATURE_CURRENT_METER | FEATURE_VBAT | FEATURE_TELEMETRY)

#define CURRENT_METER_SCALE     423 

#define USE_DSHOT
#define USE_ESC_SENSOR
#define USE_SERIAL_4WAY_BLHELI_INTERFACE

#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         0xffff
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         0xffff 