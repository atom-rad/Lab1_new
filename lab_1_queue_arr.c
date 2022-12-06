#include <stdio.h>
#include<stdlib.h>

#define MAX 50

void insert();
void delete();
void display();

int queue_array[MAX];
int rear = - 1;
int front = - 1;



void insert()
{
    int item;

    if(rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if(front== - 1)
        front = 0;

        printf("\nInset the element in queue : ");
        scanf("%d", &item);
        printf("\n");

        rear = rear + 1;
        queue_array[rear] = item;
    }
}

void delete()
{
    if(front == - 1 || front > rear)
    {
    printf("Queue Underflow \n");
    return;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
        printf("\n");
    }
}

void display()
{
    int i;

    if(front == - 1)
    {
    printf("Queue is empty \n");
    }
    else
    {
        printf("\nQueue is : ");

            for(i = front; i <= rear; i++)
            {
            printf("%d ", queue_array[i]);
            }
        printf("\n \n");
    }
}

void save()
{
    int i = front;
    FILE * f;

    f = fopen("queue.txt", "w+");

    if(f == NULL)
    {
        printf("\nFailed to create file queue.txt.");
        return;
    }

    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty, nothing to save...\n");
        printf("\n");
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % MAX) {
           putw(queue_array[i], f);
        }
        putw(queue_array[i], f);

        printf("\nSuccessfully saved to queue.txt");
    }

    fclose(f);
}

void load()
{
    int i = 0;
    int item;
    FILE * f;

    f = fopen("queue.txt", "r");

    if(f == NULL)
    {
        printf("\nFailed to open file queue.txt.");
        return;
    }

    /*while ( (item = getw(f)) != EOF ) {
        insert(item);
    }
    */
    fclose(f);
}


int main()
{
    int choice;

    while (1)
    {
    printf("1.Insert element\n");
    printf("2.Delete element\n");
    printf("3.Display all elements\n");
    printf("4.Save \n");
    printf("5.Load \n");
    printf("6.Quit \n");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                save();
                break;
            case 5:
                load();
                break;
            case 6:
                exit(1);
            default:
                printf("Wrong choice! \n");
        }
    }
}