#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 4
#define y 20
int n;int c;
int count;
int itr=4;
struct queue{
    int arr[100];
    int front;
    int rear;
};
typedef struct queue que;
void enque(que* q,int d){
    if(q->rear==99){
        return;
    }
    q->arr[++q->rear]=d;
}
void deque(que* q){
    if(q->front>q->rear)
        return;
    q->front++;
}
int isempty(que* q){
    //printf("front is %d and rear is %d\n",q->front,q->rear);
    if(q->front>q->rear)
        return 0;
    else 
       return 1;
}
void bfs(int v,int n,int mat[][n],int vis[]){
    que q;
    q.front=0;
    q.rear=-1;
    //printf("hello\n");
    vis[v]=1;
    enque(&q,v);
    printf("%d->",v);
    //printf("hello 1\n");
    //int dum=isempty(&q);
    //printf("is empty returned%d",dum);
    while(isempty(&q)){
        for(int i=0;i<n;i++){
            count++;
            //printf("hello");
            if(mat[q.front][i]==1 && vis[i]==0){
                vis[i]=1;
                enque(&q,i);
                printf("%d->",i);
            }
        }
        deque(&q);
    }
}
void bfsmain(){
    FILE *a;
    a=fopen("output.txt","a");
    int tm=0;
    srand(time(NULL));
    for(int j=4;j<20;j++){
        n=j;tm=0;
        int arr[n][n];
        int isvis[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=0;
            }
        }
        if(j<6){
            for(int i=1;i<n;i++){
                arr[i][i-1]=1;
                arr[i-1][i]=1;
            }
        }
        else if(j<10){
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    if(k==l){
                        arr[k][l]=0;
                    }
                    else{
                        arr[k][l]=rand()%2;
                        arr[l][k]=arr[k][l];
                    }
                }
            }
        }
        else{
            for(int k=0;k<j;k++){
                for(int l=0;l<j;l++){
                    if(k==l){
                        arr[k][l]=0;
                    }
                    else{
                        arr[k][l]=arr[l][k]=1;
                    }
                }
            }
        }
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
        }
            c=0;
            printf("displaying the graph %d\n",itr++);
            count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                printf("\nnew connected graph is \n");
                c++;
                bfs(i,n,arr,vis);
            }
        }
        if(c==1){
            printf("\nthe graph is connected\n");
        }
        else{
            printf("the graph is not connected\n");
        }
        fprintf(a,"%d\t%d\n",j,count);
    }
    fclose(a);
}
int main(){
    system("rm -r *.txt");
    bfsmain();
}