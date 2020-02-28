#include <iostream>
#include <vector>
using namespace std;

int digitMin(int& num)
{
	int tmp = num;	// make it a var
	int result;		// storage result
	result = tmp % 10;
	tmp /= 10;
	result += (tmp % 10) * 10;
	return result;
}

int digitHour(int& num)
{
	int tmp = num;	// make it a var
	int result;		// storage result
	tmp /= 100;
	result = tmp % 10;
	tmp /= 10;
	result += (tmp % 10) * 10;
	return result;
}

void main()
{
	vector<int> temp;
	int count = 0;
	float kpi = 0.0;
	cout << "1.输入四位整数（或者三位）。" << endl
		<< "2.按照时间格式。" << endl
		<< "3.输入0停止采集数据，开始计算。" << endl;
	while (true)
	{
		count++;
		temp.push_back(0);
		cout << "[事件" << count << "]" << endl;
		cin >> temp[count - 1];
		if (temp[count - 1] == 0)
		{
			temp.erase(temp.end() - 1);
			break;
		}
	}

	// start to calculate KPI
	for (auto item : temp)
		kpi += (float)(24.0 - (digitMin(item) / 60.0) - digitHour(item)) * 20.0;
	cout << "KPI为：" << kpi << endl;
	system("pause");
}