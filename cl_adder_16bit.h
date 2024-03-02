#ifndef CL_ADDER_16BIT_H_
#define CL_ADDER_16BIT_H_

#include <ap_int.h>

void cl_adder_16bit(ap_uint<16> a, ap_uint<16> b, ap_uint<16> &sum, ap_uint<1> &carry_out);

#endif
