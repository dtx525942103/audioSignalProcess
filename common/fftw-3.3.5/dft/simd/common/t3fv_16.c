/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sat Jul 30 16:43:52 EDT 2016 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 16 -name t3fv_16 -include t3f.h */

/*
 * This function contains 98 FP additions, 86 FP multiplications,
 * (or, 64 additions, 52 multiplications, 34 fused multiply/add),
 * 70 stack variables, 3 constants, and 32 memory accesses
 */
#include "t3f.h"

static void t3fv_16(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP414213562, +0.414213562373095048801688724209698078569671875);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 8)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 8), MAKE_VOLATILE_STRIDE(16, rs)) {
	       V T13, Tg, TY, T14, T1A, T1q, T1f, T1x, T1r, T1i, Tt, T16, TB, T1j, T1k;
	       V TH;
	       {
		    V T2, T8, Tu, T3;
		    T2 = LDW(&(W[0]));
		    T8 = LDW(&(W[TWVL * 2]));
		    Tu = LDW(&(W[TWVL * 6]));
		    T3 = LDW(&(W[TWVL * 4]));
		    {
			 V Ty, T1o, Tf, T1b, T7, Tr, TR, TX, T1g, Tl, To, Tw, TG, Tz, T1p;
			 V T1e, TC;
			 {
			      V T1, T5, Ta, Td;
			      T1 = LD(&(x[0]), ms, &(x[0]));
			      T5 = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			      Ta = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			      Td = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			      {
				   V Tx, TO, TE, Tb, Tm, Tp, TN, Te, T6, TW, TP, TS;
				   {
					V TM, T9, TL, Tc, TU, T4, TV;
					TM = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
					Tx = VZMULJ(T2, T8);
					T9 = VZMUL(T2, T8);
					TL = VZMULJ(T2, Tu);
					TO = VZMULJ(T8, T3);
					Tc = VZMUL(T8, T3);
					TU = VZMUL(T2, T3);
					T4 = VZMULJ(T2, T3);
					TV = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
					TE = VZMUL(Tx, T3);
					Ty = VZMULJ(Tx, T3);
					Tb = VZMULJ(T9, Ta);
					Tm = VZMULJ(T9, T3);
					Tp = VZMUL(T9, T3);
					TN = VZMULJ(TL, TM);
					Te = VZMULJ(Tc, Td);
					T6 = VZMULJ(T4, T5);
					TW = VZMULJ(TU, TV);
				   }
				   TP = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
				   TS = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
				   {
					V TQ, TT, Ti, Tk, Tn, Th, Tq, Tj;
					Th = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
					Tq = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
					Tj = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
					T1o = VSUB(Tb, Te);
					Tf = VADD(Tb, Te);
					T1b = VSUB(T1, T6);
					T7 = VADD(T1, T6);
					TQ = VZMULJ(TO, TP);
					TT = VZMULJ(Tx, TS);
					Ti = VZMULJ(T2, Th);
					Tr = VZMULJ(Tp, Tq);
					Tk = VZMULJ(T3, Tj);
					Tn = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
					{
					     V T1d, T1c, Tv, TF;
					     Tv = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
					     TF = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
					     T1d = VSUB(TN, TQ);
					     TR = VADD(TN, TQ);
					     T1c = VSUB(TT, TW);
					     TX = VADD(TT, TW);
					     T1g = VSUB(Ti, Tk);
					     Tl = VADD(Ti, Tk);
					     To = VZMULJ(Tm, Tn);
					     Tw = VZMULJ(Tu, Tv);
					     TG = VZMULJ(TE, TF);
					     Tz = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
					     T1p = VSUB(T1d, T1c);
					     T1e = VADD(T1c, T1d);
					     TC = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
					}
				   }
			      }
			 }
			 {
			      V T1h, Ts, TA, TD;
			      T13 = VADD(T7, Tf);
			      Tg = VSUB(T7, Tf);
			      T1h = VSUB(To, Tr);
			      Ts = VADD(To, Tr);
			      TY = VSUB(TR, TX);
			      T14 = VADD(TX, TR);
			      TA = VZMULJ(Ty, Tz);
			      T1A = VFMA(LDK(KP707106781), T1p, T1o);
			      T1q = VFNMS(LDK(KP707106781), T1p, T1o);
			      T1f = VFMA(LDK(KP707106781), T1e, T1b);
			      T1x = VFNMS(LDK(KP707106781), T1e, T1b);
			      TD = VZMULJ(T8, TC);
			      T1r = VFMA(LDK(KP414213562), T1g, T1h);
			      T1i = VFNMS(LDK(KP414213562), T1h, T1g);
			      Tt = VSUB(Tl, Ts);
			      T16 = VADD(Tl, Ts);
			      TB = VADD(Tw, TA);
			      T1j = VSUB(Tw, TA);
			      T1k = VSUB(TG, TD);
			      TH = VADD(TD, TG);
			 }
		    }
	       }
	       {
		    V T15, T19, T1l, T1s, TI, T17;
		    T15 = VADD(T13, T14);
		    T19 = VSUB(T13, T14);
		    T1l = VFNMS(LDK(KP414213562), T1k, T1j);
		    T1s = VFMA(LDK(KP414213562), T1j, T1k);
		    TI = VSUB(TB, TH);
		    T17 = VADD(TB, TH);
		    {
			 V T1y, T1t, T1B, T1m;
			 T1y = VADD(T1r, T1s);
			 T1t = VSUB(T1r, T1s);
			 T1B = VSUB(T1l, T1i);
			 T1m = VADD(T1i, T1l);
			 {
			      V T18, T1a, TJ, TZ;
			      T18 = VADD(T16, T17);
			      T1a = VSUB(T17, T16);
			      TJ = VADD(Tt, TI);
			      TZ = VSUB(TI, Tt);
			      {
				   V T1u, T1w, T1z, T1D;
				   T1u = VFNMS(LDK(KP923879532), T1t, T1q);
				   T1w = VFMA(LDK(KP923879532), T1t, T1q);
				   T1z = VFNMS(LDK(KP923879532), T1y, T1x);
				   T1D = VFMA(LDK(KP923879532), T1y, T1x);
				   {
					V T1n, T1v, T1C, T1E;
					T1n = VFNMS(LDK(KP923879532), T1m, T1f);
					T1v = VFMA(LDK(KP923879532), T1m, T1f);
					T1C = VFNMS(LDK(KP923879532), T1B, T1A);
					T1E = VFMA(LDK(KP923879532), T1B, T1A);
					ST(&(x[WS(rs, 12)]), VFNMSI(T1a, T19), ms, &(x[0]));
					ST(&(x[WS(rs, 4)]), VFMAI(T1a, T19), ms, &(x[0]));
					ST(&(x[0]), VADD(T15, T18), ms, &(x[0]));
					ST(&(x[WS(rs, 8)]), VSUB(T15, T18), ms, &(x[0]));
					{
					     V T10, T12, TK, T11;
					     T10 = VFNMS(LDK(KP707106781), TZ, TY);
					     T12 = VFMA(LDK(KP707106781), TZ, TY);
					     TK = VFNMS(LDK(KP707106781), TJ, Tg);
					     T11 = VFMA(LDK(KP707106781), TJ, Tg);
					     ST(&(x[WS(rs, 1)]), VFNMSI(T1w, T1v), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 15)]), VFMAI(T1w, T1v), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 7)]), VFMAI(T1u, T1n), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 9)]), VFNMSI(T1u, T1n), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 3)]), VFMAI(T1E, T1D), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 13)]), VFNMSI(T1E, T1D), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 11)]), VFMAI(T1C, T1z), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 5)]), VFNMSI(T1C, T1z), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 14)]), VFNMSI(T12, T11), ms, &(x[0]));
					     ST(&(x[WS(rs, 2)]), VFMAI(T12, T11), ms, &(x[0]));
					     ST(&(x[WS(rs, 10)]), VFMAI(T10, TK), ms, &(x[0]));
					     ST(&(x[WS(rs, 6)]), VFNMSI(T10, TK), ms, &(x[0]));
					}
				   }
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     VTW(0, 15),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 16, XSIMD_STRING("t3fv_16"), twinstr, &GENUS, {64, 52, 34, 0}, 0, 0, 0 };

void XSIMD(codelet_t3fv_16) (planner *p) {
     X(kdft_dit_register) (p, t3fv_16, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -twiddle-log3 -precompute-twiddles -no-generate-bytw -n 16 -name t3fv_16 -include t3f.h */

/*
 * This function contains 98 FP additions, 64 FP multiplications,
 * (or, 94 additions, 60 multiplications, 4 fused multiply/add),
 * 51 stack variables, 3 constants, and 32 memory accesses
 */
#include "t3f.h"

static void t3fv_16(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 8)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 8), MAKE_VOLATILE_STRIDE(16, rs)) {
	       V T4, T5, T6, To, T1, Ty, T7, T8, TO, TV, Te, Tp, TB, TH, Ts;
	       T4 = LDW(&(W[0]));
	       T5 = LDW(&(W[TWVL * 2]));
	       T6 = VZMULJ(T4, T5);
	       To = VZMUL(T4, T5);
	       T1 = LDW(&(W[TWVL * 6]));
	       Ty = VZMULJ(T4, T1);
	       T7 = LDW(&(W[TWVL * 4]));
	       T8 = VZMULJ(T6, T7);
	       TO = VZMUL(T5, T7);
	       TV = VZMULJ(T4, T7);
	       Te = VZMUL(T6, T7);
	       Tp = VZMULJ(To, T7);
	       TB = VZMULJ(T5, T7);
	       TH = VZMUL(T4, T7);
	       Ts = VZMUL(To, T7);
	       {
		    V TY, T1f, TR, T1g, T1q, T1r, TL, TZ, T1l, T1m, T1n, Ti, T12, T1i, T1j;
		    V T1k, Tw, T11, TU, TX, TW;
		    TU = LD(&(x[0]), ms, &(x[0]));
		    TW = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
		    TX = VZMULJ(TV, TW);
		    TY = VSUB(TU, TX);
		    T1f = VADD(TU, TX);
		    {
			 V TN, TQ, TM, TP;
			 TM = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 TN = VZMULJ(To, TM);
			 TP = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 TQ = VZMULJ(TO, TP);
			 TR = VSUB(TN, TQ);
			 T1g = VADD(TN, TQ);
		    }
		    {
			 V TA, TJ, TD, TG, TE, TK;
			 {
			      V Tz, TI, TC, TF;
			      Tz = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			      TA = VZMULJ(Ty, Tz);
			      TI = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
			      TJ = VZMULJ(TH, TI);
			      TC = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			      TD = VZMULJ(TB, TC);
			      TF = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			      TG = VZMULJ(T6, TF);
			 }
			 T1q = VADD(TA, TD);
			 T1r = VADD(TG, TJ);
			 TE = VSUB(TA, TD);
			 TK = VSUB(TG, TJ);
			 TL = VMUL(LDK(KP707106781), VSUB(TE, TK));
			 TZ = VMUL(LDK(KP707106781), VADD(TK, TE));
		    }
		    {
			 V T3, Tg, Ta, Td, Tb, Th;
			 {
			      V T2, Tf, T9, Tc;
			      T2 = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
			      T3 = VZMULJ(T1, T2);
			      Tf = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			      Tg = VZMULJ(Te, Tf);
			      T9 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			      Ta = VZMULJ(T8, T9);
			      Tc = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			      Td = VZMULJ(T5, Tc);
			 }
			 T1l = VADD(T3, Ta);
			 T1m = VADD(Td, Tg);
			 T1n = VSUB(T1l, T1m);
			 Tb = VSUB(T3, Ta);
			 Th = VSUB(Td, Tg);
			 Ti = VFNMS(LDK(KP923879532), Th, VMUL(LDK(KP382683432), Tb));
			 T12 = VFMA(LDK(KP923879532), Tb, VMUL(LDK(KP382683432), Th));
		    }
		    {
			 V Tk, Tu, Tm, Tr, Tn, Tv;
			 {
			      V Tj, Tt, Tl, Tq;
			      Tj = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			      Tk = VZMULJ(T4, Tj);
			      Tt = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			      Tu = VZMULJ(Ts, Tt);
			      Tl = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			      Tm = VZMULJ(T7, Tl);
			      Tq = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			      Tr = VZMULJ(Tp, Tq);
			 }
			 T1i = VADD(Tk, Tm);
			 T1j = VADD(Tr, Tu);
			 T1k = VSUB(T1i, T1j);
			 Tn = VSUB(Tk, Tm);
			 Tv = VSUB(Tr, Tu);
			 Tw = VFMA(LDK(KP382683432), Tn, VMUL(LDK(KP923879532), Tv));
			 T11 = VFNMS(LDK(KP382683432), Tv, VMUL(LDK(KP923879532), Tn));
		    }
		    {
			 V T1p, T1v, T1u, T1w;
			 {
			      V T1h, T1o, T1s, T1t;
			      T1h = VSUB(T1f, T1g);
			      T1o = VMUL(LDK(KP707106781), VADD(T1k, T1n));
			      T1p = VADD(T1h, T1o);
			      T1v = VSUB(T1h, T1o);
			      T1s = VSUB(T1q, T1r);
			      T1t = VMUL(LDK(KP707106781), VSUB(T1n, T1k));
			      T1u = VBYI(VADD(T1s, T1t));
			      T1w = VBYI(VSUB(T1t, T1s));
			 }
			 ST(&(x[WS(rs, 14)]), VSUB(T1p, T1u), ms, &(x[0]));
			 ST(&(x[WS(rs, 6)]), VADD(T1v, T1w), ms, &(x[0]));
			 ST(&(x[WS(rs, 2)]), VADD(T1p, T1u), ms, &(x[0]));
			 ST(&(x[WS(rs, 10)]), VSUB(T1v, T1w), ms, &(x[0]));
		    }
		    {
			 V T1z, T1D, T1C, T1E;
			 {
			      V T1x, T1y, T1A, T1B;
			      T1x = VADD(T1f, T1g);
			      T1y = VADD(T1r, T1q);
			      T1z = VADD(T1x, T1y);
			      T1D = VSUB(T1x, T1y);
			      T1A = VADD(T1i, T1j);
			      T1B = VADD(T1l, T1m);
			      T1C = VADD(T1A, T1B);
			      T1E = VBYI(VSUB(T1B, T1A));
			 }
			 ST(&(x[WS(rs, 8)]), VSUB(T1z, T1C), ms, &(x[0]));
			 ST(&(x[WS(rs, 4)]), VADD(T1D, T1E), ms, &(x[0]));
			 ST(&(x[0]), VADD(T1z, T1C), ms, &(x[0]));
			 ST(&(x[WS(rs, 12)]), VSUB(T1D, T1E), ms, &(x[0]));
		    }
		    {
			 V TT, T15, T14, T16;
			 {
			      V Tx, TS, T10, T13;
			      Tx = VSUB(Ti, Tw);
			      TS = VSUB(TL, TR);
			      TT = VBYI(VSUB(Tx, TS));
			      T15 = VBYI(VADD(TS, Tx));
			      T10 = VADD(TY, TZ);
			      T13 = VADD(T11, T12);
			      T14 = VSUB(T10, T13);
			      T16 = VADD(T10, T13);
			 }
			 ST(&(x[WS(rs, 7)]), VADD(TT, T14), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 15)]), VSUB(T16, T15), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 9)]), VSUB(T14, TT), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 1)]), VADD(T15, T16), ms, &(x[WS(rs, 1)]));
		    }
		    {
			 V T19, T1d, T1c, T1e;
			 {
			      V T17, T18, T1a, T1b;
			      T17 = VSUB(TY, TZ);
			      T18 = VADD(Tw, Ti);
			      T19 = VADD(T17, T18);
			      T1d = VSUB(T17, T18);
			      T1a = VADD(TR, TL);
			      T1b = VSUB(T12, T11);
			      T1c = VBYI(VADD(T1a, T1b));
			      T1e = VBYI(VSUB(T1b, T1a));
			 }
			 ST(&(x[WS(rs, 13)]), VSUB(T19, T1c), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 5)]), VADD(T1d, T1e), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 3)]), VADD(T19, T1c), ms, &(x[WS(rs, 1)]));
			 ST(&(x[WS(rs, 11)]), VSUB(T1d, T1e), ms, &(x[WS(rs, 1)]));
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 3),
     VTW(0, 9),
     VTW(0, 15),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 16, XSIMD_STRING("t3fv_16"), twinstr, &GENUS, {94, 60, 4, 0}, 0, 0, 0 };

void XSIMD(codelet_t3fv_16) (planner *p) {
     X(kdft_dit_register) (p, t3fv_16, &desc);
}
#endif				/* HAVE_FMA */
