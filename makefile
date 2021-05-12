ingredients.exe: main.o Dish.o Sets.o
	g++ main.o Dish.o Sets.o -o ingredients.exe 
	
main.o: main.cpp Dish.o Sets.o
	g++ -c main.cpp

Dish.o: Dish.h Dish.cpp
	g++ -c Dish.cpp

Sets.o: Sets.h Sets.cpp
	g++ -c Sets.cpp

clean:
	rm *.o ingredients.exe

run:
	./ingredients.exe