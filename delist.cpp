#include "delist.h"
#include <iostream>

using namespace std;

// Add your function implementations here

DEList::DEList() {
  head = nullptr;
  tail = nullptr;
  len = 0;
}

DEList::~DEList() {
  while (!empty()) {
    pop_front();
  }
}

bool DEList::empty() const {
  return head == nullptr;
}
    
int DEList::size() const {
  return len;
}
  
int DEList::front() const {
  if (head == nullptr) {
    return -1;
  }
  return head->val;
}

int DEList::back() const {
  if (tail == nullptr) {
    return -1;
  }
  return tail->val;
}

void DEList::push_front(int new_val) {
  DEItem* n = new DEItem(new_val);
  n->prev = nullptr;
  n->next = head;

  if (head == nullptr) {
    tail = n;
  } else {
    head->prev = n;
  }
  head = n;
  len++;
}

void DEList::push_back(int new_val) {
  DEItem* n = new DEItem(new_val);
  n->prev = tail;
  n->next = nullptr;

  if (head == nullptr) {
    head = n;
  } else {
    tail->next = n;
  }
  tail = n;
  len++;
}
   
void DEList::pop_front() {
  if (head == nullptr) {
    return;
  }
  DEItem* del = head;
  if (head->next != nullptr) {
    head = head->next;
    head->prev = nullptr;
  } else {
    head = nullptr;
    tail = nullptr;
  }

  delete del;
  len--;

}
    
void DEList::pop_back() {
  if (head == nullptr) {
    return;
  }

  DEItem* del = tail;
  if (tail->prev != nullptr) {
    tail = tail->prev;
    tail->next = nullptr;
  } else {
    head = nullptr;
    tail = nullptr;
  }

  delete del;
  len--;

}

std::string DEList::conv_to_string() const {
  std::string res = "";
  DEItem* temp = head;
  while (temp != nullptr) {
    res += to_string(temp->val);
    if (temp->next != nullptr) {
       res += " ";
    }
    temp = temp->next;

  }
  return res;
}