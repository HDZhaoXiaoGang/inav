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

#include <stdint.h>
#include "platform.h"

#include "fc/fc_msp_box.h"
#include "io/serial.h"
#include "io/piniobox.h"

#include "drivers/pwm_mapping.h"
#include "flight/mixer.h"

void targetConfiguration(void)
{
    // pinioBoxConfigMutable()->permanentId[0] = BOX_PERMANENT_ID_USER1;
    
    // 配置 UART1 为 MSP 功能
    serialConfigMutable()->portConfigs[findSerialPortIndexByIdentifier(SERIAL_PORT_USART1)].functionMask = FUNCTION_MSP;
    
    // 设置 MSP 波特率为 115200
    serialConfigMutable()->portConfigs[findSerialPortIndexByIdentifier(SERIAL_PORT_USART1)].msp_baudrateIndex = BAUD_115200;

    // 配置空心杯电机 - PA1使用32kHz PWM直接驱动（参考ALIENFLIGHT配置）
    motorConfigMutable()->motorPwmProtocol = PWM_TYPE_BRUSHED;
    motorConfigMutable()->motorPwmRate = 32000;  // 32kHz PWM频率（与ALIENFLIGHT一致）
    motorConfigMutable()->maxthrottle = 2000;    // 最大油门值
    motorConfigMutable()->mincommand = 1000;     // 最小命令值

}
