#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
void selection(){
    FILE *input;
    FILE *output;
    srand(time(NULL));
    int count=0;
    int round=0,i,j;int temp,a,b,minind;
    for(i=x;i<=y;i=i+10){
        int *arr=(int *)malloc(sizeof(int)*i);
        input=fopen("input.txt","a");
        fprintf(input,"loop %d \n before sorting    ",++round);
        for(j=0;j<i;j++){
            arr[j]=rand()%1000;
            fprintf(input,"%d\t",arr[j]);
        }
        count=0;
        for(a=0;a<i-1;a++){
            minind=a;
            for(b=a+1;b<i;b++){
                count++;
                if(arr[b]<arr[minind]){
                    minind=b;
                }
            }
            temp=arr[minind];
            arr[minind]=arr[a];
            arr[a]=temp;
        }
        output=fopen("output.txt","a");
        fprintf(output,"%d \t %d \n",i,count);
        fclose(output);
        fprintf(input,"\nafter sorting ");
        for(j=0;j<i;j++){
            fprintf(input,"%d \t",arr[j]);
        }
        fprintf(input,"\n");
        fclose(input);
    }
}
int main(){
    selection();
}