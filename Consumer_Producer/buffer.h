#pragma once
/**
* Assignment 4: Producer Consumer Problem
 * @file buffer.h
 * @author Arthur Santamaria
 * @brief header file for the buffer class
 * @version 0.1
 */
#ifndef ASSIGN4_BUFFER_H
#define ASSIGN4_BUFFER_H

 // Define the data type of the buffer items
typedef int buffer_item;

/**
 * @brief The bounded buffer class. The number of items in the buffer cannot exceed the size of the buffer.
 */
class Buffer {
private:
    //5 Variables, buffer array that will be initialized at compilation to size of constructor
    //Buffer_size will take the size of the constructor and size the array to that.
    //3 Integers to keep track of the front, back of circular array and a count to determine amount of elements within array.
    buffer_item* buffer;
    buffer_item BUFFER_SIZE;
    int front;
    int back;
    int count;

public:
    /**
     * @brief Construct a new Buffer object
     * @param size the size of the buffer
     */
    Buffer(int size = 5);

    /**
     * @brief Destroy the Buffer object
     */
    ~Buffer();

    /*@brief Copy Constructor that initializes the data members of the buffer class using another object of the same class
    * @param source of original variables
    * This function was needed for cppcheck on gradescope.
    */
    Buffer(const Buffer& src);

    /*@brief Overloaded operator that was needed for cppcheck on gradescope. Allows for overloading
    * @param = rhs = righthandside of assignment operator
    */
    Buffer operator=(const Buffer& rhs);
    /**
     * @brief Insert an item into the buffer
     * @param item the item to insert
     * @return true if successful
     * @return false if not successful
     */
    bool insert_item(buffer_item item);

    /**
     * @brief Remove an item from the buffer
     * @param item the item to remove
     * @return true if successful
     * @return false if not successful
     */
    bool remove_item(buffer_item* item);

    /**
     * @brief Get the size of the buffer
     * @return the size of the buffer
     */
    int get_size();

    /**
     * @brief Get the number of items in the buffer
     * @return the number of items in the buffer
     */
    int get_count();

    /**
     * @brief Chceck if the buffer is empty
     * @return true if the buffer is empty, else false
     */
    bool is_empty();
    /**
     * @brief Check if the buffer is full
     * @return true if the buffer is full, else false
     */
    bool is_full();

    /**
     * @brief Print the buffer
     */
    void print_buffer();
};
#endif //ASSIGN4_BUFFER_H