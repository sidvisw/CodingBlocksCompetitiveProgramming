#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int Xor=0;
	for(int i=0;i<n;i++){
		Xor^=arr[i];
	}
	cout<<Xor<<endl;
	return 0;
}