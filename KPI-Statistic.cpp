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
	int count = 0, sleep_duration, awake_time;
	float kpi = 0.0;
	cout << "1.输入四位整数（或者三位）。" << endl
		<< "2.按照时间格式。" << endl
		<< "3.输入0停止采集数据，开始计算。" << endl;
	// 开始输入KPI各项数据
	cout << "[起床时刻]" << endl;
	cin >> awake_time;
	cout << "[睡眠时间（区间）]" << endl;
	cin >> sleep_duration;
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

	// 开始计算KPI
	for (auto item : temp)
		kpi += (float)(24.0 - (digitMin(item) / 60.0) - digitHour(item)) * 20.0;
	kpi += (float)(9.0 - (digitMin(awake_time) / 60.0) - digitHour(awake_time)) * 100.0;
	kpi += (float)((digitMin(sleep_duration) / 60.0) + digitHour(sleep_duration)) * 100.0 - 500.0;
	cout << "KPI为：" << kpi << endl;
	cout << "睡眠指数：" << (float)((digitMin(sleep_duration) / 60.0) + digitHour(sleep_duration)) * (float)(9.0 - (digitMin(awake_time) / 60.0) - digitHour(awake_time)) * (float)(9.0 - (digitMin(awake_time) / 60.0) - digitHour(awake_time));
	system("pause");
}