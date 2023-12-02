#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
using namespace std;

class Event
{
private:
   char eventtype;
   int arrivtime;
   int transtime;

public:
   Event();
   Event(const Event &obj);
   Event(int time, int transTime);
   Event(int time, int transTime, char type);

   int getarrivt() const;
   int gettranstime() const;
   char geteventtype() const;
};
#endif
