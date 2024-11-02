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
  List(std::initializer_list<value_type>);
  ~List();
  void push_back(value_type);
  void pop_back();
  void push_front(value_type);

  size_type size();
  class iterator;
  iterator begin();
  iterator end();
  iterator insert(iterator, value_type);

  class iterator {
  public:
    using value_type = T;
    using pointer = T *;

  private:
    Node *current;

  public:
    friend class List;
    iterator(Node *current) : current(current) {}
    value_type operator*() { return current->value; }
    iterator operator++() {
      if (current) {
        current = current->next;
      }
      return *this;
    }
    bool operator==(iterator other) { return current == other->current; }
    bool operator!=(iterator other) { return current != other->current; }
  };
};

template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size_list(0) {}

template <typename T>
List<T>::List(std::initializer_list<value_type> list)
    : head(nullptr), tail(nullptr), size_list(0) {
  for (auto it = list.begin(); it < list.end(); it++) {
    push_back(*it);
  }
}

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

template <typename T> void List<T>::push_front(value_type value) {
  Node *new_node = new Node(value);
  if (!head) {
    head = new_node;
    tail = new_node;
  } else {
    new_node->next = head;
    head = new_node;
  }
  size_list++;
}

template <typename T> typename List<T>::iterator List<T>::begin() {
  return iterator(head);
}

template <typename T> typename List<T>::iterator List<T>::end() {
  return iterator(nullptr);
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator pos, value_type value) {
  Node *node_pos = pos.current;
  Node *new_node = new Node(value);
  if (node_pos == head) {
    if (!head) {
      head = new_node;
      tail = new_node;
      new_node->next = nullptr;
    } else {
      new_node->next = head;
      head = new_node;
    }
  } else {
    Node *current = head;
    while (current->next != node_pos) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
  size_list++;
  return iterator(new_node);
}

#endif