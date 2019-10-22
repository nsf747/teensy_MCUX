/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright (c) 2008-2013 Code Red Technologies Ltd,
 * Copyright 2015, 2018-2019 NXP
 * (c) NXP Semiconductors 2013-2019
 * Generated linker script file for MIMXRT1062xxxxA
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.23
 * MCUXpresso IDE v11.0.1 [Build 2563] [2019-09-01] on 10 Oct, 2019 3:46:03 PM
 */

MEMORY
{
  /* Define each memory region */
  SRAM_ITC (rwx) : ORIGIN = 0x0, LENGTH = 0x80000 /* 512K bytes (alias RAM) */  
  SRAM_DTC (rwx) : ORIGIN = 0x20000000, LENGTH = 0x80000 /* 512K bytes (alias RAM2) */  
  SRAM_OC (rwx) : ORIGIN = 0x20200000, LENGTH = 0x80000 /* 512K bytes (alias RAM3) */  
  Flash_00 (rx) : ORIGIN = 0x60000000, LENGTH = 0x1f0000 /* 1984K bytes (alias Flash) */  
}

  /* Define a symbol for the top of each memory region */
  __base_SRAM_ITC = 0x0  ; /* SRAM_ITC */  
  __base_RAM = 0x0 ; /* RAM */  
  __top_SRAM_ITC = 0x0 + 0x80000 ; /* 512K bytes */  
  __top_RAM = 0x0 + 0x80000 ; /* 512K bytes */  
  __base_SRAM_DTC = 0x20000000  ; /* SRAM_DTC */  
  __base_RAM2 = 0x20000000 ; /* RAM2 */  
  __top_SRAM_DTC = 0x20000000 + 0x80000 ; /* 512K bytes */  
  __top_RAM2 = 0x20000000 + 0x80000 ; /* 512K bytes */  
  __base_SRAM_OC = 0x20200000  ; /* SRAM_OC */  
  __base_RAM3 = 0x20200000 ; /* RAM3 */  
  __top_SRAM_OC = 0x20200000 + 0x80000 ; /* 512K bytes */  
  __top_RAM3 = 0x20200000 + 0x80000 ; /* 512K bytes */  
  __base_Flash_00 = 0x60000000  ; /* Flash_00 */  
  __base_Flash = 0x60000000 ; /* Flash */  
  __top_Flash_00 = 0x60000000 + 0x1f0000 ; /* 1984K bytes */  
  __top_Flash = 0x60000000 + 0x1f0000 ; /* 1984K bytes */  
