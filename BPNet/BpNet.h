#include<bits/stdc++.h>
using namespace std;
struct neuron
{//神经元
	vector<double>weight;
	vector<double>updata_w;
	double input, output = 0;
	double bias;//偏置
};
typedef vector<neuron> layer;
int cnt = 0;
class BPNet
{
	double eta;//学习率
	vector<layer>network;
public:
	void init(const vector<int> &network_);//用于初始化
	double sig(double &x) { return 1.0 / (1.0 + exp(-x)); }//激活函数
	void front(vector<double>&input_, const vector<int>&network_);//前项函数
	void back_p(const vector<double>&predict);
	void update_weight();//
	void show() const;
};
///初始化函数
void BPNet::init(const vector<int>&network_)
{
	eta = 0.6180339887;
	int layer_num = network_.size();
	for (int i = 0; i < layer_num; i++)
	{
		network.push_back(layer());
		for (int j = 0; j < network_[i]; j++)
		{
			network.back().push_back(neuron());
			if (i > 0) network[i][j].bias = 0.2;//不是输入层
			if (i < layer_num - 1)//不是输出层
			{
				for (int k = 0; k < network_[i + 1]; k++)
				{
					network[i][j].weight.push_back(rand()*(rand() % 2 ? 1 : -1)*1.0 / RAND_MAX);//权重初始值设置为-1到1之间的随机数
					network[i][j].updata_w.push_back(0);
				}
			}
		}
	}
}
///前向传播函数
/*
隐层的输出值应该是等于 ：（输入层的每个神经元的输出乘以对应的权重然后加上偏置）
把这个整体放入激活函数 得到的值，输出层也是一样的
*/
void BPNet::front(vector<double>&input_, const vector<int>&network_)
{
	//输入层的输出就是输入
	for (int t = 0; t < network_[0]; t++)
	{
		network[0][t].output = input_[t];
	}
	for (int i = 1; i < network_.size(); i++)
	{
		for (int j = 0; j < network_[i]; j++)
		{
			network[i][j].output = 0;
			for (int k = 0; k < network_[i - 1]; k++)
			{
				network[i][j].output += network[i - 1][k].output * network[i - 1][k].weight[j];
			}
			network[i][j].output += network[i][j].bias;
			network[i][j].output = sig(network[i][j].output);
		}
	}
}
///反向误差回传函数
/*
反向误差函数,链式法则求导
反向传播函数的主要目的是为了修正权重，而且输出层和隐层的权重修正是不一样的，修正的公式就是w_update=w_old-eta*delta，
关键是delta要求出来，这个delta是你要修正的那个权重对总误差求偏导数得到的值，单个误差就是（predict-out）的平方，
也就是某个输出层神经元预期的输出和真实输出的差值的平方，总误差就是把它们加起来，对于输出层的神经元，权重只会影响到单个的输出，
而对于隐层而言，一个权重的改变会对所有神经元的输出均有影响，
具体公式这部分的内容有一个网站说的特别详细（yongyuan.name/blog/back-propagtion.html）我也是参考他的公式并自己总结出来编写了代码。
*/

void BPNet::back_p(const vector<double>&predict)
{
	double delta_total = 0.0;
	double delta = 0.0;
	double sum;
	for (int i = 0; i < predict.size(); i++)
	{
		delta_total += 0.5*pow((predict[i] - network[2][i].output), 2);
	}
	cout << "total delta is " << delta_total << endl;
	for (int i = 0; i < network[1].size(); i++)
	{
		for (int j = 0; j < network[2].size(); j++)
		{
			delta = -(predict[j] - network[2][j].output)*network[2][j].output*(1 - network[2][j].output)*network[1][i].output;
			network[1][i].updata_w[j] = network[1][i].weight[j] - eta * delta*1.0;
			
		}
	}
	delta = 0.0;
	for (int i = 0; i < network[0].size(); i++)
	{
		for (int j = 0; j < network[1].size(); j++)
		{
			sum = 0.0;
			delta = network[1][j].output*(1 - network[1][j].output)*network[0][i].output;
			for (int k = 0; k < network[2].size(); k++)
			{
				sum += -(predict[k] - network[2][k].output)*network[2][k].output*(1 - network[2][k].output)*network[1][j].weight[k];
			}
			delta *= sum;
			network[0][i].updata_w[j] = network[0][i].weight[j] - eta * delta;
		}
	}
}
///更新权重函数
/*
要注意的是权重更新一定要等反向传播完成了以后再更新，
因为在修正隐层权重的时候，需要用到输出层原来的那组权重
*/
void BPNet::update_weight()
{
	for (int i = 0; i < network.size() - 1; i++)
	{
		for (int j = 0; j < network[i].size(); j++)
		{
			network[i][j].weight = network[i][j].updata_w;
		}
	}
}
void BPNet::show() const
{
	for (int i = 0; i < network[0].size(); i++)
	{
		cout << "input" << i + 1 << "=" << network[0][i].output << endl;
	}
	for (int i = 0; i < network[2].size(); i++)
	{
		cout << "output" << i + 1 << " = " << network[2][i].output << endl;
	}
}

