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

class BPNets
{
	static double eta;//学习率
	vector<layer>nextwork;
public:
	BPNet();
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

}
///前向传播函数
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