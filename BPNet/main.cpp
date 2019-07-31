#include<bits/stdc++.h>
#include "BpNet.h"
using namespace std;
int main()
{
	BPNet bpnetwork;
	vector<int>layer{ 1,2,3 };
	vector<double>input{ 0.3, 0.7, 0.4 };
	vector<double>output{ 0.5,0.4,0.5,0.7 };
	bpnetwork.init(layer);
	for (int i = 0; i < 100; i++)
	{
		bpnetwork.front(input, layer);
		bpnetwork.back_p(output);
		bpnetwork.update_weight();
		bpnetwork.show();
	}
	return 0;
}
void test()
{
	cout << "test" << endl;
}
/*
²Î¿¼×ÊÁÏ
https://blog.csdn.net/aowuyuyu/article/details/79150146
*/
