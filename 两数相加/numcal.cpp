#include<iostream>
using namespace std;

const int len = 3;

struct ListNode{
	int value;
	ListNode* next;
	//���ֲ�ͬ�Ĺ��캯��
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

//�ṹ���ʹ��ListMode *&List �ķ������д���ָ����޸ĵĽṹ��ָ��İ취���������������´�������������
void creatList(int values[],ListNode *&List,int len)
{
	
	for (int i = len; i >= 0; i--)//����������һ��ֵ��ʼ����ͷ�巨
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
	int result[len] = { 0 };
	int i = 0;
	
}

int main()
{
	int values1[3] = {2,4,3};
	int values2[3] = {5,6,4};
	ListNode* L1 = nullptr;
	ListNode* L2 = nullptr;
	creatList(values1, *&L1,len);
	creatList(values2, *&L2, len);
	viewList(L1);
	viewList(L2);
	function(L1, L2);
}
