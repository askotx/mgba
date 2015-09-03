/* Copyright (c) 2013-2015 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "util/memory.h"

#include "wii-mem2.h"

void* anonymousMemoryMap(size_t size) {
	return mem2_malloc(size);
}

void mappedMemoryFree(void* memory, size_t size) {
	UNUSED(size);
	mem2_free(memory);
}
