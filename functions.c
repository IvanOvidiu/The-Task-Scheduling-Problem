///\file functions.c
/// Conține diferite funcții pentru prelucrarea datelor.
/// Ovidiu-Adrian Ivan, CR 1.2.

#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
#include "struct.h"
#define TM 15
///\def #define TM 15
///\brief Se stabilește durata totală maximă care se poate planifica, ca fiind de 15 ore.

int duration(struct task tsk){
    ///\fn int duration(struct task tsk)
    ///\brief Returnează durata unei sarcini "tsk".
    ///\param tsk Sarcina a cărei durată se calculează.
    return tsk.finish_time - tsk.start_time;
}

void sort_tasks_by_finish_time(struct task *tasks, int no_tasks){
    ///\fn void sort_tasks_by_finish_time(struct task *tasks, int no_tasks)
    ///\brief Sortează vectorul tasks in funcție de finalul sarcinilor.
    ///\param tasks Vectorul sarcinilor.
    ///\param no_tasks Numărul sarcinilor.
    int iterator1;
    int iterator2;
    struct task aux;

    for(iterator1 = 0; iterator1 < no_tasks - 1; iterator1++){
        for(iterator2 = iterator1 + 1; iterator2 < no_tasks; iterator2++){
            if(tasks[iterator1].finish_time > tasks[iterator2].finish_time){
                aux = tasks[iterator1];
                tasks[iterator1] = tasks[iterator2];
                tasks[iterator2] = aux;
            }
        }
    }
}

void print_tasks(struct task *tsk, int n){
    ///\fn print_tasks(struct task *tasks, int no_tasks)
    ///\brief Afișează sarcinile.
    ///\param tasks Vectorul sarcinilor.
    ///\param no_tasks Numărul sarcinilor.
    int iterator;

    printf("\n Tasks:");
    for (iterator = 0; iterator < n; iterator++) {
        printf("\n id: %d      start time: %d     finish time: %d",tsk[iterator].id, tsk[iterator].start_time, tsk[iterator].finish_time);
    }
}

int task_compatibility(struct task *schedule, struct task task2, int n){
    ///\fn task_compatibility(struct task *schedule, struct task task2, int n)
    ///\brief Verifică dacă o sarcină este compatibilă cu sarcinile deja planificate.
    ///\param schedule Vectorul ce conține sarcinile planificate.
    ///\param task2 Sarcina ce trebuie verificată.
    ///\param n Dimensiunea vectorului schedule.
    int iterator;

    for(iterator = 0; iterator < n; iterator++){
        if(task2.start_time < schedule[iterator].finish_time){
            return 0;
        }
    }
    return 1;
}

void greedy(struct task *tasks, int no_tasks, struct task *schedule, int *schedule_dimension){
    ///\fn greedy(struct task *tasks, int no_tasks, struct task *schedule, int *schedule_dimension)
    ///\brief Se implementează algoritmul Greedy pentru determinarea numărului maxim de sarcini compatibile.
    ///\param tasks Vectorul ce conține totalitatea sarcinilor ce trebuies planificate.
    ///\param no_tasks Numărul total de sarcini.
    ///\param schedule Vectorul ce conține sarcinile planificate.
    ///\param schedule_dimension Dimensiunea vectorului schedule.
    int iterator;
    int scheduled_time = 0;

    schedule[0] = tasks[0];
    ///\var scheduled_time Contorizează numărul de ore planificate.
    scheduled_time += duration(tasks[0]);
    iterator = 1;

    while(scheduled_time <= TM && iterator < no_tasks)
    {
        if(task_compatibility(schedule, tasks[iterator], *schedule_dimension) && (duration(tasks[iterator]) <= (TM - scheduled_time))){
            (*schedule_dimension)++;
            schedule = realloc(schedule, sizeof(struct task) * (*schedule_dimension));
            schedule[*schedule_dimension - 1] = tasks[iterator];
            scheduled_time += duration(tasks[iterator]);
        }
        iterator++;
    }
}
