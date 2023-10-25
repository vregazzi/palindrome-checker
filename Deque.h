#include <iostream>
#include <stdexcept>
#include "DoublyLinkedList.h"

template <typename T>
class Deque
{
private:
    DoublyLinkedList<T> backing;

public:
    Deque() : backing() {}

    void enqueue_to_front(T value)
    {
        backing.push_head(value);
    }

    void enqueue_to_back(T value)
    {
        backing.push_tail(value);
    }

    T dequeue_from_front()
    {
        return backing.pop_head();
    }

    T dequeue_from_back()
    {
        return backing.pop_tail();
    }

    T peek_front()
    {
        return backing.get(0);
    }

    T peek_back()
    {
        return backing.get(backing.size() - 1);
    }

    int size()
    {
        return backing.size();
    }

    bool is_empty()
    {
        return backing.is_empty();
    }
};