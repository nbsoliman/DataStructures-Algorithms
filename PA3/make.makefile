outputq1q2q3q4: q1.o q2.o q3.o q4.o
    g++ q1.o -o outputq1
    g++ q2.o -o outputq2
    g++ q3.o -o outputq3
    g++ q4.o -o outputq4

q1.o: q1.cpp
    g++ -c q1.cpp

q2.o: q2.cpp
    g++ -c q2.cpp

q3.o: q3.cpp
    g++ -c q3.cpp

q4.o: q4.cpp OrderedMap.h
    g++ -c q4.cpp

clean:
    rm *.o outputq1 outputq2 outputq3 outputq4