all:derle bagla calistir
derle:	
	    g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
		g++ -c -I "./include" ./src/YDugum.cpp -o ./lib/YDugum.o
		g++ -c -I "./include" ./src/Yigin.cpp -o ./lib/Yigin.o
		g++ -c -I "./include" ./src/AVLAgaci.cpp -o ./lib/AVLAgaci.o
		g++ -c -I "./include" ./src/Yardimci.cpp -o ./lib/Yardimci.o
		g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	    

bagla:
	g++  ./lib/main.o ./lib/Dugum.o ./lib/YDugum.o ./lib/Yigin.o ./lib/AVLAgaci.o ./lib/Yardimci.o -o ./bin/program
	
calistir:
	./bin/program.exe