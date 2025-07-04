target : testwindGauge.o windGauge.o
	g++ -o target testwindGauge.o windGauge.o

testwindGauge.o : testwindGauge.cpp windGauge.h
	g++ -c testwindGauge.cpp

windGauge.o : windGauge.cpp windGauge.h
	g++ -c windGauge.cpp

clean :
	rm testwindGauge.o windGauge.o target