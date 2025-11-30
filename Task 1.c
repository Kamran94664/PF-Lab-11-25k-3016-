#include<stdio.h>

int add(int num[],int n){
	if(n<=1){
		return;
	}
	else{
		return num[n]+num[n-1];
	}
}



int main(){
	int n,sum;
	printf("What are the number of terms:- ");
	scanf("%d",&n);
	
	int num[n];
	int i;
	for(i=0;i<n;i++){
		printf("Enter Number%d: ",i+1);
		scanf("%d",num[i]);
	}
    sum=add(num,n);
    return 0;
}
