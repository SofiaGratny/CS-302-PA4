//Authors: Sofia Gratny, Cassandra Macon//
//Date: 10/16/22//
//Purpose: Queues//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "arrayqueue.h"
#include "priorityarrayqueue.h"
#include "event.h"

void loadData(PQ<Event>*);
bool procarriv(bool, PQ<Event>*,  arrayqueue<Event>*);
bool initiatedepart(bool, PQ<Event>*, arrayqueue<Event>*, int*);

int main(){

    PQ<Event>* eventPQptr = new PQ<Event>();
    arrayqueue<Event>* lineQptr = new arrayqueue<Event>();
    bool openteller = true;
    int waittime = 0;
    int numcus = 0;

    int loopCount = 0; //temp
    bool arrivalatevent = true;
    bool firstLoop = true;
    int prevDeparture = 0;
    int* prevDep = &prevDeparture;

    do{
        if(firstLoop){
            std::cout << "doing first loop" << '\n';
            loadData(eventPQptr);
            openteller = procarriv(openteller, eventPQptr, lineQptr);
            numcus = 1;
            firstLoop = false;
            std::cout << "completed first loop" << '\n';
        }
        else{
            std::cout << "doing other loop" << '\n';
            Event PQ(eventPQptr->peekFront());
            std::cout << "created pq event" << '\n';
            Event lineEvent(lineQptr->peekFront());
            std::cout << "created line event" << '\n';
            std::cout << "checking if lineQptr is empty" << '\n';
            if(lineQptr->isEmpty()){
                std::cout << "lineQptr is empty" << '\n';
                if(PQ.geteventtype() == 'A'){
                    arrivalatevent = true;
                }
                else{
                    arrivalatevent = false;
                }
            }
            else{
                std::cout << "lineQptr is not empty" << '\n';
                if(PQ.geteventtype() == 'A'){
                    arrivalatevent = true;
                }
                else if(lineEvent.getarrivt() > eventPQptr->peekFrontPriority()){
                    arrivalatevent = true;
                }
                else{
                    arrivalatevent = false;
                }
            }
            if(arrivalatevent){
                openteller = procarriv(openteller, eventPQptr, lineQptr);
                numcus++;
            }
            else{
                openteller = initiatedepart(openteller, eventPQptr, lineQptr, prevDep);
            }
        }
        loopCount++;
    }while(!(eventPQptr->isEmpty()) && loopCount < 40); 

    cout << "Simulator Done\n" << endl;
    cout << "Final Stats" << endl;
    cout << "People who were processed: " << numcus << endl;
    cout << "Time waiting: " << waittime << endl;
    return 0;
}

void loadData(PQ<Event>* eventPQptr){
    ifstream inFile("bank-line.txt");
    int timearrived;
    int translength;
    while(inFile >> timearrived >> translength){
        std::cout << "got data " << timearrived << ", " << translength << '\n';
        Event addArrival(timearrived, translength);
        std::cout << "created event" << '\n';
        eventPQptr->enqueue(addArrival, timearrived);
    }
}

bool procarriv(bool openteller, PQ<Event>* eventPQptr, arrayqueue<Event>* lineQptr){
    Event pqEvent(eventPQptr->peekFront());
    if(openteller){
        int depTime = (pqEvent.getarrivt()+pqEvent.gettranstime());
        Event departure(pqEvent.getarrivt(), pqEvent.gettranstime(), 'D');
        eventPQptr->dequeue();
        eventPQptr->enqueue(departure, depTime);
        cout << "Calculating time for arrival Event: " << pqEvent.getarrivt() << endl;
        openteller = false;
    }
    else{
        lineQptr->enqueue(pqEvent);
        eventPQptr->dequeue();
        cout << "Calculating time for arrival Event: " << pqEvent.getarrivt() << endl;
        openteller = false;
    }
    return openteller;
}
bool initiatedepart(bool openteller, PQ<Event>* eventPQptr, arrayqueue<Event>* lineQptr, int* prevDep){
    bool nextFromLine;

    bool isLine = (!lineQptr->isEmpty());
    if(isLine){
        Event tempLine(lineQptr->peekFront());
        Event tempPQ(eventPQptr->peekFront());
        Event lineCustomer(tempLine.getarrivt(), tempLine.gettranstime(), 'D');
        nextFromLine = (lineCustomer.getarrivt() < tempPQ.getarrivt());
        if(nextFromLine){
            int depTime = (*prevDep + lineCustomer.gettranstime());
            eventPQptr->enqueue(lineCustomer, depTime);
            lineQptr->dequeue();
        }
    }
    else{
        Event depEvent(eventPQptr->peekFront());
        int transTime = depEvent.gettranstime();
        int addTime;
        if(depEvent.getarrivt() > *prevDep){
            addTime = depEvent.getarrivt();
        }
        else{
            addTime = *prevDep;
        }
        cout << "Processing a departure Event at time: " << (transTime + addTime) << endl;
        *prevDep = (transTime + addTime);
        eventPQptr->dequeue();
        return true;
    }
    return false;
}
