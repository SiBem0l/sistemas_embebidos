#include <string.h>
#include <stdio.h>
#include "instructions.h"

Instruction instruction_read(char* word)
{
	word = strlwr(word);
	Instruction ans;

	// Compare the first characters only, because it has variable parameters
	if(strncmp(word, instruction[SET_TIMER], strlen(instruction[SET_TIMER])) == 0)
	{
		ans = SET_TIMER;
	}
	else if(strcmp(word, instruction[START_TIMER]) == 0)
	{
		ans = START_TIMER;
	}
	else if(strcmp(word, instruction[PAUSE_TIMER]) == 0)
	{
		ans = PAUSE_TIMER;
	}
	else if(strcmp(word, instruction[RESET_TIMER]) == 0)
	{
		ans = RESET_TIMER;
	}
	else if(strcmp(word, instruction[TIMER_STATUS]) == 0)
	{
		ans = TIMER_STATUS;
	}
	else
	{
		ans = INVALID;
	}
	return ans;
}


void instruction_execute(Instruction cmd, char* word, Timer* timer, Comunication* com) {
    switch (cmd) {
        case SET_TIMER:    do_set_timer(word, timer); break;
        case START_TIMER:  do_start_timer(timer); break;
        case PAUSE_TIMER:  do_pause_timer(timer); break;
        case RESET_TIMER:  do_reset_timer(timer); break;
        case TIMER_STATUS: do_timer_status(timer, com); break;
        default: break;
    }
}

void do_set_timer(char* word, Timer* timer)
{
	static unsigned long t_seconds = 0;
	// Update t_seconds only if the instruction asks
	sscanf(word + strlen(instruction[SET_TIMER]), "%lu", &t_seconds);


	if(t_seconds <= 5999 && t_seconds >= 0 && !timer_is_counting(timer))
	{
		timer_set(timer, t_seconds * 1000);
	}
}

void do_start_timer(Timer* timer)
{
	timer_start(timer);
}

void do_pause_timer(Timer* timer)
{
	timer_pause(timer);
}

void do_reset_timer(Timer* timer)
{
	if(!timer_is_counting(timer))
	{
		timer_reset(timer);
		do_set_timer("set", timer);
	}
}

void do_timer_status(Timer* timer, Comunication* com)
{
	unsigned long minutes = timer_get_minutes(timer);
	unsigned long seconds = timer_get_seconds(timer) % 60;
	char status_message[100] = {};

	sniprintf(status_message, sizeof(status_message), "%lu : %lu \n", minutes, seconds);

	if(timer_is_counting(timer))
	{
		sniprintf(status_message, sizeof(status_message), "RUNNING %lu : %lu \n", minutes, seconds);
		comunication_send(com, status_message);
	}
	else if(timer_is_finished(timer))
	{
		sniprintf(status_message, sizeof(status_message), "FINISHED\n");
		comunication_send(com, status_message);
	}
	else if(!timer_is_counting(timer) && !timer_is_finished(timer))
	{
		comunication_send(com, "PAUSED\n");
	}
}
