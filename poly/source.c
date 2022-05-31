#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
int main(){
    int v=5;
    FILE *a;
    FILE *b;
    srand(time(NULL));
    int i,j,pow,itr=0,sum,count=0;
    printf("hi");
    for(i=x;i<=y;i=i+10){
        int *arr;
        arr=malloc(i*sizeof(int));
        a=fopen("input.txt","a");
        b=fopen("out[ut.txt","a");
        fprintf(a,"iteration no %d--",++itr);
        printf("hi");
        for(j=0;j<i;j++){
            arr[i]=rand()%1000;
        }
        fprintf(a,"\n");
        //stored the data in descendinng power of x
        pow=1;
        sum=arr[i-1];
        count=0;
        for(j=i-2;j>=0;j--){
            pow=pow*v;
            sum=sum+(arr[j]*pow);
            count=count+2;
        }
        fprintf(a,"ans is %d\n",sum);
        fprintf(b,"%d\t%d\n",i,count);
        fclose(a);
        fclose(b);
        free(arr);
    }
}