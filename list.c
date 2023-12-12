#include"list.h"

//函数功能：新建一个节点并添加到链表末尾
void ListPushBack(LIST** head,SLTDataType data)
{
	LIST *p = (LIST*)malloc(sizeof(LIST));//让P指向新建节点
	if (p == NULL)//若新建节点申请内存失败，则推出程序
	{
		printf("No enough memory to applend!\n");
		exit(0);
	}
	p->data = data;
	p->next = NULL;
	if (*head == NULL)
	{
		//如果是空链表，则头指针直接指向开辟的空间
		*head = p;
		return;
	}
	//若链表未非空，则把新节点设置未表尾
	else         
	{
		LIST* pr = *head;
		while (pr->next != NULL)//若未到表位，则移动pr到表位
		{
			pr = pr->next;
		}
		pr->next = p;
	}
}


//尾部删除数据
void ListPopBack(LIST** head)
{
	//不能删除空链表
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
	while (pr->next != NULL)//若未到表位，则移动pr到表位
	{
		temp = pr;
		pr = pr->next;
	}
	free(pr);
	pr = NULL;
	//有可能造成空指针的非法访问
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

//函数功能：释放head指向的链表中所有节点占用的内存
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


//函数功能，头部添加
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
		//找到了pos的前一个地址
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
		//找到了pos的前一个地址
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
		// 不能删除最后一个节点或空节点
		return;
	}

	LIST* nextNode = node->next;
	node->data = nextNode->data;
	node->next = nextNode->next;

	free(nextNode);
}
