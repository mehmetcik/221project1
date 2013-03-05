//ArrayQueue.hpp
#ifndef _ARRAYQUEUE_HPP
#define _ARRAYQUEUE_HPP

// It's annoying, but templated classes are best defined in a single
// file.  So, we just include the .cpp file at the end of the .hpp.  See
// the end of this file.

#include "TodoList.hpp"

// This skeleton file (along with the .cpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of TodoList
template <typename T>
class ArrayQueue: public TodoList<T>
{
 public:
  ArrayQueue(); // constructor
  
  // TodoList interface
  void add(T elem);
  T remove();
  T get_next();
  bool is_empty();

  ~ArrayQueue(); // destructor

 private:
  // A helper function that consumes a number and ensures the queue
  // has enough space for that many elements.  (In C++, it might be
  // better style--and functionality--to make the argument (and all 
  // of our parameters) unsigned ints rather than ints.. but things
  // are complex enough for this assignment!
  void ensure_capacity(int n);

  // a pointer to the underlying array with elements of type T
  // use an explicit pointer, NOT T array[..] so you can resize.
  T * array;

  // TODO: list additional private member variables here,
};

#include "ArrayQueue.cpp"

#endif
