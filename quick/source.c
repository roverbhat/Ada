#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define x 10
#define y 100
int count;
int choice;
int hover(int arr[],int low,int high){
	int pi=low;
	int pivot=arr[low];
	int i=low+1,j=high;
	int temp;
	while(i<j){
		while(i<=high && arr[i]<pivot){
			i++;
			count++;
		}
		while(arr[j]>pivot){
			j--;
			count++;
		}
		if(i!=j){
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		}
		i++;j--;
	}
	temp=arr[pi];
	arr[pi]=arr[i];
	arr[i]=temp;
	return i;
}
void quicksort(int arr[],int low,int high){
	if(low<high){
		int s=hover(arr,low,high);
		quicksort(arr,low,s-1);
		quicksort(arr,s+1,high);
	}
}
void driver(int choice){
	FILE* a;
	FILE* b;
	int i,j,k,l,m;
	int *arr;
	srand(time(NULL));
	if(choice==1){
		a=fopen("ibest.txt","a");
		b=fopen("best.txt","a");
	}
	else if(choice==2){
		a=fopen("iworst.txt","a");
		b=fopen("worst.txt","a");
	}
	else{
		a=fopen("iavg.txt","a");
		b=fopen("avg.txt","a");
	}
	for(i=x;i<=y;i=i+10){
		arr=(int *)malloc(i*sizeof(int));
		if(choice==1){
			for(j=0;j<i;j++){
				arr[j]=i;
				fprintf(a,"%d \t",arr[j]);
			}
			fprintf(a,"\n");
		}
		else if(choice==2){
			for(j=0;j<i;j++){
				arr[j]=j;
				fprintf(a,"%d \t",arr[j]);
			}
			fprintf(a,"\n");
		}
        else{
            	for(j=0;j<i;j++){
				arr[j]=rand()%100;
				fprintf(a,"%d \t",arr[j]);
			}
			fprintf(a,"\n");
        }
		count=0;
		quicksort(arr,0,i-1);
		fprintf(b,"%d\t%d\n",i,count);
	}
	fclose(a);
	fclose(b);
}
int main(){
	int lp=1;
	system("rm -r *.txt");
	while(lp){
		printf("Hey please enter your choice \n");
		printf("press 1 for the best case \n");
		printf("press 2 for worst case \n");
		printf("press 3 for avg case \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			case 2:
			case 3:
				driver(choice);
				break;
			default:
				lp=0;
		}
	}
}