///\file functions.h
/// Conține diferite funcții pentru prelucrarea datelor.
/// Ovidiu-Adrian Ivan, CR 1.2.

#ifndef _FUNCTIONSH_
#define _FUNCTIONSH_

#include <stdio.h>
#include "struct.h"

int duration(struct task tsk);
void sort_tasks_by_finish_time(struct task *tasks, int no_tasks);
void print_tasks(struct task *tsk, int n);
int task_compatibility(struct task *schedule, struct task task2, int n);
void greedy(struct task *tasks, int no_tasks, struct task *schedule, int *schedule_dimension);

#endif
