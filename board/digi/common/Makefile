#
# (C) Copyright 2015
# Digi International, Inc
#
# SPDX-License-Identifier:      GPL-2.0+
#

MINIMAL=

ifdef CONFIG_SPL_BUILD
ifdef CONFIG_SPL_INIT_MINIMAL
MINIMAL=y
endif
endif

ifdef MINIMAL
# necessary to create built-in.o
obj- := __dummy__.o
else
$(if $(CONFIG_CMD_NVRAM), $(shell mkdir -p $(obj)cmd_nvram/lib/src))
$(if $(CONFIG_CMD_BOOTSTREAM), $(shell mkdir -p $(obj)cmd_bootstream))

obj-$(CONFIG_CMD_BSP) += cmd_bsp.o \
	  cmd_compat.o \
	  cmd_video.o \
	  cmd_chkimg.o \
	  vscanf.o \
	  atoi.o \
	  safe_strcat.o \
	  helper.o
obj-$(CONFIG_CMD_BOOTSTREAM) += cmd_bootstream/bch.o \
				cmd_bootstream/ncb.o \
				cmd_bootstream/cmd_bootstream.o \
				cmd_bootstream/mxsboot.o
obj-$(CONFIG_MXS_OTP) += cmd_mxsotp.o
obj-$(CONFIG_CMD_NVRAM) += cmd_nvram/mtd.o \
	  cmd_nvram/lib/src/nvram.o \
	  cmd_nvram/lib/src/nvram_cmdline.o \
	  cmd_nvram/cmd.o \
	  cmd_nvram/nvram_priv_uboot.o \
	  cmd_nvram/env.o \
	  cmd_nvram/partition.o
ifdef CONFIG_HAS_HWID
obj-y += cmd_hwid.o
obj-$(CONFIG_CC6) += ccimx6_hwid.o
endif
obj-$(CONFIG_HAS_CARRIERBOARD_VERSION) += cmd_board.o
obj-$(CONFIG_HAS_CARRIERBOARD_ID) += cmd_board.o
obj-$(CONFIG_AUTO_BOOTSCRIPT) += helper.o
obj-$(CONFIG_CMD_UPDATE_MMC) += cmd_update_mmc.o helper.o helper_mmc.o
obj-$(CONFIG_CMD_UPDATE_NAND) += cmd_update_nand.o helper.o helper_nand.o
obj-$(CONFIG_CMD_DBOOT) += cmd_dboot.o helper.o
obj-$(CONFIG_CMD_PMIC) += cmd_pmic.o
obj-$(CONFIG_HAS_TRUSTFENCE) += cmd_trustfence.o
obj-$(CONFIG_MCA_CC6UL_TAMPER) += tamper.o
endif
