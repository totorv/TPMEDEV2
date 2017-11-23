// TP2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

void Lecture_PGM(){//lit un pgm, remplit le txt

   string line;
   fstream myfile_PGM("lena.pgm");
   fstream myfile_txt("lena.txt");
   cout << "0" << endl;
   if (myfile_PGM.is_open()){
	   cout << "1" << endl;
       while (myfile_PGM.good()){
		 cout << "2" << endl;
         getline(myfile_PGM, line);
         myfile_txt << line << endl;;
       }
   }

   myfile_PGM.close();
   myfile_txt.close();

}

void Ecriture_PGM(){//lit un txt, remplit le pgm

   string line;
   fstream myfile_PGM("lena.pgm");
   fstream myfile_txt("lena.txt");

   if (myfile_txt.is_open()){
       while (myfile_txt.good()){
         getline(myfile_txt, line);
         myfile_PGM << line << endl;;
       }
   }

   myfile_PGM.close();
   myfile_txt.close();

}

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	std::cout<<"helloworld";
	std::cin>>a;
	return 0;
}

