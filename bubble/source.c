#include<stdio.h>
#include<stdlib.h>
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
            a=fopen("inputwoprst.txt","a");
            b=fopen("worst.txt","a");
        }
        arr=(int*)malloc(i*sizeof(int));
        temp=i;
        for(j=0;j<i;j++){
            if(choice==1)
                arr[j]=temp--;
            else
                arr[j]=j+1;
            fprintf(a,"%d ",arr[j]);
        }
        fprintf(a,"\n");
        count=0;
        for(c=0;c<i;c++){
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
    while(lp){
        printf("press 1 for best case \n");
        printf("enter 2 for worst case \n");
        scanf("%d",&choice);
        switch(choice){
            case  1:
                system("rm -r best.txt binput.txt");
                bubble(choice);
                break;
            case  2:
                system("rm -r worst.txt inputwoprst.txt");
                bubble(choice);
                break;
            case 3:
                lp=0;
        }
    }
}  