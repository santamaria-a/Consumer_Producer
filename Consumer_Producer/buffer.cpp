/**
* Assignment 4: Producer Consumer Problem
 * @file buffer.h
 * @author Arthur Santamaria
 * @brief header file for the buffer class
 * @version 0.1
 */
#include <iostream>
#include "buffer.h"
using namespace std;
// Define the data type of the buffer items
/**
* @brief The bounded buffer class. The number of items in the buffer cannot exceed the size of the buffer.
*/
/**
 * @brief Construct a new Buffer object
 * @param size the size of the buffer
 */
Buffer::Buffer(int size)
{
    this->BUFFER_SIZE = size; //Assigns 5 to buffer_size
    this->buffer = new int[BUFFER_SIZE]; //array[size]
    this->front = 0; // position of the front item
    this->back = 0; // position of the back item
    this->count = 0; //num of items in buffer
}

/**
 * @brief Destroy the Buffer object
 */
Buffer::~Buffer()
{
    delete[] buffer; //Deletes the array.
}

/**
 * @brief Insert an item into the buffer
 * @param item the item to insert
 * @return true if successful
 * @return false if not successful
 */
bool Buffer::insert_item(buffer_item item)
{
    if (!is_full()) //if buffer is not  full, add the item and index the back
    {
        buffer[back] = item; //stores the item into the array
        back = (back + 1) % BUFFER_SIZE; //shifts next location in array
        count++;
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Remove an item from the buffer
 * @param item the item to remove
 * @return true if successful
 * @return false if not successful
 */
bool Buffer::remove_item(buffer_item* item)
{
    if (!is_empty())//If buffer is not empty
    {
        *item = buffer[front]; //Deleteditem = front of circle buffer
        front = (front + 1) % BUFFER_SIZE; //Reassigns front and Increment circle buffer and reduce count size
        count--;
        return true;
    }
    else
    {
        cout << "-- Buffer is empty --" << endl;
        return false;
    }
}

/**
 * @brief Get the size of the buffer
 * @return the size of the buffer
 */
int Buffer::get_size()
{
    return BUFFER_SIZE;
}

/**
 * @brief Get the number of items in the buffer
 * @return the number of items in the buffer
 */
int Buffer::get_count()
{
    return count;
}

/**
 * @brief Chceck if the buffer is empty
 * @return true if the buffer is empty, else false
 */
bool Buffer::is_empty()
{
    if (count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief Check if the buffer is full
 * @return true if the buffer is full, else false
 */
bool Buffer::is_full()
{
    if (count == BUFFER_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Print the buffer
 *
 */
void Buffer::print_buffer()
{
    int j = 0;
    cout << "Buffer: [";

    for (int i = front; j < count; i = (i + 1) % BUFFER_SIZE)
    {
        if (j == count - 1)
        {
            cout << buffer[i];
        }
        else
        {
            cout << buffer[i] << ", ";
        }
        j++;
    }

    cout << "]" << endl;
}

//Source https://stackoverflow.com/questions/24227980/c-copy-constructor-for-class-with-dynamically-allocated-array
//Copy Constructor needed for cppcheck on gradescope. Variables are assigned from source.
Buffer::Buffer(const Buffer& src)
{
    front = src.front;
    back = src.back;
    count = src.count;
    BUFFER_SIZE = src.BUFFER_SIZE;
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = src.buffer[i];
    }
}
//Source https://stackoverflow.com/questions/24227980/c-copy-constructor-for-class-with-dynamically-allocated-array

Buffer Buffer::operator=(const Buffer& rhs)
{
    if (this == &rhs)
    {
        return (*this);
    }
    delete[] buffer;

    front = rhs.front;
    back = rhs.back;
    count = rhs.count;
    BUFFER_SIZE = rhs.BUFFER_SIZE;
    buffer = new int[BUFFER_SIZE];
    return *this;
}

