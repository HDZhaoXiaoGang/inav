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

#include <stdbool.h>
#include <platform.h>
#include "drivers/bus.h"
#include "drivers/io.h"
#include "drivers/pwm_mapping.h"
#include "drivers/timer.h"
#include "drivers/pinio.h"

// ��ʱ��Ӳ����������
// ��ʽ˵����DEF_TIM(��ʱ��, ͨ��, ����, ��;, DMAͨ��, DMA����)
timerHardware_t timerHardware[] = {
    // ������ͨ������
    DEF_TIM(TIM3,  CH1, PB4,  TIM_USE_OUTPUT_AUTO, 0, 0), // S1 - ���1���  DMA(1,4,5)
    DEF_TIM(TIM3,  CH2, PB5,  TIM_USE_OUTPUT_AUTO, 0, 0), // S2 - ���2���  DMA(1,5,5)
    DEF_TIM(TIM1,  CH1, PA8,  TIM_USE_OUTPUT_AUTO, 0, 1), // S3 - ���3���  DMA(2,1,6)
    DEF_TIM(TIM1,  CH2, PA9,  TIM_USE_OUTPUT_AUTO, 0, 1), // S4 - ���4���  DMA(2,2,6)
    DEF_TIM(TIM1,  CH3, PA10, TIM_USE_OUTPUT_AUTO, 0, 1), // S5 - ���5���  DMA(2,6,6)
    DEF_TIM(TIM4,  CH3, PB8,  TIM_USE_OUTPUT_AUTO, 0, 0), // S6 - ���6���  DMA(1,7,2)

    // ���ڶ�ʱ������
    DEF_TIM(TIM5,  CH3, PA2,  TIM_USE_ANY, 0, 0), // TX2���� - ����2����

    DEF_TIM(TIM11, CH1, PB9,  TIM_USE_ANY, 0, 0), // ST1���� - ����1����

    // PPM��������(��ע��)
    // DEF_TIM(TIM9,  CH2, PA3,  TIM_USE_PPM, 0, 0), // RX2���� - PPM����
};

// ���㶨ʱ��Ӳ�������С
const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
