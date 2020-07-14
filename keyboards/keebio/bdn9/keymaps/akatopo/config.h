#pragma once

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_KEYPRESSES
#endif

// https://docs.splitkb.com/hc/en-us/articles/360011068659-My-encoder-is-skipping-actions-when-turning-it
// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.

#define ENCODER_RESOLUTION 2
