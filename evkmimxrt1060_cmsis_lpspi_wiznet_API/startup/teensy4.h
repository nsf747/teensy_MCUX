/*
 * teensy4.h
 *
 *  Created on: 23-Sep-2019
 *      Author: SADHANA-PC
 */

#ifndef TEENSY4_H_
#define TEENSY4_H_

#include<stdint.h>
typedef struct {
	volatile uint32_t offset000;
	volatile uint32_t offset004;
	volatile uint32_t offset008;
	volatile uint32_t offset00C;
	volatile uint32_t offset010;
	volatile uint32_t offset014;
	volatile uint32_t offset018;
	volatile uint32_t offset01C;
	volatile uint32_t offset020;
	volatile uint32_t offset024;
	volatile uint32_t offset028;
	volatile uint32_t offset02C;
	volatile uint32_t offset030;
	volatile uint32_t offset034;
	volatile uint32_t offset038;
	volatile uint32_t offset03C;
	volatile uint32_t offset040;
	volatile uint32_t offset044;
	volatile uint32_t offset048;
	volatile uint32_t offset04C;
	volatile uint32_t offset050;
	volatile uint32_t offset054;
	volatile uint32_t offset058;
	volatile uint32_t offset05C;
	volatile uint32_t offset060;
	volatile uint32_t offset064;
	volatile uint32_t offset068;
	volatile uint32_t offset06C;
	volatile uint32_t offset070;
	volatile uint32_t offset074;
	volatile uint32_t offset078;
	volatile uint32_t offset07C;
	volatile uint32_t offset080;
	volatile uint32_t offset084;
	volatile uint32_t offset088;
	volatile uint32_t offset08C;
	volatile uint32_t offset090;
	volatile uint32_t offset094;
	volatile uint32_t offset098;
	volatile uint32_t offset09C;
	volatile uint32_t offset0A0;
	volatile uint32_t offset0A4;
	volatile uint32_t offset0A8;
	volatile uint32_t offset0AC;
	volatile uint32_t offset0B0;
	volatile uint32_t offset0B4;
	volatile uint32_t offset0B8;
	volatile uint32_t offset0BC;
	volatile uint32_t offset0C0;
	volatile uint32_t offset0C4;
	volatile uint32_t offset0C8;
	volatile uint32_t offset0CC;
	volatile uint32_t offset0D0;
	volatile uint32_t offset0D4;
	volatile uint32_t offset0D8;
	volatile uint32_t offset0DC;
	volatile uint32_t offset0E0;
	volatile uint32_t offset0E4;
	volatile uint32_t offset0E8;
	volatile uint32_t offset0EC;
	volatile uint32_t offset0F0;
	volatile uint32_t offset0F4;
	volatile uint32_t offset0F8;
	volatile uint32_t offset0FC;
	volatile uint32_t offset100;
	volatile uint32_t offset104;
	volatile uint32_t offset108;
	volatile uint32_t offset10C;
	volatile uint32_t offset110;
	volatile uint32_t offset114;
	volatile uint32_t offset118;
	volatile uint32_t offset11C;
	volatile uint32_t offset120;
	volatile uint32_t offset124;
	volatile uint32_t offset128;
	volatile uint32_t offset12C;
	volatile uint32_t offset130;
	volatile uint32_t offset134;
	volatile uint32_t offset138;
	volatile uint32_t offset13C;
	volatile uint32_t offset140;
	volatile uint32_t offset144;
	volatile uint32_t offset148;
	volatile uint32_t offset14C;
	volatile uint32_t offset150;
	volatile uint32_t offset154;
	volatile uint32_t offset158;
	volatile uint32_t offset15C;
	volatile uint32_t offset160;
	volatile uint32_t offset164;
	volatile uint32_t offset168;
	volatile uint32_t offset16C;
	volatile uint32_t offset170;
	volatile uint32_t offset174;
	volatile uint32_t offset178;
	volatile uint32_t offset17C;
	volatile uint32_t offset180;
	volatile uint32_t offset184;
	volatile uint32_t offset188;
	volatile uint32_t offset18C;
	volatile uint32_t offset190;
	volatile uint32_t offset194;
	volatile uint32_t offset198;
	volatile uint32_t offset19C;
	volatile uint32_t offset1A0;
	volatile uint32_t offset1A4;
	volatile uint32_t offset1A8;
	volatile uint32_t offset1AC;
	volatile uint32_t offset1B0;
	volatile uint32_t offset1B4;
	volatile uint32_t offset1B8;
	volatile uint32_t offset1BC;
	volatile uint32_t offset1C0;
	volatile uint32_t offset1C4;
	volatile uint32_t offset1C8;
	volatile uint32_t offset1CC;
	volatile uint32_t offset1D0;
	volatile uint32_t offset1D4;
	volatile uint32_t offset1D8;
	volatile uint32_t offset1DC;
	volatile uint32_t offset1E0;
	volatile uint32_t offset1E4;
	volatile uint32_t offset1E8;
	volatile uint32_t offset1EC;
	volatile uint32_t offset1F0;
	volatile uint32_t offset1F4;
	volatile uint32_t offset1F8;
	volatile uint32_t offset1FC;
	volatile uint32_t offset200;
	volatile uint32_t offset204;
	volatile uint32_t offset208;
	volatile uint32_t offset20C;
	volatile uint32_t offset210;
	volatile uint32_t offset214;
	volatile uint32_t offset218;
	volatile uint32_t offset21C;
	volatile uint32_t offset220;
	volatile uint32_t offset224;
	volatile uint32_t offset228;
	volatile uint32_t offset22C;
	volatile uint32_t offset230;
	volatile uint32_t offset234;
	volatile uint32_t offset238;
	volatile uint32_t offset23C;
	volatile uint32_t offset240;
	volatile uint32_t offset244;
	volatile uint32_t offset248;
	volatile uint32_t offset24C;
	volatile uint32_t offset250;
	volatile uint32_t offset254;
	volatile uint32_t offset258;
	volatile uint32_t offset25C;
	volatile uint32_t offset260;
	volatile uint32_t offset264;
	volatile uint32_t offset268;
	volatile uint32_t offset26C;
	volatile uint32_t offset270;
	volatile uint32_t offset274;
	volatile uint32_t offset278;
	volatile uint32_t offset27C;
	volatile uint32_t offset280;
	volatile uint32_t offset284;
	volatile uint32_t offset288;
	volatile uint32_t offset28C;
	volatile uint32_t offset290;
	volatile uint32_t offset294;
	volatile uint32_t offset298;
	volatile uint32_t offset29C;
	volatile uint32_t offset2A0;
	volatile uint32_t offset2A4;
	volatile uint32_t offset2A8;
	volatile uint32_t offset2AC;
	volatile uint32_t offset2B0;
	volatile uint32_t offset2B4;
	volatile uint32_t offset2B8;
	volatile uint32_t offset2BC;
	volatile uint32_t offset2C0;
	volatile uint32_t offset2C4;
	volatile uint32_t offset2C8;
	volatile uint32_t offset2CC;
	volatile uint32_t offset2D0;
	volatile uint32_t offset2D4;
	volatile uint32_t offset2D8;
	volatile uint32_t offset2DC;
	volatile uint32_t offset2E0;
	volatile uint32_t offset2E4;
	volatile uint32_t offset2E8;
	volatile uint32_t offset2EC;
	volatile uint32_t offset2F0;
	volatile uint32_t offset2F4;
	volatile uint32_t offset2F8;
	volatile uint32_t offset2FC;
	volatile uint32_t offset300;
	volatile uint32_t offset304;
	volatile uint32_t offset308;
	volatile uint32_t offset30C;
	volatile uint32_t offset310;
	volatile uint32_t offset314;
	volatile uint32_t offset318;
	volatile uint32_t offset31C;
	volatile uint32_t offset320;
	volatile uint32_t offset324;
	volatile uint32_t offset328;
	volatile uint32_t offset32C;
	volatile uint32_t offset330;
	volatile uint32_t offset334;
	volatile uint32_t offset338;
	volatile uint32_t offset33C;
	volatile uint32_t offset340;
	volatile uint32_t offset344;
	volatile uint32_t offset348;
	volatile uint32_t offset34C;
	volatile uint32_t offset350;
	volatile uint32_t offset354;
	volatile uint32_t offset358;
	volatile uint32_t offset35C;
	volatile uint32_t offset360;
	volatile uint32_t offset364;
	volatile uint32_t offset368;
	volatile uint32_t offset36C;
	volatile uint32_t offset370;
	volatile uint32_t offset374;
	volatile uint32_t offset378;
	volatile uint32_t offset37C;
	volatile uint32_t offset380;
	volatile uint32_t offset384;
	volatile uint32_t offset388;
	volatile uint32_t offset38C;
	volatile uint32_t offset390;
	volatile uint32_t offset394;
	volatile uint32_t offset398;
	volatile uint32_t offset39C;
	volatile uint32_t offset3A0;
	volatile uint32_t offset3A4;
	volatile uint32_t offset3A8;
	volatile uint32_t offset3AC;
	volatile uint32_t offset3B0;
	volatile uint32_t offset3B4;
	volatile uint32_t offset3B8;
	volatile uint32_t offset3BC;
	volatile uint32_t offset3C0;
	volatile uint32_t offset3C4;
	volatile uint32_t offset3C8;
	volatile uint32_t offset3CC;
	volatile uint32_t offset3D0;
	volatile uint32_t offset3D4;
	volatile uint32_t offset3D8;
	volatile uint32_t offset3DC;
	volatile uint32_t offset3E0;
	volatile uint32_t offset3E4;
	volatile uint32_t offset3E8;
	volatile uint32_t offset3EC;
	volatile uint32_t offset3F0;
	volatile uint32_t offset3F4;
	volatile uint32_t offset3F8;
	volatile uint32_t offset3FC;
} IMXRT_REGISTER32_t;

// For FlexRAM config
#define IMXRT_IOMUXC_GPR 	   (*(IMXRT_REGISTER32_t *)0x400AC000)
#define IOMUXC_GPR_GPR14		(IMXRT_IOMUXC_GPR.offset038)
#define IOMUXC_GPR_GPR16		(IMXRT_IOMUXC_GPR.offset040)
#define IOMUXC_GPR_GPR17		(IMXRT_IOMUXC_GPR.offset044)

// These all have "T4_" prefix, just in case. I used these for debugging the boot (led blinking).
#define T4_IMXRT_IOMUXC		(*(IMXRT_REGISTER32_t *)0x401F8000)
#define T4_IOMUXC_SW_MUX_CTL_PAD_GPIO_B0_03	(T4_IMXRT_IOMUXC.offset148)
#define T4_IOMUXC_SW_PAD_CTL_PAD_GPIO_B0_03	(T4_IMXRT_IOMUXC.offset338)
#define T4_IMXRT_IOMUXC_GPR	(*(IMXRT_REGISTER32_t *)0x400AC000)
#define T4_IOMUXC_GPR_GPR27		(T4_IMXRT_IOMUXC_GPR.offset06C)
#define T4_IMXRT_GPIO7		(*(IMXRT_REGISTER32_t *)0x42004000)
#define T4_GPIO7_GDIR			(T4_IMXRT_GPIO7.offset004)
#define T4_GPIO7_DR_SET			(T4_IMXRT_GPIO7.offset084)
#define T4_GPIO7_DR_CLEAR			(T4_IMXRT_GPIO7.offset088)
#define T4_IOMUXC_PAD_DSE(n)				((uint32_t)(((n) & 0x07) << 3))

#endif /* TEENSY4_H_ */

