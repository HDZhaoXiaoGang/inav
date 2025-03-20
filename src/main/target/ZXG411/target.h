/*
 * ����INAV�ɿع̼���һ���֡�
 *
 * INAV�ǻ���GNUͨ�ù������֤�������������:
 * �������������������ᷢ����GNUͨ�ù������֤��3�����߰汾��������
 * ���·ַ���/���޸�����
 *
 * INAV�ķ�����ϣ�����ܹ����ã������ṩ�κα�֤;
 * �������ṩ�����Ի��ض���;�����Ե�Ĭʾ��֤��
 * ������ϸ��Ϣ�������GNUͨ�ù������֤��
 */

#pragma once

// �������ʶ��������
#define TARGET_BOARD_IDENTIFIER "ZXG4"

// LED����
#define LED0                    PC13  // ����LED0����ΪPC13
#define LED1                    PC14  // ����LED1����ΪPC14

// ����������
#define BEEPER                  PB2   // �������������ΪPB2
#define BEEPER_INVERTED        // �������źŷ���

// *************** SPI1 �����Ǻͼ��ٶȼ����� **********************
#define USE_SPI                // ����SPI����
#define USE_SPI_DEVICE_1      // ����SPI1�豸

// SPI1���Ŷ���
#define SPI1_SCK_PIN            PA5   // SPI1ʱ������
#define SPI1_MISO_PIN           PA6   // SPI1 MISO��������
#define SPI1_MOSI_PIN           PA7   // SPI1 MOSI��������

// MPU6500����������
#define USE_IMU_MPU6500         // ����MPU6500 IMU������
#define IMU_MPU6500_ALIGN       CW0_DEG  // ��������װ����Ϊ0��
#define MPU6500_CS_PIN          PA4      // MPU6500Ƭѡ����
#define MPU6500_SPI_BUS         BUS_SPI1 // MPU6500ʹ��SPI1����

// *************** SPI2 OSD��FLASH���� *****************************
#define USE_SPI_DEVICE_2        // ����SPI2�豸
#define SPI2_SCK_PIN            PB13    // SPI2ʱ������
#define SPI2_MISO_PIN           PB14    // SPI2 MISO��������
#define SPI2_MOSI_PIN           PB15    // SPI2 MOSI��������

// ���ݱ���ѡ�����ʹ�úں��ӻ�OSD
#ifdef ZXG411_BLACKBOX
// �ں�����������
#define USE_FLASHFS
#define USE_FLASH_M25P16
#define M25P16_CS_PIN           PB12
#define M25P16_SPI_BUS          BUS_SPI2
#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
#else
// MAX7456 OSD����
#define USE_MAX7456
#define MAX7456_SPI_BUS         BUS_SPI2
#define MAX7456_CS_PIN          PB12
#endif

// *************** UART�������� *****************************
// UART1����
#define USE_UART1
#define UART1_TX_PIN            PA15    // UART1��������
#define UART1_RX_PIN            PB3     // UART1��������

// UART2����
#define USE_UART2
#define UART2_TX_PIN            PA2     // UART2��������
#define UART2_RX_PIN            PA3     // UART2��������

// UART6����
#define USE_UART6
#define UART6_TX_PIN            PC6     // UART6��������
#define UART6_RX_PIN            PC7     // UART6��������

// ����1����
#define USE_SOFTSERIAL1
#define SOFTSERIAL_1_TX_PIN     PB9     // ����1��������
#define SOFTSERIAL_1_RX_PIN     PB8     // ����1��������

// ������������
#define SERIAL_PORT_COUNT       4       // UART1 + UART2 + UART6 + SS1

// I2C��������
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL                PB6     // I2C1ʱ����
#define I2C1_SDA                PB7     // I2C1������

#define DEFAULT_I2C_BUS         BUS_I2C1

// ��ѹ������
#define USE_BARO
#define BARO_I2C_BUS            BUS_I2C1    // ��ѹ��ʹ��I2C1����
#define USE_BARO_SPL06          // ����SPL06��ѹ��

// ����������
#define USE_MAG
#define MAG_I2C_BUS             BUS_I2C1    // ������ʹ��I2C1����
#define USE_MAG_QMC5883L        // ����QMC5883L������

#define TEMPERATURE_I2C_BUS     BUS_I2C1

// ���������
#define USE_RANGEFINDER
#define USE_RANGEFINDER_MSP
#define RANGEFINDER_I2C_BUS     BUS_I2C1

// ADCͨ������
#define USE_ADC
#define ADC_CHANNEL_1_PIN       PC2     // ADCͨ��1����
#define ADC_CHANNEL_2_PIN       PC1     // ADCͨ��2����
#define ADC_CHANNEL_3_PIN       PC0     // ADCͨ��3����
#define ADC_CHANNEL_4_PIN       PC3     // ADCͨ��4����

// ADCͨ�����ܶ���
#define VBAT_ADC_CHANNEL                ADC_CHN_1    // ��ص�ѹ���
#define CURRENT_METER_ADC_CHANNEL       ADC_CHN_2    // �������
#define RSSI_ADC_CHANNEL                ADC_CHN_3    // �ź�ǿ�ȼ��
#define AIRSPEED_ADC_CHANNEL            ADC_CHN_4    // ���ټ��

// LED2812����
#define USE_LED_STRIP
#define WS2811_PIN                  PB10

// PINIO����
#define USE_PINIO
#define USE_PINIOBOX
#define PINIO1_PIN                  PA13 // ����ͷ�л���

// ң��������
#define USE_SPEKTRUM_BIND
#define BIND_PIN                PA3     // �󶨰�ť����(RX2)
#define DEFAULT_RX_TYPE         RX_TYPE_SERIAL
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define SERIALRX_UART           SERIAL_PORT_USART2

// ����������
#define USE_DSHOT              // ����DSHOTЭ��
#define USE_ESC_SENSOR        // ���õ��������
#define USE_SERIAL_4WAY_BLHELI_INTERFACE // ����BLHeli�ӿ�

// IO�˿�����
#define TARGET_IO_PORTA         0xffff  // ����PORTA��������
#define TARGET_IO_PORTB         0xffff  // ����PORTB��������
#define TARGET_IO_PORTC         0xffff  // ����PORTC��������
#define TARGET_IO_PORTD         (BIT(2))// ����PORTD�ĵ�2������

// ���PWM���ͨ����
#define MAX_PWM_OUTPUT_PORTS       6    // ����6��PWM���ͨ��

// Ĭ�Ϲ�������
#define DEFAULT_FEATURES        (FEATURE_TX_PROF_SEL | FEATURE_OSD | FEATURE_CURRENT_METER | FEATURE_VBAT | FEATURE_TELEMETRY | FEATURE_SOFTSERIAL)

// �����Ʊ���
#define CURRENT_METER_SCALE     423 