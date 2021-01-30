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
void creatList(int values[],ListNode *&List,int length)
{
	
	for (int i = length; i >= 0; i--)//����������һ��ֵ��ʼ����ͷ�巨
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
	int k = 0; //��λ�ź�
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
