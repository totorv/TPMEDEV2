// TP2.cpp�: d�finit le point d'entr�e pour l'application console.
//
<<<<<<< HEAD


=======
//#include "image.h"
>>>>>>> bf755c5e8662a7ceba8e8110283e2141f089c6c1
#include "stdafx.h"
/*#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "image.h"
#include <vector>*/
using namespace std;


<<<<<<< HEAD
vector<vector<int>> Lecture_PGM(string filename){//lit un pgm, remplit le tableau
	
   string line;
   int val;
   fstream myfile_PGM(filename);
=======
vector<vector<int>> Lecture_PGM(string str){//lit un pgm, remplit le tableau
	
   string line;
   //int val;
   fstream myfile_PGM(str);
>>>>>>> bf755c5e8662a7ceba8e8110283e2141f089c6c1
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
    height = pgm.size();// taile du fichier de base � doubler

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
<<<<<<< HEAD
		} 
=======
		}
>>>>>>> bf755c5e8662a7ceba8e8110283e2141f089c6c1
	}
return pgmgrand;
}

vector<vector<int>> reduit(vector<vector<int>> pgm){

	vector<vector<int>> pgmpetit;
	int width, height;
    width = pgm[0].size();
    height = pgm.size();// taile du fichier de base � doubler

	//remplit la nouvelle matrice de vector de taille 2n
	vector<int> ligne(width/2) ;
	for(int i=0;i<height/2;i++)
	{
		pgmpetit.push_back(ligne);
	}

	int somme = 0;
	for(int i=0;i<height/2;i++)
	{
		for(int j=0;j<width/2;j++)
		{
			somme += pgm[2*i][2*j] +pgm[2*i+1][2*j] +pgm[2*i][2*j+1] +pgm[2*i+1][2*j+1];
			pgmpetit[i][j]=somme/4;
		}
	}
return pgmpetit;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> table;
<<<<<<< HEAD
	table = Lecture_PGM("lena.pmg");
	table = agrandit(table);
	Ecriture_PGM(table);

=======
	vector<vector<int>> table2;
	table = Lecture_PGM("lena.pgm");
	//table = agrandit(table);
	
	table = seuillage(50, table);
	Ecriture_PGM(table);
	//table2 = Lecture_PGM("vide.pgm");
	/*table2 = dif(table, table2);
	table2 = dif(table2, table);
	Ecriture_PGM(table2);*/
>>>>>>> bf755c5e8662a7ceba8e8110283e2141f089c6c1
	return 0;
}

