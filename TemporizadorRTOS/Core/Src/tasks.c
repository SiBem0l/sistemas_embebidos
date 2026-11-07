#include "tasks.h"

void refreshTimer(void* argument)
{
	int unsigned wait_time = TIMER_REFRESH_RATE;
	uint32_t wait_ticks = pdMS_TO_TICKS(wait_time);
	uint32_t next_tick = osKernelGetTickCount();

	while(true)
	{
		next_tick += wait_ticks;

		bool counting = timer_is_counting(&timer);
		bool finished = timer_is_finished(&timer);
		bool buzzing  = buzzer_is_on(&buzzer);

		if (counting)
		{
			timer_substract(&timer, TIMER_REFRESH_RATE);
		}
		else if (finished && !buzzing)
		{
			buzzer_on(&buzzer);
		}

		osDelayUntil(next_tick);
	}
}

void displayShowDigit(void* argument)
{
	int display_block;
	int digit = 0;

	int unsigned wait_time = 2; // Display digit cada 1ms
	uint32_t wait_ticks = pdMS_TO_TICKS(wait_time);
	uint32_t next_tick = osKernelGetTickCount();

	while(true)
	{
		next_tick += wait_ticks;
		display_block = display.current_block;
		if(display_block == 0 || display_block == 1)
		{
			digit = timer_get_seconds_digit(&timer, display_block);
		}
		else if(display_block == 2 || display_block == 3)
		{
			digit = timer_get_minutes_digit(&timer, display_block-2);
		}

		display_show(&display, digit);
		display_next_block(&display);

		osDelayUntil(next_tick);
	}
}

void countPressed(void* argument)
{
	while(true)
	{
		osStatus_t status = osSemaphoreAcquire(countPressedSemaphore, osWaitForever);
		if(status == osOK && button_check_pressed(&count))
		{
			bool timer_running = timer_is_counting(&timer);
			if(timer_running)
			{
				timer_pause(&timer);
			}
			else
			{
				timer_start(&timer);
			}
		}
	}
}

void resetPressed(void* argument)
{
	while(true)
	{
		osStatus_t status = osSemaphoreAcquire(resetPressedSemaphore, osWaitForever);
		if(status == osOK && button_check_pressed(&reset) && !timer_is_counting(&timer))
		{
		    timer_reset(&timer);
		    buzzer_off(&buzzer);
		}
	}
}

void processInput(void* argument)
{
	char input[BUFFER_SIZE];

	while(1)
	{
		if(xQueueReceive(comunication.messages_queue, (void*)input, portMAX_DELAY))
		{
			// Traducir el string al comando correspondiente (Enum Instruction)
			Instruction cmd = instruction_read(input);

			// Ejecutar la acción sobre el temporizador y la UART
			if(cmd == INVALID)
			{
				comunication_send(&comunication, "INVALID INSTRUCTION\n");
			}
			else
			{
				instruction_execute(cmd, input, &timer, &comunication);
				if(cmd == RESET_TIMER)
				{
					buzzer_off(&buzzer);
				}
				comunication_send(&comunication, "OK\n");
			}
		}
	}
}
