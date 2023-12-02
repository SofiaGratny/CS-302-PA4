#include "arrayqueue.h"
#include "event.h"

template<class ItemType>
arrayqueue<ItemType>::arrayqueue(){
    front = -1;
    back = -1;
    count = 0; // you put a minus sign here
}

template<class ItemType>
bool arrayqueue<ItemType>::isEmpty() const{
    return count == 0;
}

template<class ItemType>
bool arrayqueue<ItemType>::enqueue(const ItemType& newEntry){
    bool result = false;
    if(count < DEFAULT_CAPACITY){
        if(front == -1){
            front = 0;
        }
        back = (back + 1) % DEFAULT_CAPACITY;
        items[back] = newEntry;
        count++;
        result = true;
    }
    return result;
}

template<class ItemType>
bool arrayqueue<ItemType>::dequeue(){
    bool result = false;
    if(!isEmpty()){
        front = (front + 1) % DEFAULT_CAPACITY;
        count--;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType arrayqueue<ItemType>::peekFront() const{
    bool ableToPeek = !isEmpty();
    if(ableToPeek){
        return items[front];
    }
    throw ("Empty Queue"); //throw
}

template<class ItemType>
arrayqueue<ItemType>::~arrayqueue(){ }


template class arrayqueue<Event>;