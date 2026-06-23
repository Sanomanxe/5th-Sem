#include<iostream>
using namespace std;
int fibonacciIterative(int n){
	int a=0,b=1,c;
	cout<<"\nTracing Iterative Fibonacci:\n";
	cout<<"Initial values-> a=0,b=1\n";
	if(n==0)return a;
	if(n==1)return b;
	for(int i=2;i<=n;i++){
		c=a+b;
		cout<<"Step"<<i<<"c=a+b="<<a<<"+"<<b<<"="<<c<<endl;	
		a=b;
		b=c;}
		return b;
}
int main(){
	int n;
	cout<<"Enter n:";
	cin>>n;
	int result=fibonacciIterative(n);
	cout<<"\nFibonacci("<<n<<")="<<result<<endl;
	return 0;
}