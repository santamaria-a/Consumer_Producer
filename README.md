# Consumer_Producer
A solution to the consumer-producer problem using a bounded-buffer

The program is running as a solution to the producer and consumer problem by using a
bounded buffer. The producer and consumer acts as two different processes trying to
access a resource in the circular bounded buffer. They are synchronized using
semaphores to insert and delete items from the buffer and the outcome results in the
producer not producing when the buffer is full and the consumer not to consume
whenever it is empty. Using mutex and semaphores this can be accomplished by
locking the mutex whenever the producer is producing or consumer is consuming, then
releasing the lock whenever it is done doing this(critical section). To keep track of the
buffer size, semaphores can be used to ensure that the buffer is not full with max size of
five, and also not empty whenever it is 0.
