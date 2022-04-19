#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ > 0) {
      Node* temp_prev = nullptr;
      Node* temp = front_;
      Node* temp_next = temp->next;
      while (temp_next != nullptr) {
        temp->next = temp_prev;
        temp_prev = temp;
        temp = temp_next;
        temp_next = temp_next->next;
      }
      temp->next = temp_prev;
      Node* front = front_;
      front_ = back_;
      back_ = front;
    }
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 0) {
      reverse_recursive_helper(front_->next, front_);
      Node* temp = nullptr;
      front_->next = temp;
      Node* front = front_;
      front_ = back_;
      back_ = front;
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr) {
      return;
    }
    reverse_recursive_helper(curr->next, curr);
    curr->next = prev;
  }

}  // namespace assignment
