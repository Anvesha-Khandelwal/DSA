#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function declarations
struct Node* createList();
void displayList(struct Node *head);
struct Node* reverseList(struct Node *head);
struct Node* mergeLists(struct Node *head1, struct Node *head2);
struct Node* sortList(struct Node *head);

// Function to create a linked list
struct Node* createList() {
    struct Node *head = NULL, *newNode, *temp;
    int n, data;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("Memory allocation failed.\n");
            return head;
        }

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// Function to display a linked list
void displayList(struct Node *head) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse a linked list
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Function to merge two linked lists
struct Node* mergeLists(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

// Function to sort a linked list (Bubble Sort)
struct Node* sortList(struct Node *head) {
    if (head == NULL) return head;

    struct Node *i, *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

// Main function (Menu-driven)
int main() {
    struct Node *list1 = NULL, *list2 = NULL, *merged = NULL;
    int choice;

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display Lists\n");
        printf("4. Reverse List 1\n");
        printf("5. Merge Lists\n");
        printf("6. Sort Merged List\n");
        printf("7. Display Final List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                list1 = createList();
                break;
            case 2:
                list2 = createList();
                break;
            case 3:
                printf("List 1: ");
                displayList(list1);
                printf("List 2: ");
                displayList(list2);
                break;
            case 4:
                list1 = reverseList(list1);
                printf("Reversed List 1: ");
                displayList(list1);
                break;
            case 5:
                merged = mergeLists(list1, list2);
                printf("Merged List: ");
                displayList(merged);
                break;
            case 6:
                merged = sortList(merged);
                printf("Sorted Merged List: ");
                displayList(merged);
                break;
            case 7:
                printf("Final Sorted List: ");
                displayList(merged);
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
