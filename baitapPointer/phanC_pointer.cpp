#include <iostream>
#include <iomanip> 
using namespace std;

int strlen(char a[]){
	int length = 0;
	while (a[length] != '\0'){
		length++;
	}
	return length;
}

 
void reverse(char a[]){
	int len = strlen(a);
	for(int i = 0; i < len/2; i++){
		char temp = *(a+i);
		*(a+i) = *(a+len-i-1);
		*(a+len-i-1) = temp;
	}
}

void  delete_char(char a[], char c){
	int len = strlen(a);
	int i = 0; 
	while(i < len){
		if(*(a+i) == c){
			for(int j = i; j < len-1; j++){
				*(a+j) = *(a+j+1);
			}
			len--;
		} 
		else{
			i++; 
		} 
	} 
	*(a+len) = '\0'; 
}

// ki tu '_' tuong trung cho ' '. 

void pad_right(char a[], int n){
	int len = strlen(a);
	if(len >= n) return;
	for(int i = len; i < n; i++){
		*(a+i) = '_';
	}
	*(a+n) = '\0'; 
}

void pad_left(char a[], int n){
	int len = strlen(a);
	if(len >= n) return; 
	int k = n - len; 
	for(int i = len; i >= 0; i--){
		*(a+i+k) = *(a+i);
	}
	for(int i = 0; i < n -len; i++){
		*(a+i) = '_'; 
	} 
}

void truncate(char a[], int n){
	int len = strlen(a);
	if(n >= len) return;
	*(a+n) = '\0'; 
}

bool is_palindrome(char a[]){
	int len = strlen(a);
	for(int i = 0; i < len/2; i++){
		if(*(a+i) != *(a+len-i-1)) return false;
	}
	return true;
}

void trim_left(char a[]){
	int len = strlen(a); 
	int i = 0;
	while(*(a+i) == ' '){
		i++; 
	}
	
	for(int j = 0; j < len - i; j++){
		*(a+j) = *(a+j+i); 
	}
	*(a+len-i) = '\0'; 
}

void trim_right(char a[]){
	int len = strlen(a);
	int i = len - 1;
	while(*(a+i) == '_' && i > 0){
		i--; 
	}  
	*(a + i + 1) = '\0';
}



int main(){
	char a[] = "eht ohk oas uad o edoc coh";
	reverse(a); 
	cout << a << endl;
	
	char b[] = "holc tail truongl uetl";
	delete_char(b, 'l');
	cout << b << endl;
	
	pad_right(b, 25);
	cout << b << endl;
	
	pad_left(b,30); 
	cout << b << endl;
	
	truncate(b,28);
	cout << b << endl;
	
	char c[] = "coc coc";
	char c1[] = "UET UET"; 
	cout << boolalpha << is_palindrome(c) << endl;  
	cout << boolalpha << is_palindrome(c1) << endl;
	
	char d[] = "     Thu 2 phai day som di hoc :(     ";
	trim_right(d);	
	cout << d << endl;
    trim_left(d);
	cout << d << endl; 
	
	return 0; 
}