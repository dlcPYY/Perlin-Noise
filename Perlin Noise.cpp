#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include"Perlin.h"
#include"NoiseVisualization.h"
#include"ValueNoise.h"
#include"SimplexNoise.h"
using namespace std;
void Readin(int& rowl, int& col, int& type, int& edgeOptimization) {
	std::ifstream in("./config");
	if (!in.is_open())
	{
		std::cout << "Error opening Configure file!";
		return;
	}
	else {
		in >> rowl >> col >> type >> edgeOptimization;
	}
	in.close();
}
int main() {
	//������������
	/*(i, j, k, l)
	* i:ͼ��ĸ�
	* j:ͼ��ĳ�
	* k:�������ͣ�0��1,2
	* l:�Ƿ�ʹ��ȫ���Ż�
	*/
	//	perlinNoise->getPerlinNoise(360, 360, 0, false);
	int rowl, col, type;
	int edgeOptimization;
	vector<vector<int>>* grayScale;
	Readin(rowl, col, type, edgeOptimization);
	if (type == 0) {
		ValueNoise* valueNoise = new ValueNoise;
		grayScale = valueNoise->getNoise(rowl, col, edgeOptimization);
	}
	else if(type == 1) {
		Perlin* perlinNoise = new Perlin;
		grayScale = perlinNoise->getPerlinNoise(rowl, col, edgeOptimization);
	}
	else {
		SimplexNoise* simplexNoise = new SimplexNoise;
		grayScale = simplexNoise->getNoise(rowl, col, edgeOptimization);
	}
	
	
	
	//����������ʾ
	string resultPath;
	if (type == 0) {
		resultPath = "./Result/Wood";
	}
	else if (type == 1) {
		resultPath = "./Result/Cloud";
	}
	else {
		resultPath = "./Result/New";
	}
	NoiseVisualization* noiseVisualization = new NoiseVisualization(grayScale, resultPath);

	return 0;
}