#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
void checkbest(){
    FILE *bpt;
    FILE *res;
    int i,j,count,iteration=0;
    srand(time(NULL));
    for(i=x;i<=y;i=i+10){
        bpt=fopen("inputbest.txt","a");
        count=0;
        int * arr=malloc(i*sizeof(int));
        fprintf(bpt,"%d time \t",++iteration);
        for(int j=0;j<i;j++){
            arr[j]=rand()%1000;
            fprintf(bpt,"%d  ",arr[j]);
        }
        int key=arr[0];
        fprintf(bpt,"\nkey==%d\n",key);
        for(int k=0;k<i;k++){
            count++;
            if(arr[k]==key){
                break;
            }
        }
        fprintf(bpt,"count== %d\n\n",count);
        fclose(bpt);
        res=fopen("bestresult.txt","a");
        fprintf(res,"%d\t%d\n",i,count);
        fclose(res);
    }
}
void checkworst(){
    FILE *bpt;
    FILE *res;
    int i,j,count,iteration=0;
    srand(time(NULL));
    for(i=x;i<=y;i=i+10){
        bpt=fopen("inputworst.txt","a");
        count=0;
        int * arr=malloc(i*sizeof(int));
        fprintf(bpt,"%d time \t",++iteration);
        for(int j=0;j<i;j++){
            arr[j]=rand()%1000;
            fprintf(bpt,"%d  ",arr[j]);
        }
        int key=arr[i-1];
        fprintf(bpt,"\nkey==%d\n",key);
        for(int k=0;k<i;k++){
            count++;
            if(arr[k]==key){
                break;
            }
        }
        fprintf(bpt,"count== %d\n\n",count);
        fclose(bpt);
        res=fopen("worstresult.txt","a");
        fprintf(res,"%d\t%d\n",i,count);
        fclose(res);
    }
}
int main(){
    int lc=1;
    int choice;
    while(lc){
        printf("Press 1 . to check the best case\n");
        printf("press 2. to check the worst case\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                checkbest();
                break;
            case 2:
                checkworst();
                break;
            case 4:
                lc=0;
                break; 
        }
    }

}