#include "event.h"

Event::Event()
{
   arrivtime = 0;
   transtime = 0;
   eventtype = ' ';
}

Event::Event(const Event &obj)
{
   arrivtime = obj.getarrivt();
   transtime = obj.gettranstime();
   eventtype = obj.geteventtype();
}

Event::Event(int arrTime, int transTime)
{
   arrivtime = arrTime;
   transtime = transTime;
   eventtype = 'A';
}

Event::Event(int arrTime, int transTime, char type)
{
   arrivtime = arrTime;
   transtime = transTime;
   eventtype = type;
}

int Event::getarrivt() const
{
   return arrivtime;
}

int Event::gettranstime() const
{
   return transtime;
}

char Event::geteventtype() const
{
   return eventtype;
}
