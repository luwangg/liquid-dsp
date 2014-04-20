/*
 * Copyright (c) 2007 - 2014 Joseph Gaeddert
 *
 * This file is part of liquid.
 *
 * liquid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * liquid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with liquid.  If not, see <http://www.gnu.org/licenses/>.
 */

//
// modemf.c : linear modem API, floating-point (single precision)
//

#include <math.h>
#include "liquid.internal.h"

// declare fixed-point math
#define LIQUID_FPM          1
#define Q(name)             LIQUID_CONCAT(q16,name)
#define CQ(name)            LIQUID_CONCAT(cq16,name)

#define CREAL(X)            cq16_real(X)
#define CIMAG(X)            cq16_imag(X)
#define CONJ(X)             cq16_conj(X)

// Macro definitions
#define MODEM(name)         LIQUID_CONCAT(modemq16,name)
#define FREQMOD(name)       LIQUID_CONCAT(freqmodq16,name)
#define FREQDEM(name)       LIQUID_CONCAT(freqdemq16,name)

// supporting objects
#define FIRFILT_CRC(name)   LIQUID_CONCAT(firfilt_crcq16,name)
#define IIRFILT_RRR(name)   LIQUID_CONCAT(iirfilt_rrrq16,name)
#define IIRFILT_CRC(name)   LIQUID_CONCAT(iirfilt_crcq16,name)
#define NCO_CRC(name)       LIQUID_CONCAT(nco_crcq16,    name)

#define T                   q16_t           /* primitive type */
#define TC                  cq16_t          /* primitive type (complex) */

#define PRINTVAL_T(X,F)     PRINTVAL_FLOAT(X,F)
#define PRINTVAL_TC(X,F)    PRINTVAL_CFLOAT(X,F)

// common source must come first (object definition)
#include "modem_common.c"

// generic modem specifications
#include "modem_psk.c"
#include "modem_dpsk.c"
#include "modem_ask.c"
#include "modem_qam.c"
#include "modem_apsk.c"

// specific modems
#include "modem_bpsk.c"
#include "modem_qpsk.c"
#include "modem_ook.c"
#include "modem_sqam32.c"
#include "modem_sqam128.c"

// arbitary modems
#include "modem_arb.c"

// analog modems
#include "freqmod.c"
#include "freqdem.c"
