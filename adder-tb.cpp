#include "adder-tb.h"
#include "cl_adder_16bit.h"
#include <iostream>
#include <bitset>

void test_cl_adder_16bit() {
    ap_uint<16> a, b;
    ap_uint<16> sum;
    ap_uint<1> carry;

    // Test cu valori mici
    a = 0x0003; // 0000000000000011
    b = 0x0002; // 0000000000000010
    cl_adder_16bit(a, b, sum, carry);
    std::cout << "SUMA: Test cu valori mici: " << std::bitset<16>(sum).to_string() << ", Carry: " << carry << std::endl;

    // Test cu overflow
    a = 0xFFFF; // 1111111111111111
    b = 0xFFFF; // 1111111111111111
	cl_adder_16bit(a, b, sum, carry);
	std::cout << "SUMA: Test cu overflow: " << std::bitset<16>(sum).to_string() << ", Carry: " << carry << std::endl;

	// Test cu 0
	a = 0x1234; // 0001001000110100
	b = 0x0000; // 0000000000000000
	cl_adder_16bit(a, b, sum, carry);
	std::cout << "SUMA: Test cu 0: " << std::bitset<16>(sum).to_string() << ", Carry: " << carry << std::endl;

	// Test cu valori medii
	a = 0x0A5A; // 0000101001011010
	b = 0x05A0; // 0000010110100000
	cl_adder_16bit(a, b, sum, carry);
	std::cout << "SUMA: Test cu valori medii: " << std::bitset<16>(sum).to_string() << ", Carry: " << carry << std::endl;

	//Test cu un bit diferit
	a = 0x5555; // 0101010101010101
	b = 0x5554; // 0101010101010100
	cl_adder_16bit(a, b, sum, carry);
	std::cout << "SUMA: Test cu un bit diferit: " << std::bitset<16>(sum).to_string() << ", Carry: " << carry << std::endl;

	// Test cu Carry Out 1
	a = 0xFFFF; // 1111111111111111 (valoarea maxima pe 16 biți)
	b = 0x0001; // 0000000000000001 (cel mai mic numar pozitiv)
	cl_adder_16bit(a, b, sum, carry);
	std::cout << "SUMA: Test cu Carry out 1: " << std::bitset<16>(sum).to_string() << ", Carry: " << carry << std::endl;


}

int main() {
    test_cl_adder_16bit();
    return 0;
}

