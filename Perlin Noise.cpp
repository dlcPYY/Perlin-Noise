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
	/*(i, j, k, l)
	* i:ͼ��ĸ�
	* j:ͼ��ĳ�
	* k:�������ͣ�0��1,2
	* l:�Ƿ�ʹ��ȫ���Ż�
	*/
	vector<vector<int>>* grayScale = perlinNoise->getPerlinNoise(360, 360, 1, false);
	//����������ʾ
	NoiseVisualization* noiseVisualization = new NoiseVisualization(grayScale,"./");

	return 0;
}