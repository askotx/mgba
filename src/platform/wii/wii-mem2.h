/****************************************************************************
 * Snes9x Nintendo Wii/Gamecube Port
 *
 * Tantric 2010
 *
 * mem2.h
 *
 * MEM2 memory allocator
 ***************************************************************************/



#ifndef _MEM2MANAGER_H_
#define _MEM2MANAGER_H_

int32_t InitMem2Manager ();
void* mem2_malloc(int32_t size);
bool mem2_free(void *ptr);

#endif


