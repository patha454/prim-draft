/**
 * @file machines.c
 * @brief Defines names the machines types in the COFF specification.
 * 
 * `machines.c` defines names for the machines recognised by the COFF
 * specification, and string representations of their names.
 * 
 * `machines.c` also provides a function to get the name of a machine from its'
 * machine ID, and test if a machine ID is recognised.
 * 
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 18/10/2019.
 */

#include "format/pecoff/machines.h"
#include "platform/types.h"


/**
 * @struct machine_string
 * @brief Associates a machine ID with a string name.
 */
struct machine_string 
{
    uint16_ne id;
    const char* const name;
};

/**
 * @var machine_strings
 * @brief machine_strings pairs COFF machine IDs with human readable names.
 */
const struct machine_string machine_strings[] = 
{
    COFF_MACH_UNKNOWN,      "Unknown/Default (COFF)",
    COFF_MACH_AM33,         "Matsushita AM33 (COFF)",
    COFF_MACH_AMD64,        "x86_64 (COFF)",
    COFF_MACH_ARM,          "ARM32 little endian (COFF)",
    COFF_MACH_ARM64,        "ARM64 little endian (COFF)",
    COFF_MACH_ARMNT,        "ARM Thumb-2 little endian (COFF)",
    COFF_MACH_EBC,          "EFI bytecode (COFF)",
    COFF_MACH_I386,         "x86 (COFF)",
    COFF_MACH_IA64,         "IA64 Itanium (COFF)",
    COFF_MACH_M32R,         "Mitshubishi M32R little endian (COFF)",
    COFF_MACH_MIPS16,       "MIPS16 (COFF)",
    COFF_MACH_MIPSFPU,      "MIPS with FPU (COFF)",
    COFF_MACH_MIPSFPU16,    "MIPS 16-bit with FPU (COFF)",
    COFF_MACH_POWERPC,      "PowerPC (COFF)",
    COFF_MACH_POWERPCFP,    "PowerPC with FPU (COFF)",
    COFF_MACH_MIPSFPU,      "MIPS little endian (COFF)",
    COFF_MACH_RISCV32,      "RISC-V 32-bit (COFF)",
    COFF_MACH_RISCV64,      "RISC-V 64-bit (COFF)",
    COFF_MACH_RISCV128,     "RISC-V 128-bit (COFF)",
    COFF_MACH_SH3,          "Hitachi SH3 (COFF)",
    COFF_MACH_SH3DP,        "Hitachi Sh3 DSP (COFF)",
    COFF_MACH_SH4,          "Hitachi SH4 (COFF)",
    COFF_MACH_SH5,          "Hitachi SH5 (COFF)",
    COFF_MACH_THUMB,        "ARM Thumb (COFF)",
    COFF_MACH_WCEMIPSV2,    "MIPS WCE v2 little endian (COFF)",
};

/**
 * @brief Returns the human readable representation of a machine ID.
 * 
 * @see machines.h for more information.
 * 
 * @param   machine_id  The COFF machine ID.
 * @return  A pointer to a human readable machine name.
 */
const char* get_coff_machine_name(uint16_ne machine_id)
{
    static const char* const unrecognised_machine = "Unrecognised (COFF)";
    unsigned int i;
    for (i = 0;
         i < sizeof(machine_strings) / sizeof(struct machine_string);
         i++) 
    {
        if (machine_strings[i].id == machine_id) 
        {
            return machine_strings[i].name;
        }
    }
    return unrecognised_machine;
}

/**
 * @brief Indicates if a machine ID corresponds to a known COFF machine ID.
 * 
 * The PE/COFF specification includes a value for "Unknown" which is used as a
 * default and as a "dont' care" value.
 * 
 * @see machines.h for more information.
 * 
 * @param   machine_id  The COFF machine ID.
 * @return  1 if the machine type is recognised; 0 otherwise.
 */
int is_coff_machine_known(uint16_ne machine_id)
{
    unsigned int i;
    for (i = 0;
         i < sizeof(machine_strings) / sizeof(struct machine_string);
         i++)
    {
        if (machine_strings[i].id == machine_id) 
        {
            return 1;
        }
    }
    return 0;
}
