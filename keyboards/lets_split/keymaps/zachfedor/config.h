/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#define USE_I2C

// #define MASTER_LEFT
#define _MASTER_RIGHT
// #define EE_HANDS

#ifdef SUBPROJECT_rev1
    #include "../../rev1/config.h"
#endif
#ifdef SUBPROJECT_rev2
    #include "../../rev2/config.h"
#endif
#ifdef SUBPROJECT_rev2fliphalf
	#include "../../rev2fliphalf/config.h"
#endif

// prevent rapid `key,key2` reverting to `mod+key2` if first key is
// set up as mod tappable
#define IGNORE_MOD_TAP_INTERRUPT

// prevents `mod+key` press from missing `key` if completed within
// tapping term
#define PERMISSIVE_HOLD

// prevents pressed mod from being stuck as pressed if mod doesn't
// exist on newly selected layer
#define PREVENT_STUCK_MODIFIERS

