#include <stdio.h>
#include <stdlib.h>

/**
 * 数据结构与算法-C语言描述
 * 这里描述的是"抽象数据类型"章节-链表
 *
 * 这本书描述的不够详细，对链表的很多操作都需要读者自行实现。
 * 这里我通过书本的知识再结合自己查阅的其它资料进行了整理，在命名上可能跟书中的不一样。
 *
 */
typedef int ElemType;
typedef struct Node {
    ElemType data;
    struct Node *next;
} LNode, *LinkList;

//创建链表
LinkList Create() {
    //初始化长度为5的int类型数组，每个数组的值是链表每个节点中data的值
    ElemType LinkListArr[5] = {1, 2, 3, 4, 5};
    LinkList headerNode, assistNode, newNode;

    //初始化链表头结点
    headerNode = (LinkList) malloc(sizeof(LinkList));
    headerNode->next = NULL;
    //这时辅助节点和头结点共同指向了同一块内存地址
    assistNode = headerNode;

    for (int i = 1; i <= 5; i++) {
        //创建新的节点
        newNode = (LinkList) malloc(sizeof(LinkList));
        if (newNode == NULL) {
            printf("申请空间失败！");
            exit(0);
        }
        newNode->data = i;
        //辅助节点指向了新创建的节点，如果i等于1那么头结点也指向了新创建的节点
        assistNode->next = newNode;
        //辅助节点后移，辅助节点的指针指向了新创建的节点，辅助节点和新创建的节点共同指向了同一块内存地址
        assistNode = newNode;
    }
    //创建完链表后，辅助节点的指针会指向最后一个节点所在的内存地址，最后一个节点的下一个节点是NULL
    assistNode->next = NULL;
    //返回头节点的指针
    return headerNode;
}

void visit(LinkList L) //遍历
{
    LinkList node = L->next;
    while (node != NULL) {
        printf("%5d", node->data);
        node = node->next;
    }
    printf("\n\n");
}

void InsertBefore(LinkList headerNode, int position, ElemType value)//前插
{
    LinkList p = headerNode->next, currentNode = headerNode, assistNode;

    int n = 1;
    while (p != NULL && n < position) {
        currentNode = p;
        p = p->next;
        n++;
    }
    if (p != NULL) {
        assistNode = (LinkList) malloc(sizeof(LNode));
        assistNode->data = value;
        assistNode->next = p;
        currentNode->next = assistNode;
    } else {
        printf("插入失败！\n");
    }
}

void InsertAfter(LinkList L, int pos, ElemType value)
{
    LinkList p = L->next, s;

    int n = 1;
    while (p != NULL && n < pos) {
        p = p->next;
        n++;
    }
    if (p != NULL) {
        s = (LinkList) malloc(sizeof(LNode));
        s->data = value;
        s->next = p->next;
        p->next = s;
    } else {
        printf("插入失败！\n");
    }
}

void Delete(LinkList L, int pos)
{
    LinkList p = L->next, q = L;
    int n = 1;
    while (p != NULL && n < pos) {
        q = p;
        p = p->next;
        n++;
    }
    if (p != NULL) {
        q->next = p->next;
        free(p);
    } else {
        printf("删除失败！\n\n");
    }
}

int main() {
    LinkList headerNode;
    int position;
    ElemType value;

    headerNode = Create();
    printf("创建的链表是：\t");
    visit(headerNode);//创建后的遍历

    printf("前插，请输入位置int position和插入值int value: ");
    scanf("%d%d", &position, &value);
    InsertBefore(headerNode, position, value);//前插
    printf("前插后的链表是:\t");
    visit(headerNode);

    printf("后插输入位置int pos和插入值int value: ");
    scanf("%d%d", &position, &value);
    InsertAfter(headerNode, position, value);//后插
    printf("后插后的链表是:\t");
    visit(headerNode);//后插后的遍历

    printf("删除输入位置int pos: ");
    scanf("%d", &position);
    Delete(headerNode, position);//删除
    printf("删除后的链表是:\t");
    visit(headerNode);//删除后的遍历

    return 0;
}
