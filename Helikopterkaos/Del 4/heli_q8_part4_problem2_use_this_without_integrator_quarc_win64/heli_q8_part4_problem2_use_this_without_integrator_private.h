/*
 * heli_q8_part4_problem2_use_this_without_integrator_private.h
 *
 * Code generation for model "heli_q8_part4_problem2_use_this_without_integrator".
 *
 * Model version              : 1.93
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Oct 17 20:17:59 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_heli_q8_part4_problem2_use_this_without_integrator_private_h_
#define RTW_HEADER_heli_q8_part4_problem2_use_this_without_integrator_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);
void heli_q8_part4_problem2_use_this_without_integrator_output0(void);
void heli_q8_part4_problem2_use_this_without_integrator_update0(void);
void heli_q8_part4_problem2_use_this_without_integrator_output2(void);
void heli_q8_part4_problem2_use_this_without_integrator_update2(void);/* private model entry point functions */
extern void heli_q8_part4_problem2_use_this_without_integrator_derivatives(void);

#endif                                 /* RTW_HEADER_heli_q8_part4_problem2_use_this_without_integrator_private_h_ */
