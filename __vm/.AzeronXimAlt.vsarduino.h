/* 
	Editor: https://www.visualmicro.com/
			visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
			the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
			all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
			note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Teensy++ 2.0, Platform=teensy, Package=teensy
*/

#if defined(_VMICRO_INTELLISENSE)

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __HARDWARE_AT90usb1286__
#define __HARDWARE_AT90USB1286__
#define TEENSYDUINO 144
#define ARDUINO_ARCH_AVR
#define ARDUINO 10807
#define F_CPU 16000000L
#define USB_SERIAL_HID
#define LAYOUT_US_ENGLISH
#define __cplusplus 201103L
#define __AVR__
#define __extension__
#define  __attribute__(x)
typedef void *__builtin_va_list;

#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__

#define NEW_H

#include <arduino.h>
#undef cli
#define cli()
#include "AzeronXimAlt.ino"
#endif
#endif
