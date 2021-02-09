#include "binary_search_tree.h"

struct _TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
    int Count;
};

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    while (T != NULL) {
        if (T->Element < X)
            T = T->Right;
        else if (T->Element > X)
            T = T->Left;
        else
            return T;
    }
    printf("Not found! \n");
    return NULL;
}

Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;

    while (T->Left != NULL) {
        T = T->Left;
    }

    return T;
}

Position FindMax(SearchTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}

Position CreateNode(ElementType X)
{
    Position p;
    p = (Position)malloc(sizeof(TreeNode));
    if (p == NULL) {
        printf("Error! Out of memory! \n");
        return NULL;
    }
    p->Left = p->Right = NULL;
    p->Element = X;
    p->Count = 1;
    return p;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    Position t = CreateNode(X);
    Position p = T;
    if (T == NULL)
        return t;

    while (1) {
        if (p->Element < X) {
            if (p->Right != NULL)
                p = p->Right;
            else {
                p->Right = t;
                return T;
            }
        } else if (p->Element > X) {
            if (p->Left != NULL)
                p = p->Left;
            else {
                p->Left = t;
                return T;
            }
        } else {
            p->Count++;
            return T;
        }
    }
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position temp;
    int t;
    if (T == NULL) {
        printf("Error! The tree is empty! \n");
        return NULL;
    }
    if (T->Element < X)
        T->Right = Delete(X, T->Right);
    else if(T->Element > X)
        T->Left = Delete(X, T->Left);
    else {
        if (T->Count > 1)
            T->Count--;
        else {
            if (T->Left && T->Right) {
                temp = FindMin(T);
                t = FindMin(T->Right)->Element;
                T->Count = temp->Count;
                temp->Count = 1;
                Delete(t, T);
                T->Element = t;
                return T;
            } else if(T->Left) {
                temp = T->Left;
                free(T);
                return temp;
            } else if (T->Right) {
                temp = T->Right;
                free(T);
                return temp;
            } else {
                free(T);
                return NULL;
            }
        }
    }
    return NULL;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

//先序遍历非递归实现
void PreOrderNoRec(SearchTree T) 
{
    SearchTree p = T;
    SearchTree stack[10];
    int num = 0;
    while (NULL != p || num > 0) {
        while (NULL != p) {
            printf("%d  ", p->Element);
            stack[num++] = p;
            p = p->Left;
        }
        num--;
        p = stack[num];
        p = p->Right;
    }
    printf("\n");
}

//中序遍历非递归实现
void InOrderNoRec(SearchTree T)
{
	SearchTree p = T;
	int num=0;
	SearchTree stack[30];
	while (NULL != p || num > 0) {
		while (NULL != p) {
			stack[num++]=p;
			p = p->Left;
		}
		num--;
		p = stack[num];
		printf("%d  ",p->Element);
		p = p->Right;
	}
	printf("\n");
}

//后续遍历非递归实现
void PostOrderNoRec(SearchTree T)
{
	SearchTree p = T;
	SearchTree stack[30];
	int num = 0;
	SearchTree have_visited = NULL;
 
	while (NULL != p || num > 0) {
		while (NULL != p) {
			stack[num++]=p;
			p = p->Left;		
		}
		p = stack[num-1];
		if (NULL == p->Right || have_visited == p->Right) {
			printf("%d  ",p->Element);
			num--;
			have_visited = p;
			p = NULL;
		} else {
			p = p->Right;
		}
	}
	printf("\n");
}


int main()
{
    Position p;
    p = CreateNode(5);

    for (int i = 2; i < 10; i++) {
        if (i == 5) {
            continue;
        }
        Insert(i, p);
    }

    PreOrderNoRec(p);
    return 0;
}
