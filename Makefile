
# rez: main.cpp figures.cpp
# 	g++ -Wall -o rez main.cpp figures.cpp -lglut -lX11 -lGL -lGLU

# clean:
# 	rm -rf rez

bin/prog: build/main.o build/point.o build/line.o build/triangle.o build/square.o
	g++ build/main.o build/point.o build/line.o build/triangle.o build/square.o -o bin/prog -lglut -lX11 -lGL -lGLU

build/main.o: src/main.cpp src/figures.h
	g++ -Wall -Werror -c src/main.cpp -o build/main.o 

build/point.o: src/point.cpp src/figures.h
	g++ -Wall -Werror -c src/point.cpp -o build/point.o 

build/line.o: src/line.cpp src/figures.h
	g++ -Wall -Werror -c src/line.cpp -o build/line.o 

build/triangle.o: src/triangle.cpp src/figures.h
	g++ -Wall -Werror -c src/triangle.cpp -o build/triangle.o 

build/square.o: src/square.cpp src/figures.h
	g++ -Wall -Werror -c src/square.cpp -o build/square.o 

clean: 
	rm -rf bin/prog build/*.o

.PHONY: all clean 