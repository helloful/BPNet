#include<bits/stdc++.h>
using namespace std;
struct neuron
{//神经元
	vector<double>weight;
	vector<double>updata_w;
	double input, output;
	double bias;//偏置
};
typedef vector<neuron> layer;

class BPNet
{
	static double eta;//学习率
	vector<layer>network;
public:
	//BPNet();
	void init(const vector<int> &network_);//用于初始化
	static double sig(double &x) { return 1.0 / (1.0 + exp(-x)); }//激活函数
	void front(vector<double>&input_, const vector<int>&network_);//前项函数
	void back_p(const vector<double>&predict);
	void update_weight();//
	void show() const;
};
///初始化函数
void BPNet::init(const vector<int>&network_)
{
	int layer_num = network_.size();
	for (int i = 0; i < layer_num; i++)
	{
		network.push_back(layer());
		for (int j = 0; j < network_[i]; j++)
		{
			network.back().push_back(neuron());
			if (i > 0) network[i][j].bias = 0.5;//不是输入层
			if (i < layer_num - 1)//不是输入层
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

}
///反向误差回传函数
void BPNet::back_p(const vector<double>&predict)
{

}
///更新权重函数
void BPNet::update_weight()
{

}
void BPNet::show() const 
{

}