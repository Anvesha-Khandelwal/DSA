#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node* NODE;

NODE insert(NODE first){
    NODE newnode;
    newnode = (NODE)malloc(sizeof(struct node));

    printf("Enter the element: ");
    scanf("%d", &newnode->info);

    newnode->left = NULL;    
    newnode->right = first;   
    first = newnode;         

    return first;
}

NODE del(NODE first){
    NODE temp;

    if(first == NULL){
        printf("Stack underflow\n");
        return first;
    }

    temp = first;
    printf("%d deleted\n", temp->info);

    first = first->right;  
    free(temp);

    if(first != NULL)
        first->left = NULL;

    return first;
}

void display(NODE first){
    NODE temp = first;

    if(temp == NULL){
        printf("Nothing to display\n");
        return;
    }

    while(temp != NULL){
        printf("%d ", temp->info);
        temp = temp->right;
    }
    printf("\n");
}

int main(){
    int ch;
    NODE first = NULL;

    while(1){
        printf("\n1: Insert  2: Delete  3: Display  4: Exit\n");
        scanf("%d", &ch);

        switch(ch){
            case 1: first = insert(first); break;
            case 2: first = del(first); break;
            case 3: display(first); break;
            default: exit(0);
        }
    }
}
