CC=g++
TARGET=volimage
FLAGS=-std=c++11 -I ./LibVolImage -L ./LibVolImage -lvolimage

.PHONY: clean

$(TARGET): driver.o
	$(CC) -o $(TARGET) driver.o $(FLAGS)

driver.o: driver.cpp
	make -C ./LibVolImage/
	$(CC) -c -o driver.o driver.cpp $(FLAGS)

clean:
	rm -f *.o ./volimage
	make -C ./LibVolImage clean

run: $(TARGET)
	export LD_LIBRARY_PATH=LibVolImage/; \
	./volimage ./brain_mri_raws/MRI

extract: $(TARGET)
	export LD_LIBRARY_PATH=LibVolImage/; \
	./volimage ./brain_mri_raws/MRI -x 1 ./output/

diff: $(TARGET)
	export LD_LIBRARY_PATH=LibVolImage/; \
	./volimage ./brain_mri_raws/MRI -d 1 0 ./output/