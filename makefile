okCXX = g++
CXXFLAGS = -Wall


proj4: War.o Heavy.o Medium.o Light.o Warhorse.o Untrained.o Horse.o driver.cpp
	$(CXX) $(CXXFLAGS) Horse.o Untrained.o Warhorse.o Light.o Medium.o Heavy.o War.o driver.cpp -o proj4


War.o: War.cpp War.h Heavy.o Medium.o Light.o Warhorse.o Untrained.o Horse.o
	$(CXX) $(CXXFLAGS) -c War.cpp


Heavy.o: Heavy.cpp Heavy.h Untrained.o Horse.o Warhorse.o
	$(CXX) $(CXXFLAGS) -c Heavy.cpp


Medium.o: Medium.cpp Medium.h Untrained.o Horse.o Warhorse.o
	$(CXX) $(CXXFLAGS) -c Medium.cpp


Light.o: Light.cpp Light.h Untrained.o Horse.o Warhorse.o
	$(CXX) $(CXXFLAGS) -c Light.cpp


Warhorse.o: Warhorse.cpp Warhorse.h Untrained.o Horse.o
	$(CXX) $(CXXFLAGS) -c Warhorse.cpp


Untrained.o: Untrained.cpp Untrained.h Horse.o
	$(CXX) $(CXXFLAGS) -c Untrained.cpp

Horse.o: Horse.cpp Horse.h
	$(CXX) $(CXXFLAGS) -c Horse.cpp


clean:
	rm -f *.o
	rm -f *~

run:
	./proj4 proj4_data.txt


val:
	valgrind ./proj4 proj4_data.txt
