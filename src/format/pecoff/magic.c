/**
 * @file magic.c
 * @brief Defines magic numbers for PE images.
 * 
 * 'magic.c' defines names for magic numbers recognised by the PE specification
 * for defining image types
 * 
 * 'magic.c' defines a function to generate human readable names for PE magic 
 * numbers, and a function to test if a magic number is recognised.
 * 
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 27/10/19.
 */

#include "format/pecoff/magic.h"
#include "platform/types.h"

/**
 * @struct magic_string
 * @brief Associates a magic number with a string name.
 */
struct magic_string
{
    uint16_ne magic;
    const char* const name;
};

/**
 * @var magic_strings
 * @brief machine_strings pair PE magic numbers with human readable names.
 */
const struct magic_string magic_strings[] =
{
    PE_MAGIC_PE32,      "PE32 Image (PE)",
    PE_MAGIC_PE32P,     "PE32+ Image (PE)",
    PE_MAGIC_ROM,       "PE ROM Image (PE)",
};

/**
 * @brief Returns the human readable representation of a magic number.
 * 
 * @param   magic   The PE magic number.
 * @return  A pointer to the human readable magic number.
 */
const char* get_pe_magic_name(uint16_ne magic)
{
    static const char* const unrecognised_magic = "Unrecognised (PE)";
    unsigned int i;
    for (i = 0;
         i < sizeof(magic_strings) / sizeof(struct magic_string);
         i++)
    {
        if (magic_strings[i].magic == magic)
        {
            return magic_strings[i].name;
        }
    }
    return unrecognised_magic;
}

/**
 * @brief Indicates if a magic number is a known PE magic number.
 * 
 * @param   magic   The magic number to test.
 * @return  1 if the magic number is known and valid; 0 otherwise.
 */
int is_pe_magic_known(uint16_ne magic)
{
    unsigned int i;
    for (i = 0;
         i < sizeof(magic_strings) / sizeof(struct magic_string);
         i++)
    {
        if (magic_strings[i].magic == magic)
        {
            return 1;
        }
    }
    return 0;
}