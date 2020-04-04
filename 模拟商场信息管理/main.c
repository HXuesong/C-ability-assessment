#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct member {
	char num[20];
	char name[20];
	int total;
	struct member *next;
}*head;

void creat();
void show();
void upd(char name[]);
void Free();

int main() {

	char num[20];
	creat();
	printf("请输入要修改的会员编号：\n");
	scanf("%s", num);
	upd(num);
	Free();
	return 0;
}

void  creat() {

	struct member *q, *tail;

	head = (struct member *)malloc(sizeof(struct member));

	head->next = NULL;
	tail = head;

	char flag = 'Y';

	while(flag == 'Y')      {

		printf("请依次输入每个会员的编号、姓名、积分： \n");

		q = (struct member *)malloc(sizeof(struct member));
		q->next = NULL;

		scanf("%s %s %d", q->num, q->name, &q->total);

		tail->next = q;
		tail = q;

		printf("是否继续输入,按Y键继续输入，其他键就结束.\n");

		getchar();
		flag = getchar();
	}

	tail->next = NULL;
}
void show()  {

	struct member *out;
	out = head->next;

	printf("请依次输出每个会员的编号、姓名、积分： \n");

	while(out) {

		printf("%s %s %d\n", out->num, out->name, out->total);
		out = out->next;
	}
}
void upd(char num[])  {

	struct member *p;
	int  mark;
	mark = 0;
	p = head;

	if(head == NULL) {

		printf("修改失败.\n不存在此联系人.\n");
		return ;
	} else {
		while(p != NULL) {

			if(strcmp(p->num, num) == 0) {

				printf("请输入要修改的编号：");
				scanf("%s", p->num);
				printf("请输入要修改的姓名：");
				scanf("%s", p->name); //1
				printf("请输入要修改的积分：");
				scanf("%d", &p->total);
				mark = 1;
				break;

			} else
				p = p -> next;
		}
	}
	if(!mark) {

		printf("修改失败.\n不存在此联系人.\n");
		return ;
	}
	show();
}

void Free() {

	struct member *p = head, *pr = NULL;

	while (p != NULL) {

		pr = p;
		p = p->next;
		free(pr);
	}
}
