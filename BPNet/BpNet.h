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

class BPNets
{
	static double eta;//ѧϰ��
	vector<layer>nextwork;
public:
	BPNet();
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

}
///ǰ�򴫲�����
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