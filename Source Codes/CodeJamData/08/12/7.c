#include <stdlib.h>
#include "mylinklist.h"

MyLinkList* MyLinkListCreateNode(void *content){
    MyLinkList *l = malloc(sizeof(MyLinkList));
    l->content = content;
    l->next = l->prev = NULL;
    return l;
}

MyLinkList* MyLinkListAdd(MyLinkList *list, void *content){
    if(list == NULL){
        return MyLinkListCreateNode(content);
    }else{
        MyLinkList *l = list;
        while(l->next != NULL){
            l = l->next;
        }
        l->next = MyLinkListCreateNode(content);
        ((MyLinkList*)l->next)->prev = l;
    }
    return list;
}

int MyLinkListCounts(MyLinkList *list){
    int n = 0;
    while(list != NULL){
        list = list->next;
        n++;
    }
    return n;
}

MyLinkList *MyLinkListGetNode(MyLinkList *list,int index){
    while(index-- && list != NULL){
        list = list->next;
    }
    return list;
}

MyLinkList *MyLinkListRemove(MyLinkList *list, int index){
    MyLinkList *l = MyLinkListGetNode(list,index);
    if(l != NULL){
        if(l->prev == NULL){
            list = l->next;
        }else{
            ((MyLinkList*)l->prev)->next = l->next;
        }
        if(l->next != NULL){
            ((MyLinkList*)l->next)->prev = l->prev;
        }
        free(l->content);
        free(l);
    }
    return list;
}

void* MyLinkListGetElement(MyLinkList *list,int index){
    MyLinkList *l = MyLinkListGetNode(list,index);
    return (l == NULL)? NULL : l->content;
}

MyLinkList *MyLinkListFree(MyLinkList *list){
    if(list != NULL){
        int counts = MyLinkListCounts(list);
        int i;
        for(i=counts-1; i >= 0; i--){
            MyLinkListRemove(list,i);
        }
        //        free(list);
    }
    return NULL;
}
