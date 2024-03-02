#ifndef ADDER_TB_H_
#define ADDER_TB_H_

#include <ap_int.h>

void cl_adder_16bit(ap_uint<16> a, ap_uint<16> b, ap_uint<16> &sum, ap_uint<1> &carry_out);
void test_cl_adder_16bit();
#endif // ADDER_TB_H
