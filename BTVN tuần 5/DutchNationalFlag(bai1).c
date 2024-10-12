//Dutch National Flag Problem
#include<stdio.h> 
void swap(int A[],int i ,int j)
{
	int temp= A[i] ;
	A[i] =A[j] ;
	A[j] = temp ;
}
void Sorting(int A[],int end) {
	int start=0 ,mid =0 ;
	int pivot =1 ;
	
	while(mid <=end) 
	{
		if(A[mid]<pivot) {         //current element is 0
			swap(A,start,mid) ;
			++start,++mid ;
		}
		else if(A[mid]>pivot) {   //current element is 2
			swap(A,mid,end) ;
			--end;
		}
		else {     //current element is 1
			++mid ;
		}
	}
}
int main() 
{
	int A[] ={0,2,1,2,2,0,0,1,1,1,1,1,2,0,0,2,1,2,0,2,1,2,0,1,2} ;
	int n= sizeof(A)/sizeof(A[0]) ;
	Sorting(A,n-1) ;
	for(int i=0;i<n;i++) {
		printf("%d",A[i]) ;
	}
	return 0;
}
