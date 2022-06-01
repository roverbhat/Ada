    #include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
int count=0;
void binsearch(int arr[],int low,int high,int key){
	int mid=low+(high-low)/2;
	count++;
	if(arr[mid]==key){
		return;
	}
	else if(arr[mid]>key){
		binsearch(arr,low,mid-1,key);
	}
	else
		binsearch(arr,mid+1,high,key);
}
void helper(int arr[],int n,int key){
	count=0;
	binsearch(arr,0,n-1,key);
}
void binary(int choice){
	FILE *a;
	FILE *b;
	int i,j,key,temp,res;int *arr;
	srand(time(NULL));
		if(choice==1){
			a=fopen("bestin.txt","a");
			b=fopen("best.txt","a");
		}
		else if(choice==2){
			a=fopen("worstin.txt","a");
			b=fopen("worst.txt","a");
		}
		else{
			a=fopen("avgin.txt","a");
			b=fopen("avg.txt","a");
		}
	for( i=x;i<=y;i=i+10){
		arr=(int *)malloc(i*sizeof(int));
		res=rand()%100;
		for(j=0;j<i;j++)
		{
			arr[j]=j+res;
			fprintf(a,"%d ",arr[j]);
		}
		fprintf(a,"\n");
		if(choice==1)
		{
			key=arr[(i-1)/2];
		}
		else if(choice==2){
			key=arr[i-1];
		}
		else{
			temp=rand()%(i-1);
			key=arr[temp];
		}
		helper(arr,i,key);
		fprintf(b,"%d\t%d\n",i,count);
	}
		fclose(a);
		fclose(b);
}
void main(){
	int lp=1;
	int choice;
	system("rm -r *.txt");
	while(lp){
		printf("Enter 1 for the best case\n ");
		printf("ENter 2 for the worst case\n");
		printf("Enter 3 for worst case\n");
		printf("Enter 4 to exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			case 2:
			case 3:
				binary(choice);
				break;
			case 4:
				lp=0;
				break;
		}
	}

}	