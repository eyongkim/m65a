#ifndef __CONFIG_H__
#define __CONFIG_H__

//#include "config_common.h"

#ifdef PRODUCT
#undef PRODUCT
#endif
#define PRODUCT         RAMA M65-A

#ifdef DESCRIPTION
#undef DESCRIPTION
#endif
#define DESCRIPTION     RAMA M65-A QMK PCB

#ifdef RGB_DI_PIN
#define RGBLIGHT_HUE_STEP   12
#define RGBLIGHT_SAT_STEP   8
#define RGBLIGHT_VAL_STEP   8
#define RGBLIGHT_SLEEP
#endif

#endif//__CONFIG_H__
