#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include"Perlin.h"
#include"NoiseVisualization.h"
using namespace std;
int main() {
	Perlin* perlinNoise = new Perlin;
	//������������
	vector<vector<int>>* grayScale = perlinNoise->getPerlinNoise(500, 500);
	//����������ʾ
	NoiseVisualization* noiseVisualization = new NoiseVisualization(grayScale,"./");

	return 0;
}