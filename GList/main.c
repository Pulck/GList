//
//  main.c
//  GList
//
//  Created by admin on 2017/4/15.
//  Copyright © 2017年 chen. All rights reserved.
//

#include <stdio.h>
#include "GList.h"

int main(int argc, const char * argv[]) {
    GList list = NULL;
    CreateList(&list, "(1,2,3,(1),1,2,3,4,(1,2,3,4),((((1,2)))))");
    return 0;
}
