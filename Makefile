all: compile link

compile:
	g++ -fexceptions -DSFML_STATIC -I"C:/Users/klove/Downloads/SFML/SFML-2.5.1 for MINGW/SFML-2.5.1/include" -c  ${fileDirname}\\**.cpp  ${fileDirname}\\**.h

link: 
	g++ **.o -o main -L"C:/Users/klove/Downloads/SFML/SFML-2.5.1 for MINGW/SFML-2.5.1/lib" -lsfml-graphics -lsfml-window -lsfml-system