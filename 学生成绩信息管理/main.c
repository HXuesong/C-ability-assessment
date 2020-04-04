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

	printf("����������\n");

	display(head);

	pnew = (NODE *)malloc(sizeof(NODE));

	printf("������Ҫ������ĳɼ���ID:\n");
	scanf("%d,%s", &pnew->score, pnew->ID);

	getchar();

	printf("������Ҫ�������λ��,�����λ�ú�������½�㣺\n");

	scanf("%d", &n);

	head = insert(head, pnew, n);

	printf("����������\n");

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
		printf("����ʧ�ܣ�");
		return NULL;
	}

	head->next = NULL;
	tail = head;

	printf("����ѧ���ɼ���ID��\n");

	while (1) {

		scanf("%d,%s", &score, ID);

		if (score < 0)
			break;

		pnew = (NODE *)malloc(sizeof(NODE));

		if (pnew == NULL) {
			printf("����ʧ�ܣ�");
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

		printf("����Ľڵ㲻���ڣ�");
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
