#pragma
/*Debug模式下读文件961秒，release模式下55秒*/
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Point
{
	string x;
	string y;
	string z;
};
// 利用strtok()将字符数组分割成字符串，以空格隔开
Point split(char *buff, Point point)
{
	point.x = strtok(buff, " ");
	point.y = strtok(nullptr, " ");
	point.z = strtok(nullptr, " ");
	return point;
}

void readFile(FILE* file)
{
	if (!file)
	{
		cout << "file can't open";
		return;
	}

	Point point;
	Point point1, point2, point3;
	const char con1 = 'n';
	char buff[255];
	int flag = 0;
	// 从file按行读取文件，并存到字符数组buff[]里
	while (fgets(buff, 255, (FILE*)file))  // 读满256个字符或者遇到换行符'\n'停止读取
	{
		// 遇到“nVectics 3”开始从下一行连续读取3行
		if (buff[0] == con1) {
			flag = 1;
			continue;
		}
		if (flag > 0)
		{
			if (flag == 1)
			{
				point1 = split(buff, point);
			}
			if (flag == 2)
			{
				point2 = split(buff, point);
			}
			if (flag == 3)
			{
				point3 = split(buff, point);
			}
			flag++;
			if (flag == 4)
			{
				double a_x = stof(point1.x);
				double a_y = stof(point1.y);
				double a_z = stof(point1.z);

				double b_x = stof(point2.x);
				double b_y = stof(point2.y);
				double b_z = stof(point2.z);

				double c_x = stof(point3.x);
				double c_y = stof(point3.y);
				double c_z = stof(point3.z);

				// 测试
				/*cout << fixed << setprecision(10) << a_x << " " << a_y << " " << a_z << endl;
				cout << fixed << setprecision(10) << b_x << " " << b_y << " " << b_z << endl;
				cout << fixed << setprecision(10) << c_x << " " << c_y << " " << c_z << endl;*/

				flag = 0;
			}
		}
	}
}
int main()
{
	FILE* file = fopen("G://40000000Cos.ter", "rb");
	float start = clock();
	readFile(file);
	cout << "读取地形文件用时" << (clock() - start) / 1000 << "秒" << endl;

	system("pause");
	return 0;
}
