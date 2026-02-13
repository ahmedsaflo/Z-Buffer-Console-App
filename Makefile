hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Rectangle.o -c ./src/Rectangle.cpp
	g++ -I ./include/ -o ./lib/Triangle.o -c ./src/Triangle.cpp
	g++ -I ./include/ -o ./lib/Star.o -c ./src/Star.cpp
	g++ -I ./include/ -o ./lib/TekYonluListe.o -c ./src/TekYonluListe.cpp
	g++ -I ./include/ -o ./lib/CiftYonluListe.o -c ./src/CiftYonluListe.cpp
	g++ -I ./include/ -o ./lib/EkranYonetici.o -c ./src/EkranYonetici.cpp
	g++ -I ./include/ -o ./bin/program ./lib/Rectangle.o ./lib/Triangle.o ./lib/Star.o ./lib/TekYonluListe.o ./lib/CiftYonluListe.o ./lib/EkranYonetici.o ./src/main.cpp

calistir:
	./bin/program