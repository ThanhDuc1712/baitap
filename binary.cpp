#include <iostream>
#include <algorithm> 
using namespace std; 

void  bbsort(int a[], int n){
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]); 
			} 
		} 
	} 
}

int  findSmallestGreater(int a[], int n, int k){
	int l = 0;
	int r = n - 1;
	int result = -1; 
	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] > k){
			result = a[mid];
			r = mid - 1; 
		}else{
			l = mid + 1;
		}
    }
	return result;
}

int main(){
	int n,k; cin >> n >> k;
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	bbsort(a,n); 
	int num =  findSmallestGreater(a,n,k);
	if(num == -1){
		cout << "There is no number greater than " << k; 
	} else{
		cout << num; 
	} 
}