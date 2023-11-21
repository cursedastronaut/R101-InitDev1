#include <iostream>
using namespace std;
int f(int);
double fa(int);
int main(){
 int i;    
 double d;
 i = f(2);  
 d = fa(4);
 cout <<" i = "<< i <<" et d = "<< d <<endl;
 return 0;
}
int f(int a){
	return (2*a) ;
}
double fa(int c){
	return (c/2.0);
}
