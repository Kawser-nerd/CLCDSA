#if !defined(__MYLINKLIST_H_INCLUDED__)
#define __MYLINKLIST_H_INCLUDED__

typedef struct _MyLinkList {
    void *content;
    struct MyLinkList *next;
    struct MyLinkList *prev;
} MyLinkList;

MyLinkList* MyLinkListCreateNode(void *content);
MyLinkList* MyLinkListAdd(MyLinkList *list, void *content);
int MyLinkListCounts(MyLinkList *list);
MyLinkList *MyLinkListGetNode(MyLinkList *list,int index);
MyLinkList *MyLinkListRemove(MyLinkList *list, int index);
void* MyLinkListGetElement(MyLinkList *list,int index);
MyLinkList *MyLinkListFree(MyLinkList *list);

#endif // __MYLINKLIST_H_INCLUDED__




