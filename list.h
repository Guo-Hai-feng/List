/*
�ļ�˵�������������ʵ��
����Ĵ�С�Ƕ�̬�ģ����Բ�������ǰ���ٵĿռ䣬��һ���˳���ͬ,���Ա��봫��ָ��
//����ָ�����ɲ��ְ�����
//ͷָ�룬ͷ�ڵ㣬�м�ڵ㣬ĩ�ڵ㣬ÿ���ڵ����һ�����ݲ��ֺ�һ��nextָ��ָ����һ���ڵ�
ĩ�ڵ��nextָ��Ϊ��
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


//���������������ص�ַ
//����˵��������������кܶ��Ŀ��������ʹ��������
/*
* LIST* pos=ListFind(LIST**head,SLTDataType,2);
* int i=0;
  while(pos)
  {
	  printf("��%d���ڵ㣺%d-->%d\n",i++,pos,pos->data);
	  pos=ListFind(pos->next,2)
  }
* */
LIST* ListFind(LIST* hhead, SLTDataType data);


void ListPushHead(LIST** head, SLTDataType nodeData);//ͷ���������
void ListPopHead(LIST** head);//ͷ��ɾ������
void ListPushBack(LIST** head,SLTDataType data);//β���������
void ListPopBack(LIST** head);//β��ɾ������
void DestoryMemory(LIST* head);//��������
void ListPrint(LIST* phead);//��ӡ����
void InsertData(LIST** head, LIST* pos,SLTDataType data);//posʹ����һ�������õ�
void EraseData(LIST** head, LIST* pos);
void EraserAfter(LIST* pos);
void InsertAfter(LIST* pos,SLTDataType data);
void deleteNode(LIST* node);//ɾ�������Ľڵ�