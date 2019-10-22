//
//  graphAL.c
//  
//
//  Created by 毕熙 on 2019/8/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int isEdge(Graph g,Edge e){
    int found = 0;
    if(g != NULL && validV(g,e.v) && validV(g,e.w)){
        List cur;
        for(cur=g-edges[e.v];cur != NULL;cur=cur->next){
            if(cur->name == e.w){
                found = 1;
            }
        }
    }
    return found;
}

Graph freeGraph(Graph g){
    if(g != NULL){
        for(int i=0;i<g->nV;i++){
            List cur = g->edges[i];
            while(cur != NULL){
                List temp = cur;
                cur = cur->next;
                free(temp);
            }
        }
    free(g->edges);
    free(g);
    g=NULL;
    }
    return g;
}
