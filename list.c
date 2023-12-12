#include"list.h"

//�������ܣ��½�һ���ڵ㲢��ӵ�����ĩβ
void ListPushBack(LIST** head,SLTDataType data)
{
	LIST *p = (LIST*)malloc(sizeof(LIST));//��Pָ���½��ڵ�
	if (p == NULL)//���½��ڵ������ڴ�ʧ�ܣ����Ƴ�����
	{
		printf("No enough memory to applend!\n");
		exit(0);
	}
	p->data = data;
	p->next = NULL;
	if (*head == NULL)
	{
		//����ǿ�������ͷָ��ֱ��ָ�򿪱ٵĿռ�
		*head = p;
		return;
	}
	//������δ�ǿգ�����½ڵ�����δ��β
	else         
	{
		LIST* pr = *head;
		while (pr->next != NULL)//��δ����λ�����ƶ�pr����λ
		{
			pr = pr->next;
		}
		pr->next = p;
	}
}


//β��ɾ������
void ListPopBack(LIST** head)
{
	//����ɾ��������
	assert(head != NULL);
	LIST* pr = *head;
	LIST* temp = NULL;
	if (pr->next == NULL)
	{
		free(pr);
		pr = NULL;
		*head = NULL;
		return;
	}
	while (pr->next != NULL)//��δ����λ�����ƶ�pr����λ
	{
		temp = pr;
		pr = pr->next;
	}
	free(pr);
	pr = NULL;
	//�п�����ɿ�ָ��ķǷ�����
	temp->next = NULL;
}



void ListPrint(LIST* phead)
{
	LIST* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
}

//�������ܣ��ͷ�headָ������������нڵ�ռ�õ��ڴ�
void DestoryMemory(LIST* head)
{
	struct link* p = head, * pr =NULL;
	while (p != NULL)
	{
		pr = p;
		p = p->next;
		free(pr);
	}
	//free(head);
}


//�������ܣ�ͷ�����
void ListPushHead(LIST** head, SLTDataType data)
{
	LIST* p = (LIST*)malloc(sizeof(LIST));
	if (p == NULL)
	{
		printf("malloc err");
		exit(-1);
	}
	p->data = data;
	p->next = *head;
	*head = p;
}

void ListPopHead(LIST** head)
{
	assert(head != NULL);
	LIST* phead = *head;
	*head = phead->next;
	free(phead);
	phead = NULL;
}

LIST* ListFind(LIST* head, SLTDataType data)
{
	LIST* phead = head;
	while (phead)
	{
		if (phead->data == data)
		{
			return phead;
		}
		else
		{
		    phead = phead->next;
	    }
	}
	return NULL;
}

void InsertData(LIST** head, LIST* pos, SLTDataType data)
{
	assert(head != NULL);
	LIST* newnode = (LIST*)malloc(sizeof(LIST));
	LIST* phead = *head;
	if (pos == phead)
	{
		ListPushHead(head, data);
		return;
	}
	else
	{
		while (phead->next != pos)
		{
			phead = phead->next;
		}
		//�ҵ���pos��ǰһ����ַ
		phead->next = newnode;
		newnode->next = pos;
	}
}

void EraseData(LIST** head, LIST* pos)
{
	assert(head != NULL);
	LIST* phead = *head;
	if (pos == phead)
	{
		ListPopHead(head);
	}
	else
	{
		while (phead->next != pos)
		{
			printf("rfff");
			phead = phead->next;
		}
		//�ҵ���pos��ǰһ����ַ
		phead->next = pos->next;
		free(pos);
			
	}
}

void EraserAfter(LIST* pos)
{
	LIST* next = pos->next;
	pos->next = next->next;
	free(next);
}

void InsertAfter(LIST* pos, SLTDataType data)
{
	LIST* p = (LIST*)malloc(sizeof(LIST));
	p->next = pos->next;
	pos->next = p;
	p->data = data;
}

void deleteNode(LIST* node) {
	if (node == NULL || node->next == NULL) {
		// ����ɾ�����һ���ڵ��սڵ�
		return;
	}

	LIST* nextNode = node->next;
	node->data = nextNode->data;
	node->next = nextNode->next;

	free(nextNode);
}
