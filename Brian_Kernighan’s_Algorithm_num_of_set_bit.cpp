// It helps in finding no of set bits(1s) in binary representation of a number.
// Again using our observation about x & x-1 and use it to give rightmost set bit 
// so if we do it again and again till we get 0 then we will get no of set bits it originally had! 
// This is what Brian Kernighan’s algo does.

while (n) {
	n = n & (n-1);
	count++; 
}