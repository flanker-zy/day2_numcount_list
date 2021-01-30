#include<iostream>
using namespace std;

const int len = 3;

struct ListNode{
	int value;
	ListNode* next;
	//三种不同的构造函数
	ListNode(int value1, ListNode* next1 ){
		value = value1;
		next = next1;
		}
	ListNode() {
		value = 0;
		next = nullptr;
	}
	ListNode(int value2) {
		value = value2;
		next = nullptr;
	}
};

//结构体可使用ListMode *&List 的方法进行传入指向可修改的结构体指针的办法，将更改内容重新传回主调函数。
void creatList(int values[],ListNode *&List,int length)
{
	
	for (int i = length; i >= 0; i--)//从数组的最后一个值开始进行头插法
	{
		List = new ListNode(values[i], List);
	}
	
}

void viewList(ListNode *List)
{
	while (List->next != nullptr)
	{
		cout << List->value << " ";
		List = List->next;
	}
	cout << endl;
}

ListNode* function(ListNode *L1,ListNode *L2 )
{
	ListNode* ptr = nullptr;
	int result[len+1] = { 0 };
	int i = 0;
	int k = 0; //进位信号
	//for (int i = 0; i < len; i++)
	
	while (L1->next != nullptr || L2->next != nullptr)
	{
		int value = L1->value + L2->value;
		if ( value < 10)
		{
			result[i] = value + k;
			k = 0;
		}
		else if (value >= 10)
		{
			result[i] = value % 10+k;
			k = 1;
		}
		i++;
		L1 = L1->next;
		L2 = L2->next;
	}
	if (k == 1)
	{
		result[i] = 1;
		creatList(result, ptr,len+1);
	}
	else
	{
		creatList(result, ptr,len);
	}
	
	return ptr;
}

int main()
{
	int values1[3] = {6,4,2};
	int values2[3] = {5,6,4};
	ListNode* L1 = nullptr;
	ListNode* L2 = nullptr;
	creatList(values1, *&L1,len);
	creatList(values2, *&L2,len);
	viewList(L1);
	viewList(L2);
	viewList(function(L1, L2));
	return 0;
}
