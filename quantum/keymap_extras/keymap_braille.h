/* Copyright 2020 Lovro Oreskovic lovro@oreskovic.me
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

#include "keymap.h"
#include "quantum_keycodes.h"

enum braille_keycodes {
    BRL__MIN = QK_BRAILLE,
    BRL_D1   = BRL__MIN,
    BRL_D2,
    BRL_D3,
    BRL_D4,
    BRL_D5,
    BRL_D6,
    BRL__MAX,
};
