#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "comunication.h"
#include "timer.h"

typedef enum
{
	SET_TIMER,
	START_TIMER,
	PAUSE_TIMER,
	RESET_TIMER,
	TIMER_STATUS,
	INVALID
}Instruction;

static const char instruction[][50] = {"set", "start", "pause", "reset", "status"};

Instruction instruction_read(char* word);
void instruction_execute(Instruction instruction, char* word, Timer* timer, Comunication* com);

void do_set_timer(char* word, Timer* timer);
void do_start_timer(Timer* timer);
void do_pause_timer(Timer* timer);
void do_reset_timer(Timer* timer);
void do_timer_status(Timer* timer, Comunication* com);
void do_invalid_instruction(Comunication* com);

#endif
