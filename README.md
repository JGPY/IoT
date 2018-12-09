
# IoT
	本人本科专业是电子信息工程，现在在读硕士计算机技术专业，容我粗略描绘下IoT世界。
	我们聊理论，我们聊软硬件框架，我们更聊实战！


	想独自一人游刃有余的完成一个完整的IoT神奇世界，是不容易的。
	需要熟练会一款单片机的开发，它将用来边缘处理等工作。
	需要会后端开发，它将完成物联设备传送过来的数据处理等工作。
	当然工具类的东西，会用就好。
	我们分为三个阶段，
		第一阶段：熟悉一款单片机开发,电路板绘制和后端开发。
		第二阶段：熟悉IoT
		第三阶段：项目实战


# 第一阶段：
	入门STM32单片机开发
	入门Altuim designer电路板绘制
	入门阿里云服务器部署
	注：内容零散不连贯。
	
## 入门STM32单片机开发
	MCU-STM32
	IDE=MDK5（keil编译器）
	lib=3.5标准库
	
	文件说明：https://github.com/JGPY/IoT/tree/master/STM32F103VBT6%E5%88%9D%E6%8E%A2	
	STM32F103VBT6初探 #MCU控制器练习入门
	|--- 0、工程模板_DEMO
	|    |---doc
	|    |---lib
	|    |---list
	|    |---obj
	|    |---pro
	|    |---user
	|        |---inc
	|        |---src
	|---1、GPIO控制蜂鸣器
	|---2、按键控制蜂鸣器
	|---3、串口通信
	|---4、按键中断
	|---5、TIM定时器
	|---6、PWM控制LED
	|---7、独立看门狗
	|---8、RTC（串口显示）
	|---9、ADC（串口显示）
	|---10、声音检测（OLED显示）
	|---11、循迹检测
	|---12、气体检测（OLED显示）
	|---13、舵机控制
	|---14、红外解码（OLED显示）
	|---15、超声测距（OLED显示）
	|---16、电机驱动PWM控制

	
## 入门Altuim designer电路板绘制
	EDA=altuim designer （版本14以上）
	利用altuim degiser创建标准PCB工程：https://blog.csdn.net/qq_21508727/article/details/79547067
	文件说明 ：https://github.com/JGPY/IoT/tree/master/%E4%BC%A0%E6%84%9F%E5%99%A8%E5%88%9D%E6%8E%A2
	传感器初探 #电路原理图和PCB绘制练习入门
	|---1-红外解码
	|---2-火焰
	|---3-Motor Interface
	|---4-Ultrasound
	|---5-循迹
	|---6-buzzer
	|---7-sound
	|---8-MQ
	|---10-舵机超声接口
	|---11-测速
	|---12-LED
	|---13-按键
	|---14-人体热红外探测
		
## 入门阿里云服务器部署
	阿里云服务器申请开通：
	阿里云centos7配置JDK1.8+Tomcat7+Mysql5.7：https://blog.csdn.net/qq_21508727/article/details/79592349
	阿里云Centos7安装Redis4.0.8：https://blog.csdn.net/qq_21508727/article/details/79596423
	阿里云Centos7安装Nginx服务器实现反向代理：https://blog.csdn.net/qq_21508727/article/details/80071174
	阿里云+github+Hexo部署静态资源博客：https://blog.csdn.net/qq_21508727/article/details/80044265

TCP/IP
===
#TODO


JAVA服务端
===
#TODO
