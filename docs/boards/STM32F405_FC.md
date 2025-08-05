# Board - STM32F405 飞控板

## 硬件概述

基于STM32F405RGT6微控制器的飞控板，专为无人机和飞行器控制系统设计。

## 核心规格

### MCU参数
- **型号**: STM32F405RGT6
- **架构**: ARM Cortex-M4
- **主频**: 168MHz
- **Flash**: 1MB
- **RAM**: 192KB
- **封装**: LQFP64
- **晶振**: 8MHz (已配置)

## 引脚分配

### 串口连接
- **UART1**: PA10 (TX), PA11 (RX)
- **UART2**: PA2 (TX), PA3 (RX) - 默认接收机端口
- **UART3**: PB10 (TX), PB11 (RX)
- **UART4**: PC11 (TX), PC10 (RX)
- **UART5**: PC12 (TX), PD2 (RX)
- **UART6**: PC6 (TX), PC7 (RX)

### SPI接口
#### SPI1 - MPU6500
- **CS**: PA4
- **SCK**: PA5
- **MISO**: PA6
- **MOSI**: PA7

#### SPI2 - AT7456E OSD
- **CS**: PB12
- **SCK**: PB13
- **MISO**: PB14
- **MOSI**: PB15

### I2C接口
- **SDA**: PB7
- **SCL**: PB6
- **支持传感器**: SLP06气压计, QMC5883L磁力计

### PWM输出端口
- **S1**: PB3
- **S2**: PB4
- **S3**: PB5
- **S4**: PB8
- **S5**: PB9
- **S6**: PA0
- **S7**: PA1

### 备用电机控制端口
- **MS1**: PB0
- **MS2**: PB1
- **MS3**: PC9
- **MS4**: PA8

### 指示灯
- **LED_FC**: PC13
- **LED_LXB**: PC14

### ADC输入
- **VBAT**: PC4 (电池电压监测)
- **CURR**: PC5 (电流监测)

## 支持的传感器

### 陀螺仪/加速度计
- MPU6500 (SPI)

### 气压计
- SLP06 (I2C)

### 磁力计
- QMC5883L (I2C)

### OSD
- AT7456E (SPI)

## 默认配置

- 默认接收机: SBUS (UART2)
- 默认功能: OSD, 电流计, 电池电压监测, 遥测
- 最大PWM输出端口: 7个
- 支持DSHOT协议
- 支持BLHeli_32电调

## 编译选项

```bash
make STM32F405_FC
```

## 注意事项

1. 确保使用正确的晶振频率 (8MHz)
2. 首次使用时需要配置接收机类型
3. 建议使用5V稳压电源以确保稳定性
4. 备用电机控制端口可通过PINIO功能配置 