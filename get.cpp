# Query: get

25 results - 3 files

driver.cpp:
   48:                 if(pq.getEventType() == 'A'){
   56:                 if(pq.getEventType() == 'A'){
   59:                 else if(lineEvent.getArrivalTime() > eventPQptr->peekFrontPriority()){
   97:         int depTime = (pqEvent.getArrivalTime()+pqEvent.getTransactionTime());
   98:         Event departure(pqEvent.getArrivalTime(), pqEvent.getTransactionTime(), 'D');
  101:         cout << "Processing an arrival event at time: " << pqEvent.getArrivalTime() << endl;
  107:         cout << "Processing an arrival event at time: " << pqEvent.getArrivalTime() << endl;
  119:         Event lineCustomer(tempLine.getArrivalTime(), tempLine.getTransactionTime(), 'D');
  120:         nextFromLine = (lineCustomer.getArrivalTime() < tempPQ.getArrivalTime());
  122:             int depTime = (*prevDep + lineCustomer.getTransactionTime());
  129:         int transTime = depEvent.getTransactionTime();
  131:         if(depEvent.getArrivalTime() > *prevDep){
  132:             addTime = depEvent.getArrivalTime();

event.cpp:
  12:    arrivalTime = obj.getArrivalTime();
  13:    transactionTime = obj.getTransactionTime();
  14:    eventType = obj.get_type();
  31: int Event::getArrivalTime() const
  36: int Event::getTransactionTime() const
  41: char Event::getEventType() const

event.h:
  21:    int getArrivalTime() const;
  22:    int getTransactionTime() const;
