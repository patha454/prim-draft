/**
 * @file pe.h
 * @brief Describes the PE header used by PE image.
 * 
 * PE images contain an additional header after the general purpose COFF
 * header. 
 * 
 * The PE/COFF specification calls this the "optional" header. The header is 
 * optional as in COFF objects don't require it, the the header is required for
 * all PE images. 
 * 
 * The first fields of the PE header are standard, and can be followed by a 
 * target specific set of fields - hence why the COFF header specifies the 
 * length of the PE header (including the platform specific headers).
 * 
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 19/10/19.
 */

#ifndef FORMAT_PECOFF_PE_H_
#define FORMAT_PECOFF_PE_H_


#include "platform/types.h"


/**
 * @struct pe_header
 * @brief Layout of the "optional" header included in all PE executables.
 * 
 */
struct pe_header
{
    /**
     * @var magic
     * @brief Identifies PE images type and validity.
     */
    uint16_ne magic;

    /**
     * @var major_link_version
     * @brief The major version of the linker which produced this image.
     */
    uint8_ne major_link_version;

    /**
     * @var minor_link_version
     * @brief The minor version of the linker which produced this image.
     */
    uint8_ne minor_link_version;

    /**
     * @var text_size
     * @brief The size of all .text (code) sections in this image.
     */
    uint32_ne text_size;

    /**
     * @var data_size
     * @brief The size of all .data (initialised data) sections in the image.
     */
    uint32_ne data_size;

    /**
     * @var bss_size
     * @brief The size of all .bss (uninitialized data) sections in the image.
     */
    uint32_ne bss_size;

    /**
     * @var entry_point
     * @brief The entry point for the program.
     * 
     * The entry point is relative to the base of the image when loaded into
     * memory. This is the start address for user programs and the
     * initialisation function for device drives. An entry point is optional
     * for dynamically linked libraries.
     * 
     * `entry_point` must be zero when no entry point is present in the image.
     */
    uint32_ne entry_point;

    /**
     * @var text_address
     * @brief The relative virtual address of the .text section after loading.
     */
    uint32_ne text_address;

    /**
     * @bar data_address
     * @brief The relative virtual address of the .data section after loading.
     * 
     * @warning 'data_address` is only present in PE32 images, and not PE32+
     * images. The user should check the image type, for example using the
     * magic number, before attempting to access `data_address`.
     */
    uint32_ne data_address;
};


#endif
