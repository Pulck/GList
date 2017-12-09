//
//  GList.h
//  GList
//
//  Created by admin on 2017/4/15.
//  Copyright © 2017年 chen. All rights reserved.
//

#ifndef GList_h
#define GList_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int AtomType;

typedef enum {ATOM,SUBLIST} ElemTag;

typedef struct GLNode {
    ElemTag tag;
    union {
        AtomType atom;
        struct {
            struct GLNode *verticalNode;
            struct GLNode *alignNode;
        } ptr;
    };
} *GList;

extern void InitGList (GList *list, ElemTag tag);
extern void CreateList(GList *list,char description[]);

#endif /* GList_h */
//((1,2),3,((1,(1,2))))
