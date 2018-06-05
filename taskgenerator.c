///\file functions.c
/// Conține funcția de generare aleatorie a sarcinilor.
/// Ovidiu-Adrian Ivan, CR 1.2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "taskgenerator.h"
#include "struct.h"

void generate_task(struct task *tasks, int no_tasks){
    ///\fn generate_task(struct task *tasks, int no_tasks)
    ///\brief Generează în mod aleatoriu sarcinile.
    ///\param tasks Vectorul sarcinilor.
    ///\param no_tasks Numărul sarcinilor.
    int iterator;
    time_t t;

    srand((unsigned) time(&t));
    for(iterator = 0; iterator < no_tasks; iterator++){
        tasks[iterator].id = iterator;
        tasks[iterator].start_time = rand() % 16 + 7;
        tasks[iterator].finish_time = rand() % 16 + 7;
        while(tasks[iterator].start_time >= tasks[iterator].finish_time)
        {
            tasks[iterator].finish_time = rand() % 16 + 7;
        }
    }
}
