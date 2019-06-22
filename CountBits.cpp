short CountBits(unsigned int x) {
	short num_bits = 0;
	while (x) {
		num_bits += x & 1;
		x >>= 1;
	}
	return num_bits;
}
// A signed integer can represent negative numbers; unsigned cannot.
// Signed integers have undefined behavior if they overflow, while unsigned integers wrap around using modulo.