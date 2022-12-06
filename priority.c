#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void add(int item)
{
    int i;
    int j;
 
    for (i = 0; i <= rear; i++)
    {
        if (item >= queue[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                queue[j] = queue[j - 1];
            }
            queue[i] = item;
            return;
        }
    }
    queue[i] = item;
}

void enqueue(int item)
{
    int i;
    int j;

    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow!!!");
        return;
    }

    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        queue[rear] = item;
        return;
    }    
    else
    {
        add(item);
    }
    rear++;
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
        printf("\nQueue is empty, nothing to save...");
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % MAX) {
           putw(queue[i], f);
        }
        putw(queue[i], f);

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

    while ( (item = getw(f)) != EOF ) {
        enqueue(item);
    }

    fclose(f);
}

void dequeue(int item)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty!!!");
        return;
    }
    else
    {
        for (i = 0; i <= rear; i++)
        {
            if (item == queue[i])
            {
                for (; i < rear; i++)
                {
                    queue[i] = queue[i + 1];
                }
    
                queue[i] = -99;
                rear--;
        
                if (rear == -1) 
                {
                    front = -1;
                }
                return;
            }
        }
        printf("\nItem not found in queue!!!");
    } 
}

void search(int item)
{
    int i;
    int result = -1;

    for (i=0; i < MAX; i++) 
    {
        if (item == queue[i]) {
            result = i;
        }
    }

    if (result == -1) 
    {
        printf("\nItem not found!");
    } 
    else
    {
        printf("\nItem fund at index %d\n", result);
    }
}

void display()
{
    int cnt = 0;
    int i = front;

    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty!!!");
    } 
    else 
    {
        printf("\nItems in a Queue: \n");

        for (; i <= rear; i++)
        {
            cnt++;
            printf("%d) %d \n", cnt, queue[i]);
        }
    }
}

int main()
{
    int choice = 1; 
    int item;

    while (1) 
    {
        printf("\nPress 1: Insert an item");
        printf("\nPress 2: Delete an item");
        printf("\nPress 3: Display items");
        printf("\nPress 4: Load queue");
        printf("\nPress 5: Save queue");
        printf("\nPress 6: Search");
        printf("\nPress 0: Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 0:
                exit(0);
            case 1:
                printf("Enter an item to be inserted: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                printf("Enter an item to be deleted: ");
                scanf("%d", &item);
                dequeue(item);
                break;
            case 3:
                display();
                break;
            case 4:
                load();
                break;
            case 5:
                save();
                break;
            case 6:
                printf("Search item: ");
                scanf("%d", &item);
                search(item);
                break;
            default:
                printf("Wrong choice!");
        }
    }
    return 0;
}