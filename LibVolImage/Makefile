CC=g++
TARGET=libvolimage.so
FLAGS=-fPIC -shared -std=c++11

$(TARGET): VolImage.o
	$(CC) -o $(TARGET) VolImage.o $(FLAGS)

VolImage.o: VolImage.cpp VolImage.h
	$(CC) -c -o VolImage.o VolImage.cpp $(FLAGS)

clean:
	rm -f *.o *.so