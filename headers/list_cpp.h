#ifndef LIST_CPP_H
#define LIST_CPP_H

#include <gtest/gtest.h>
#include <initializer_list>
#include <iostream>

template <typename T> class List {
private:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  struct Node {
    value_type value;
    Node *next;
    Node(value_type value) : value(value), next(nullptr) {}
  };

  Node *head;
  Node *tail;
  size_type size_list;

public:
  List();
  ~List();
  void push_back(value_type);
  void pop_back();
  size_type size();
};

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size_list(0) {}

template <typename T> List<T>::~List() {
  while (head) {
    pop_back();
  }
}

template <typename T> void List<T>::pop_back() {
  if (head == tail) {
    delete head;
    head = nullptr;
    tail = nullptr;
  } else {
    Node *node = head;
    while (node->next != tail) {
      node = node->next;
    }
    delete tail;
    tail = node;
    tail->next = nullptr;
  }
  size_list--;
}

template <typename T> void List<T>::push_back(value_type value) {
  Node *new_node = new Node(value);
  if (!head) {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }
  size_list++;
}

template <typename T> typename List<T>::size_type List<T>::size() {
  return size_list;
}

#endif