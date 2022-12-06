#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void add(int item)
{
    if ((front == rear + 1) || (front == 0 && rear == MAX - 1)) {
        printf("\nQueue is full!!!\n");
    }
    else
    {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = item;
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
        add(item);
    }

    fclose(f);
}



void delete()
{
    int item;
    if (front == -1)
    {
        printf("\nQueue is empty!!!\n");
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        printf("\nDeleted item: %d \n", item);
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

void sort() {

  for (int step = 0; step < MAX - 1; ++step) 
  {
    for (int i = 0; i < MAX - step - 1; ++i) 
    {
      if (queue[i] > queue[i + 1]) 
      {
        int temp = queue[i];
        queue[i] = queue[i + 1];
        queue[i + 1] = temp;
      }
    }
  }
}

void reverse()
{
    int tmp;
    for (int i = 0; i < MAX / 2; i++)
    {
        tmp = queue[i];
        queue[i] = queue[MAX-i-1];
        queue[MAX-i-1] = tmp;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("\nQueue is empty!!!\n");
    }
    else
    {
        printf("\nItems in a Queue: \n");

        for (i = front; i != rear; i = (i + 1) % MAX) {
           printf("%d) %d \n", i + 1, queue[i]);
        }
        printf("%d) %d \n", i + 1, queue[i]);
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
        printf("\nPress 7: Sort");
        printf("\nPress 8: Reverse");
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
                add(item);
                break;
            case 2:
                delete();
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
            case 7:
                sort();
                break;
            case 8:
                reverse();
                break;
            default:
                printf("Wrong choice!");
        }
    }
    return 0;
}