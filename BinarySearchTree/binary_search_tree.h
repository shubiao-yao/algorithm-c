#include <stdio.h>
#include <stdlib.h>

struct _TreeNode;
typedef struct _TreeNode TreeNode;
typedef TreeNode *Position;
typedef TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);