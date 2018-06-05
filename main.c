///\file main.c
///\brief "The task-scheduling problem"
///
/// Ovidiu-Adrian Ivan, CR 1.2.

#include <stdio.h> ///> printf(), scanf()
#include <stdlib.h>///> malloc()
#include "taskgenerator.h"///> generate_task()
#include "functions.h"///> print_tasks(), sort_taks_by_finish_time(), greedy()
#include "struct.h"

int main()
{
    ///\fn int main()
    ///\brief Funcția main.
    /// Conține apelul funcțiilor pentru generarea sarcinilor din biblioteca "taskgenerator.h", precum și funcții din biblioteca "functions.h". Afișează vectorul cu sarcinile compatibile.
    ///\var tasks Conține toate sarcinile ce trebuiesc planificate.
    struct task *tasks;
    ///\var schedule Conține sarcinile planificate.
    struct task *schedule;
    ///\var no_tasks Reprezintă numărul de sarcini. Este citită de la tastatură.
    int no_tasks;
    ///\var schedule_dimension Reprezintă dimensiunea vectorului "schedule".
    int schedule_dimension = 1;

    printf("Give the number of tasks: ");
    scanf("%d",&no_tasks);
    tasks = malloc(no_tasks * sizeof(struct task));
    schedule = malloc(sizeof(struct task));
    generate_task(tasks, no_tasks);

    printf("\n=== Random tasks ===");
    print_tasks(tasks, no_tasks);

    printf("\n=== Sorted tasks by finish time ===");
    sort_tasks_by_finish_time(tasks, no_tasks);
    print_tasks(tasks, no_tasks);

    printf("\n=== Today's schedule: ===");
    greedy(tasks, no_tasks, schedule, &schedule_dimension);
    print_tasks(schedule, schedule_dimension);

    free(tasks);
    free(schedule);

    return 0;
}
