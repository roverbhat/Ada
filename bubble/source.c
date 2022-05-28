#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
void bubble(int choice){
    FILE *a;
    FILE *b;
    int i,j,count;
    int *arr;int temp,c,d,flag=0;
    for(i=x;i<=y;i=i+10){
        if(choice==1){
        a=fopen("binput.txt","a");
        b=fopen("best.txt","a");
        }
        else if(choice==2){
            a=fopen("inputworst.txt","a");
            b=fopen("worst.txt","a");
        }
        else{
            a=fopen("inputavg.txt","a");
            b=fopen("avg.txt","a");
        }
        arr=(int*)malloc(i*sizeof(int));
        temp=rand()%1000;
        for(j=0;j<i;j++){
            if(choice==1){
                arr[j]=temp-j;
            }   
            else if(choice==2)
                arr[j]=j+temp;
            else{
                arr[j]=rand()%999;
            }
            fprintf(a,"%d ",arr[j]);
        }
        fprintf(a,"\n");
        count=0;
        for(c=0;c<i-1;c++){
            flag=0;
            for(d=0;d<i-1-c;d++){
                count++;
                if(arr[d]<arr[d+1]){
                    flag=1;
                    temp=arr[d];
                    arr[d]=arr[d+1];
                    arr[d+1]=temp;
                }
            }
            if(flag==0){
                break;
            }
        }
        fprintf(b,"%d\t%d\n",i,count);
        fclose(a);
        fclose(b);
    }    
        
}
int main(){
    int lp=1,choice;
    system("rm -r *.txt");
    srand(time(NULL));
    while(lp){
        printf("press 1 for best case \n");
        printf("enter 2 for worst case \n");
        printf("Press 3 for avg case\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            case 2:
            case 3:
                bubble(choice);
                break;
            case 4:
                lp=0;
                break;

        }
    }
}  