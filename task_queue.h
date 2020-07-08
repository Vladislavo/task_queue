/// @task_queue.h
/// header file for the task queue library
/// author Vladislav Rykov

#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H


struct task_queue;
typedef struct task_queue task_queue_t;

typedef void (*task_func_t)(void *arg);


/*! \brief Creates a task queue.
 * 
 *  Allocates necessary memory and initializes internal variables.
 *
 *  \param max_threads Upper limit for active threads number.
 *  \param max_size Maximum queue size.
 *
 *  \return task_queue_t pointer on success, -1 on failure, -2 on full queue.
*/  
task_queue_t * task_queue_create(const int max_threads, const int max_size);


/*! \brief Destroys a task queue.
 * 
 *  Frees memory for all tasks and related structs.
*/  
void task_queue_destroy(task_queue_t *tq);

/*! \brief Enqueues a new task into the queue.
 * 
 *  Allocates necessary memory for the task and links it to the queue.
 *
 *  \param tq Pointer to the task queue.
 *  \param task Function to execute.
 *  \param arg Pointer to argument for the function.
 *
 *  \return current queue size on success, -1 on failure.
*/  
int task_queue_enqueue(task_queue_t *tq, task_func_t task, void *arg);

/*! \brief Suspends tasks execution.
 * 
 *  Pauses tasks execution while allow to enqueue new tasks.
 *
 *  \param tq Pointer to the task queue.
*/  
void task_queue_suspend(task_queue_t *tq);

/*! \brief Unsuspends tasks execution.
 * 
 *  Continues tasks execution throwing maximum or necessary number of threads.
 *
 *  \param tq Pointer to the task queue.
*/  
void task_queue_unsuspend(task_queue_t *tq);

/*! \brief Gets current task queue size.
 * 
 *  \param tq Pointer to the task queue.
 *
 *  \return current queue size.
*/  
int task_queue_get_size(task_queue_t *tq);

/*! \brief Checks if the task queue is empty
 * 
 *  \param tq Pointer to the task queue.
 *
 *  \return 1 if empty, otherwise 0.
*/  
int task_queue_is_empty(task_queue_t *tq);

#endif // TASK_QUEUE_H
