//
//  GList.c
//  GList
//
//  Created by admin on 2017/4/15.
//  Copyright © 2017年 chen. All rights reserved.
//

#include "GList.h"

static bool createIsCoplemented = false;

void InitGList (GList *list, ElemTag tag) {
    AtomType temp = 0;
    *list = (GList) malloc(sizeof(struct GLNode));
    if (*list == NULL) {
        return;
    }
    
    (*list) -> tag = tag;
    if (tag == ATOM) {
        while (printf("Enter the value of atom: "),scanf("%d",&temp) == 0) {
            scanf("%*s");
            while (getchar() != '\n');
        }
        (*list) -> atom = temp;
    } else {
        (*list) -> ptr.alignNode = NULL;
        (*list) -> ptr.verticalNode = NULL;
    }
}

void CreateList(GList *list, char description[]) {
    //判断广义表是否创建完毕，可以消除')'符号带来的歧义
    if (createIsCoplemented)
        return;
    
    //如果描述信息全为空代表创建结束（似乎用不到）
    if (description == NULL) {
        return;
    }
    
    //遇到'('符号代表需要创建子表，每次执行完描述信息命令则读取描述信息的下一个字符
    if (*description == '(') {
        InitGList(list, SUBLIST);
        description++;
        //子表初始化完毕则进入子表内部递归进行下一步的创建
        CreateList(&((*list) -> ptr.verticalNode),description);
        
        //递归按级返回到子表创建刚刚创建的位置时描述信息也会初始化为初始状态，迭代取出所有已执行过的命令
        while (*description != ')') {
            description++;
        }
        description++;
        
        //区别于创建下一个子表或原子，当所有表创建完毕时，描述信息中将只剩下')'符号，此时将完成状态置为已完成
        if (strchr(description, ',') == NULL) {
            createIsCoplemented = true;
        }
        //子表内部创建完毕后进过一系列对描述信息的处理后，从此开始对同一层级的原子或子表进行创建
        CreateList(&((*list) -> ptr.alignNode), description);
    } else if (*description == ')') {
        description++;
        return;
    } else if (*description != ','){
        //对描述信息中的原子值进行输入并前进到当前子表的下一个位置创建紧接其后的原子或子表
        InitGList(list, SUBLIST);
        InitGList(&((*list) -> ptr.verticalNode), ATOM);
        while (*description != ')' && *description != ',') {
            description++;
        }
        if (*description == ',') {
            description++;
        }
        CreateList(&((*list) -> ptr.alignNode),description);
    } else {
        //对多余的逗号的处理
        description++;
        CreateList(list,description);
    }
}
