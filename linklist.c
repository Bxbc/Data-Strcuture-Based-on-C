//
//  linklist.c
//  
//
//  Created by 毕熙 on 2019/8/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LL.h"


void putHead(int n,Lisk marker){
    if(marker == NULL){
        fprintf(stderr,"putHead: no linked list found\n");
    }else{
        Lsit new = createList();
        new->data = n;
        new->next = marker->next;
        marker->next = new;
    }
    return;
}

int getHead(List marker){
    int retval = 0;
    if(marker == NULL){
        fprintf(stdout,"getHead: no linked list found\n");
    }else{
        List p = marker->next;
        marker->next = p->next;
        retval = p->data;
        free(p);
    }
    return retval;
}

int getTail(List marker){
    int retval = 0;
    if(marker == NULL){
        fprintf(stdout,"getHead: no linked list found\n");
    }else{
        List p = marker->next;
        while(p->next->next != NULL){
            p = p->next;
        }
        retval = p->next->data;
        free(p->next);
        p->next = NULL;
    }
    return retval;
}
