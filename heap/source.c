#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <time.h>

int count;

void swap(int *arr, int u, int v)
{

    int temp;

    temp = arr[u];

    arr[u] = arr[v];

    arr[v] = temp;
}

void hpfy(int *arr, int n, int r)
{

    int largest = r;

    int left = (2 * r) + 1;

    int right = (2 * r) + 2;

    if (left < n && arr[left] > arr[largest])
    {

        // left child may be greater

        count++;

        largest = left;
    }

    if (right < n && arr[right] > arr[largest])

    {

        // right child may be greatest

        count++;

        largest = right;
    }

    if (largest != r)
    {

        // if root is not the largest

        swap(arr, largest, r);

        hpfy(arr, n, largest);
    }
}

void construct(int *a, int n)
{

    int root = (n / 2) - 1;

    for (int i = root; i >= 0; i--)
    {

        hpfy(a, n, i);
    }

    int cstrcou = count;

    count = 0;

    for (int i = n - 1; i >= 0; i--)
    {

        swap(a, 0, i);

        hpfy(a, i, 0);
    }
}

void driver(int choice)
{

    srand(time(NULL));

    FILE *a;

    if (choice == 1)
    {

        a = fopen("best.txt", "a");
    }

    else if (choice == 2)

        a = fopen("worst.txt", "a");

    else

        a = fopen("avg.txt", "a");

    for (int i = 10; i < 100; i += 10)
    {

        int n = i;

        int *arr;

        count = 0;

        arr = (int *)malloc(sizeof(int) * n);

        if (choice == 1)
        {

            int temp = rand() % 100;

            for (int j = 0; j < n; j++)
            {

                arr[j] = temp--;
            }
        }

        else if (choice == 2)
        {

            for (int j = 0; j < n; j++)
            {

                arr[j] = j + 1;
            }
        }

        else
        {

            for (int j = 0; j < n; j++)
            {

                arr[j] = rand() % 100;
            }
        }

        printf("array before sorting\n");

        for (int i = 0; i < n; i++)
        {

            printf("%d\t", arr[i]);
        }

        printf("\n");

        // following zero based indexing

        construct(arr, n);

        printf("array after sorting\n");

        for (int i = 0; i < n; i++)
        {

            printf("%d\t", arr[i]);
        }

        fprintf(a, "%d\t%d\n", i, count);

        printf("\n");
    }
    fclose(a);
}

int main()
{

    printf("IMplementation of heap sort\n");

    int choice;

    system("rm -r *.txt");

    int lp = 1;

    while (lp)
    {

        printf("Enter the choice\n");

        printf("press 1 for best case\n");

        printf("press 2 for worst case\n");

        printf("press 3 for avg case \n");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

        case 2:

        case 3:

            driver(choice);

            break;

        case 4:

            lp = 0;
        }
    }
}