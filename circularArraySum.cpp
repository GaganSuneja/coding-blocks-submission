#include <iostream>
using namespace std;


int kadane(int *arr,int start,int end){

	int current_sum = 0;
	int current_sum_uptil = 0;

	for(int i=start;i<=end;i++){
		current_sum = current_sum + arr[i];
		if(current_sum>current_sum_uptil){
			current_sum_uptil = current_sum;
		}
		if(current_sum<0){
			current_sum = 0;
		}
	}
	return current_sum_uptil;
}

int maxSum(int *arr,int l){
	int subArraymax = 0,previosSubArrayMax = 0;
		
		for(int i=0;i<l-1;i++){
			subArraymax = kadane(arr,i,i+l-1);
			if(subArraymax>previosSubArrayMax)
			{
				previosSubArrayMax = subArraymax ;
			}
		}
		return previosSubArrayMax;
}

int main(){
	
	int testCases;
	int n;
	cin>>testCases;
	int input[100000];
	while(testCases){
	    cin>>n;
	    for(int x=0;x<n;x++)
	    {cin>>input[x];input[x+n] = input[x];} 
	    cout<<maxSum(input,n)<<endl;
	    --testCases;
	}
	return 0;
}