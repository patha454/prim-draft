/**
 * @file machines.h
 * @brief Machine type definitions in the PE/COFF specification.
 * 
 * The COFF header specifies the target machine type as a two-byte integer. The
 * PE/COFF specification defines the codes used for common machines times. 
 * 
 * This files lists the recognised machine types and their string names.
 * 
 * <a href="https://docs.microsoft.com/en-us/windows/win32/debug/pe-format">
 * https://docs.microsoft.com/en-us/windows/win32/debug/pe-format</a> is
 * considered to be the definitive reference on the PE/COFF formats for the 
 * the purpose of this file.
 * 
 * @see machines.c for more information on the machine types.
 * 
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 17/10/2019.
 */

#ifndef FORMAT_PECOFF_MACHINES_H_
#define FORMAT_PECOFF_MACHINES_H_

#include "platform/types.h"


#define COFF_MACH_UNKNOWN   0x0

#define COFF_MACH_AM33      0x1d3

#define COFF_MACH_AMD64     0x8664

#define COFF_MACH_ARM       0x1c0

#define COFF_MACH_ARM64     0xaa64

#define COFF_MACH_ARMNT     0x1c4

#define COFF_MACH_EBC       0xebc

#define COFF_MACH_I386      0x14c

#define COFF_MACH_IA64      0x200

#define COFF_MACH_M32R      0x9041

#define COFF_MACH_MIPS16    0x266

#define COFF_MACH_MIPSFPU   0x366

#define COFF_MACH_MIPSFPU16 0x466

#define COFF_MACH_POWERPC   0x1f0

#define COFF_MACH_POWERPCFP 0x1f1

#define COFF_MACH_MIPS      0x166

#define COFF_MACH_RISCV32   0x5032

#define COFF_MACH_RISCV64   0x5064

#define COFF_MACH_RISCV128  0x5128

#define COFF_MACH_SH3       0x1a2

#define COFF_MACH_SH3DP     0x1a3

#define COFF_MACH_SH4       0x1a6

#define COFF_MACH_SH5       0x1a8

#define COFF_MACH_THUMB     0x1c2

#define COFF_MACH_WCEMIPSV2 0x169

#endif
