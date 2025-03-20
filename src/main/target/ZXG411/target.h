/*
 * 这是INAV飞控固件的一部分。
 *
 * INAV是基于GNU通用公共许可证发布的自由软件:
 * 您可以在自由软件基金会发布的GNU通用公共许可证第3版或更高版本的条款下
 * 重新分发和/或修改它。
 *
 * INAV的发布是希望它能够有用，但不提供任何保证;
 * 甚至不提供适销性或特定用途适用性的默示保证。
 * 更多详细信息，请参阅GNU通用公共许可证。
 */

#pragma once

// 开发板标识符和名称
#define TARGET_BOARD_IDENTIFIER "ZXG4"

// LED配置
#define LED0                    PC13  // 定义LED0引脚为PC13
#define LED1                    PC14  // 定义LED1引脚为PC14

// 蜂鸣器配置
#define BEEPER                  PB2   // 定义蜂鸣器引脚为PB2
#define BEEPER_INVERTED        // 蜂鸣器信号反相

// *************** SPI1 陀螺仪和加速度计配置 **********************
#define USE_SPI                // 启用SPI功能
#define USE_SPI_DEVICE_1      // 启用SPI1设备

// SPI1引脚定义
#define SPI1_SCK_PIN            PA5   // SPI1时钟引脚
#define SPI1_MISO_PIN           PA6   // SPI1 MISO数据引脚
#define SPI1_MOSI_PIN           PA7   // SPI1 MOSI数据引脚

// MPU6500陀螺仪配置
#define USE_IMU_MPU6500         // 启用MPU6500 IMU传感器
#define IMU_MPU6500_ALIGN       CW0_DEG  // 传感器安装方向为0度
#define MPU6500_CS_PIN          PA4      // MPU6500片选引脚
#define MPU6500_SPI_BUS         BUS_SPI1 // MPU6500使用SPI1总线

// *************** SPI2 OSD或FLASH配置 *****************************
#define USE_SPI_DEVICE_2        // 启用SPI2设备
#define SPI2_SCK_PIN            PB13    // SPI2时钟引脚
#define SPI2_MISO_PIN           PB14    // SPI2 MISO数据引脚
#define SPI2_MOSI_PIN           PB15    // SPI2 MOSI数据引脚

// 根据编译选项决定使用黑盒子或OSD
#ifdef ZXG411_BLACKBOX
// 黑盒子闪存配置
#define USE_FLASHFS
#define USE_FLASH_M25P16
#define M25P16_CS_PIN           PB12
#define M25P16_SPI_BUS          BUS_SPI2
#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
#else
// MAX7456 OSD配置
#define USE_MAX7456
#define MAX7456_SPI_BUS         BUS_SPI2
#define MAX7456_CS_PIN          PB12
#endif

// *************** UART串口配置 *****************************
// UART1配置
#define USE_UART1
#define UART1_TX_PIN            PA15    // UART1发送引脚
#define UART1_RX_PIN            PB3     // UART1接收引脚

// UART2配置
#define USE_UART2
#define UART2_TX_PIN            PA2     // UART2发送引脚
#define UART2_RX_PIN            PA3     // UART2接收引脚

// UART6配置
#define USE_UART6
#define UART6_TX_PIN            PC6     // UART6发送引脚
#define UART6_RX_PIN            PC7     // UART6接收引脚

// 软串口1配置
#define USE_SOFTSERIAL1
#define SOFTSERIAL_1_TX_PIN     PB9     // 软串口1发送引脚
#define SOFTSERIAL_1_RX_PIN     PB8     // 软串口1接收引脚

// 串口总数定义
#define SERIAL_PORT_COUNT       4       // UART1 + UART2 + UART6 + SS1

// I2C总线配置
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL                PB6     // I2C1时钟线
#define I2C1_SDA                PB7     // I2C1数据线

#define DEFAULT_I2C_BUS         BUS_I2C1

// 气压计配置
#define USE_BARO
#define BARO_I2C_BUS            BUS_I2C1    // 气压计使用I2C1总线
#define USE_BARO_SPL06          // 启用SPL06气压计

// 磁力计配置
#define USE_MAG
#define MAG_I2C_BUS             BUS_I2C1    // 磁力计使用I2C1总线
#define USE_MAG_QMC5883L        // 启用QMC5883L磁力计

#define TEMPERATURE_I2C_BUS     BUS_I2C1

// 测距仪配置
#define USE_RANGEFINDER
#define USE_RANGEFINDER_MSP
#define RANGEFINDER_I2C_BUS     BUS_I2C1

// ADC通道配置
#define USE_ADC
#define ADC_CHANNEL_1_PIN       PC2     // ADC通道1引脚
#define ADC_CHANNEL_2_PIN       PC1     // ADC通道2引脚
#define ADC_CHANNEL_3_PIN       PC0     // ADC通道3引脚
#define ADC_CHANNEL_4_PIN       PC3     // ADC通道4引脚

// ADC通道功能定义
#define VBAT_ADC_CHANNEL                ADC_CHN_1    // 电池电压检测
#define CURRENT_METER_ADC_CHANNEL       ADC_CHN_2    // 电流检测
#define RSSI_ADC_CHANNEL                ADC_CHN_3    // 信号强度检测
#define AIRSPEED_ADC_CHANNEL            ADC_CHN_4    // 空速检测

// LED2812配置
#define USE_LED_STRIP
#define WS2811_PIN                  PB10

// PINIO配置
#define USE_PINIO
#define USE_PINIOBOX
#define PINIO1_PIN                  PA13 // 摄像头切换器

// 遥控器配置
#define USE_SPEKTRUM_BIND
#define BIND_PIN                PA3     // 绑定按钮引脚(RX2)
#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define SERIALRX_UART           SERIAL_PORT_USART2

// 电调相关配置
#define USE_DSHOT              // 启用DSHOT协议
#define USE_ESC_SENSOR        // 启用电调传感器
#define USE_SERIAL_4WAY_BLHELI_INTERFACE // 启用BLHeli接口

// IO端口配置
#define TARGET_IO_PORTA         0xffff  // 启用PORTA所有引脚
#define TARGET_IO_PORTB         0xffff  // 启用PORTB所有引脚
#define TARGET_IO_PORTC         0xffff  // 启用PORTC所有引脚
#define TARGET_IO_PORTD         (BIT(2))// 启用PORTD的第2个引脚

// 最大PWM输出通道数
#define MAX_PWM_OUTPUT_PORTS       6    // 定义6个PWM输出通道

// 默认功能配置
#define DEFAULT_FEATURES        (FEATURE_TX_PROF_SEL | FEATURE_OSD | FEATURE_CURRENT_METER | FEATURE_VBAT | FEATURE_TELEMETRY | FEATURE_SOFTSERIAL)

// 电流计比例
#define CURRENT_METER_SCALE     423 