IMAGE_INSTALL += "i2c-tools"
IMAGE_INSTALL += "can-utils"
IMAGE_INSTALL += " iproute2"
IMAGE_INSTALL += " iproute2-tc"
IMAGE_INSTALL += " ceetm dce restool"

require conf/make_nxp_lx2xxx_wic.inc

# BSP's default template
PROPRIETATY_LEGAL_WARNING = "WARNING: Building bootloader will involve NXP proprietary firmware. Please consult \
your legal department should you have questions regarding the licensing terms and obligations."
BANNER[nxp-lx2xxx_default] = "${@bb.utils.contains('CUSTOMER_BUILD_BOOTLOADER', '1', '${PROPRIETATY_LEGAL_WARNING}', '', d)}"

