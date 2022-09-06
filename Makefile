
#
# Makefile for P2 (submitted version)
# COSC 052
# Fall 2019
#

DRIVER_NAME = main
SUBMIT_NAME = submit
LIBRARY_NAME = agLibrary


a.out: $(DRIVER_NAME).o VehicleLog.o Vehicle.o Resources.o Exceptions.o
	g++ -std=c++11 $(DRIVER_NAME).o VehicleLog.o Vehicle.o Resources.o Exceptions.o

$(DRIVER_NAME).o: $(DRIVER_NAME).cpp $(DRIVER_NAME).h VehicleLog.h Vehicle.h Resources.h
	g++ -std=c++11 -c $(DRIVER_NAME).cpp

VehicleLog.o: VehicleLog.cpp VehicleLog.h Vehicle.h Exceptions.h
	g++ -std=c++11 -c VehicleLog.cpp

Vehicle.o: Vehicle.cpp Vehicle.h Resources.h
	g++ -std=c++11 -c Vehicle.cpp

Resources.o: Resources.cpp Resources.h
	g++ -std=c++11 -c Resources.cpp

Exceptions.o: Exceptions.cpp Exceptions.h
	g++ -std=c++11 -c Exceptions.cpp


.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(DRIVER_NAME).cpp $(DRIVER_NAME).h VehicleLog.cpp VehicleLog.h Vehicle.cpp Vehicle.h Exceptions.cpp Exceptions.h Resources.cpp Resources.h Makefile

clean:
	rm -f *.o core a.out


