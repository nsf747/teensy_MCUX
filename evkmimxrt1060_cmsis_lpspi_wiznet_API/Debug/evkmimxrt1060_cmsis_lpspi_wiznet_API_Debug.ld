/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2019
 * Generated linker script file for MIMXRT1062xxxxA
 * Created from linkscript.ldt by FMCreateLinkLibraries
 * Using Freemarker v2.3.23
 * MCUXpresso IDE v11.0.1 [Build 2563] [2019-09-01] on 17 Oct, 2019 12:40:28 PM
 */

INCLUDE "evkmimxrt1060_cmsis_lpspi_wiznet_API_Debug_library.ld"
INCLUDE "evkmimxrt1060_cmsis_lpspi_wiznet_API_Debug_memory.ld"

/* The entry point is outright wrong, must point to the vector, not the ISR. Thanks to T4 linker script for
 * pointing it out up front (its documented wrong in the NXP material). I used "linkscript_common.ldt"
 *  for this one. */

/*ENTRY(ResetISR)*/

ENTRY(ImageVectorTable)

SECTIONS
{
     /* Image Vector Table and Boot Data for booting from external flash */
    .boot_hdr : ALIGN(4)
    {
        FILL(0xff)
        __boot_hdr_start__ = ABSOLUTE(.) ;
        KEEP(*(.boot_hdr.conf1))
        . = 0x1000 ;
        KEEP(*(.boot_hdr.ivt1))
        . = 0x1020 ;
        KEEP(*(.boot_hdr.boot_data1))
        . = 0x1030 ;
        KEEP(*(.boot_hdr.dcd_data))
        __boot_hdr_end__ = ABSOLUTE(.) ;
        . = 0x2000 ;
    } >Flash_00

    /* MAIN TEXT SECTION */
    /* Goes right after the .boot_hdr. I used "main_text_section.ldt" for this. I use 
	* this to let IDE-generated stuff remain intact, while still be able to do some 
	* initialization before entering the default ResetISR. */
     
    .teensy_boot : ALIGN(4)
    {
    	FILL(0xff)
    	__teensy_vectors_start__ = ABSOLUTE(.) ;
    	KEEP(*(.teensy_boot.vectors))
    	KEEP(*(.teensy_boot.isr))
    	*(.teensy_boot.*)
    } > Flash_00
    
     .text : ALIGN(4)
    {
        FILL(0xff)
        __vectors_start__ = ABSOLUTE(.) ;
        KEEP(*(.isr_vector))
        /* Global Section Table */
        . = ALIGN(4) ;
        __section_table_start = .;
        
        __data_section_table = .;
	        /* LONG((LOADADDR(.data_RAM) - __base_Flash_00) + __base_SRAM_ITC); */
	        LONG(LOADADDR(.data_RAM));
	        LONG(    ADDR(.data_RAM));
	        LONG(  SIZEOF(.data_RAM));
	        /* LONG((LOADADDR(.data) - __base_Flash_00) + __base_SRAM_ITC); */
	        LONG(LOADADDR(.data));
	        LONG(    ADDR(.data));
	        LONG(  SIZEOF(.data));
	        /* LONG((LOADADDR(.data_RAM3) - __base_Flash_00) + __base_SRAM_ITC); */
	        LONG(LOADADDR(.data_RAM3));
	        LONG(    ADDR(.data_RAM3));
	        LONG(  SIZEOF(.data_RAM3));
        __data_section_table_end = .;
        __bss_section_table = .;
        LONG(    ADDR(.bss_RAM));
        LONG(  SIZEOF(.bss_RAM));
        LONG(    ADDR(.bss));
        LONG(  SIZEOF(.bss));
        LONG(    ADDR(.bss_RAM3));
        LONG(  SIZEOF(.bss_RAM3));
        __bss_section_table_end = .;
        __section_table_end = . ;
        /* End of Global Section Table */

        *(.after_vectors*)

    } > SRAM_ITC AT> Flash_00

    .text : ALIGN(4)
    {
       *(.text*)
       *(.rodata .rodata.* .constdata .constdata.*)
       . = ALIGN(4);
    } > SRAM_ITC AT> Flash_00


    /*
     * for exception handling/unwind - some Newlib functions (in common
     * with C++ and STDC++) use this. 
     */
    .ARM.extab : ALIGN(4) 
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > SRAM_ITC AT> Flash_00

    __exidx_start = .;

    .ARM.exidx : ALIGN(4)
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > SRAM_ITC AT> Flash_00
    __exidx_end = .;
 
    _etext = .;
        
    /* DATA section for SRAM_ITC */

    .data_RAM : ALIGN_WITH_INPUT
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM = .) ;
        *(.ramfunc.$RAM)
        *(.ramfunc.$SRAM_ITC)
        *(.data.$RAM)
        *(.data.$SRAM_ITC)
        *(.data.$RAM.*)
        *(.data.$SRAM_ITC.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM = .) ;
     } > SRAM_ITC AT>Flash_00
    /* DATA section for SRAM_OC */

    .data_RAM3 : ALIGN(4)
    {
        FILL(0xff)
        PROVIDE(__start_data_RAM3 = .) ;
        *(.ramfunc.$RAM3)
        *(.ramfunc.$SRAM_OC)
        *(.data.$RAM3)
        *(.data.$SRAM_OC)
        *(.data.$RAM3.*)
        *(.data.$SRAM_OC.*)
        . = ALIGN(4) ;
        PROVIDE(__end_data_RAM3 = .) ;
     } > SRAM_OC AT>Flash_00
    /* MAIN DATA SECTION */
    .uninit_RESERVED (NOLOAD) :
    {
        . = ALIGN(4) ;
        KEEP(*(.bss.$RESERVED*))
       . = ALIGN(4) ;
        _end_uninit_RESERVED = .;
    } > SRAM_DTC

    /* Main DATA section (SRAM_DTC) */
    .data : ALIGN(4)
    {
       FILL(0xff)
       _data = . ;
       *(vtable)
       *(.ramfunc*)
       KEEP(*(CodeQuickAccess))
       KEEP(*(DataQuickAccess))
       *(RamFunction)
       *(NonCacheable.init)
       *(.data*)
       . = ALIGN(4) ;
       _edata = . ;
    } > SRAM_DTC AT>Flash_00

    /* BSS section for SRAM_ITC */
    .bss_RAM :
    {
       . = ALIGN(4) ;
       PROVIDE(__start_bss_RAM = .) ;
       *(.bss.$RAM)
       *(.bss.$SRAM_ITC)
       *(.bss.$RAM.*)
       *(.bss.$SRAM_ITC.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM = .) ;
    } > SRAM_ITC

    /* BSS section for SRAM_OC */
    .bss_RAM3 :
    {
       . = ALIGN(4) ;
       PROVIDE(__start_bss_RAM3 = .) ;
       *(.bss.$RAM3)
       *(.bss.$SRAM_OC)
       *(.bss.$RAM3.*)
       *(.bss.$SRAM_OC.*)
       . = ALIGN (. != 0 ? 4 : 1) ; /* avoid empty segment */
       PROVIDE(__end_bss_RAM3 = .) ;
    } > SRAM_OC

    /* MAIN BSS SECTION */
    .bss :
    {
        . = ALIGN(4) ;
        _bss = .;
       *(NonCacheable)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4) ;
        _ebss = .;
        PROVIDE(end = .);
    } > SRAM_DTC

    /* NOINIT section for SRAM_ITC */
    .noinit_RAM (NOLOAD) :
    {
       . = ALIGN(4) ;
       *(.noinit.$RAM)
       *(.noinit.$SRAM_ITC)
       *(.noinit.$RAM.*)
       *(.noinit.$SRAM_ITC.*)
       . = ALIGN(4) ;
    } > SRAM_ITC

    /* NOINIT section for SRAM_OC */
    .noinit_RAM3 (NOLOAD) :
    {
       . = ALIGN(4) ;
       *(.noinit.$RAM3)
       *(.noinit.$SRAM_OC)
       *(.noinit.$RAM3.*)
       *(.noinit.$SRAM_OC.*)
       . = ALIGN(4) ;
    } > SRAM_OC

    /* DEFAULT NOINIT SECTION */
    .noinit (NOLOAD):
    {
         . = ALIGN(4) ;
        _noinit = .;
        *(.noinit*)
         . = ALIGN(4) ;
        _end_noinit = .;
    } > SRAM_DTC

    /* Reserve and place Heap within memory map */
    _HeapSize = 0x1000;
    .heap :  ALIGN(4)
    {
        _pvHeapStart = .;
        . += _HeapSize;
        . = ALIGN(4);
        _pvHeapLimit = .;
    } > SRAM_DTC

    /* Reserve and place Stack within memory map */
    _StackSize = 0x1000;
    .stack :  ALIGN(4)
    {
        _vStackBase = .;
        . += _StackSize;
        . = ALIGN(4);
        _vStackTop = .;
    } > SRAM_DTC

    /* Provide basic symbols giving location and size of main text
     * block, including initial values of RW data sections. Note that
     * these will need extending to give a complete picture with
     * complex images (e.g multiple Flash banks).
     */
    _itcm_size = SIZEOF(.text) + SIZEOF(.ARM.extab) + SIZEOF(.ARM.exidx) + SIZEOF(.data) + SIZEOF(.bss) + SIZEOF(.noinit_RAM); 
	_itcm_start = ORIGIN(SRAM_ITC);
	_itcm_end = _itcm_start + _itcm_size;
	_itcm_loadstart = LOADADDR(.text);
    _itcm_block_count = (_itcm_size + 0x7FFE) >> 15; 
       /* _itcm_block_count = (_itcm_size + 0x7FFF)>>15;*/
        _flexram_bank_config = (0xAAAAAAAA)|((1<<(_itcm_block_count * 2)) - 1);
    _image_start = LOADADDR(.text);
    _image_end = LOADADDR(.data) + SIZEOF(.data);
    _image_size = _image_end - _image_start;
   
    /* Here we lend and adapt some of the T4s linking logic for our purposes. Use "image_size.ldt" for
         * this. */
	/* WARNING: requires heap and stack:
	 *    1) configured post-data
	 *    2) configured small enough to fit into the DTCM what is left over after ITCM bank reservation
	 */
	}