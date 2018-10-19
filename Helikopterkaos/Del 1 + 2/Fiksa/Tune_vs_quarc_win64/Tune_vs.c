/*
 * Tune_vs.c
 *
 * Code generation for model "Tune_vs".
 *
 * Model version              : 1.65
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Sun Oct 14 13:09:46 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Tune_vs.h"
#include "Tune_vs_private.h"
#include "Tune_vs_dt.h"

/* Block signals (auto storage) */
B_Tune_vs_T Tune_vs_B;

/* Continuous states */
X_Tune_vs_T Tune_vs_X;

/* Block states (auto storage) */
DW_Tune_vs_T Tune_vs_DW;

/* Real-time model */
RT_MODEL_Tune_vs_T Tune_vs_M_;
RT_MODEL_Tune_vs_T *const Tune_vs_M = &Tune_vs_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Tune_vs_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Tune_vs_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (Tune_vs_M->Timing.TaskCounters.TID[1] == 0) {
    Tune_vs_M->Timing.RateInteraction.TID1_2 =
      (Tune_vs_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Tune_vs_M->Timing.perTaskSampleHits[5] =
      Tune_vs_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Tune_vs_M->Timing.TaskCounters.TID[2])++;
  if ((Tune_vs_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    Tune_vs_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Tune_vs_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void Tune_vs_output0(void)             /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_DeadZoney;
  real_T rtb_Backgain;
  real_T u0;
  if (rtmIsMajorTimeStep(Tune_vs_M)) {
    /* set solver stop time */
    if (!(Tune_vs_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Tune_vs_M->solverInfo,
                            ((Tune_vs_M->Timing.clockTickH0 + 1) *
        Tune_vs_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Tune_vs_M->solverInfo,
                            ((Tune_vs_M->Timing.clockTick0 + 1) *
        Tune_vs_M->Timing.stepSize0 + Tune_vs_M->Timing.clockTickH0 *
        Tune_vs_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Tune_vs_M)) {
    Tune_vs_M->Timing.t[0] = rtsiGetT(&Tune_vs_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Tune_vs_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

    /* S-Function Block: Tune_vs/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(Tune_vs_DW.HILReadEncoderTimebase_Task, 1,
        &Tune_vs_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          Tune_vs_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          Tune_vs_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = Tune_vs_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Constant: '<Root>/Constant2' */
    Tune_vs_B.Constant2 = Tune_vs_P.Constant2_Value;

    /* Gain: '<S5>/Travel: Count to rad' */
    Tune_vs_B.TravelCounttorad = Tune_vs_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S12>/Gain' */
    Tune_vs_B.Gain = Tune_vs_P.Gain_Gain * Tune_vs_B.TravelCounttorad;
  }

  /* Gain: '<S13>/Gain' incorporates:
   *  TransferFcn: '<S5>/Travel: Transfer Fcn'
   */
  Tune_vs_B.Gain_d = (Tune_vs_P.TravelTransferFcn_C *
                      Tune_vs_X.TravelTransferFcn_CSTATE +
                      Tune_vs_P.TravelTransferFcn_D * Tune_vs_B.TravelCounttorad)
    * Tune_vs_P.Gain_Gain_l;
  if (rtmIsMajorTimeStep(Tune_vs_M)) {
    /* Gain: '<S5>/Pitch: Count to rad' */
    Tune_vs_B.PitchCounttorad = Tune_vs_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S10>/Gain' */
    Tune_vs_B.Gain_i = Tune_vs_P.Gain_Gain_a * Tune_vs_B.PitchCounttorad;
  }

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S5>/Pitch: Transfer Fcn'
   */
  Tune_vs_B.Gain_b = (Tune_vs_P.PitchTransferFcn_C *
                      Tune_vs_X.PitchTransferFcn_CSTATE +
                      Tune_vs_P.PitchTransferFcn_D * Tune_vs_B.PitchCounttorad) *
    Tune_vs_P.Gain_Gain_ae;
  if (rtmIsMajorTimeStep(Tune_vs_M)) {
    /* Gain: '<S5>/Elevation: Count to rad' */
    Tune_vs_B.ElevationCounttorad = Tune_vs_P.ElevationCounttorad_Gain *
      rtb_DeadZoney;

    /* Gain: '<S8>/Gain' */
    Tune_vs_B.Gain_e = Tune_vs_P.Gain_Gain_lv * Tune_vs_B.ElevationCounttorad;
  }

  /* Gain: '<S9>/Gain' incorporates:
   *  TransferFcn: '<S5>/Elevation: Transfer Fcn'
   */
  Tune_vs_B.Gain_dg = (Tune_vs_P.ElevationTransferFcn_C *
                       Tune_vs_X.ElevationTransferFcn_CSTATE +
                       Tune_vs_P.ElevationTransferFcn_D *
                       Tune_vs_B.ElevationCounttorad) * Tune_vs_P.Gain_Gain_n;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S7>/Kpd '
   *  Gain: '<S7>/Kpp '
   *  Sum: '<S7>/Sum'
   */
  rtb_Backgain = Tune_vs_P.w_0 * Tune_vs_P.w_0 / (Tune_vs_P.k_f * Tune_vs_P.l_p /
    (2.0 * Tune_vs_P.m_p * Tune_vs_P.l_p * Tune_vs_P.l_p)) *
    (Tune_vs_B.Constant2 - Tune_vs_P.Gain1_Gain * Tune_vs_B.Gain_i) - 2.0 *
    Tune_vs_P.w_0 / (Tune_vs_P.k_f * Tune_vs_P.l_p / (2.0 * Tune_vs_P.m_p *
    Tune_vs_P.l_p * Tune_vs_P.l_p)) * (Tune_vs_P.Gain1_Gain * Tune_vs_B.Gain_b);
  if (rtmIsMajorTimeStep(Tune_vs_M)) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Tune_vs_B.Gain_g = Tune_vs_P.Gain_Gain_c * Tune_vs_P.Constant1_Value;

    /* Gain: '<S3>/Gain1' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Tune_vs_B.Gain1 = Tune_vs_P.Gain1_Gain_e * Tune_vs_P.Constant_Value;
  }

  /* Sum: '<S4>/Sum1' incorporates:
   *  Gain: '<S2>/Gain1'
   */
  Tune_vs_B.Sum1 = Tune_vs_B.Gain1 - Tune_vs_P.Gain1_Gain * Tune_vs_B.Gain_e;
  if (rtmIsMajorTimeStep(Tune_vs_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (rtb_Backgain + Tune_vs_B.Gain_g) * Tune_vs_P.Frontgain_Gain;

  /* Saturate: '<S5>/Front motor: Saturation' */
  if (u0 > Tune_vs_P.FrontmotorSaturation_UpperSat) {
    Tune_vs_B.FrontmotorSaturation = Tune_vs_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < Tune_vs_P.FrontmotorSaturation_LowerSat) {
    Tune_vs_B.FrontmotorSaturation = Tune_vs_P.FrontmotorSaturation_LowerSat;
  } else {
    Tune_vs_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S5>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (Tune_vs_B.Gain_g - rtb_Backgain) * Tune_vs_P.Backgain_Gain;

  /* Saturate: '<S5>/Back motor: Saturation' */
  if (u0 > Tune_vs_P.BackmotorSaturation_UpperSat) {
    Tune_vs_B.BackmotorSaturation = Tune_vs_P.BackmotorSaturation_UpperSat;
  } else if (u0 < Tune_vs_P.BackmotorSaturation_LowerSat) {
    Tune_vs_B.BackmotorSaturation = Tune_vs_P.BackmotorSaturation_LowerSat;
  } else {
    Tune_vs_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S5>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(Tune_vs_M)) {
    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: Tune_vs/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      Tune_vs_DW.HILWriteAnalog_Buffer[0] = Tune_vs_B.FrontmotorSaturation;
      Tune_vs_DW.HILWriteAnalog_Buffer[1] = Tune_vs_B.BackmotorSaturation;
      result = hil_write_analog(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILWriteAnalog_channels, 2, &Tune_vs_DW.HILWriteAnalog_Buffer
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
      }
    }

    /* RateTransition: '<S6>/Rate Transition: x' */
    if (Tune_vs_M->Timing.RateInteraction.TID1_2) {
      Tune_vs_B.RateTransitionx = Tune_vs_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S6>/Rate Transition: x' */

    /* DeadZone: '<S6>/Dead Zone: x' */
    if (Tune_vs_B.RateTransitionx > Tune_vs_P.DeadZonex_End) {
      rtb_DeadZoney = Tune_vs_B.RateTransitionx - Tune_vs_P.DeadZonex_End;
    } else if (Tune_vs_B.RateTransitionx >= Tune_vs_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = Tune_vs_B.RateTransitionx - Tune_vs_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: x' */

    /* Gain: '<S6>/Joystick_gain_x' incorporates:
     *  Gain: '<S6>/Gain: x'
     */
    Tune_vs_B.Joystick_gain_x = Tune_vs_P.Gainx_Gain * rtb_DeadZoney *
      Tune_vs_P.Joystick_gain_x;

    /* RateTransition: '<S6>/Rate Transition: y' */
    if (Tune_vs_M->Timing.RateInteraction.TID1_2) {
      Tune_vs_B.RateTransitiony = Tune_vs_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S6>/Rate Transition: y' */

    /* DeadZone: '<S6>/Dead Zone: y' */
    if (Tune_vs_B.RateTransitiony > Tune_vs_P.DeadZoney_End) {
      rtb_DeadZoney = Tune_vs_B.RateTransitiony - Tune_vs_P.DeadZoney_End;
    } else if (Tune_vs_B.RateTransitiony >= Tune_vs_P.DeadZoney_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = Tune_vs_B.RateTransitiony - Tune_vs_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: y' */

    /* Gain: '<S6>/Joystick_gain_y' incorporates:
     *  Gain: '<S6>/Gain: y'
     */
    Tune_vs_B.Joystick_gain_y = Tune_vs_P.Gainy_Gain * rtb_DeadZoney *
      Tune_vs_P.Joystick_gain_y;
  }
}

/* Model update function for TID0 */
void Tune_vs_update0(void)             /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Tune_vs_M)) {
    rt_ertODEUpdateContinuousStates(&Tune_vs_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Tune_vs_M->Timing.clockTick0)) {
    ++Tune_vs_M->Timing.clockTickH0;
  }

  Tune_vs_M->Timing.t[0] = rtsiGetSolverStopTime(&Tune_vs_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Tune_vs_M->Timing.clockTick1)) {
    ++Tune_vs_M->Timing.clockTickH1;
  }

  Tune_vs_M->Timing.t[1] = Tune_vs_M->Timing.clockTick1 *
    Tune_vs_M->Timing.stepSize1 + Tune_vs_M->Timing.clockTickH1 *
    Tune_vs_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Tune_vs_derivatives(void)
{
  XDot_Tune_vs_T *_rtXdot;
  _rtXdot = ((XDot_Tune_vs_T *) Tune_vs_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += Tune_vs_P.TravelTransferFcn_A *
    Tune_vs_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += Tune_vs_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += Tune_vs_P.PitchTransferFcn_A *
    Tune_vs_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += Tune_vs_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += Tune_vs_P.ElevationTransferFcn_A *
    Tune_vs_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += Tune_vs_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE = Tune_vs_B.Sum1;
}

/* Model output function for TID2 */
void Tune_vs_output2(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: Tune_vs/Joystick/Game Controller (game_controller_block) */
  {
    if (Tune_vs_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(Tune_vs_DW.GameController_Controller, &state,
        &new_data);
      if (result == 0) {
        Tune_vs_B.GameController_o4 = state.x;
        Tune_vs_B.GameController_o5 = state.y;
      }
    } else {
      Tune_vs_B.GameController_o4 = 0;
      Tune_vs_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void Tune_vs_update2(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S6>/Rate Transition: x' */
  Tune_vs_DW.RateTransitionx_Buffer0 = Tune_vs_B.GameController_o4;

  /* Update for RateTransition: '<S6>/Rate Transition: y' */
  Tune_vs_DW.RateTransitiony_Buffer0 = Tune_vs_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Tune_vs_M->Timing.clockTick2)) {
    ++Tune_vs_M->Timing.clockTickH2;
  }

  Tune_vs_M->Timing.t[2] = Tune_vs_M->Timing.clockTick2 *
    Tune_vs_M->Timing.stepSize2 + Tune_vs_M->Timing.clockTickH2 *
    Tune_vs_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void Tune_vs_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Tune_vs_output0();
    break;

   case 2 :
    Tune_vs_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void Tune_vs_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Tune_vs_update0();
    break;

   case 2 :
    Tune_vs_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Tune_vs_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Tune_vs/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &Tune_vs_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(Tune_vs_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Tune_vs_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
      return;
    }

    if ((Tune_vs_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &Tune_vs_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = Tune_vs_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &Tune_vs_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = Tune_vs_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_analog_input_chan, 8U,
        &Tune_vs_DW.HILInitialize_AIMinimums[0],
        &Tune_vs_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }

    if ((Tune_vs_P.HILInitialize_set_analog_output && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &Tune_vs_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = Tune_vs_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &Tune_vs_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = Tune_vs_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_analog_output_cha, 8U,
        &Tune_vs_DW.HILInitialize_AOMinimums[0],
        &Tune_vs_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }

    if ((Tune_vs_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Tune_vs_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Tune_vs_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_analog_output_cha, 8U,
        &Tune_vs_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }

    if (Tune_vs_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Tune_vs_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Tune_vs_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Tune_vs_DW.HILInitialize_Card,
         Tune_vs_P.HILInitialize_analog_output_cha, 8U,
         &Tune_vs_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }

    if ((Tune_vs_P.HILInitialize_set_encoder_param && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &Tune_vs_DW.HILInitialize_QuadratureModes
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = Tune_vs_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_encoder_channels, 8U, (t_encoder_quadrature_mode
        *) &Tune_vs_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }

    if ((Tune_vs_P.HILInitialize_set_encoder_count && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &Tune_vs_DW.HILInitialize_InitialEICounts
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = Tune_vs_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_encoder_channels, 8U,
        &Tune_vs_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }

    if ((Tune_vs_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &Tune_vs_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Tune_vs_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &Tune_vs_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          Tune_vs_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &Tune_vs_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            Tune_vs_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            Tune_vs_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              Tune_vs_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            Tune_vs_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            Tune_vs_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              Tune_vs_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(Tune_vs_DW.HILInitialize_Card,
          &Tune_vs_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &Tune_vs_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(Tune_vs_DW.HILInitialize_Card,
          &Tune_vs_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &Tune_vs_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &Tune_vs_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = Tune_vs_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &Tune_vs_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = Tune_vs_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &Tune_vs_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = Tune_vs_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &Tune_vs_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &Tune_vs_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &Tune_vs_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &Tune_vs_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = Tune_vs_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &Tune_vs_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Tune_vs_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_pwm_channels, 8U,
        &Tune_vs_DW.HILInitialize_POSortedFreqs[0],
        &Tune_vs_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }

    if ((Tune_vs_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Tune_vs_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Tune_vs_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(Tune_vs_DW.HILInitialize_Card,
        Tune_vs_P.HILInitialize_pwm_channels, 8U,
        &Tune_vs_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }

    if (Tune_vs_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &Tune_vs_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Tune_vs_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Tune_vs_DW.HILInitialize_Card, Tune_vs_P.HILInitialize_pwm_channels, 8U,
         &Tune_vs_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

  /* S-Function Block: Tune_vs/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(Tune_vs_DW.HILInitialize_Card,
      Tune_vs_P.HILReadEncoderTimebase_samples_,
      Tune_vs_P.HILReadEncoderTimebase_channels, 3,
      &Tune_vs_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S6>/Rate Transition: x' */
  Tune_vs_B.RateTransitionx = Tune_vs_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S6>/Rate Transition: y' */
  Tune_vs_B.RateTransitiony = Tune_vs_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: Tune_vs/Joystick/Game Controller (game_controller_block) */
  {
    if (Tune_vs_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open(Tune_vs_P.GameController_ControllerNumber,
        Tune_vs_P.GameController_BufferSize, deadzone, saturation,
        Tune_vs_P.GameController_AutoCenter, 0, 1.0,
        &Tune_vs_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  Tune_vs_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  Tune_vs_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  Tune_vs_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  Tune_vs_X.Integrator_CSTATE = Tune_vs_P.Integrator_IC;

  /* InitializeConditions for RateTransition: '<S6>/Rate Transition: x' */
  Tune_vs_DW.RateTransitionx_Buffer0 = Tune_vs_P.RateTransitionx_X0;

  /* InitializeConditions for RateTransition: '<S6>/Rate Transition: y' */
  Tune_vs_DW.RateTransitiony_Buffer0 = Tune_vs_P.RateTransitiony_X0;
}

/* Model terminate function */
void Tune_vs_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Tune_vs/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Tune_vs_DW.HILInitialize_Card);
    hil_monitor_stop_all(Tune_vs_DW.HILInitialize_Card);
    is_switching = false;
    if ((Tune_vs_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &Tune_vs_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = Tune_vs_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((Tune_vs_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (Tune_vs_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &Tune_vs_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = Tune_vs_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Tune_vs_DW.HILInitialize_Card
                         , Tune_vs_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , Tune_vs_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &Tune_vs_DW.HILInitialize_AOVoltages[0]
                         , &Tune_vs_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(Tune_vs_DW.HILInitialize_Card,
            Tune_vs_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &Tune_vs_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(Tune_vs_DW.HILInitialize_Card,
            Tune_vs_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &Tune_vs_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Tune_vs_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Tune_vs_DW.HILInitialize_Card);
    hil_monitor_delete_all(Tune_vs_DW.HILInitialize_Card);
    hil_close(Tune_vs_DW.HILInitialize_Card);
    Tune_vs_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: Tune_vs/Joystick/Game Controller (game_controller_block) */
  {
    if (Tune_vs_P.GameController_Enabled) {
      game_controller_close(Tune_vs_DW.GameController_Controller);
      Tune_vs_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Tune_vs_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Tune_vs_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Tune_vs_initialize();
}

void MdlTerminate(void)
{
  Tune_vs_terminate();
}

/* Registration function */
RT_MODEL_Tune_vs_T *Tune_vs(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Tune_vs_M, 0,
                sizeof(RT_MODEL_Tune_vs_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Tune_vs_M->solverInfo, &Tune_vs_M->Timing.simTimeStep);
    rtsiSetTPtr(&Tune_vs_M->solverInfo, &rtmGetTPtr(Tune_vs_M));
    rtsiSetStepSizePtr(&Tune_vs_M->solverInfo, &Tune_vs_M->Timing.stepSize0);
    rtsiSetdXPtr(&Tune_vs_M->solverInfo, &Tune_vs_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Tune_vs_M->solverInfo, (real_T **)
                         &Tune_vs_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Tune_vs_M->solverInfo,
      &Tune_vs_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Tune_vs_M->solverInfo, (&rtmGetErrorStatus(Tune_vs_M)));
    rtsiSetRTModelPtr(&Tune_vs_M->solverInfo, Tune_vs_M);
  }

  rtsiSetSimTimeStep(&Tune_vs_M->solverInfo, MAJOR_TIME_STEP);
  Tune_vs_M->ModelData.intgData.f[0] = Tune_vs_M->ModelData.odeF[0];
  Tune_vs_M->ModelData.contStates = ((real_T *) &Tune_vs_X);
  rtsiSetSolverData(&Tune_vs_M->solverInfo, (void *)
                    &Tune_vs_M->ModelData.intgData);
  rtsiSetSolverName(&Tune_vs_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Tune_vs_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Tune_vs_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Tune_vs_M->Timing.sampleTimes = (&Tune_vs_M->Timing.sampleTimesArray[0]);
    Tune_vs_M->Timing.offsetTimes = (&Tune_vs_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Tune_vs_M->Timing.sampleTimes[0] = (0.0);
    Tune_vs_M->Timing.sampleTimes[1] = (0.002);
    Tune_vs_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    Tune_vs_M->Timing.offsetTimes[0] = (0.0);
    Tune_vs_M->Timing.offsetTimes[1] = (0.0);
    Tune_vs_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Tune_vs_M, &Tune_vs_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Tune_vs_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = Tune_vs_M->Timing.perTaskSampleHitsArray;
    Tune_vs_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Tune_vs_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Tune_vs_M, -1);
  Tune_vs_M->Timing.stepSize0 = 0.002;
  Tune_vs_M->Timing.stepSize1 = 0.002;
  Tune_vs_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  Tune_vs_M->Sizes.checksums[0] = (3214474514U);
  Tune_vs_M->Sizes.checksums[1] = (3090759925U);
  Tune_vs_M->Sizes.checksums[2] = (3875927736U);
  Tune_vs_M->Sizes.checksums[3] = (2126344067U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Tune_vs_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Tune_vs_M->extModeInfo,
      &Tune_vs_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Tune_vs_M->extModeInfo, Tune_vs_M->Sizes.checksums);
    rteiSetTPtr(Tune_vs_M->extModeInfo, rtmGetTPtr(Tune_vs_M));
  }

  Tune_vs_M->solverInfoPtr = (&Tune_vs_M->solverInfo);
  Tune_vs_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Tune_vs_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Tune_vs_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Tune_vs_M->ModelData.blockIO = ((void *) &Tune_vs_B);

  {
    Tune_vs_B.Constant2 = 0.0;
    Tune_vs_B.TravelCounttorad = 0.0;
    Tune_vs_B.Gain = 0.0;
    Tune_vs_B.Gain_d = 0.0;
    Tune_vs_B.PitchCounttorad = 0.0;
    Tune_vs_B.Gain_i = 0.0;
    Tune_vs_B.Gain_b = 0.0;
    Tune_vs_B.ElevationCounttorad = 0.0;
    Tune_vs_B.Gain_e = 0.0;
    Tune_vs_B.Gain_dg = 0.0;
    Tune_vs_B.Gain_g = 0.0;
    Tune_vs_B.Gain1 = 0.0;
    Tune_vs_B.Sum1 = 0.0;
    Tune_vs_B.FrontmotorSaturation = 0.0;
    Tune_vs_B.BackmotorSaturation = 0.0;
    Tune_vs_B.RateTransitionx = 0.0;
    Tune_vs_B.Joystick_gain_x = 0.0;
    Tune_vs_B.RateTransitiony = 0.0;
    Tune_vs_B.Joystick_gain_y = 0.0;
    Tune_vs_B.GameController_o4 = 0.0;
    Tune_vs_B.GameController_o5 = 0.0;
  }

  /* parameters */
  Tune_vs_M->ModelData.defaultParam = ((real_T *)&Tune_vs_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Tune_vs_X;
    Tune_vs_M->ModelData.contStates = (x);
    (void) memset((void *)&Tune_vs_X, 0,
                  sizeof(X_Tune_vs_T));
  }

  /* states (dwork) */
  Tune_vs_M->ModelData.dwork = ((void *) &Tune_vs_DW);
  (void) memset((void *)&Tune_vs_DW, 0,
                sizeof(DW_Tune_vs_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Tune_vs_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Tune_vs_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Tune_vs_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Tune_vs_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Tune_vs_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Tune_vs_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Tune_vs_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      Tune_vs_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  Tune_vs_DW.HILWriteAnalog_Buffer[0] = 0.0;
  Tune_vs_DW.HILWriteAnalog_Buffer[1] = 0.0;
  Tune_vs_DW.RateTransitionx_Buffer0 = 0.0;
  Tune_vs_DW.RateTransitiony_Buffer0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Tune_vs_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  Tune_vs_M->Sizes.numContStates = (4);/* Number of continuous states */
  Tune_vs_M->Sizes.numY = (0);         /* Number of model outputs */
  Tune_vs_M->Sizes.numU = (0);         /* Number of model inputs */
  Tune_vs_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Tune_vs_M->Sizes.numSampTimes = (3); /* Number of sample times */
  Tune_vs_M->Sizes.numBlocks = (51);   /* Number of blocks */
  Tune_vs_M->Sizes.numBlockIO = (21);  /* Number of block outputs */
  Tune_vs_M->Sizes.numBlockPrms = (152);/* Sum of parameter "widths" */
  return Tune_vs_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
