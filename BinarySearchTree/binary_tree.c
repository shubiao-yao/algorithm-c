#define  MAXSIZE 100
#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct node
{
	DataType data;
	struct node *lchild, *rchild;
}BTree;

typedef struct {
	BTree *s[MAXSIZE];
	int front,rear;
}Sequence;

//二叉树的层次创建
BTree *CreateTree() {
	FILE *fp;
	BTree *t, *p, *seq[MAXSIZE];
	DataType x;
	int i;

	fp = fopen("btree.dat", "r");
	printf("输入二叉树的层次结点：\n");
	fscanf(fp, "%d %c", &i, &x);
	printf("%d %c\n", i, x);

	if (x == '@') 
		return NULL;

	t = (BTree *)malloc(sizeof(BTree));
	t->data = x;
	t->lchild = NULL;
	t->rchild = NULL;

	seq[i] = t;
  	fscanf(fp, "%d %c", &i, &x);
	printf("%d %c\n", i, x);

    while (x != '@') {
		p = (BTree *)malloc(sizeof(BTree));
		p->data = x;
		p->lchild = NULL;
		p->rchild = NULL;

		seq[i]=p;
		if (i%2==0) {
			seq[i/2]->lchild = p;
		} else {
			seq[i/2]->rchild = p;
		}
		fscanf(fp, "%d %c", &i, &x);
		printf("%d %c\n", i, x);
	}

	fclose(fp);
	printf("\n");
	return t;
}

//二叉树的层次遍历
void ScanLevel(BTree *t) {
	Sequence que;
	que.front = 0;
	que.rear = 0;

	if (t != NULL) {
		que.rear++;
		que.s[que.rear]=t;
	}
	printf("二叉树的层次结点是：");

	while (que.front != que.rear) {
		que.front++;
		t = que.s[que.front];
		printf("%c ", t->data); //遍历结点
		if (t->lchild != NULL) {
			que.rear++;
			que.s[que.rear] = t->lchild;
		}
		if (t->rchild != NULL) {
			que.rear++;
			que.s[que.rear] = t->rchild;
		}
	}
}

int main() {
	BTree *t;
	t = CreateTree();
	ScanLevel(t);
  	printf("\n");

  	return 0;
}