/********
* ec2c version 0.68
* c file generated for node : fibonacci 
* context   method = HEAP
* ext call  method = PROCEDURES
********/
#include <stdlib.h>
#include <string.h>
#define _fibonacci_EC2C_SRC_FILE
#include "fibonacci.h"
/*--------
Internal structure for the call
--------*/
typedef struct  {
   void* client_data;
   //INPUTS
   _integer _n;
   //OUTPUTS
   _integer _res;
   //REGISTERS
   _integer M9;
   _boolean M9_nil;
   _integer M8;
   _boolean M8_nil;
   _boolean M2;
} fibonacci_ctx;
/*--------
Output procedures must be defined,
Input procedures must be used:
--------*/
void fibonacci_I_n(fibonacci_ctx* ctx, _integer V){
   ctx->_n = V;
}
extern void fibonacci_O_res(void* cdata, _integer);
#ifdef CKCHECK
extern void fibonacci_BOT_res(void* cdata);
#endif
/*--------
Internal reset input procedure
--------*/
static void fibonacci_reset_input(fibonacci_ctx* ctx){
   //NOTHING FOR THIS VERSION...
}
/*--------
Reset procedure
--------*/
void fibonacci_reset(fibonacci_ctx* ctx){
   ctx->M9_nil = _true;
   ctx->M8_nil = _true;
   ctx->M2 = _true;
   fibonacci_reset_input(ctx);
}
/*--------
Copy the value of an internal structure
--------*/
void fibonacci_copy_ctx(fibonacci_ctx* dest, fibonacci_ctx* src){
   memcpy((void*)dest, (void*)src, sizeof(fibonacci_ctx));
}
/*--------
Dynamic allocation of an internal structure
--------*/
fibonacci_ctx* fibonacci_new_ctx(void* cdata){
   fibonacci_ctx* ctx = (fibonacci_ctx*)calloc(1, sizeof(fibonacci_ctx));
   ctx->client_data = cdata;
   fibonacci_reset(ctx);
   return ctx;
}
/*--------
Step procedure
--------*/
void fibonacci_step(fibonacci_ctx* ctx){
//LOCAL VARIABLES
   _integer L4;
   _integer L7;
   _integer L1;
   _integer T9;
   _integer T8;
//CODE
   if (ctx->M2) {
      L4 = 0;
   } else {
      L4 = 1;
   }
   L7 = (ctx->M8 + ctx->M9);
   if (ctx->M2) {
      L1 = L4;
   } else {
      L1 = L7;
   }
   fibonacci_O_res(ctx->client_data, L1);
   T9 = ctx->M8;
   T8 = ctx->_n;
   ctx->M9 = T9;
   ctx->M9_nil = _false;
   ctx->M8 = T8;
   ctx->M8_nil = _false;
   ctx->M2 = ctx->M2 && !(_true);
}
