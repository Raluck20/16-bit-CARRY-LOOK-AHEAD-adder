#include "cl_adder_16bit.h"

// Functia implementeaza un adder carry look-ahead de 16 biti.
// Intrari: a, b - numere de 16 biti pentru adunare
// Iesiri: sum - suma calculata de 16 biti, carry_out - bitul de carry out
void cl_adder_16bit(ap_uint<16> a, ap_uint<16> b, ap_uint<16> &sum, ap_uint<1> &carry_out) {

    // Array-uri pentru stocarea valorilor de generate si propagate
    ap_uint<1> generate[16];
    ap_uint<1> propagate[16];

    // Initializarea array-ului de carry cu toate valorile la 0
    ap_uint<1> carry[17] = {0};

    // Calculul generate si propagate pentru fiecare bit
    for (int i = 0; i < 16; i++) {
        generate[i] = a[i] & b[i]; // Genereaza (AND) pentru fiecare bit
        propagate[i] = a[i] ^ b[i]; // Propaga (XOR) pentru fiecare bit
    }

    // Initializare carry-in ca 0
    carry[0] = 0;

    // Calculul carry pentru fiecare bit, folosind valorile de generate si propagate
    for (int i = 0; i < 16; i++) {
        carry[i+1] = generate[i] | (propagate[i] & carry[i]);
    }

    // Calculul sumei pentru fiecare bit
    for (int i = 0; i < 16; i++) {
        sum[i] = propagate[i] ^ carry[i]; // XOR intre propagate si carry
    }

    // Seteaza carry-out ca ultimul bit de carry calculat
    carry_out = carry[16];
}
