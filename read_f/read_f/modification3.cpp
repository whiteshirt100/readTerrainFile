#pragma
/*Debugģʽ�¶��ļ�101�룬releaseģʽ��41��*/
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
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
};

void readFile(FILE* file)
{
	if (!file)
	{
		cout << "file can't open";
		return;
	}
	Point point1, point2, point3;
	const char con = 'n';
	char buff[255];
	int flag = 0;
	// ��file���ж�ȡ�ļ������浽�ַ�����buff[]��
	while (fgets(buff, 255, (FILE*)file)) // ����256���ַ������������з�'\n'ֹͣ��ȡ
	{
		// ������nVectics 3����ʼ����һ��������ȡ3��
		if (buff[0] == con) {
			flag = 1;
			continue;
		}
		if (flag > 0)
		{
			if (flag == 1)
			{	// ��sscanf_s���ַ�������תΪ�����Ͳ�����point
				sscanf_s(buff, "%f %f %f", &(point1.x), &(point1.y), &(point1.z));
			}
			if (flag == 2)
			{
				sscanf_s(buff, "%f %f %f", &(point2.x), &(point2.y), &(point2.z));
			}
			if (flag == 3)
			{
				sscanf_s(buff, "%f %f %f", &(point3.x), &(point3.y), &(point3.z));
			}
			flag++;
			if (flag == 4)
			{
				// ����
				/*cout << fixed << setprecision(10) << a_x << " " << a_y << " " << a_z << endl;
				cout << fixed << setprecision(10) << b_x << " " << b_y << " " << b_z << endl;
				cout << fixed << setprecision(10) << c_x << " " << c_y << " " << c_z << endl;*/

				/*cout << fixed << setprecision(6) << point1.x << " " << point1.y << " " << point1.z << endl;
				cout << fixed << setprecision(6) << point2.x << " " << point2.y << " " << point2.z << endl;
				cout << fixed << setprecision(6) << point3.x << " " << point3.y << " " << point3.z << endl;*/
				flag = 0;
			}
		}
	}
}
int main()
{
	FILE* file;
	errno_t err;
	err = fopen_s(&file, "G://40000000Cos.ter", "rb");  
	float start = clock();
	readFile(file);
	cout << "��ȡ�����ļ���ʱ" << (clock() - start) / 1000 << "��" << endl;

	system("pause");
	return 0;
}
