
#ifndef QUEUE_INTERFACE
#define QUEUE_INTERFACE
template<class ItemType>
class QueueInterface {
public:
    virtual bool isEmpty() const = 0;
    virtual bool enqueue(const ItemType& anEntry) = 0;
    virtual bool dequeue() = 0;
    //virtual ItemType dequeue() const = 0; // this function should not be here
    
    virtual ~QueueInterface() { }
}; 
#endif
