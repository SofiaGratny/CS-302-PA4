banksim: driver.o event.o priorityarrayqueue.o arrayqueue.o
	g++ driver.o event.o priorityarrayqueue.o arrayqueue.o -o banksim

driver.o: driver.cpp
	g++ -c driver.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

priorityarrayqueue.o: priorityarrayqueue.h priorityarrayqueue.cpp
	g++ -c priorityarrayqueue.cpp

arrayqueue.o: arrayqueue.h arrayqueue.cpp
	g++ -c arrayqueue.cpp

clean:
	rm banksim *.o
