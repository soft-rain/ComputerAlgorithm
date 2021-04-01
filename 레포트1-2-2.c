#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int elem;
	struct ListNode* next;
}ListNode;


ListNode* buildList(int n)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	ListNode* L;
	
	L = p;
	p->elem = 1;
	int i;
	for (i = 2; i <= n; i++) {
		p->next = (ListNode*)malloc(sizeof(ListNode));
		p = p->next;
		p->elem = i;
	}
	p->next = L;
	return L;
}
int candle(int n, int k)
{
	ListNode* L = buildList(n);
	return runSimulation(L, n, k);
}
int runSimulation(ListNode* L, int n, int k)
{
	ListNode* p = L;
	ListNode* pnext;
	while (p != p->next) {
		int i;
		for (i = 1; i < k; i++) {
			p = p->next;
		}
		pnext = p->next;
		p->next = p->next->next;
		free(pnext);
		p=p->next;
	}
	return p->elem;
}

int main(void) {
	ListNode* L;
	int n,k;
	scanf("%d %d", &n, &k);
	printf("%d", candle(n,k));

}
