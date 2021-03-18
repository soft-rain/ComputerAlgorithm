#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode* link;
}ListNode;

typedef struct
{
	ListNode* head;
}LinkedListType;

void init(LinkedListType* L)
{
	L->head=NULL;
}

void addFirst(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = item;
	node->link = L->head;
	L->head = node;
}

void add(LinkedListType* L, int pos, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* before = L->head;
	int i;
	for(i=0; i<pos-1; i++)
		before = before->link;
	node->data = item;
	node->link = before->link;
	before->link=node;
}
int get(LinkedListType* L, int pos)
{
	ListNode* p = L->head;
	int i;
	for(i = 1; i<pos; i++)
		p=p->link;
	return p->data;
}

void printList(LinkedListType* L)
{
	ListNode* p;
	for(p = L->head; p!=NULL; p=p->link)
		printf("[%d] -> ",p->data);
 	printf("NULL\n");
}

void main()
{
	LinkedListType list;
	init(&list);
	
	addFirst(&list,10); printList(&list);
	addFirst(&list,20); printList(&list);
	addFirst(&list,30); printList(&list);
	getchar();
	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);
	int pos;
	printf("\n�� �� ����� ���� ��ȯ�ұ��?");
	scanf("%d", &pos);
	printf("%d�� ����� ���� %d\n", pos, get(&list, pos)); 

}
