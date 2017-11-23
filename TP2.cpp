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

// cette fonction double la taille de l'image en recopiant les valeurs 4 fois

vector<vector<int>> agrandit(vector<vector<int>> pgm){

	vector<vector<int>> pgmgrand;
	int width, height;
    width = pgm[0].size();
    height = pgm.size();// taile du fichier de base à doubler

	//remplit la nouvelle matrice de vector de taille 2n
	vector<int> ligne(width*2) ;
	for(int i=0;i<2*height;i++)
	{
		pgmgrand.push_back(ligne);
	}


	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
		pgmgrand[2*i][2*j]=pgm[i][j];
		pgmgrand[2*i+1][2*j]=pgm[i][j];
		pgmgrand[2*i][2*j+1]=pgm[i][j];
		pgmgrand[2*i+1][2*j+1]=pgm[i][j];
		}
	}
return pgmgrand;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> table;
	table = Lecture_PGM();
	table = agrandit(table);
	Ecriture_PGM(table);

	return 0;
}

