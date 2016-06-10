//printer et fixedpoint tal i 16.16 format
void printFix(long i) {
	if((i & 0x80000000) != 0) {
		printf("-");
		i = ~i+1;
	}
	printf("%ld.%04ld", i >> 16, 10000 * (unsigned long) (i & 0xffff) >> 16);
}

//converterer et 18.14 fixedpoint tal til 16.16
long expand(long i) {
	return i << 2;
}
