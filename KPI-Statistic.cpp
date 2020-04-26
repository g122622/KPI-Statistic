#include <iostream>
#include <vector>
//#include "gymath.h"
using namespace std;

/*----------函数----------*/
int digitMin(int num)
{
	int result;
	result = num % 10;
	num /= 10;
	result += (num % 10) * 10;
	return result;
}

int digitHour(int num)
{
	int result;
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

/*----------全局变量----------*/
vector<int> temp;
int sleep_time = 0,
set_out_time = 0,
shcool_homework_finish_time = 0,
lg_times = 0;
float kpi = 0.0;

/*----------对象----------*/
class action
{
public:
	void calcKPI()
	{
		for (auto item : temp)
			kpi += (float)(24.0 - digitTime(item)) * 500.0;
		kpi += (float)(7.5 - digitTime(set_out_time)) * 5000.0;
		kpi += (float)(24.0 - digitTime(sleep_time)) * 5000.0;
		kpi += (float)(24.0 - digitTime(shcool_homework_finish_time)) * 500.0;
		kpi += (float)(2 - lg_times) * 300.0;
		cout << "KPI为：" << kpi << endl;
		kpi = 0.0;
		return;
	}

	/*void calcSI()
	{
		cout << "睡眠指数：" << (float)digitTime(sleep_time) * \
			(float)(9.0 - digitTime(set_out_time)) * \
			(float)(9.0 - digitTime(set_out_time)) << endl;
		return;
	}*/
};

/*----------主函数----------*/
void main()
{
	action Action;
	cout << "1.输入四位整数（或者三位）。" << endl
		<< "2.按照时间格式。" << endl
		<< "3.输入0停止采集数据，开始计算。" << endl;
	// 开始输入KPI各项数据
	cout << "[早上出发时间]" << endl;
	cin >> set_out_time;
	cout << "[睡眠时刻]" << endl;
	cin >> sleep_time;
	cout << "[完成学校作业时间]" << endl;
	cin >> shcool_homework_finish_time;
	cout << "[次数]" << endl;
	cin >> lg_times;

//	Action.calcSI();
//	Action.calcKPI();

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
		Action.calcKPI();
	}

	cout << endl << endl << "==========" << endl;
	// 开始计算KPI
	Action.calcKPI();
//	Action.calcSI();
/*	int sum = 0;
	for (int i = 0; i < temp.size() - 1; i++)
	{
		sum += temp[i + 1] - temp[i];
	}
	sum /= temp.size();
	cout << "平均每项耗时" << sum << endl;*/
	system("pause");
}