/**
 * @file characteristics.c
 * @brief Human readable strings for COFF header attribute flags.
 * 
 * The COFF header specifies attribute flags which indicate various properties.
 * 
 * characteristics.c contins human readable strings for the attribute flags and
 * a function to query the string based on a flag.
 *
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 18/10/2019.
 */

#include "format/pecoff/characteristics.h"
#include "platform/types.h"

/**
 * @struct characteristic_string
 * @brief Associates a flag with a COFF characteristic. 
 */ 
struct characteristic_string 
{
    uint16_ne flag;
    const char* const name;
};

/**
 * @var characteristic_strings
 * @brief Associates COFF flags with a human readable string.
 */
struct characteristic_string characteristic_strings[] =
{
    PE_RELOCATIONS_STRIPPED,            "PE relocations stripped (COFF)",
    PE_IMAGE_EXECUTABLE,                "PE image is a valid executable (COFF)",
    COFF_LINE_NUMS_STRIPPED,            "Line numbers stripped. Deprecated/SBZ (COFF)",
    COFF_LOCAL_SYMBOLS_STRIPPED,        "Local symbols stripped. Deprecated/SBZ (COFF)",
    COFF_AGGRESSIVE_WS_TRIM,            "Aggressive workspace trim. Obsolete/SBZ (COFF)",
    COFF_LARGE_ADDRESS_AWARE,           "Large address space aware (COFF)",
    COFF_RESERVED_1,                    "Reserved 1. SBZ (COFF)",
    COFF_LITTLE_ENDIAN,                 "Little endian. Deprecated/SBZ (COFF)",
    COFF_32_BIT_IMAGE,                  "32-bit image (COFF)",
    COFF_DEBUG_INFO_STRIPPED,           "Debugging info stripped (COFF)",
    COFF_REMOVABLE_RUN_FROM_SWAP,       "Removable run from swap space (COFF)",
    COFF_NET_RUN_FROM_SWAP,             "Network run from swap space (COFF)",
    COFF_SYSTEM_FILE,                   "Operating system image (COFF)",
    COFF_DLL,                           "Dynamically linked library (COFF)",
    COFF_UNIPROCESSOR_ONLY,             "Uniprocessor only (COFF)",
    COFF_BIG_ENDIAN,                    "Big endian. Deprecated/SBZ (COFF)",
};

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
const char* get_coff_characteristic_string(uint16_ne characteristic)
{
    static const char* const not_a_characteristic 
        = "Not a characteristic (COFF)";
    int i;
    for (i = 0;
         i < sizeof(characteristic_strings) / sizeof(struct characteristic_string);
         i++)
    {
        if (characteristic & characteristic_strings[i].flag)
        {
            return characteristic_strings[i].name;
        }
    }
    return not_a_characteristic;
}
