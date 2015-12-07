#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>

template <class T>
class Node {
 public:
  T data_;
  Node<T> *next_;
};

template <class T>
class Queue {
 public:
  Queue();
  ~Queue();
  void push(const T data);
  void pop();
  T top() const;
  void clear();
  int is_empty() const;
  int get_size() const;
 private:
  Node<T> *head_;
  Node<T> *tail_;
  int size_;
};

template <class T>
inline Queue<T>::Queue() : head_(NULL), tail_(NULL), size_(0) { }

template <class T>
inline Queue<T>::~Queue() { 
  clear(); 
}

template <class T>
inline void Queue<T>::push(T data) {
  Node<T> *p = new Node<T>;
  p -> data_ = data;
  p -> next_ = NULL;
  if(is_empty()) {
    head_ = tail_ = p;
  } else {
    tail_ -> next_ = p;
    tail_ = p;
  }
  ++size_;
}

template <class T>
inline void Queue<T>::pop() {
  assert(!is_empty());
  Node<T> *p = head_;
  head_ = head_ -> next_;
  delete(p);
  p = NULL;
  --size_;
}

template <class T>
inline T Queue<T>::top() const {
  assert(!is_empty());
  return head_ -> data_;
}

template <class T>
inline void Queue<T>::clear() {
  while(!is_empty())
    pop();
}

template <class T>
inline int Queue<T>::is_empty() const {
  return NULL == head_;
}

template <class T>
inline int Queue<T>::get_size() const {
  return size_;
}

#endif  // QUEUE_H
