#include <stdio.h>
#include <stdlib.h>


#define EXIT 5

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
} List;


void printList(Node *curNode);
void clearBuffer();
void addNode(List *list, int dataToAdd);
void deleteNode(List *list, int dataToDelete);

int main()
{
    List list = {NULL};
    int input = 0;

    printf("1)add node\n2)print list\n3)delete node\n4)number of nodes in list\n5)exit\n");
    scanf("%d",&input);
    clearBuffer();

    while (input != EXIT)
    {
        switch (input)
        {
            /*  add */
            case 1:
                printf("Enter value:\n");
                scanf("%d",&input);
                addNode(&list,input);
                break;

            /*  print   */
            case 2:
                printList(list.head);
                break;

            /*  delete  */
            case 3:
                printf("Enter value to delete:\n");
                scanf("%d",&input);
                deleteNode(&list,input);
                break;

            /*  number of nodes */
            case 4:
                printf("Number of nodes is %d:\n",);    //to be implemented
                break;

            default:
                printf("Invalid input. try again\n");
        }
        printf("1)add node\n2)print list\n3)delete node\n4)number of nodes in list\n5)exit\n");
        scanf("%d",&input);
        clearBuffer();
    }

    printList(list.head);
    return 0;
}


/*  deletes node with given data
 *  @input: list, data of node to delete
 *  @output: none*/
void deleteNode(List *list, int dataToDelete)
{
    Node *toDelete = NULL;
    Node *curNode = list->head;

    /*  if list is empty    */
    if (!list->head)
    {
        return;
    }

    /*  if node to delete is the first node in list */
    if (list->head->data == dataToDelete)
    {
        /*  save address of node to delete  */
        toDelete = list->head;

        /*  head is set to be the second node in list   */
        list->head = toDelete->next;

        /*  free memory of node to delete   */
        free(toDelete);
        return;
    }

    while (curNode->next != NULL)   //while list is not finished
    {
        /*  if node to delete is the next node  */
        if (curNode->next->data == dataToDelete)
        {
            /*  save address of node to delete  */
            toDelete = curNode->next;

            /*  current node points to node after next  */
            curNode->next = toDelete->next;

            /*  free memory of node to delete   */
            free(toDelete);
            return;
        }

        /*  move to next node   */
        curNode = curNode->next;
    }

}

/*  adds node with given data
 *  @input: list, data of node to add
 *  @output: none   */
void addNode(List *list, int dataToAdd)
{
    Node *newNode = (Node *) malloc (sizeof(Node));
    newNode->data = dataToAdd;

    /*  new node points to same node as the head    */
    newNode->next = list->head;

    /*  head is now new node    */
    list->head = newNode;
}

/*  clears buffer   */
void clearBuffer()
{
    while (getchar() != '\n');
}


/*  prints list recursively  */
void printList(Node *curNode)
{
    if (!curNode)
    {
        putchar('\n');
        return;
    }
    printf("%d\t",curNode->data);
    printList(curNode->next);
}
