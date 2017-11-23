//Seuillage et différence
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
}
