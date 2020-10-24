#pragma
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(std::string str)
{
	string x, y, z;
	vector<string> vec;
	stringstream ss(str);
	ss >> x >> y >> z;
	vec.push_back(x);
	vec.push_back(y);
	vec.push_back(z);
	return vec;
}

void readTerrain(const std::string file)
{
	ifstream input_ter(file.c_str());
	if (input_ter.peek() == -1)
		cout << "读取失败" << endl;
	vector<string> vec1, vec2, vec3;

	if (!input_ter)
	{
		cout << ("Open terrain file failed.");
		throw "Open terrain file failed!";
	}
	else
	{
		string line;
		int position;
		int flag = 0;

		while (getline(input_ter, line))
		{
			position = line.find("nVertices");
			if (position != line.npos) {
				flag = 1;
				continue;
			}
			if (flag > 0)
			{
				if (flag == 1)
				{
					vec1 = split(line);
				}
				if (flag == 2)
				{
					vec2 = split(line);
				}
				if (flag == 3)
				{
					vec3 = split(line);
				}
				flag++;
				if (flag == 4)
				{
					double a_x = strtod(vec1[0].c_str(), nullptr);
					double a_y = strtod(vec1[1].c_str(), nullptr);
					double a_z = strtod(vec1[2].c_str(), nullptr);

					double b_x = strtod(vec2[0].c_str(), nullptr);
					double b_y = strtod(vec2[1].c_str(), nullptr);
					double b_z = strtod(vec2[2].c_str(), nullptr);

					double c_x = strtod(vec3[0].c_str(), nullptr);
					double c_y = strtod(vec3[1].c_str(), nullptr);
					double c_z = strtod(vec3[2].c_str(), nullptr);

					// 测试
					/*cout << fixed << setprecision(10) << a_x << " " << a_y << " " << a_z << endl;
					cout << fixed << setprecision(10) << b_x << " " << b_y << " " << b_z << endl;
					cout << fixed << setprecision(10) << c_x << " " << c_y << " " << c_z << endl;*/

					flag = 0;
					vec1.clear();
					vec2.clear();
					vec3.clear();
				}
			}
		}
	}
}

int main()
{
	float start = clock();
	readTerrain("G://40000000Cos.ter");
	cout << "读取地形文件用时" << (clock() - start) / 1000 << "秒" << endl;
	system("pause");
	return 0;
}
