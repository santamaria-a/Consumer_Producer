/**
 * Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author Arthur Santamaria
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */
 // You must complete the all parts marked as "TODO". Delete "TODO" after you are
 // done.
 // Remember to add sufficient and clear comments to your code
#include "buffer.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

using namespace std;

// global buffer object
Buffer buffer;

// semaphores for full, empty
sem_t full;
sem_t empty;
// mutex lock
pthread_mutex_t mutex;

// Producer thread function
// producer has a unique thread id that will insert into circlular array
void* producer(void* param) {
    // Each producer insert its own ID into the buffer
    // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.

    buffer_item item = *((int*)param);
    // cout << "Item = " << item << endl;
    // NO LONGER SEG FAULTS had to pass unique id as 4th parameter on thread creation
    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000);
        // item = rand() % find_thread;
        // gets empty lock
        sem_wait(&empty); // Waits when there is no room

        // gets mutex lock
        pthread_mutex_lock(&mutex);
        if (buffer.insert_item(item)) {
            cout << "Producer " << item << ": Inserted item " << item << endl;
            buffer.print_buffer();
        }
        else {
            cout << "Producer error condition" << endl; // shouldn't come here
        }
        pthread_mutex_unlock(&mutex); // unlocks the mutex
        sem_post(&full);              // full ++ and releases the semaphore
    }
}

// Consumer thread function
// Consumes(removes) the item for circular array.
void* consumer(void* param) {
    buffer_item item;

    while (true) {
        /* sleep for a random period of time */
        usleep(rand() % 1000000);

        // Wait until at least 1 element to consume
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        if (buffer.remove_item(&item)) {
            cout << "Consumer "
                << "Removed item " << item << endl;
            buffer.print_buffer();
        }
        else {
            cout << "Consumer error condition" << endl; // shouldn't come here
        }

        pthread_mutex_unlock(&mutex); // unlocks the mutex
        sem_post(&empty);
    }
}

int main(int argc, char* argv[]) {

    // cli arguments , 1st sleep, 2nd producer, 3rd consumer
    int sleep_time = atoi(argv[1]);
    int prod_num_thread = atoi(argv[2]);
    int consum_num_thread = atoi(argv[3]);

    /* TODO: 2. Initialize buffer and synchronization primitives */

    pthread_t prod_thread[prod_num_thread];
    pthread_t consumer_threads[consum_num_thread];
    int nums[prod_num_thread];
    pthread_mutex_init(&mutex, NULL);

    // Initilization of global semaphores
    sem_init(&empty, 0, 5); // initialized empty to buffersize
    sem_init(&full, 0, 0);  // initialzed full to 0

    /* TODO: 3. Create producer thread(s).
     * You should pass an unique int ID to each producer thread, starting from 1
     * to number of threads */
     //(void *) &j
    for (int i = 0; i < prod_num_thread; i++) {
        nums[i] = i + 1;
        pthread_create(&prod_thread[i], NULL, producer, &nums[i]);
    }

    /* TODO: 4. Create consumer thread(s) */
    for (int i = 0; i < consum_num_thread; i++) {
        pthread_create(&consumer_threads[i], NULL, consumer, NULL);
    }

    /* TODO: 5. Main thread sleep */
    sleep(sleep_time);
    cout << "Times up " << endl;

    /* TODO: 6. Exit */
    exit(0);
}