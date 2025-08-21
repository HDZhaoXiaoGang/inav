# STM32F405_FC 飞控板配置

## PWM输出端口配置

### 标准电机输出端口 (S1-S6)
- **S1**: PB3 (TIM2_CH2) - 电机输出1
- **S2**: PB4 (TIM3_CH1) - 电机输出2  
- **S3**: PB5 (TIM3_CH2) - 电机输出3
- **S4**: PB8 (TIM4_CH3) - 电机输出4
- **S5**: PB9 (TIM4_CH4) - 电机输出5
- **S6**: PA0 (TIM2_CH1) - 电机输出6

### 有刷电机输出端口 (MS1-MS2)
- **MS1**: PB0 (TIM3_CH3) - 有刷电机1
- **MS2**: PB1 (TIM3_CH4) - 有刷电机2

## 配置说明

### MS1和MS2端口特性（有刷电机专用）
- **定时器**: TIM3
- **通道**: CH3 (MS1), CH4 (MS2)
- **引脚**: PB0 (MS1), PB1 (MS2)
- **用途**: 专门用于有刷电机驱动
- **支持功能**:
  - 有刷电机PWM控制
  - 自动有刷/无刷ESC检测
  - 可配置PWM频率
  - 电机方向控制

### 配置参数
```bash
# 启用有刷电机支持
feature BRUSHED_MOTORS

# 设置有刷电机PWM频率 (默认50Hz)
set motor_pwm_rate = 50

# 设置PWM协议为有刷模式
set motor_pwm_protocol = BRUSHED

# 配置电机方向（如果需要反转）
set motor_direction = 1  # 1=正常, -1=反转
```

### 硬件连接
- **MS1 (PB0)**: 连接到有刷电机驱动电路
- **MS2 (PB1)**: 连接到有刷电机驱动电路
- **电源**: 确保有适当的电源供应
- **保护**: 建议添加电机保护电路

### 使用示例
```bash
# 查看当前电机输出状态
get motor_output

# 测试MS1端口输出
set motor_output[0] = 1500  # 50%占空比

# 测试MS2端口输出  
set motor_output[1] = 2000  # 100%占空比

# 启用有刷电机自动检测
feature BRUSHED_ESC_AUTODETECT
```

## 注意事项
1. MS1和MS2使用TIM3定时器，与S2、S3共享
2. 确保PWM频率适合您的有刷电机
3. 注意电源电压和电流限制
4. 建议添加适当的保护电路
5. 有刷电机需要适当的驱动电路（如H桥或MOS管驱动）

## 有刷电机测试和验证

### 编译前检查
确保以下定义已启用：
```bash
# 在target.h中应该看到：
#define USE_BRUSHED_ESC_AUTODETECT
#define TARGET_MOTOR_COUNT          8
#define BRUSHED_MOTORS
```

### 编译后验证
```bash
# 连接飞控后，在CLI中检查：
get motor_pwm_protocol
# 应该显示: motor_pwm_protocol = BRUSHED

get motor_pwm_rate  
# 应该显示: motor_pwm_rate = 16000

get motor_output
# 检查MS1/MS2输出是否正常
```

### 硬件测试
1. 连接有刷电机到MS1/MS2端口
2. 使用示波器检查PWM信号
3. 验证电机响应和方向
4. 测试不同油门值下的电机转速

### 故障排除
- 如果电机不转，检查PWM频率是否合适
- 如果方向错误，调整motor_direction设置
- 如果响应慢，可以尝试降低PWM频率
