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

void addLast(LinkedListType* L, int item)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	ListNode* temp;
	
	node->data = item;
	if(L->head == NULL)
	{
		node->link = NULL;
		L->head = node;
	}
	else
	{
		temp = L->head;
		while(temp->link!=NULL)
			temp = temp -> link;
		temp->link = node;
		node->link = NULL;
	}
}

int get(LinkedListType* L, int pos)
{
	ListNode* p = L->head;
	int i;
	for(i = 1; i<pos; i++)
		p=p->link;
	return p->data;
}

void set(LinkedListType* L, int pos, int item)
{
	ListNode* p = L->head;
	int i;
	for(i = 1; i<pos; i++)
		p=p->link;
	p->data = item;
}

void deleteNode(LinkedListType* L, int pos)
{
	int i;
	ListNode* delNode, *pre;
	if(L->head == NULL)
		return;
	else
	{
		delNode = L->head;
		pre = L->head;
		
		for(i=2; i<=pos; i++)
		{
			pre = delNode;
			delNode - delNode->link;
			
			if(delNode==NULL)
				break;
		}
		if(delNode!=NULL)
		{
			if(delNode==L->head)
				L->head = L->head->link;
			pre->link = delNode->link;
			delNode->link = NULL;
			free(delNode);
		}
	}
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
	addLast(&list,80); printList(&list);
	addFirst(&list,30); printList(&list);
	getchar();
	add(&list, 1, 40); printList(&list);
	add(&list, 1, 50); printList(&list);
	add(&list, 3, 60); printList(&list);
	getchar();
	printList(&list);
	addLast(&list,25); printList(&list);
	getchar();
	deleteNode(&list, 2); printList(&list);
	deleteNode(&list, 1); printList(&list);
	deleteNode(&list, 0); printList(&list);

	int pos;
	printf("\n몇 번 노드의 값을 반환할까요?");
	scanf("%d", &pos);
	printf("%d번 노드의 값은 %d\n", pos, get(&list, pos)); 

}
