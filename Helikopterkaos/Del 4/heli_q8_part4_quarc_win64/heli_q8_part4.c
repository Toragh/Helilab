/*
 * heli_q8_part4.c
 *
 * Code generation for model "heli_q8_part4".
 *
 * Model version              : 1.90
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Oct 17 14:32:21 2018
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "heli_q8_part4.h"
#include "heli_q8_part4_private.h"
#include "heli_q8_part4_dt.h"

/* Block signals (auto storage) */
B_heli_q8_part4_T heli_q8_part4_B;

/* Continuous states */
X_heli_q8_part4_T heli_q8_part4_X;

/* Block states (auto storage) */
DW_heli_q8_part4_T heli_q8_part4_DW;

/* Real-time model */
RT_MODEL_heli_q8_part4_T heli_q8_part4_M_;
RT_MODEL_heli_q8_part4_T *const heli_q8_part4_M = &heli_q8_part4_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_part4_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_part4_M, 2);
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
  if (heli_q8_part4_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_part4_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_part4_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_part4_M->Timing.perTaskSampleHits[5] =
      heli_q8_part4_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_part4_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_part4_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_part4_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 11;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_part4_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_part4_output0(void)       /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_TmpSignalConversionAtToFile[14];
  real_T rtb_DeadZoney;
  real_T rtb_Frontgain;
  real_T rtb_Backgain;
  int32_T i;
  real_T tmp[5];
  real_T tmp_0[2];
  real_T tmp_1[3];
  real_T tmp_2[6];
  real_T tmp_3[6];
  int32_T i_0;
  real_T rtb_Sum_idx_1;
  real_T rtb_Sum_idx_0;
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;
  real_T unnamed_idx_2;
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    /* set solver stop time */
    if (!(heli_q8_part4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_part4_M->solverInfo,
                            ((heli_q8_part4_M->Timing.clockTickH0 + 1) *
        heli_q8_part4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_part4_M->solverInfo,
                            ((heli_q8_part4_M->Timing.clockTick0 + 1) *
        heli_q8_part4_M->Timing.stepSize0 + heli_q8_part4_M->Timing.clockTickH0 *
        heli_q8_part4_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_part4_M)) {
    heli_q8_part4_M->Timing.t[0] = rtsiGetT(&heli_q8_part4_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_part4/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (heli_q8_part4_DW.HILReadEncoderTimebase_Task, 1,
         &heli_q8_part4_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_part4_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_part4_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = heli_q8_part4_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S5>/Travel: Count to rad' */
    heli_q8_part4_B.TravelCounttorad = heli_q8_part4_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S14>/Gain' */
    heli_q8_part4_B.Gain = heli_q8_part4_P.Gain_Gain *
      heli_q8_part4_B.TravelCounttorad;
  }

  /* Gain: '<S15>/Gain' incorporates:
   *  TransferFcn: '<S5>/Travel: Transfer Fcn'
   */
  heli_q8_part4_B.Gain_d = (heli_q8_part4_P.TravelTransferFcn_C *
    heli_q8_part4_X.TravelTransferFcn_CSTATE +
    heli_q8_part4_P.TravelTransferFcn_D * heli_q8_part4_B.TravelCounttorad) *
    heli_q8_part4_P.Gain_Gain_l;
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    /* Gain: '<S5>/Pitch: Count to rad' */
    heli_q8_part4_B.PitchCounttorad = heli_q8_part4_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S12>/Gain' */
    heli_q8_part4_B.Gain_i = heli_q8_part4_P.Gain_Gain_a *
      heli_q8_part4_B.PitchCounttorad;
  }

  /* Gain: '<S13>/Gain' incorporates:
   *  TransferFcn: '<S5>/Pitch: Transfer Fcn'
   */
  heli_q8_part4_B.Gain_b = (heli_q8_part4_P.PitchTransferFcn_C *
    heli_q8_part4_X.PitchTransferFcn_CSTATE + heli_q8_part4_P.PitchTransferFcn_D
    * heli_q8_part4_B.PitchCounttorad) * heli_q8_part4_P.Gain_Gain_ae;
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    /* Gain: '<S5>/Elevation: Count to rad' */
    heli_q8_part4_B.ElevationCounttorad =
      heli_q8_part4_P.ElevationCounttorad_Gain * rtb_DeadZoney;

    /* Gain: '<S10>/Gain' */
    heli_q8_part4_B.Gain_e = heli_q8_part4_P.Gain_Gain_lv *
      heli_q8_part4_B.ElevationCounttorad;

    /* Sum: '<Root>/Sum4' incorporates:
     *  Constant: '<Root>/zero output constant'
     */
    heli_q8_part4_B.Sum4 = heli_q8_part4_B.Gain_e -
      heli_q8_part4_P.zerooutputconstant_Value;
  }

  /* Gain: '<S11>/Gain' incorporates:
   *  TransferFcn: '<S5>/Elevation: Transfer Fcn'
   */
  heli_q8_part4_B.Gain_dg = (heli_q8_part4_P.ElevationTransferFcn_C *
    heli_q8_part4_X.ElevationTransferFcn_CSTATE +
    heli_q8_part4_P.ElevationTransferFcn_D * heli_q8_part4_B.ElevationCounttorad)
    * heli_q8_part4_P.Gain_Gain_n;

  /* Gain: '<S3>/Gain1' */
  heli_q8_part4_B.Gain1[0] = heli_q8_part4_P.Gain1_Gain * heli_q8_part4_B.Gain;
  heli_q8_part4_B.Gain1[1] = heli_q8_part4_P.Gain1_Gain * heli_q8_part4_B.Gain_d;
  heli_q8_part4_B.Gain1[2] = heli_q8_part4_P.Gain1_Gain * heli_q8_part4_B.Gain_i;
  heli_q8_part4_B.Gain1[3] = heli_q8_part4_P.Gain1_Gain * heli_q8_part4_B.Gain_b;
  heli_q8_part4_B.Gain1[4] = heli_q8_part4_P.Gain1_Gain * heli_q8_part4_B.Sum4;
  heli_q8_part4_B.Gain1[5] = heli_q8_part4_P.Gain1_Gain *
    heli_q8_part4_B.Gain_dg;

  /* Step: '<S9>/Opp' */
  if (heli_q8_part4_M->Timing.t[0] < heli_q8_part4_P.Opp_Time) {
    rtb_Sum_idx_1 = heli_q8_part4_P.Opp_Y0;
  } else {
    rtb_Sum_idx_1 = heli_q8_part4_P.Opp_YFinal;
  }

  /* End of Step: '<S9>/Opp' */

  /* Step: '<S9>/Ned' */
  if (heli_q8_part4_M->Timing.t[0] < heli_q8_part4_P.Ned_Time) {
    rtb_Sum_idx_0 = heli_q8_part4_P.Ned_Y0;
  } else {
    rtb_Sum_idx_0 = heli_q8_part4_P.Ned_YFinal;
  }

  /* End of Step: '<S9>/Ned' */

  /* Sum: '<S9>/Sum2' */
  heli_q8_part4_B.Sum2 = rtb_Sum_idx_1 + rtb_Sum_idx_0;

  /* Step: '<S8>/Opp1' */
  if (heli_q8_part4_M->Timing.t[0] < heli_q8_part4_P.Opp1_Time) {
    rtb_Sum_idx_1 = heli_q8_part4_P.Opp1_Y0;
  } else {
    rtb_Sum_idx_1 = heli_q8_part4_P.Opp1_YFinal;
  }

  /* End of Step: '<S8>/Opp1' */

  /* Step: '<S8>/Ned1' */
  if (heli_q8_part4_M->Timing.t[0] < heli_q8_part4_P.Ned1_Time) {
    rtb_Sum_idx_0 = heli_q8_part4_P.Ned1_Y0;
  } else {
    rtb_Sum_idx_0 = heli_q8_part4_P.Ned1_YFinal;
  }

  /* End of Step: '<S8>/Ned1' */

  /* Sum: '<S8>/Sum3' */
  heli_q8_part4_B.Sum3 = rtb_Sum_idx_1 + rtb_Sum_idx_0;

  /* Integrator: '<S4>/Integrator' */
  for (i = 0; i < 6; i++) {
    heli_q8_part4_B.Integrator[i] = heli_q8_part4_X.Integrator_CSTATE[i];
  }

  /* End of Integrator: '<S4>/Integrator' */
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtToFile[i] = heli_q8_part4_B.Gain1[i];
    }

    rtb_TmpSignalConversionAtToFile[6] = heli_q8_part4_B.Sum2;
    rtb_TmpSignalConversionAtToFile[7] = heli_q8_part4_B.Sum3;
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtToFile[i + 8] = heli_q8_part4_B.Integrator[i];
    }

    /* End of SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */

    /* ToFile: '<Root>/To File' */
    if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
      {
        if (!(++heli_q8_part4_DW.ToFile_IWORK.Decimation % 1) &&
            (heli_q8_part4_DW.ToFile_IWORK.Count*15)+1 < 100000000 ) {
          FILE *fp = (FILE *) heli_q8_part4_DW.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[15];
            heli_q8_part4_DW.ToFile_IWORK.Decimation = 0;
            u[0] = heli_q8_part4_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAtToFile[0];
            u[2] = rtb_TmpSignalConversionAtToFile[1];
            u[3] = rtb_TmpSignalConversionAtToFile[2];
            u[4] = rtb_TmpSignalConversionAtToFile[3];
            u[5] = rtb_TmpSignalConversionAtToFile[4];
            u[6] = rtb_TmpSignalConversionAtToFile[5];
            u[7] = rtb_TmpSignalConversionAtToFile[6];
            u[8] = rtb_TmpSignalConversionAtToFile[7];
            u[9] = rtb_TmpSignalConversionAtToFile[8];
            u[10] = rtb_TmpSignalConversionAtToFile[9];
            u[11] = rtb_TmpSignalConversionAtToFile[10];
            u[12] = rtb_TmpSignalConversionAtToFile[11];
            u[13] = rtb_TmpSignalConversionAtToFile[12];
            u[14] = rtb_TmpSignalConversionAtToFile[13];
            if (fwrite(u, sizeof(real_T), 15, fp) != 15) {
              rtmSetErrorStatus(heli_q8_part4_M,
                                "Error writing to MAT-file variables.mat");
              return;
            }

            if (((++heli_q8_part4_DW.ToFile_IWORK.Count)*15)+1 >= 100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file variables.mat.\n");
            }
          }
        }
      }
    }

    /* Constant: '<S1>/Constant2' */
    heli_q8_part4_B.Constant2 = heli_q8_part4_P.Constant2_Value;
  }

  /* Step: '<S1>/Step' */
  if (heli_q8_part4_M->Timing.t[0] < heli_q8_part4_P.Step_Time) {
    rtb_Sum_idx_1 = heli_q8_part4_P.Step_Y0;
  } else {
    rtb_Sum_idx_1 = heli_q8_part4_P.Step_YFinal;
  }

  /* End of Step: '<S1>/Step' */

  /* Switch: '<S1>/Switch' */
  if (rtb_Sum_idx_1 >= heli_q8_part4_P.Switch_Threshold) {
    heli_q8_part4_B.Switch = heli_q8_part4_B.Gain1[5];
  } else {
    heli_q8_part4_B.Switch = heli_q8_part4_B.Constant2;
  }

  /* End of Switch: '<S1>/Switch' */
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
  }

  /* SignalConversion: '<S7>/TmpSignal ConversionAtGainInport1' incorporates:
   *  Gain: '<S7>/Gain'
   *  Integrator: '<S7>/Integrator'
   *  Integrator: '<S7>/Integrator1'
   */
  tmp[0] = heli_q8_part4_B.Gain1[2];
  tmp[1] = heli_q8_part4_B.Gain1[3];
  tmp[2] = heli_q8_part4_B.Switch;
  tmp[3] = heli_q8_part4_X.Integrator_CSTATE_m;
  tmp[4] = heli_q8_part4_X.Integrator1_CSTATE;

  /* Gain: '<S7>/Gain' incorporates:
   *  Sum: '<S7>/Sum'
   */
  for (i = 0; i < 2; i++) {
    tmp_0[i] = 0.0;
    for (i_0 = 0; i_0 < 5; i_0++) {
      tmp_0[i] += heli_q8_part4_P.K[(i_0 << 1) + i] * tmp[i_0];
    }
  }

  /* Sum: '<S7>/Sum' incorporates:
   *  Gain: '<S7>/Gain1'
   *  SignalConversion: '<S7>/TmpSignal ConversionAtGain1Inport1'
   */
  rtb_Sum_idx_0 = (heli_q8_part4_P.P[0] * heli_q8_part4_B.Sum2 +
                   heli_q8_part4_P.P[2] * heli_q8_part4_B.Sum3) - tmp_0[0];
  rtb_Sum_idx_1 = (heli_q8_part4_P.P[1] * heli_q8_part4_B.Sum2 +
                   heli_q8_part4_P.P[3] * heli_q8_part4_B.Sum3) - tmp_0[1];
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant'
     */
    heli_q8_part4_B.Gain_o = heli_q8_part4_P.Gain_Gain_j *
      heli_q8_part4_P.Constant_Value;
  }

  /* Sum: '<Root>/Sum1' */
  rtb_Backgain = rtb_Sum_idx_1 + heli_q8_part4_B.Gain_o;
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    /* Constant: '<Root>/V_s*    ' */
    heli_q8_part4_B.V_s = heli_q8_part4_P.v_star;
  }

  /* Sum: '<Root>/Sum' */
  rtb_Frontgain = heli_q8_part4_B.V_s + rtb_Sum_idx_0;

  /* Gain: '<S4>/C_est' incorporates:
   *  Sum: '<S4>/Sum2'
   */
  for (i = 0; i < 3; i++) {
    tmp_1[i] = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_1[i] += heli_q8_part4_P.C_est[3 * i_0 + i] *
        heli_q8_part4_B.Integrator[i_0];
    }
  }

  /* End of Gain: '<S4>/C_est' */

  /* Sum: '<S4>/Sum2' incorporates:
   *  Gain: '<S4>/L'
   */
  unnamed_idx_0 = heli_q8_part4_B.Gain1[2] - tmp_1[0];
  unnamed_idx_1 = heli_q8_part4_B.Gain1[4] - tmp_1[1];
  unnamed_idx_2 = heli_q8_part4_B.Gain1[0] - tmp_1[2];
  for (i = 0; i < 6; i++) {
    /* Gain: '<S4>/L' incorporates:
     *  Sum: '<S4>/Sum3'
     */
    tmp_2[i] = heli_q8_part4_P.L[i + 12] * unnamed_idx_2 + (heli_q8_part4_P.L[i
      + 6] * unnamed_idx_1 + heli_q8_part4_P.L[i] * unnamed_idx_0);

    /* Gain: '<S4>/B_est' incorporates:
     *  Sum: '<S4>/Sum3'
     */
    tmp_3[i] = heli_q8_part4_P.B_est[i + 6] * rtb_Sum_idx_1 +
      heli_q8_part4_P.B_est[i] * rtb_Sum_idx_0;
  }

  /* Sum: '<S4>/Sum3' incorporates:
   *  Gain: '<S4>/A_est'
   */
  for (i = 0; i < 6; i++) {
    rtb_Sum_idx_1 = 0.0;
    for (i_0 = 0; i_0 < 6; i_0++) {
      rtb_Sum_idx_1 += heli_q8_part4_P.A_est[6 * i_0 + i] *
        heli_q8_part4_B.Integrator[i_0];
    }

    heli_q8_part4_B.Sum3_l[i] = (tmp_2[i] + tmp_3[i]) + rtb_Sum_idx_1;
  }

  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
  }

  /* Gain: '<S2>/Front gain' incorporates:
   *  Sum: '<S2>/Add'
   */
  rtb_Sum_idx_0 = (rtb_Backgain + rtb_Frontgain) *
    heli_q8_part4_P.Frontgain_Gain;

  /* Saturate: '<S5>/Front motor: Saturation' */
  if (rtb_Sum_idx_0 > heli_q8_part4_P.FrontmotorSaturation_UpperSat) {
    heli_q8_part4_B.FrontmotorSaturation =
      heli_q8_part4_P.FrontmotorSaturation_UpperSat;
  } else if (rtb_Sum_idx_0 < heli_q8_part4_P.FrontmotorSaturation_LowerSat) {
    heli_q8_part4_B.FrontmotorSaturation =
      heli_q8_part4_P.FrontmotorSaturation_LowerSat;
  } else {
    heli_q8_part4_B.FrontmotorSaturation = rtb_Sum_idx_0;
  }

  /* End of Saturate: '<S5>/Front motor: Saturation' */

  /* Gain: '<S2>/Back gain' incorporates:
   *  Sum: '<S2>/Subtract'
   */
  rtb_Sum_idx_0 = (rtb_Frontgain - rtb_Backgain) * heli_q8_part4_P.Backgain_Gain;

  /* Saturate: '<S5>/Back motor: Saturation' */
  if (rtb_Sum_idx_0 > heli_q8_part4_P.BackmotorSaturation_UpperSat) {
    heli_q8_part4_B.BackmotorSaturation =
      heli_q8_part4_P.BackmotorSaturation_UpperSat;
  } else if (rtb_Sum_idx_0 < heli_q8_part4_P.BackmotorSaturation_LowerSat) {
    heli_q8_part4_B.BackmotorSaturation =
      heli_q8_part4_P.BackmotorSaturation_LowerSat;
  } else {
    heli_q8_part4_B.BackmotorSaturation = rtb_Sum_idx_0;
  }

  /* End of Saturate: '<S5>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: heli_q8_part4/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_part4_DW.HILWriteAnalog_Buffer[0] =
        heli_q8_part4_B.FrontmotorSaturation;
      heli_q8_part4_DW.HILWriteAnalog_Buffer[1] =
        heli_q8_part4_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILWriteAnalog_channels, 2,
        &heli_q8_part4_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
      }
    }
  }

  /* Sum: '<S7>/Sum1' */
  heli_q8_part4_B.Sum1 = heli_q8_part4_B.Gain1[2] - heli_q8_part4_B.Sum2;

  /* Sum: '<S7>/Sum2' */
  heli_q8_part4_B.Sum2_h = heli_q8_part4_B.Switch - heli_q8_part4_B.Sum3;

  /* RateTransition: '<S6>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    if (heli_q8_part4_M->Timing.RateInteraction.TID1_2) {
      heli_q8_part4_B.RateTransitionx = heli_q8_part4_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S6>/Dead Zone: x' */
    if (heli_q8_part4_B.RateTransitionx > heli_q8_part4_P.DeadZonex_End) {
      rtb_DeadZoney = heli_q8_part4_B.RateTransitionx -
        heli_q8_part4_P.DeadZonex_End;
    } else if (heli_q8_part4_B.RateTransitionx >=
               heli_q8_part4_P.DeadZonex_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = heli_q8_part4_B.RateTransitionx -
        heli_q8_part4_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: x' */

    /* Gain: '<S6>/Joystick_gain_x' incorporates:
     *  Gain: '<S6>/Gain: x'
     */
    heli_q8_part4_B.Joystick_gain_x = heli_q8_part4_P.Gainx_Gain * rtb_DeadZoney
      * heli_q8_part4_P.Joystick_gain_x;

    /* RateTransition: '<S6>/Rate Transition: y' */
    if (heli_q8_part4_M->Timing.RateInteraction.TID1_2) {
      heli_q8_part4_B.RateTransitiony = heli_q8_part4_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S6>/Rate Transition: y' */

    /* DeadZone: '<S6>/Dead Zone: y' */
    if (heli_q8_part4_B.RateTransitiony > heli_q8_part4_P.DeadZoney_End) {
      rtb_DeadZoney = heli_q8_part4_B.RateTransitiony -
        heli_q8_part4_P.DeadZoney_End;
    } else if (heli_q8_part4_B.RateTransitiony >=
               heli_q8_part4_P.DeadZoney_Start) {
      rtb_DeadZoney = 0.0;
    } else {
      rtb_DeadZoney = heli_q8_part4_B.RateTransitiony -
        heli_q8_part4_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: y' */

    /* Gain: '<S6>/Joystick_gain_y' incorporates:
     *  Gain: '<S6>/Gain: y'
     */
    heli_q8_part4_B.Joystick_gain_y = heli_q8_part4_P.Gainy_Gain * rtb_DeadZoney
      * heli_q8_part4_P.Joystick_gain_y;
  }

  /* End of RateTransition: '<S6>/Rate Transition: x' */
}

/* Model update function for TID0 */
void heli_q8_part4_update0(void)       /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_part4_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_part4_M->solverInfo);
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
  if (!(++heli_q8_part4_M->Timing.clockTick0)) {
    ++heli_q8_part4_M->Timing.clockTickH0;
  }

  heli_q8_part4_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_part4_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_part4_M->Timing.clockTick1)) {
    ++heli_q8_part4_M->Timing.clockTickH1;
  }

  heli_q8_part4_M->Timing.t[1] = heli_q8_part4_M->Timing.clockTick1 *
    heli_q8_part4_M->Timing.stepSize1 + heli_q8_part4_M->Timing.clockTickH1 *
    heli_q8_part4_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_part4_derivatives(void)
{
  int32_T i;
  XDot_heli_q8_part4_T *_rtXdot;
  _rtXdot = ((XDot_heli_q8_part4_T *) heli_q8_part4_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_part4_P.TravelTransferFcn_A *
    heli_q8_part4_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_part4_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_part4_P.PitchTransferFcn_A *
    heli_q8_part4_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_part4_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_part4_P.ElevationTransferFcn_A
    * heli_q8_part4_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_part4_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  for (i = 0; i < 6; i++) {
    _rtXdot->Integrator_CSTATE[i] = heli_q8_part4_B.Sum3_l[i];
  }

  /* End of Derivatives for Integrator: '<S4>/Integrator' */

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = heli_q8_part4_B.Sum1;

  /* Derivatives for Integrator: '<S7>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_part4_B.Sum2_h;
}

/* Model output function for TID2 */
void heli_q8_part4_output2(void)       /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_part4/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_part4_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_part4_DW.GameController_Controller,
        &state, &new_data);
      if (result == 0) {
        heli_q8_part4_B.GameController_o4 = state.x;
        heli_q8_part4_B.GameController_o5 = state.y;
      }
    } else {
      heli_q8_part4_B.GameController_o4 = 0;
      heli_q8_part4_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void heli_q8_part4_update2(void)       /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_part4_DW.RateTransitionx_Buffer0 = heli_q8_part4_B.GameController_o4;

  /* Update for RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_part4_DW.RateTransitiony_Buffer0 = heli_q8_part4_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_part4_M->Timing.clockTick2)) {
    ++heli_q8_part4_M->Timing.clockTickH2;
  }

  heli_q8_part4_M->Timing.t[2] = heli_q8_part4_M->Timing.clockTick2 *
    heli_q8_part4_M->Timing.stepSize2 + heli_q8_part4_M->Timing.clockTickH2 *
    heli_q8_part4_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_part4_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_part4_output0();
    break;

   case 2 :
    heli_q8_part4_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_part4_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_part4_update0();
    break;

   case 2 :
    heli_q8_part4_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_part4_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_part4/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_part4_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_part4_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_part4_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
      return;
    }

    if ((heli_q8_part4_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_part4_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = heli_q8_part4_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_part4_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_part4_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILInitialize_analog_input_chan, 8U,
        &heli_q8_part4_DW.HILInitialize_AIMinimums[0],
        &heli_q8_part4_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_part4_P.HILInitialize_set_analog_output && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_part4_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = heli_q8_part4_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_part4_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_part4_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_part4_DW.HILInitialize_AOMinimums[0],
        &heli_q8_part4_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_part4_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_part4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_part4_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILInitialize_analog_output_cha, 8U,
        &heli_q8_part4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_part4_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_part4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_part4_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_part4_DW.HILInitialize_Card,
         heli_q8_part4_P.HILInitialize_analog_output_cha, 8U,
         &heli_q8_part4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_part4_P.HILInitialize_set_encoder_param && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_part4_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_part4_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_part4_DW.HILInitialize_Card,
         heli_q8_part4_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_part4_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_part4_P.HILInitialize_set_encoder_count && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_part4_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            heli_q8_part4_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILInitialize_encoder_channels, 8U,
        &heli_q8_part4_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_part4_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_part4_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_part4_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &heli_q8_part4_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          heli_q8_part4_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &heli_q8_part4_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            heli_q8_part4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            heli_q8_part4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_part4_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_part4_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            heli_q8_part4_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = heli_q8_part4_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_part4_DW.HILInitialize_Card,
          &heli_q8_part4_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_q8_part4_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_part4_DW.HILInitialize_Card,
          &heli_q8_part4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_part4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_part4_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_part4_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_part4_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_part4_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_part4_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_part4_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &heli_q8_part4_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_part4_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_part4_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_part4_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_part4_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_part4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_part4_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_part4_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_part4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_part4_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_part4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_part4_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(heli_q8_part4_DW.HILInitialize_Card,
        heli_q8_part4_P.HILInitialize_pwm_channels, 8U,
        &heli_q8_part4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_part4_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_part4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_part4_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_part4_DW.HILInitialize_Card,
         heli_q8_part4_P.HILInitialize_pwm_channels, 8U,
         &heli_q8_part4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_part4/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_part4_DW.HILInitialize_Card,
      heli_q8_part4_P.HILReadEncoderTimebase_samples_,
      heli_q8_part4_P.HILReadEncoderTimebase_channels, 3,
      &heli_q8_part4_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    char fileName[509] = "variables.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_part4_M,
                        "Error creating .mat file variables.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,15,0,"variables")) {
      rtmSetErrorStatus(heli_q8_part4_M,
                        "Error writing mat file header to file variables.mat");
      return;
    }

    heli_q8_part4_DW.ToFile_IWORK.Count = 0;
    heli_q8_part4_DW.ToFile_IWORK.Decimation = -1;
    heli_q8_part4_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_part4_B.RateTransitionx = heli_q8_part4_P.RateTransitionx_X0;

  /* Start for RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_part4_B.RateTransitiony = heli_q8_part4_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_part4/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_part4_P.GameController_Enabled) {
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

      result = game_controller_open
        (heli_q8_part4_P.GameController_ControllerNumber,
         heli_q8_part4_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_part4_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_part4_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for TransferFcn: '<S5>/Travel: Transfer Fcn' */
    heli_q8_part4_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
    heli_q8_part4_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
    heli_q8_part4_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    for (i = 0; i < 6; i++) {
      heli_q8_part4_X.Integrator_CSTATE[i] = heli_q8_part4_P.Integrator_IC;
    }

    /* End of InitializeConditions for Integrator: '<S4>/Integrator' */

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    heli_q8_part4_X.Integrator_CSTATE_m = heli_q8_part4_P.Integrator_IC_o;

    /* InitializeConditions for Integrator: '<S7>/Integrator1' */
    heli_q8_part4_X.Integrator1_CSTATE = heli_q8_part4_P.Integrator1_IC;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition: x' */
    heli_q8_part4_DW.RateTransitionx_Buffer0 =
      heli_q8_part4_P.RateTransitionx_X0;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition: y' */
    heli_q8_part4_DW.RateTransitiony_Buffer0 =
      heli_q8_part4_P.RateTransitiony_X0;
  }
}

/* Model terminate function */
void heli_q8_part4_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_part4/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_part4_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_part4_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_part4_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_part4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_part4_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((heli_q8_part4_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (heli_q8_part4_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_part4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_part4_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_part4_DW.HILInitialize_Card
                         , heli_q8_part4_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , heli_q8_part4_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_part4_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_part4_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_part4_DW.HILInitialize_Card,
            heli_q8_part4_P.HILInitialize_analog_output_cha,
            num_final_analog_outputs,
            &heli_q8_part4_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_part4_DW.HILInitialize_Card,
            heli_q8_part4_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &heli_q8_part4_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_part4_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_part4_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_part4_DW.HILInitialize_Card);
    hil_close(heli_q8_part4_DW.HILInitialize_Card);
    heli_q8_part4_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) heli_q8_part4_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "variables.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_part4_M,
                          "Error closing MAT-file variables.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_part4_M,
                          "Error reopening MAT-file variables.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 15, heli_q8_part4_DW.ToFile_IWORK.Count,
           "variables")) {
        rtmSetErrorStatus(heli_q8_part4_M,
                          "Error writing header for variables to MAT-file variables.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_part4_M,
                          "Error closing MAT-file variables.mat");
        return;
      }

      heli_q8_part4_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8_part4/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_part4_P.GameController_Enabled) {
      game_controller_close(heli_q8_part4_DW.GameController_Controller);
      heli_q8_part4_DW.GameController_Controller = NULL;
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
  heli_q8_part4_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_part4_update(tid);
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
  heli_q8_part4_initialize();
}

void MdlTerminate(void)
{
  heli_q8_part4_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_part4_T *heli_q8_part4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)heli_q8_part4_M, 0,
                sizeof(RT_MODEL_heli_q8_part4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_part4_M->solverInfo,
                          &heli_q8_part4_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_part4_M->solverInfo, &rtmGetTPtr(heli_q8_part4_M));
    rtsiSetStepSizePtr(&heli_q8_part4_M->solverInfo,
                       &heli_q8_part4_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_part4_M->solverInfo,
                 &heli_q8_part4_M->ModelData.derivs);
    rtsiSetContStatesPtr(&heli_q8_part4_M->solverInfo, (real_T **)
                         &heli_q8_part4_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&heli_q8_part4_M->solverInfo,
      &heli_q8_part4_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&heli_q8_part4_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_part4_M)));
    rtsiSetRTModelPtr(&heli_q8_part4_M->solverInfo, heli_q8_part4_M);
  }

  rtsiSetSimTimeStep(&heli_q8_part4_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_part4_M->ModelData.intgData.f[0] = heli_q8_part4_M->ModelData.odeF[0];
  heli_q8_part4_M->ModelData.contStates = ((real_T *) &heli_q8_part4_X);
  rtsiSetSolverData(&heli_q8_part4_M->solverInfo, (void *)
                    &heli_q8_part4_M->ModelData.intgData);
  rtsiSetSolverName(&heli_q8_part4_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_part4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_part4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_part4_M->Timing.sampleTimes =
      (&heli_q8_part4_M->Timing.sampleTimesArray[0]);
    heli_q8_part4_M->Timing.offsetTimes =
      (&heli_q8_part4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_part4_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_part4_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_part4_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_part4_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_part4_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_part4_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_part4_M, &heli_q8_part4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_part4_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_part4_M->Timing.perTaskSampleHitsArray;
    heli_q8_part4_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_part4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_part4_M, 30.0);
  heli_q8_part4_M->Timing.stepSize0 = 0.002;
  heli_q8_part4_M->Timing.stepSize1 = 0.002;
  heli_q8_part4_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_part4_M->Sizes.checksums[0] = (1263525144U);
  heli_q8_part4_M->Sizes.checksums[1] = (464814613U);
  heli_q8_part4_M->Sizes.checksums[2] = (3593851572U);
  heli_q8_part4_M->Sizes.checksums[3] = (3651110528U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    heli_q8_part4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_part4_M->extModeInfo,
      &heli_q8_part4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_part4_M->extModeInfo,
                        heli_q8_part4_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_part4_M->extModeInfo, rtmGetTPtr(heli_q8_part4_M));
  }

  heli_q8_part4_M->solverInfoPtr = (&heli_q8_part4_M->solverInfo);
  heli_q8_part4_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_part4_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_part4_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_part4_M->ModelData.blockIO = ((void *) &heli_q8_part4_B);

  {
    int_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_part4_B.Gain1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_part4_B.Integrator[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_part4_B.Sum3_l[i] = 0.0;
    }

    heli_q8_part4_B.TravelCounttorad = 0.0;
    heli_q8_part4_B.Gain = 0.0;
    heli_q8_part4_B.Gain_d = 0.0;
    heli_q8_part4_B.PitchCounttorad = 0.0;
    heli_q8_part4_B.Gain_i = 0.0;
    heli_q8_part4_B.Gain_b = 0.0;
    heli_q8_part4_B.ElevationCounttorad = 0.0;
    heli_q8_part4_B.Gain_e = 0.0;
    heli_q8_part4_B.Sum4 = 0.0;
    heli_q8_part4_B.Gain_dg = 0.0;
    heli_q8_part4_B.Sum2 = 0.0;
    heli_q8_part4_B.Sum3 = 0.0;
    heli_q8_part4_B.Constant2 = 0.0;
    heli_q8_part4_B.Switch = 0.0;
    heli_q8_part4_B.Gain_o = 0.0;
    heli_q8_part4_B.V_s = 0.0;
    heli_q8_part4_B.FrontmotorSaturation = 0.0;
    heli_q8_part4_B.BackmotorSaturation = 0.0;
    heli_q8_part4_B.Sum1 = 0.0;
    heli_q8_part4_B.Sum2_h = 0.0;
    heli_q8_part4_B.RateTransitionx = 0.0;
    heli_q8_part4_B.Joystick_gain_x = 0.0;
    heli_q8_part4_B.RateTransitiony = 0.0;
    heli_q8_part4_B.Joystick_gain_y = 0.0;
    heli_q8_part4_B.GameController_o4 = 0.0;
    heli_q8_part4_B.GameController_o5 = 0.0;
  }

  /* parameters */
  heli_q8_part4_M->ModelData.defaultParam = ((real_T *)&heli_q8_part4_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_part4_X;
    heli_q8_part4_M->ModelData.contStates = (x);
    (void) memset((void *)&heli_q8_part4_X, 0,
                  sizeof(X_heli_q8_part4_T));
  }

  /* states (dwork) */
  heli_q8_part4_M->ModelData.dwork = ((void *) &heli_q8_part4_DW);
  (void) memset((void *)&heli_q8_part4_DW, 0,
                sizeof(DW_heli_q8_part4_T));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_part4_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_part4_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_part4_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_part4_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_part4_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_part4_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_part4_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_part4_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  heli_q8_part4_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_part4_DW.HILWriteAnalog_Buffer[1] = 0.0;
  heli_q8_part4_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_part4_DW.RateTransitiony_Buffer0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_part4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_part4_M->Sizes.numContStates = (11);/* Number of continuous states */
  heli_q8_part4_M->Sizes.numY = (0);   /* Number of model outputs */
  heli_q8_part4_M->Sizes.numU = (0);   /* Number of model inputs */
  heli_q8_part4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_part4_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_part4_M->Sizes.numBlocks = (74);/* Number of blocks */
  heli_q8_part4_M->Sizes.numBlockIO = (29);/* Number of block outputs */
  heli_q8_part4_M->Sizes.numBlockPrms = (264);/* Sum of parameter "widths" */
  return heli_q8_part4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
