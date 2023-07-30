do_image_wic[prefuncs] += "nxp_lx2xxx_wic"

nxp_lx2xxx_wic() {
	if [ "${CUSTOMER_BUILD_BOOTLOADER}" = "0" ] && \
		[ ! -f ${DEPLOY_DIR_IMAGE}/firmware_lx2160ardb-rev2_uboot_sdboot.img ]; then
		# Create a dummy bootloader file.
		echo "This is a dummy bootloader file." > "${DEPLOY_DIR_IMAGE}/firmware_lx2160ardb-rev2_uboot_sdboot.img"
	fi
}
