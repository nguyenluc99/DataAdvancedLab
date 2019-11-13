#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "jrb.h"

void main() {
    int i, n, tmp;
    char filename[6] = "in.txt";
    FILE *fpt;
    JRB root;
    fpt = fopen(filename, "r");
    if (!fpt) {
        printf("error reading file\n");
        return;
    }
        root = make_jrb();
        if (root == NULL) {
            printf("error creating root");
            return ;
        }
        fscanf(fpt, "%d", &n);
        for ( i = 0; i < n; i++)
        {   
            fscanf(fpt, "%d", &tmp);
            jrb_insert_int(root, tmp, new_jval_i(tmp));
        }
        printf("finish inserting\n");
    return;
}
