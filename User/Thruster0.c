/*
 * File: Thruster0.c
 *
 * Code generated for Simulink model 'Thruster0'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sun Feb 17 21:46:59 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "Thruster0.h"

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Model step function */
void Thruster0_step(void)
{
  real_T tmp;

  /* Signum: '<S1>/Sign' incorporates:
   *  Inport: '<Root>/Direction'
   */
  if (rtU.Direction < 0.0) {
    tmp = -1.0;
  } else if (rtU.Direction > 0.0) {
    tmp = 1.0;
  } else if (rtU.Direction == 0.0) {
    tmp = 0.0;
  } else {
    tmp = rtU.Direction;
  }

  /* Outport: '<Root>/Speed' incorporates:
   *  Inport: '<Root>/Switch'
   *  Inport: '<Root>/Value'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   *  Signum: '<S1>/Sign'
   *  Switch: '<S1>/Switch1'
   */
  rtY.Speed = tmp * rtU.Value * (real_T)(rtU.Switch > 0.0);
}

/* Model initialize function */
void Thruster0_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
