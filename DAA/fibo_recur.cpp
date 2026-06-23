#include<iostream>
using namespace std;
int fibonacciRecursive(int n){

	cout<<"\nCalling Fibonacci:("<<n<<")"<<endl;

	if(n==0){cout<<"return 0";
	return 0;}
	
	if(n==1)
	{cout<<"return 1";
	return 1;}
	int result=fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
	cout<<"Fibonacci("<<n<<")="<<result<<endl;
	return result;
	}
	

int main(){
	int n;
	cout<<"Enter n:";
	cin>>n;
	cout<<"\nTracing Recursive fibonacci:\n";
	int result=fibonacciRecursive(n);
	cout<<"\nFinal Result:Fibonacci("<<n<<")="<<result<<endl;
	return 0;
}