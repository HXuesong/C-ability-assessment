#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct grade {
	int score;
	char ID[6];
	struct grade *next;
};

typedef struct grade NODE;

struct grade *create();

NODE *insert(NODE *head, NODE *pnew, int i);

void display(NODE *head);
void Pfree(NODE *head);

int main() {

	struct grade *head, *pnew;
	int n;

	head = create();

	if (head == NULL)
		return 0;

	printf("创建的链表：\n");

	display(head);

	pnew = (NODE *)malloc(sizeof(NODE));

	printf("请输入要插入结点的成绩和ID:\n");
	scanf("%d,%s", &pnew->score, pnew->ID);

	getchar();

	printf("请输入要插入结点的位置,在这个位置后面插入新结点：\n");

	scanf("%d", &n);

	head = insert(head, pnew, n);

	printf("插入后的链表：\n");

	display(head);

	Pfree(head);

	return 0;
}
struct grade *create() {

	NODE *head, *tail, *pnew;
	int score;
	char ID[6];
	head = (NODE *)malloc(sizeof(NODE));

	if (head == NULL) {
		printf("创建失败！");
		return NULL;
	}

	head->next = NULL;
	tail = head;

	printf("输入学生成绩和ID：\n");

	while (1) {

		scanf("%d,%s", &score, ID);

		if (score < 0)
			break;

		pnew = (NODE *)malloc(sizeof(NODE));

		if (pnew == NULL) {
			printf("创建失败！");
			return NULL;
		}

		pnew->score = score;
		strcpy(pnew->ID, ID);
		pnew->next = NULL;
		tail->next = pnew;
		tail = pnew;
	}

	return head;
}
NODE *insert(NODE *head, NODE *pnew, int i) {

	NODE *p;
	int j;

	p = head;
	for (j = 0; j < i && p != NULL; j++)
		p = p->next;

	if (p == NULL) {

		printf("插入的节点不存在！");
		return head;
	}

	pnew->next = p->next;
	p->next = pnew;
	return head;
}

void display(NODE * head) {

	NODE *p;
	for (p = head->next; p != NULL; p = p->next)
		printf("%d,%s\n", p->score, p->ID);
}

void Pfree(NODE * head) {

	NODE *p, *q = NULL;
	p = head;
	while (p != NULL) {

		q = p;
		p = p->next;
        free(q);
	}
}
