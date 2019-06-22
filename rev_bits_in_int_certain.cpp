#include <iostream>
#include <stack>
using namespace std;

void p(int n){
	cout << n << "\t=> "; 
	int mask=1;
	stack<int> s;
	for(int i=0;i<32;i++){
		s.push(int(n&mask?1:0));
		mask = mask << 1;
	}
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
	cout << endl;
}

int main(){
	int x= 20;
	p(x);
	x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
	p(x);
	x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
	p(x);
	x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
	p(x);
	x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
	p(x);
	x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
	p(x);
}