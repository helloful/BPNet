#include<bits/stdc++.h>
using namespace std;
struct neuron
{//��Ԫ
	vector<double>weight;
	vector<double>updata_w;
	double input, output;
	double bias;//ƫ��
};
typedef vector<neuron> layer;

class BPNet
{
	static double eta;//ѧϰ��
	vector<layer>network;
public:
	//BPNet();
	void init(const vector<int> &network_);//���ڳ�ʼ��
	static double sig(double &x) { return 1.0 / (1.0 + exp(-x)); }//�����
	void front(vector<double>&input_, const vector<int>&network_);//ǰ���
	void back_p(const vector<double>&predict);
	void update_weight();//
	void show() const;
};
///��ʼ������
void BPNet::init(const vector<int>&network_)
{
	int layer_num = network_.size();
	for (int i = 0; i < layer_num; i++)
	{
		network.push_back(layer());
		for (int j = 0; j < network_[i]; j++)
		{
			network.back().push_back(neuron());
			if (i > 0) network[i][j].bias = 0.5;//���������
			if (i < layer_num - 1)//���������
			{
				for (int k = 0; k < network_[i + 1]; k++)
				{
					network[i][j].weight.push_back(rand()*(rand() % 2 ? 1 : -1)*1.0 / RAND_MAX);//Ȩ�س�ʼֵ����Ϊ-1��1֮��������
					network[i][j].updata_w.push_back(0);
				}
			}
		}
		


	}
}
///ǰ�򴫲�����
/*
��������ֵӦ���ǵ��� ����������ÿ����Ԫ��������Զ�Ӧ��Ȩ��Ȼ�����ƫ�ã�
�����������뼤��� �õ���ֵ�������Ҳ��һ����
*/
void BPNet::front(vector<double>&input_, const vector<int>&network_)
{

}
///�������ش�����
void BPNet::back_p(const vector<double>&predict)
{

}
///����Ȩ�غ���
void BPNet::update_weight()
{

}
void BPNet::show() const 
{

}