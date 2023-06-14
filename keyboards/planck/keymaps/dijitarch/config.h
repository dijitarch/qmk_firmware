/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef AUDIO_ENABLE
//#    define STARTUP_SONG SONG(PLANCK_SOUND)
 #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

//#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
//#define ENCODER_RESOLUTION 4

#define TAPPING_TERM 175

//Unicode:
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

//User static macro strings
#include "macros.h"
#ifndef MACRO_EML1
#define MACRO_EML1 ""
#endif
#ifndef MACRO_EML2
#define MACRO_EML2 ""
#endif
#ifndef MACRO_EML3
#define MACRO_EML3 ""
#endif
#ifndef MACRO_EML4
#define MACRO_EML4 ""
#endif
#ifndef MACRO_EML5
#define MACRO_EML5 ""
#endif
#ifndef MACRO_SIG1
#define MACRO_SIG1 ""
#endif
#ifndef MACRO_SIG2
#define MACRO_SIG2 ""
#endif
#ifndef MACRO_SIG3
#define MACRO_SIG3 ""
#endif
#ifndef MACRO_SIG4
#define MACRO_SIG4 ""
#endif
#ifndef MACRO_SIG5
#define MACRO_SIG5 ""
#endif
