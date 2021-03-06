/*
 * Copyright 2014 Digi International Inc. All Rights Reserved.
 */

/*
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#ifndef __HWID_H_
#define __HWID_H_

struct ccimx6_hwid {
	unsigned char	location;	/* location */
	u8		variant;	/* module variant */
	unsigned char	hv;		/* hardware version */
	unsigned char	cert;		/* type of wifi certification */
	u8		year;		/* manufacturing year */
	u8		week;		/* manufacturing week */
	u8		genid;		/* generator id */
	u32		sn;		/* serial number */
	unsigned char	wid;		/* wireless ID */
};

enum imx6_cpu {
	IMX6_NONE = 0,	/* Reserved */
	IMX6Q,		/* Quad */
	IMX6D,		/* Dual */
	IMX6DL,		/* Dual-Lite */
	IMX6S,		/* Solo */
	IMX6UL,		/* UltraLite */
};

enum digi_cert{
	DIGI_CERT_USA = 0,
	DIGI_CERT_INTERNATIONAL,
	DIGI_CERT_JAPAN,

	DIGI_MAX_CERT,
};

struct ccimx6_variant {
	enum imx6_cpu	cpu;
	const int	sdram;
	u8		capabilities;
	const char	*id_string;
};

/* RAM size */
#define MEM_2GB		0x80000000
#define MEM_1GB		0x40000000
#define MEM_512MB	0x20000000
#define MEM_256MB	0x10000000

/* Capabilities */
#define	CCIMX6_HAS_WIRELESS	(1 << 0)
#define	CCIMX6_HAS_BLUETOOTH	(1 << 1)
#define	CCIMX6_HAS_KINETIS	(1 << 2)
#define	CCIMX6_HAS_EMMC		(1 << 3)

void fdt_fixup_hwid(void *fdt);

#ifdef CONFIG_CC6
void ccimx6_print_hwid(u32 *buf);
void ccimx6_print_manufid(u32 *buf);
int ccimx6_manufstr_to_hwid(int argc, char *const argv[], u32 *val);
int ccimx6_get_hwid(struct ccimx6_hwid *hwid);
void ccimx6_fdt_fixup_hwid(void *fdt, struct ccimx6_hwid *hwid);
#endif

#endif	/* __HWID_H_ */
