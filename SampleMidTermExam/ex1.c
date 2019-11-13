#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"jrb.h"

#define MAX_LEN 1000

void swap(int*, int*);
void menu();

void main() {
    char* filename = "in.txt";
    int i, j, num, tmp;
    int intArr[MAX_LEN];
    char ch;
    FILE *fpt;
    JRB root, node;
    int choice = 3;
    do {
        menu();
        scanf("%d", &choice) ; while((ch = getchar()) != '\n');
        switch (choice) {
            case 1:
                if ((fpt = fopen(filename, "r")) == NULL) {
                    printf("Error reading file\n");
                    break;
                }   
                fscanf(fpt, "%d ", &num);
                for (i = 0; i < num; i++) {
                    fscanf(fpt, "%d ", &intArr[i]);
                }
                printf("a) ");
                for (i = 0; i < num; i++) {
                    printf("%d ", intArr[i]);
                }
                printf("\n");
                for (i = 0; i < num; i++) {
                    for ( j = 0; j < i; j++)
                        if (intArr[i] <  intArr[j]) swap(&intArr[i], &intArr[j]);
                }
                printf("b) ");
                for (i = 0; i < num; i++) {
                    printf("%d ", intArr[i]);
                }
                printf("\n");
                fclose(fpt);
                if ((fpt = fopen("out_bubblesort.txt","w")) == NULL){
                    printf("Error opening file");
                    break;
                }
                for(i = 0; i < num; ++i){
                    fprintf(fpt, "%d ", intArr[i]);
                }
                printf("c) Finished writing file.\n");
                fclose(fpt); 
                break;
            case 2 :
                fpt = fopen(filename, "r");
                if (!fpt) {
                    printf("Error reading file.\n");
                    break;
                }
                root = make_jrb();
                if (root == NULL) {
                    printf("Error creating root.");
                    break ;
                }
                fscanf(fpt, "%d", &num);
                for ( i = 0; i < num; i++)
                {   
                    fscanf(fpt, "%d", &tmp);
                    jrb_insert_int(root, tmp, new_jval_i(tmp));
                }
                fclose(fpt);
                printf("a) ");
                jrb_traverse(node, root)
                    printf("%d ", jval_i(node->key));
                printf("\n");
                if ((fpt = fopen("out_rbt.txt","w")) == NULL){
                    printf("Error opening file\n");
                    break;
                }
                jrb_traverse(node, root)
                    fprintf(fpt, "%d ", jval_i(node->val));
                printf("b) Finished writing file.\n");
                fclose(fpt);
                break;
            case 0 : 
                printf("Thanks for your usage.");
                break;
            default : break;
        }
    } while(choice != 0);
   return;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void menu(){
    printf("Choose an options:\n");
    printf("1. Reading file, bubble sort.\n");
    printf("2. Reading file, Red-Black tree.\n");
    printf("0. Quit.\n\t");
}