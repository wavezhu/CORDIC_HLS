#include <ap_fixed.h>
#include <ap_int.h>

#define WA 17
#define FA 14
#define WS 16
#define FS 14

typedef ap_fixed<WA,WA-FA> di_t;
typedef ap_fixed<WS,WS-FS> do_t;
typedef ap_uint<2> flag_t;

const do_t Kn = 0.607252935;
const di_t PI = 3.1415926;

void cir_cordic (di_t alpha, do_t &sin_out, do_t &cos_out);
