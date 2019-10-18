/**
 * @file coff.h
 * @brief Describes the COFF header used by COFF objects and PE executables.
 * 
 * The COFF header is part of the PE/COFF standard. The COFF header is used by
 * both PE executables and COFF object files to describe the basic layout of the file.
 * 
 * COFF.h describes the format of the COFF header and the constats used by the
 * header.
 * 
 * <a href="https://docs.microsoft.com/en-us/windows/win32/debug/pe-format">
 * https://docs.microsoft.com/en-us/windows/win32/debug/pe-format</a> is
 * considered to be the definitive reference on the PE/COFF formats for the 
 * the purpose of this file.
 * 
 * @author H Paterson.
 * @copyright Boost Software License 1.0.
 * @date 17/10/2019.
 */

#ifndef FORMAT_PECOFF_COFF_H_
#define FORMAT_PECOFF_COFF_H_

#include "platform/types.h"


/**
 * @struct coff_header
 * @brief Sets out the COFF header format used in PE/COFF binaries.
 * 
 * `struct coff_header` describes the layout of the COFF header used in both PE
 * executables and COFF object files.
 * 
 * The COFF header occurs at the start of COFF files, and at an indicated 
 * offset in PE executable files.
 */
struct coff_header
{
    /** 
     * @var machine_id
     * @brief Indicates the CPU architecture the binary was compiled
     * for. 
     * 
     * Machine ID also implies the endianess used in the PE/COFF headers,
     * which should be the same endianess the machine uses.
     */
    uint16_ne machine_id;

    /**
     * @var section_count
     * @brief Indicates the number of binary sections in the file.
     * 
     * The section count refers to how many sections (.bss, .text, .rodata...)
     * are present in this file, and therefore the length of the section header
     * table.
     */
    uint16_ne section_count;

    /**
     * @var timestamp
     * @brief The timestamp indicate the date the binary file was created.
     * 
     * `timestamp` indicates the date and time this PE/COFF file was generated
     * , given as the number of sections since 00:00:00 01/01/70 - that is, as
     * a C standard library time_t value.
     */
    uint32_ne timestamp;

    /**
     * @var symbol_table_offset
     * @brief The offset of the symbol table within the PE/COFF file.
     * 
     * The symbol table offset is the location of the symbol table inside a COFF
     * COFF object files.
     * 
     * The Microsoft specification notes this value should be 0 in PE 
     * PE executables, because COFF debugging information has been deprecated.
     */
    uint32_ne symbol_table_offset;

    /**
     * @var symbol_count
     * @brief The number of entries in the symbol table.
     * 
     * `symbol_count` states the number of symbols in the COFF file's symbol
     * table. The symbol count should be 0 in PE executables because COFF
     * debugging information has been deprecated by Microsoft.
     * 
     * @note `symbol_count` also implies the location of the string table, 
     * which is located immediately after the symbol table. The location of the
     * string table should be `symbol_table_offset + symbol_count * 
     * sizeof($SYMBOL_TABLE_ENTRY)`.
     */
    uint32_ne symbol_count;

    /**
     * @brief executable_header_size
     * @brief The size of the executable header("optional header").
     * 
     * `executable_header_size` contains the length of the executable header, 
     * which gives information for loading the image such as the entry point
     * and mode (PE32 32 bit address space, or PE32+ [almost] 64 bit address
     * space).
     * 
     * The optional header can be diffrent lengths because Windows executables
     * have additional data in the table, and PE32 and PE32+ executables have
     * slightly diffrent fields and data widths.
     * 
     * @note Microsoft refers to the executable header as the "optional
     * header". Prim uses the name "executable header" for additional clarity.
     * The header is not optional for PE executables, but is called optional
     * because the header can be included but is generally meaningless.
     */
    uint16_ne executable_header_size;

    /**
     * @var characteristics
     * @brief flags which describe various file attributes.
     * 
     * `characteristics` are flags which note various file properties. See the
     * chracteristics defintions for more information.
     */
    uint16_ne characteristics;
};

/**
 * @brief Returns the human readable representation of a machine ID.
 * 
 * If the machine ID is unknown, get_coff_machine_name() will return a pointer
 * to a string stating the machine is unrecognised.
 * 
 * @param   machine_id  The COFF machine ID.
 * @return  A pointer to a human readable machine name.
 */
const char* get_coff_machine_name(uint16_ne machine_id);

/**
 * @brief Indicates if a machine ID corresponds to a known COFF machine ID.
 * 
 * The PE/COFF "Unknown" machine type is considered to be known for the purpose
 * of this function. A machine ID is considered unknown if it does not appear 
 * in the PE/COFF specification.
 * 
 * @param   machine_id  The COFF machine ID.
 * @return  1 if the machine type is recognised; 0 otherwise.
 */
int is_coff_machine_known(uint16_ne machine_id);

#endif
