#ifndef TASKS_H
#define TASKS_H

#include "cmsis_os.h"
#include "display.h"
#include "timer.h"
#include "button.h"
#include "buzzer.h"
#include "instructions.h"

extern Display display;
extern Timer timer;
extern Button count;
extern Button reset;
extern Buzzer buzzer;
extern Comunication comunication;

extern osThreadId_t refreshTimerTask;
extern osThreadId_t displayShowDigitTask;
extern osThreadId_t countPressedTask;
extern osThreadId_t resetPressedTask;
extern osThreadId_t processInputTask;

extern osSemaphoreId_t countPressedSemaphore;
extern osSemaphoreId_t resetPressedSemaphore;
extern osSemaphoreId_t processInputSemaphore;

void refreshTimer(void* argument);
void displayShowDigit(void* argument);
void countPressed(void* argument);
void resetPressed(void* argument);
void processInput(void* argument);

#endif
