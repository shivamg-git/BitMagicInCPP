// O(N)
short Parity(unsigned long x) {
	short result = 0;
	while (x) {
		result ^= (x & 1);
		x >>= 1;
	}
	return result;
}

// O(K) => bitmagic
short Parity(unsigned long x) {
	short result = 0;
	while (x) {
		result ^= 1;
		x &= (x - 1); // Drops the lowest set bit of x.
	}
	return result;
}

// x & ~(x-1) 	=> return the integer where leftmost 1 bit of x is 1 remaining everything is set to zero
// x&(x-1)		=> return the integer x with leftmost 1 bit set to 0.


// O(n/L) => precomputing result
short Parity(unsigned long x) {// 64 bit = x 
	const int kMaskSize = 16;
	const int kBitMask = 0xFFFF;
	return 	precomputed_parity[x >> (3 * kMaskSize)]^
			precomputed_parity[(x >> (2 * kMaskSize)) & kBitMask] ^
			precomputed_parity[(x >> kMaskSize) & kBitMask] ^
			precomputed_parity[x & kBitMask];
}

// O(log n) => canceling parity 
short Parity(unsigned long x) {
	x ^= x >> 32;
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;
	return x & 0x1;
}