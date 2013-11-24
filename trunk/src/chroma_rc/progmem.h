#ifndef _WORKAROUND_H_
#define _WORKAROUND_H_

#include <avr/pgmspace.h>

#ifdef PROGMEM
#undef PROGMEM
#define PROGMEM __attribute__((section(".progmem.data")))
#endif

inline byte readProgmemByte(const byte data[], byte index) {
	return pgm_read_byte_near(data + index);
}

#endif /* _WORKAROUND_H_ */
