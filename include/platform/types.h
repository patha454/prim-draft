/**
 * @file types.h 
 * @brief Type definitions used by Prim.
 *
 * Prim is designed to be built into arbitrary software components: Prim could
 * be used as part of an operating system kernel or user program, as a 
 * standalone executable or library on hardware with different native word 
 * sizes.
 *
 * Many binary formats specify exact widths for their data type, but C's 
 * built-in types have no guaranteed widths - only minimum guaranteed widths.
 * C's fixed width datatypes defined in <stdint.h> originate in ISO C99, which
 * is supported by most, but <em>not all<em> compilers. 
 *
 * Prim uses its own typedef’s types whenever a fixed width is required, which
 * maximises the host platforms available to Prim. This file, platform/types.h,
 * should be edited when porting Prim to a new platform, so the types in this
 * file have the correct widths on the target platform.
 *
 * @attention This version of platform/types.h is setup for compiling Prim in 
 * an environment which supports ISO C99's <stdin.h>.
 *
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 17/10/2019.
 */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_


#include <stdint.h>


/**
 * @typedef uint8_ne A native (or don't care) endian, 8 bit, unsigned integer.
 */
typedef uint8_t uint8_ne;

/**
 * @typedef uint16_ne A native (or don't care) endian, 16 bit, unsigned integer.
 */
typedef uint16_t uint16_ne;

/**
 * @typedef uint32_ne A native (or don't care) endian, 32 bit, unsigned integer.
 */
typedef uint32_t uint32_ne;

/**
 * @typedef uint64_ne A native (or don't care) endian, 64 bit, unsigned integer.
 */
typedef uint64_t uint64_ne;

/**
 * @typedef uint8_le A little endian, 8 bit, unsigned integer.
 */
typedef uint8_t uint8_le;

/**
 * @typedef uint16_le A little endian, 16 bit, unsigned integer.
 */
typedef uint16_t uint16_le;

/**
 * @typedef uint32_le A little endian, 32 bit, unsigned integer.
 */
typedef uint32_t uint32_le;

/**
 * @typedef uint64_le A little endian, 64 bit, unsigned integer.
 */
typedef uint64_t uint64_le;

/**
 * @typedef uint8_be A big endian, 8 bit, unsigned integer.
 */
typedef uint8_t uint8_be;

/**
 * @typedef uint16_be A big endian, 16 bit, unsigned integer.
 */
typedef uint16_t uint16_be;

/**
 * @typedef uint32_be A big endian, 32 bit, unsigned integer.
 */
typedef uint32_t uint32_be;

/**
 * @typedef uint64_be A big endian, 64 bit, unsigned integer.
 */
typedef uint64_t uint64_be;

/**
 * @typedef int8_ne A native endian, 8 bit, signed integer.
 */
typedef int8_t int8_ne;

/**
 * @typedef int16_ne A native endian, 16 bit, signed integer.
 */
typedef int16_t int16_ne;

/**
 * @typedef int32_ne A native endian, 32 bit, signed integer.
 */
typedef int32_t int32_ne;

/**
 * @typedef int64_ne A native endian, 64 bit, signed integer.
 */
typedef int64_t int64_ne;

/**
 * @typedef int8_le A little endian, 8 bit, signed integer.
 */
typedef int8_t int8_le;

/**
 * @typedef int16_le A little endian, 16 bit, signed integer.
 */
typedef int16_t int16_le;

/**
 * @typedef int32_le A little endian, 32 bit, signed integer.
 */
typedef int32_t int32_le;

/**
 * @typedef int64_le A little endian, 64 bit, signed integer.
 */
typedef int64_t int64_le;

/**
 * @typedef int8_be A big endian, 8 bit, signed integer.
 */
typedef int8_t int8_be;

/**
 * @typedef int16_be A big endian, 16 bit, signed integer.
 */
typedef int16_t int16_be;

/**
 * @typedef int32_be A big endian, 32 bit, signed integer.
 */
typedef int32_t int32_be;

/**
 * @typedef int64_be A big endian, 64 bit, signed integer.
 */
typedef int64_t int64_be;

#endif
