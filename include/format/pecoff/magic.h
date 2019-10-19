/**
 * @file magic.h
 * @brief Magic numbers used in the PE "optional" header.
 * 
 * The PE "optional" header uses magic numbers to communicate the ty[e of the
 * image: Either a 64-bit PE-32+ image or a 32-bit PE32 image. PE32+ images 
 * allow for a 64-bit address space, while PE32 images are limited to the first
 * 2 GiB (The area above 2Gib upto 4 GiB is usually reserved for the operaring
 * system.
 * 
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 27/10/2019.
 */

#ifndef FORMAT_PECOFF_MAGIC_H_
#define FORMAT_PECOFF_MAGIC_H_

#include "platform/types.h"

/**
 * @def PE_MAGIC_PE32
 * @brief Image is a PE32 image, with an address space less than 2 GiB.
 */
#define PE_MAGIC_PE32       0x10b

/**
 * @def PE_MAGIC_PE32P
 * @brief Image is a PE32+ image, with a full 64-bit address space.
 */
#define PE_MAGIC_PE32P      0x20b

/**
 * @def PE_MAGIC_ROM
 * @brief Image is a ROM excutable, with an unspecified address space.
 */
#define PE_MAGIC_ROM        0x107

/**
 * @brief Indicates if a magic number is a known PE magic number.
 * 
 * @param   magic   The magic number to test.
 * @return  1 if the magic number is known and valid; 0 otherwise.
 */
int is_pe_magic_known(uint16_ne magic);

/**
 * @brief Returns the human readable representation of a magic number.
 * 
 * @param   magic   The PE magic number.
 * @return  A pointer to the human readable magic number.
 */
const char* get_pe_magic_name(uint16_ne magic);

#endif
