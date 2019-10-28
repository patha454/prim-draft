/**
 * @file characteristics.h
 * @brief COFF object attributes, as defined in the PE/COFF specification.
 * 
 * The COFF header specifies attribute flags which indicate various properties
 * of the PE image or COFF object. characteristics.h defines these flags.
 *
 * <a href="https://docs.microsoft.com/en-us/windows/win32/debug/pe-format">
 * https://docs.microsoft.com/en-us/windows/win32/debug/pe-format</a> is
 * considered to be the definitive reference on the PE/COFF formats for the 
 * the purpose of this file.
 * 
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 18/10/2019.
 */

#ifndef FORMAT_PECOFF_CHARACTERISTICS_H_
#define FORMAT_PECOFF_CHARACTERISTICS_H_


#include "platform/types.h"


/**
 * @def PE_RELOCATIONS_STRIPPED
 * @brief Indicates a PE image has no relocation information available.
 * 
 * The image must be loaded at its pefreed base address, because the loader will
 * (probably) not have the date required to relocation the image.
 */
#define PE_RELOCATIONS_STRIPPED         0x0001

/**
 * @def PE_EXECUTABLE_IMAGE
 * @brief This is a valid PE image which can be executed.
 * 
 * If a PE images does not have this bit set, a linker error occurred and the
 * image may be invalid.
 */
#define PE_IMAGE_EXECUTABLE             0x0002

/**
 * @def COFF_LINE_NUMS_STRIPPED
 * @brief Deprecated. Should be zero.
 * 
 * @deprecated Used to indicate that the COFF line number data had been
 * removed.
 */
#define COFF_LINE_NUMS_STRIPPED         0x0004

/**
 * @def COFF_LOCAL_SYMS_STRIPPED
 * @brief Deprecated. Should be zero.
 * 
 * @deprecated Used to indicate local debug symbols have been removed.
 */
#define COFF_LOCAL_SYMBOLS_STRIPPED     0x0008

/**
 * @def COFF_AGGRESSIVE_WS_TRIM
 * @brief Obsolete. Must be zero.
 * 
 * @deprecated The working set must be trimmed aggressively.
 * 
 * @warning Deprecated and *must* be zero on Windows 2000 and later binaries.
 */
#define COFF_AGGRESSIVE_WS_TRIM         0x0010

/**
 * @def COFF_LARGE_ADDRESS_AWARE
 * @brief Application can handle address spaces larger than 2GiB.
 * 
 * Typically used for 64-bit binaries.
 * 
 * @note 32-bit machines can address 4GiB of memory, but the top 2GB is
 * reserved by most operating systems.
 */
#define COFF_LARGE_ADDRESS_AWARE        0x0020

/**
 * @def COFF_RESERVED_1
 * @brief Reserved for future use in the PE/COFF specification.
 */
#define COFF_RESERVED_1                 0x0040

/**
 * @def COFF_LITTLE_ENDIAN
 * @brief Deprecated. Should be zero.
 * 
 * @deprecated Indicates the image is little endian.
 * 
 * Since deprecation images are assumed to be native endian.
 */
#define COFF_LITTLE_ENDIAN              0x0080

/**
 * @def COFF_32_BIT_IMAGE
 * @brief Target machine uses a 32-bit architecture.
 */
#define COFF_32_BIT_IMAGE               0x0100

/**
 * @def COFF_DEBUG_INFO_STRIPPED
 * @brief Debugging info has been stripped from this file.
 */
#define COFF_DEBUG_INFO_STRIPPED        0x0200

/**
 * @def COFF_REMOVABLE_RUN_FROM_SWAP
 * @brief Image should not be run from removable media.
 * 
 * If the image is stored on removable media, fully copy the image to swap
 * space before executing.
 */
#define COFF_REMOVABLE_RUN_FROM_SWAP    0x0400

/**
 * @def COFF_NET_RUN_FROM_SWAP
 * @brief Image should not be run from network media
 * 
 * If the image is stored on network media, fully copy the image to the swap
 * space before executing.
 */
#define COFF_NET_RUN_FROM_SWAP          0x0800

/**
 * @def COFF_SYSTEM_FILE
 * @brief The image is an operating system binary, not a user application.
 * 
 * Executing as a user space program will likely be problimatic or impossible.
 */
#define COFF_SYSTEM_FILE                0x1000

/**
 * @def COFF_DLL
 * @brief This image is a DLL file.
 * 
 * This is a DLL shared library, not a standalone program.
 */
#define COFF_DLL                        0x2000

/**
 * @def COFF_UNIPROCESSOR_ONLY
 * @brief This image should only be run on a uniprocessor machine.
 */
#define COFF_UNIPROCESSOR_ONLY          0x4000

/**
 * @def COFF_BIG_ENDIAN
 * @brief Deprecated. Should be zero.
 * 
 * @deprecated Used to indicate this image is big endian. Since deprecation the
 * image is assumed to be in the target machine's endianess.
 */
#define COFF_BIG_ENDIAN                 0x8000

/**
 * @brief Gets the human readable string associated with a characteristic flag.
 * 
 * get_coff_characteristic_string matches a COFF characteristic flag to a human
 * readable string describing the chracteristic.
 * 
 * This function returns eagerly, so it will only match the first flag in
 * `characteristic`. The function should be called with each flag in the field
 * to build up a full set of characteristic strings.
 * 
 * @param   characteristic  The COFF characteristic flag to match.
 * @return  A pointer to a human readable string describing `characteristic`.
 */
const char* get_coff_characteristic_string(uint16_ne characteristic);

#endif
