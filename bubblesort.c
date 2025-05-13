#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void bubblesort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
					int temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
	
}
}
}
}
void printarray(int arr[],int n){

for(int i=0;i<n;i++){
printf("%d ", arr[i]);

}

}
int main(){
       int array[]={12,9,25,18,10};
       int size=sizeof(array)/sizeof(array[0]);

       bubblesort(array,size);

       printf("sorted array");

       printarray(array,size);

       return 0;
}


