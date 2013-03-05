//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
template <typename T>
LinkedListQueue<T>::LinkedListQueue()
{
  head = NULL;
  tail = NULL;
  size = 0;
}

template <typename T>
void LinkedListQueue<T>::add(T elem)
{
  if(head == NULL)
    {
      head = new node;
      head->next = NULL;
      head->data = elem;
      tail = head;
      size++;
    }
  else
    {
      tail->next = new node;
      tail->next->data = elem;
      tail->next->next = NULL;
      tail = tail->next;
      size++;
    }
}

template <typename T>
T LinkedListQueue<T>::remove()
{
  assert(head != NULL);
  T ret = head->data;
  node* temp = head->next;
  delete head;
  head = temp;
  size--;
  return ret;
}

template <typename T>
T LinkedListQueue<T>::get_next()
{
  assert(head != NULL);
  return head->data;
}

template <typename T>
bool LinkedListQueue<T>::is_empty()
{
  return size==0;
}

template <typename T>
LinkedListQueue<T>::~LinkedListQueue()
{
  while(size > 0)
    this->remove();
}

#endif

