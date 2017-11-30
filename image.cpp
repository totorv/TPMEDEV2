//Seuillage et différence
<<<<<<< HEAD
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//différence image PGM
int dif(Vector<int> Mat1, Vector<int> Mat2) {
	int somme;
	int taille = size(Mat1);
	for (int i=0;i<taille; i++){
		for(int k=0;k<taille;k++){
				somme += abs(Mat1[i,k] - Mat2[i, k]);
			}
		}
	return somme;
}

void seuillage(int seuil, Vector<int> Mat) {
	int somme;
	int taille = size(Mat);
	for (int i = 0; i<taille; i++) {
		for (int k = 0; k<taille; k++) {
			if (Mat[i,k] < seuil) {
				Mat[i, k]= 0;
			}
			else {
				Mat[i, k] = 256;
			}
		}
	}
=======
#include "stdafx.h"
using namespace std;

//différence image PGM
vector<vector<int>> dif(vector<vector<int>> Mat1, vector<vector<int>> Mat2) {
	vector<vector<int>> res;
	int width, height;
    width = Mat1[0].size();
    height = Mat1.size();
	for (int i=0;i<height; i++){
		res.push_back(vector<int>(width));
		for(int k=0;k<width;k++){
				res[i][k] = abs(Mat1[i][k] - Mat2[i][k]);
			}
		}
	return res;
}

vector<vector<int>> seuillage(int seuil, vector<vector<int>> Mat) {
	vector<vector<int>> res;
	int width, height;
    width = Mat[0].size();
    height = Mat.size();
	for (int i = 0; i<height; i++) {
		res.push_back(vector<int>(width));
		for (int k = 0; k<width; k++) {
			if (Mat[i][k] < seuil) {
				res[i][k]= 0;
			}
			else {
				res[i][k] = 255;
			}
		}
	}
	return res;
>>>>>>> bf755c5e8662a7ceba8e8110283e2141f089c6c1
}
