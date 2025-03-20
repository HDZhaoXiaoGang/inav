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

#include <stdbool.h>
#include <platform.h>
#include "drivers/bus.h"
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"
#include "drivers/pinio.h"

// 定时器硬件配置数组
// 格式说明：DEF_TIM(定时器, 通道, 引脚, 用途, DMA通道, DMA请求)
timerHardware_t timerHardware[] = {
    // 电机输出通道配置
    DEF_TIM(TIM3,  CH1, PB4,  TIM_USE_OUTPUT_AUTO, 0, 0), // S1 - 电机1输出  DMA(1,4,5)
    DEF_TIM(TIM3,  CH2, PB5,  TIM_USE_OUTPUT_AUTO, 0, 0), // S2 - 电机2输出  DMA(1,5,5)
    DEF_TIM(TIM1,  CH1, PA8,  TIM_USE_OUTPUT_AUTO, 0, 1), // S3 - 电机3输出  DMA(2,1,6)
    DEF_TIM(TIM1,  CH2, PA9,  TIM_USE_OUTPUT_AUTO, 0, 1), // S4 - 电机4输出  DMA(2,2,6)
    DEF_TIM(TIM1,  CH3, PA10, TIM_USE_OUTPUT_AUTO, 0, 1), // S5 - 电机5输出  DMA(2,6,6)
    DEF_TIM(TIM4,  CH3, PB8,  TIM_USE_OUTPUT_AUTO, 0, 0), // S6 - 电机6输出  DMA(1,7,2)

    // 软串口定时器配置
    DEF_TIM(TIM5,  CH3, PA2,  TIM_USE_ANY, 0, 0), // TX2引脚 - 软串口2发送

    DEF_TIM(TIM11, CH1, PB9,  TIM_USE_ANY, 0, 0), // ST1引脚 - 软串口1发送

    // PPM接收配置(已注释)
    // DEF_TIM(TIM9,  CH2, PA3,  TIM_USE_PPM, 0, 0), // RX2引脚 - PPM输入
};

// 计算定时器硬件数组大小
const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
