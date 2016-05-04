/*
libskry - astronomical image stacking
Copyright (C) 2016 Filip Szczerek <ga.software@yahoo.com>

This file is part of libskry.

Libskry is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Libskry is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with libskry.  If not, see <http://www.gnu.org/licenses/>.

File description:
    Miscellaneous functions header.
*/

#ifndef LIBSKRY_MISC_UTILS_HEADER
#define LIBSKRY_MISC_UTILS_HEADER

#include <stdint.h>
#include <skry/image.h>

#define WHITE_8bit 0xFF


/// Returns 1 on equality
int compare_extension(const char *file_name,
                      const char *extension ///< lowercase without '.'
                     );

/// Finds brightness level 'b' such that all pixels <= b belong to the background
uint8_t get_background_threshold(
    /// Must be SKRY_PIX_MONO8
    const SKRY_Image *img
);

void SKRY_set_clock_func(SKRY_clock_sec_fn new_clock_func);

double SKRY_clock_sec(void);

void find_min_max_brightness(const SKRY_Image *img, uint8_t *bmin, uint8_t *bmax);

int is_machine_big_endian(void);

/// Conditionally swaps bytes in a 32-bit value
uint32_t cnd_swap_32(uint32_t x, int do_swap);

/// Conditionally swaps two lower bytes of a 32-bit value
uint32_t cnd_swap_16_in_32(uint32_t x, int do_swap);

/// Conditionally swaps bytes in a 16-bit value
uint16_t cnd_swap_16(uint16_t x, int do_swap);

/// Changes endianess of 16-bit words
void swap_words16(SKRY_Image *img);

#endif // LIBSKRY_MISC_UTILS_HEADER