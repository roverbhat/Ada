#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100
void bin(int choice){
    FILE *a;
    FILE *b;
    int i,j,count;
    int *arr;int key,low,mid,high;
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
        for(j=0;j<i;j++){
            arr[j]=j+1;
            fprintf(a,"%d ",arr[j]);
        }
        fprintf(a,"\n");
        count=0;low=0;high=i-1;
        if(choice==1){
            key=arr[i-1]/2;
        }
        else{
            key=arr[0];
        }
        fprintf(a,"key=%d\t",key);
        count=0;
        while(low<=high){
            count++;
            mid=low+(high-low)/2;
            if(arr[mid]==key){
                fprintf(a,"index=%d\n",mid);
                break;
            }
            else if(arr[mid]>key){
                high=mid-1;
            }
            else{
                low=mid+1;
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
                 system("rm -r best.txt  binput.txt");
                 bin(choice);
                 break;
            case  2:
                system("rm -r worst.txt inputwoprst.txt");
                bin(choice);
                break;
            case 3:
                lp=0;
        }
    }
}