#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define x 10
#define y 100
int count;
void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    // it contain the left half of the array
    int n2 = high - mid;
    // contain the right sideof the array
    // now we have to create 2 array so fn1 nad n2 leght and using this 2 array and using 2 pointer approch
    // we are going to merge it and uopdate the same in original array
    // it is easy to say that we are merging 2 sorted subarray
    // because end the end of the each recursive call we left it with the single elemtn and sort it with the parent call sub array
    int left[n1];
    int right[n2];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (int j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = low;
    count++;
    // k is used as index for arr to modify the original array
    while (i < n1 && j < n2)
    {
        count++;
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    // after existing the loop we left out with some elemt in any one of the array in left or right
    // we can directly copy it because the reamin are always sorted
    while (i < n1)
    {
        arr[k++] = left[i++];
    }
    while (j < n2)
    {
        arr[k++] = right[j++];
    }
}
void mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        // this is same as low+high /2 mto avoid overflow for large input we are writing this as shown above
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void combinein(int arr[],int left[],int right[],int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        arr[i]=left[i];
    }
    for(j=0;j<n;j++){
        arr[i++]=right[j];
    }
}
void gendata(int c[],int n){
    if(n<=1){
        return;
        //for 1 element dont do anything
    }
    if(n==2){
        //which means array has 2 elements
        //swap those
        int temp=c[0];
        c[0]=c[1];
        c[1]=temp;
    }
    int i,j,mid;
    mid=(n+1)/2;
    int a[mid];
    int b[n-mid];
    j=0;
    for(i=0;i<n;i=i+2){
        //accessing even index
        a[j++]=c[i];
    }
    j=0;
    for(i=1;i<n;i=i+2){
        b[j++]=c[i];
    }
    gendata(a,mid);
    gendata(b,n-mid);
    combinein(c,a,b,mid,n-mid);
}
void func(int choice)
{
    FILE *a;
    FILE *b;
    int i, itr = 0;
    int *arr;
    srand(time(NULL));
    printf("hello");
    for (i = 10; i <= 100; i = i + 10)
    {
        if (choice == 1)
        {
            a = fopen("Binput.txt", "a");
            b = fopen("best.txt", "a");
        }
        else if (choice == 2)
        {
            a = fopen("iavg.txt", "a");
            b = fopen("avg.txt", "a");
        }
        else
        {
            a = fopen("iworst.txt", "a");
            b = fopen("worst.txt", "a");
        }
        arr = (int *)malloc(i * sizeof(int));
        fprintf(a, "iteration %d ----\t", itr++);
        if (choice == 1)
        {
            for (int j = 0; j < i; j++)
            {
                arr[j] = j;
                fprintf(a, "%d \t", arr[j]);
            }
            fprintf(a, "\n");
        }
        else if(choice ==2)
        {
            for (int j = 0; j < i; j++)
            {
                arr[j] = rand() % 100;
                fprintf(a, "%d \t", arr[j]);
            }
        }
        else{
            for(int j=0;j<i;j++){
                arr[j]=j;
            }
            gendata(arr,i);
            for(int j=0;j<i;j++){
                fprintf(a,"%d \t",arr[j]);
            }
            fprintf(a,"\n");
        }
        count = 0;
        mergesort(arr,0,i-1);
        fprintf(b, "%d \t%d\n", i, count);
        fclose(a);
        fclose(b);
    }
}
int main()
{
    int lp = 1;
    int choice;
    system("rm -r *.txt");
    while (lp)
    {
        printf("Presss 1 for the best case\n");
        printf("Press 2 for the avg case \n");
        printf("press 3 for the worst case \n");
        scanf("%d", &choice);
        printf("Choice is %d", choice);
        switch (choice)
        {
        case 1:
        case 2:
        case 3:
            func(choice);
            break;
        default:
            lp = 0;
        }
    }
}