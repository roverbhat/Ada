#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 150
void uclid(int choice){
    FILE *f;FILE *result;
    srand(time(NULL));
    int m,n,i,j,prevp=3,it=0,count,r,k,l;
    srand(time(NULL));
    for(i=0;i<10;i++){
        if(choice==1){
            m=rand()%100;
            n=m*2;
            f=fopen("bestinput.txt","a");
            fprintf(f,"iteration %d\n",it++);
            fprintf(f,"%d\t %d \n",m,n);
        }
        else{
            m=prevp;
            int flag=0;
            for(k=prevp+1;k<1000;k++){
                flag=0;
                for(l=2;l<=(k/2);l++){
                    if(k%l==0)
                        flag=1;
                }
                if(flag==0){
                    n=k;
                    prevp=n;
                    break;
                }
            }
            f=fopen("worstinput.txt","a");
            fprintf(f,"iteration %d\n",it++);
            fprintf(f,"%d\t %d \n",m,n);
        }
    count=0;
    int max=(m>n)?m:n;
    if(choice==1){
        result=fopen("rb.txt","a");
    }
    else{
        result=fopen("rw.txt","a");
    }
    while(n!=0){
        count++;
        r=m%n;
        m=n;
        n=r;
    }
    fprintf(result,"%d\t%d\n",max,count);
    fclose(f);
    fclose(result);
    }
}
int main(){
    int lp=1;
    int choice;
    while(lp){
        printf("Enter your choice\n");
        printf("1.calculate best case\n ");
        printf("2.worst\n");
        scanf("%d",&choice);
        if(choice==2 || choice==1){
            uclid(choice);
        }
        else{
            lp=0;
        }
    }
}