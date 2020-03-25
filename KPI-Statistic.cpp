#include <iostream>
#include <vector>
using namespace std;

// 全局变量
vector<int> temp;
int sleep_duration = 0, awake_time = 0;
float kpi = 0.0;

int digitMin(int num)
{
	int result;		// storage result
	result = num % 10;
	num /= 10;
	result += (num % 10) * 10;
	return result;
}

int digitHour(int num)
{
	int result;		// storage result
	num /= 100;
	result = num % 10;
	num /= 10;
	result += (num % 10) * 10;
	return result;
}

float digitTime(int num)
{
	return (float)((digitMin(num) / 60.0) + digitHour(num));
}

class action
{
public:
	void calcKPI()
	{
		for (auto item : temp)
			kpi += (float)(24.0 - digitTime(item)) * 20.0;
		kpi += (float)(9.0 - digitTime(awake_time)) * 100.0;
		kpi += (float)(digitTime(sleep_duration)) * 100.0 - 500.0;
		cout << "KPI为：" << kpi << endl;
		kpi = 0.0;
		return;
	}

	void calcSI()
	{
		cout << "睡眠指数：" << (float)digitTime(sleep_duration) * \
			(float)(9.0 - digitTime(awake_time)) * \
			(float)(9.0 - digitTime(awake_time)) << endl;
		return;
	}
};
void main()
{
	action action;
	cout << "1.输入四位整数（或者三位）。" << endl
		<< "2.按照时间格式。" << endl
		<< "3.输入0停止采集数据，开始计算。" << endl;
	// 开始输入KPI各项数据
	cout << "[起床时刻]" << endl;
	cin >> awake_time;
	cout << "[睡眠时间（区间）]" << endl;
	cin >> sleep_duration;
	action.calcSI();
	action.calcKPI();
	cout << endl << endl;

	int count = 0;
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
		action.calcKPI();
	}

	cout << endl << endl << "==========" << endl;
	// 开始计算KPI
	action.calcKPI();
	action.calcSI();
	system("pause");
}