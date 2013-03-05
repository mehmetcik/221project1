#ifndef _ARRAYQUEUE_CPP
#define _ARRAYQUEUE_CPP

//ArrayQueue.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of TodoList
template <typename T>
ArrayQueue<T>::ArrayQueue()
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  // TODO: implement constructor
}

template <typename T>
void ArrayQueue<T>::add(T /*elem*/)
{
  // TODO: uncomment parameter name (commented out so you don't get a warning)
  // TODO: implement add method
}

template <typename T>
T ArrayQueue<T>::remove()
{
  return (T)0;
  // TODO: implement remove method
}

template <typename T>
T ArrayQueue<T>::get_next()
{
  return (T)0;
  // TODO: implement get_next method
}

template <typename T>
bool ArrayQueue<T>::is_empty()
{
  return false;
  // TODO: implement is_empty method
}

// TODO: implement ensure_capacity (but leave this to last.. just start with lots of capacity!)
template <typename T>
void ArrayQueue<T>::ensure_capacity(int n)
{
  if (true /* TODO: if there's not already enough room */) {
    // Make plenty of room.
    int target_capacity = 0 /* TODO: the larger of n and twice the current capacity */;

    // TODO: Set the current array aside and make room for the new one.

    // TODO: Copy each element of the old array over.
    // Update front carefully as you go!  Can you just use front++?

    // TODO: Fix front and back and capacity so they correspond to the new array.

    // TODO: Delete the old array.
  }
}


template <typename T>
ArrayQueue<T>::~ArrayQueue()
{
  // TODO: implement the destructor

  // do any cleanup like deallocating
  // any dynamically allocated memory
}

#endif
