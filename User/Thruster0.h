/*
 * File: Thruster0.h
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

#ifndef RTW_HEADER_Thruster0_h_
#define RTW_HEADER_Thruster0_h_
#ifndef Thruster0_COMMON_INCLUDES_
# define Thruster0_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Thruster0_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T Direction;                    /* '<Root>/Direction' */
  real_T Value;                        /* '<Root>/Value' */
  real_T Switch;                       /* '<Root>/Switch' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Speed;                        /* '<Root>/Speed' */
} ExtY;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Thruster0_initialize(void);
extern void Thruster0_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('thruster/Thruster')    - opens subsystem thruster/Thruster
 * hilite_system('thruster/Thruster/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'thruster'
 * '<S1>'   : 'thruster/Thruster'
 */
#endif                                 /* RTW_HEADER_Thruster0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
