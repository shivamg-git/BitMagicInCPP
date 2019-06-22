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
	int x = -20;
	int y = 20;
	unsigned int z = 20;
	int mask;
	
	//@Extract Lowest Bit => (x & ~(x-1)) , x & (-x) 
	
	cout << "# Extract Lowest Bit" << endl;
	cout << "on x = -20 signed!"   << endl;
	p(x);
	p(int(x&~(x-1)));
	p(x&(-x));

	cout << "on x = 20 signed!" << endl;
	p(y);
	p(int(y&~(y-1)));
	p(y&(-y));

	cout << "on x = 20 unsigned!" << endl;
	p(z);
	p(int(z&~(z-1)));
	p(z&(-z));
	cout << endl;


	//@Testing Shift Operation
	cout << "Left Shift Operation!!!" << endl;
	p(x);
	p(x<<1);cout << endl;
	p(y);
	p(y<<1);cout << endl;
	p(z);
	p(z<<1);cout << endl;

	cout << "right Shift Operation!!!" << endl;
	p(x);
	p(x>>1);cout << endl;
	p(y);
	p(y>>1);cout << endl;
	p(z);
	p(z>>1);cout << endl;

	//@Clear lowest bit
	p(x);
	p(x & (x - 1));
	p(y);
	p(y & (y - 1));
	p(z);
	p(z & (z - 1));

	//@negative numbers are generally stored inform of 2's compliment

	//@ Arithmatic Shift vs Logical Shift
	/*
		When shifting left, there is no difference between arithmetic and logical shift. When shifting right, the type of shift depends on the type of the value being shifted.
		(As background for those readers unfamiliar with the difference, a "logical" right shift by 1 bit shifts all the bits to the right and fills in the leftmost bit with a 0. 
		An "arithmetic" shift leaves the original value in the leftmost bit. The difference becomes important when dealing with negative numbers.)
		When shifting an unsigned value, the >> operator in C is a logical shift. When shifting a signed value, the >> operator is an arithmetic shift.

		For example, assuming a 32 bit machine:

		signed int x1 = 5;
		assert((x1 >> 1) == 2);
		signed int x2 = -5;
		assert((x2 >> 1) == -3);
		unsigned int x3 = (unsigned int)-5;
		assert((x3 >> 1) == 0x7FFFFFFD); 
	*/

	//@ Get Bit at index i
	p(x);
	p(x&(1<<5));

	//@ Set Bit at index i
	p(y);
	p(y|(1<<5));

	//@ Clear Bit at index i
	p(y);
	p(y&(~(1<<4)));

	//@ Clear_bits_msb_through_i(num, index)
	mask = (1 << 2) - 1;
	cout << "mask: ";
	p(mask);
	p(y);
	p(y & mask);

	//@ clear_bits_from_i_through_0(num, index)
	mask = ~((1 << 4) - 1);
	p(mask);
	p(y);
	p(y & mask);

	//@ Right propagate the rightmost 1-bit. 01010000 => 01011111
	p(y);
	p(y | (y - 1));

	//@ Isolate the rightmost 0-bit. 10101011 => 00000100
	p(y);
	p(~y & (y + 1));

	//@ Turn on the rightmost 0-bit. 10100011 => 10100111
	p(y);
	p( y | (y + 1));

	//@ Simple Bitwise oprator
	p(10);
	p(20);
	cout << "10 | 20 :" ;p(10|20); // set union
	cout << "10 & 20 :" ;p(10&20); // set Intersection
	cout << "10 ^ 20 :" ;p(10^20); // XOR: bit 1 represent bit at loc are diff(Hamming difference);
	cout << "10 &-20 :" ;p(10&~20); // set Substraction

	//@ negate number
	p(x);
	p(~x + 1); 

	//@ power of 2 or not x&(x-1)?false:true;
	// x!=0 && ((x&(x-1)) == 0);

}