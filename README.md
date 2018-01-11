
# IoT
本人本科专业是电子信息工程，现在在读硕士计算机技术专业，或许我更能描述好IoT世界。
我们聊理论，我们聊框架，我们更聊实战！

文件说明
===
	传感器初探 #电路原理图和PCB绘制练习入门
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
	
	STM32F103VBT6初探 #MCU控制器练习入门
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
	
	
MCU-STM32
===
	IDE=MDK5（keil编译器）
	lib=3.5标准库
PCB
===
	EDA=altuim designer （版本14以上）
	1 硬件设计方案
	1.1 原理图与PCB绘制软件选择
	    绘制原理图与PCB的软件很多，目前国内低端低速产品用的最多的软件是Altium Designer，欧洲地区流行使用EAGLE Layout，
	国内中小规模公司常使用PADS软件绘制多层板，而一般大型公司则使用Cadende SPB，鉴于此次开发电路并不过于复杂，双面绘制足
	以。此处推荐使用Altium Designer软件。鉴于以后工作薪资要求，后期可自行学习Cadende SPB（个人推荐）
	1.2  PCB布局规则
	    PCB布局规则很多，涉及到的知识也很庞杂，如信号与系统、电磁场与电磁波、信号的完整性等理论知识，而对于低端低速产品
	在稳定工作的情况下其要求的规则并没有过多的限制。以下仅对重点进行规则简要说明，具体详细规则请参考文件名为“硬件参考手
	册资料”目录下的《PCB板布局原则、布线技巧(图解).PDF》和《硬件工程师手册-深圳华为.PDF》。
	(1) 布线宽度：信号线<电源线<地线；信号线宽度一般是8~12mil，电源线一般15~25mil以上，整个PCB要做铺地抗干扰处理。
	(2) 过孔内直径不要低于8mil，内直径要随线宽的增加而增加，外直径一般为内直径的两倍。<\br>
	(3) 元器件摆放位置要考虑到后期便于手工焊接（特别是贴片电阻电容等），注意模拟电路与数字电路的隔离，注意高压大电流器件与低压小电流器件的隔离。
	(4) 整体布局要紧凑合理，尽量缩小PCB，以减少加工PCB费用。
	1.3  PCB打样厂家的选择
	  下表为一般厂家打样费，一般数量是5块板左右，当大批量加工时，以下价格不适用（他是按照多大一块加工板计算,如1M*1M的加工板多少钱）下表价格不包
	含寄运费。
	大小/cm	厚度/cm	几层	数量/片	价格/元
	5*5	   1	    2	      5	        30
	10*10	   1	    2	      5		50
 	    现在可通过淘宝等平台找到很多PCB打样的厂家，加工实力参差不齐。如果厂家加工出来的PCB质量不过关，可能有电路短路，后期电路板易变形和手工焊
	接易脱焊盘等致命质量问题，所以选择一家质量有保障的厂家是十分重要的事，根据以往经验选择*****公司制作的电路板还是非常不错的，国内很多中
	小企业都选择这家电路板制作厂商。鉴于成本要求，前期测试开发可使用洞洞板代替（实验室若有热转印机和腐蚀机可自行制作PCB），后期产品成熟再送入
	厂家加工打样。


TCP/IP
===
#TODO


JAVA服务端
===
#TODO
