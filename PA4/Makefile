outputq1q2q3q4: q1.o q2.o q3.o
    g++ q1.o -o outputq1
    g++ q2.o -o outputq2
    g++ q3.o -o outputq3

q1.o: q1.cpp
    g++ -c q1.cpp

q2.o: q2_1.cpp MinHeap.h
    g++ -c q2_1.cpp

q3.o: q2_3.cpp MinHeap.h
    g++ -c q2_3.cpp

clean:
    rm *.o outputq1 outputq2 outputq3 