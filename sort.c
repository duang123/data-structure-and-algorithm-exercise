#include<stdlib.h> 
#include<stdio.h>

#define leftChild(i) (2*(i)+1)

static void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}

void insertSort(int A[],int N){
	int i,j;
	for(i=1;i<N;i++){
		int tmp=A[i];
		for(j=i;j>0 && tmp<A[j-1];j--)
		  A[j]=A[j-1];
		A[j]=tmp;
	}
}

void shellSort(int A[],int N){
	int increase,i,j,tmp;
	for(increase=N/2;increase>0;increase/=2){
		for(i=increase;i<N;i++){
			tmp=A[i];
			for(j=i;j>=increase;j-=increase){
				if(tmp<A[j-increase])
				  A[j]=A[j-increase];
				else break;
			}
			A[j]=tmp;
		}
	}
}

void printArray(int arr[],int N){
	int i;
	for(i=0;i<N;i++)
	  printf("%d\t",arr[i]);
	printf("\n");
}

static void percDown(int arr[],int pos,int N){
	int child,i;
	int tmp=arr[pos];
	for(i=pos;leftChild(i)<N;i=child){
		child=leftChild(i);
		if(child!=N-1 && arr[child]<arr[child+1])
		  ++child;
		if(tmp<arr[child])
		  arr[i]=arr[child];
		else break;
	}
	arr[i]=tmp;
}

void heapSort(int arr[],int N){
	int i;
	for(i=N/2;i>=0;i--)
		percDown(arr,i,N);
	for(i=N-1;i>0;i--){
		swap(&arr[0],&arr[i]);
		percDown(arr,0,i);
	}	
}


int main(){
	int array[9]={56,78,33,22,14,156,123,64,634};
	insertSort(array,9);
	printArray(array,9);
	shellSort(array,9);
	printArray(array,9);
	heapSort(array,9);
	printArray(array,9);
	return 0;
	
}
