/*
文件说明：单向链表的实现
链表的大小是动态的，所以不存在提前开辟的空间，这一点和顺序表不同,所以必须传入指针
//单向指针的组成部分包括：
//头指针，头节点，中间节点，末节点，每个节点包括一个数据部分和一个next指针指向下一个节点
末节点的next指针为空
*/
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef int SLTDataType;
typedef struct link
{
	SLTDataType data;
	struct link* next;
	
}LIST;


//链表中找数，返回地址
//函数说明，如果链表中有很多个目标数，则使用类似于
/*
* LIST* pos=ListFind(LIST**head,SLTDataType,2);
* int i=0;
  while(pos)
  {
	  printf("第%d个节点：%d-->%d\n",i++,pos,pos->data);
	  pos=ListFind(pos->next,2)
  }
* */
LIST* ListFind(LIST* hhead, SLTDataType data);


void ListPushHead(LIST** head, SLTDataType nodeData);//头部添加数据
void ListPopHead(LIST** head);//头部删除数据
void ListPushBack(LIST** head,SLTDataType data);//尾部添加数据
void ListPopBack(LIST** head);//尾部删除数据
void DestoryMemory(LIST* head);//销毁链表
void ListPrint(LIST* phead);//打印链表
void InsertData(LIST** head, LIST* pos,SLTDataType data);//pos使用上一个函数得到
void EraseData(LIST** head, LIST* pos);
void EraserAfter(LIST* pos);
void InsertAfter(LIST* pos,SLTDataType data);
void deleteNode(LIST* node);//删除给定的节点