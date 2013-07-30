/*
The MIT License (MIT)

Copyright (c) 2013 Andrew Ruef

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef _NT_HEADERS
#define _NT_HEADERS
#include <boost/cstdint.hpp>

#define _offset(t, f) ((boost::uint32_t)(ptrdiff_t)&(((t*)0)->f))

//need to pack these structure definitions

//some constant definitions
const boost::uint16_t MZ_MAGIC = 0x5A4D;
const boost::uint32_t NT_MAGIC = 0x00004550;
const boost::uint16_t NUM_DIR_ENTRIES = 16;
const boost::uint16_t NT_OPTIONAL_32_MAGIC = 0x10B;
const boost::uint16_t NT_SHORT_NAME_LEN = 8;
const boost::uint16_t DIR_EXPORT = 0;
const boost::uint16_t DIR_IMPORT = 1;
const boost::uint16_t DIR_RESOURCE = 2;
const boost::uint16_t DIR_EXCEPTION = 3;
const boost::uint16_t DIR_SECURITY = 4;
const boost::uint16_t DIR_BASERELOC = 5;
const boost::uint16_t DIR_DEBUG = 6;
const boost::uint16_t DIR_ARCHITECTURE = 7;
const boost::uint16_t DIR_GLOBALPTR = 8;
const boost::uint16_t DIR_TLS = 9;
const boost::uint16_t DIR_LOAD_CONFIG = 10;
const boost::uint16_t DIR_BOUND_IMPORT = 11;
const boost::uint16_t DIR_IAT = 12;
const boost::uint16_t DIR_DELAY_IMPORT = 13;
const boost::uint16_t DIR_COM_DESCRIPTOR = 14;

struct dos_header {
    boost::uint16_t   e_magic;           
    boost::uint16_t   e_cblp;            
    boost::uint16_t   e_cp;              
    boost::uint16_t   e_crlc;            
    boost::uint16_t   e_cparhdr;         
    boost::uint16_t   e_minalloc;        
    boost::uint16_t   e_maxalloc;        
    boost::uint16_t   e_ss;              
    boost::uint16_t   e_sp;              
    boost::uint16_t   e_csum;            
    boost::uint16_t   e_ip;              
    boost::uint16_t   e_cs;              
    boost::uint16_t   e_lfarlc; 
    boost::uint16_t   e_ovno;            
    boost::uint16_t   e_res[4];          
    boost::uint16_t   e_oemid;           
    boost::uint16_t   e_oeminfo; 
    boost::uint16_t   e_res2[10];        
    boost::uint32_t   e_lfanew;          
};

struct file_header {
    boost::uint16_t   Machine;
    boost::uint16_t   NumberOfSections;
    boost::uint32_t   TimeDateStamp;
    boost::uint32_t   PointerToSymbolTable;
    boost::uint32_t   NumberOfSymbols;
    boost::uint16_t   SizeOfOptionalHeader;
    boost::uint16_t   Characteristics;
};

struct data_directory {
  boost::uint32_t VirtualAddress;
  boost::uint32_t Size;
};

struct optional_header_32 {
  boost::uint16_t   Magic;
  boost::uint8_t    MajorLinkerVersion;
  boost::uint8_t    MinorLinkerVersion;
  boost::uint32_t   SizeOfCode;
  boost::uint32_t   SizeOfInitializedData;
  boost::uint32_t   SizeOfUninitializedData;
  boost::uint32_t   AddressOfEntryPoint;
  boost::uint32_t   BaseOfCode;
  boost::uint32_t   BaseOfData;
  boost::uint32_t   ImageBase;
  boost::uint32_t   SectionAlignment;
  boost::uint32_t   FileAlignment;
  boost::uint16_t   MajorOperatingSystemVersion;
  boost::uint16_t   MinorOperatingSystemVersion;
  boost::uint16_t   MajorImageVersion;
  boost::uint16_t   MinorImageVersion;
  boost::uint16_t   MajorSubsystemVersion;
  boost::uint16_t   MinorSubsystemVersion;
  boost::uint32_t   Win32VersionValue;
  boost::uint32_t   SizeOfImage;
  boost::uint32_t   SizeOfHeaders;
  boost::uint32_t   CheckSum;
  boost::uint16_t   Subsystem;
  boost::uint16_t   DllCharacteristics;
  boost::uint32_t   SizeOfStackReserve;
  boost::uint32_t   SizeOfStackCommit;
  boost::uint32_t   SizeOfHeapReserve;
  boost::uint32_t   SizeOfHeapCommit;
  boost::uint32_t   LoaderFlags;
  boost::uint32_t   NumberOfRvaAndSizes;
  data_directory    DataDirectory[NUM_DIR_ENTRIES];
};

struct nt_header_32 {
  boost::uint32_t     Signature;
  file_header         FileHeader;
  optional_header_32  OptionalHeader;
};

struct image_section_header {
    boost::uint8_t    Name[NT_SHORT_NAME_LEN];
    union {
            boost::uint32_t   PhysicalAddress;
            boost::uint32_t   VirtualSize;
    } Misc;
    boost::uint32_t   VirtualAddress;
    boost::uint32_t   SizeOfRawData;
    boost::uint32_t   PointerToRawData;
    boost::uint32_t   PointerToRelocations;
    boost::uint32_t   PointerToLinenumbers;
    boost::uint16_t   NumberOfRelocations;
    boost::uint16_t   NumberOfLinenumbers;
    boost::uint32_t   Characteristics;
};

struct import_dir_entry {
  boost::uint32_t LookupTableRVA;
  boost::uint32_t TimeStamp;
  boost::uint32_t ForwarderChain;
  boost::uint32_t NameRVA;
  boost::uint32_t AddressRVA;
};

enum reloc_type {
  ABSOLUTE = 0,
  HIGH = 1,
  LOW = 2,
  HIGHLOW = 3,
  HIGHADJ = 4,
  MIPS_JMPADDR = 5,
  MIPS_JMPADDR16 = 9,
  IA64_IMM64 = 9,
  DIR64 = 10
};

struct reloc_block {
  boost::uint32_t PageRVA;
  boost::uint32_t BlockSize;
};

#endif
