// TP2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

vector<vector<int>> Lecture_PGM(){//lit un pgm, remplit le tableau
	
   string line;
   int val;
   fstream myfile_PGM("lena.pgm");
   getline(myfile_PGM, line);
   getline(myfile_PGM, line);
   vector<vector<int>> table;
   int width, height, poubelle;
   myfile_PGM >> width >> height >> poubelle;
   for (int i = 0; i<height; i++){
	   table.push_back(vector<int>(width));
	   for(int j = 0; j<width; j++){
		   myfile_PGM >> table[i][j];
	   }
   }
   myfile_PGM.close();
   return table;
}

void Ecriture_PGM(vector<vector<int>> table){//lit un tableau, remplit le pgm

   string line;
   fstream myfile_PGM("vide.pgm");
   myfile_PGM << "P2" << endl << "#" << endl;
   int width, height;
   width = table[0].size();
   height = table.size();
   myfile_PGM << width << " " << height << endl << 255 << endl;
   for (int i = 0; i<height; i++){
	   for(int j = 0; j<width; j++){
		   myfile_PGM << table[i][j] << " ";
	   }
	   myfile_PGM << endl;
   }


   myfile_PGM.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a;
	std::cout<<"helloworld";
	std::cin>>a;
	return 0;
}

