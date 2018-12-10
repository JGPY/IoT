#ifndef __TB6612_H
#define __TB6612_H

#include "share.h"

void GPIO_CONFIG(void);
void TIM2_Configuration(void);
void TB6612_Init(void);
void forward(u16 n);
void backward(u16 n);
void left(u16 n);
void right(u16 n);
void stop(void);

#endif
