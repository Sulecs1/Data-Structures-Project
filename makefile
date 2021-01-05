hepsi: derle calistir

derle:
	g++ -I ./include -o ./lib/Kisi.o  -c ./src/Kisi.cpp
	g++ -I ./include -o ./lib/stack.o -c ./src/stack.cpp
	g++ -I ./include -o ./lib/avltree.o -c ./src/avltree.cpp
	g++ -I ./include -o ./bin/main.exe ./lib/avltree.o ./lib/Kisi.o ./lib/stack.o ./src/main.cpp

calistir:
	./bin/main.exe