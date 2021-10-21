update_dhcpcd_interface() {
    if [ -e ${D}/etc/default/dhcpcd ]; then
        sed -i -e 's/eth0/eth1/' ${D}/etc/default/dhcpcd
    fi
}

UPDATE_DHCPCD_INTERFACE_FUNC ?= ""
UPDATE_DHCPCD_INTERFACE_FUNC_nxp-lx2xxx = "update_dhcpcd_interface"
do_install[postfuncs] += "${UPDATE_DHCPCD_INTERFACE_FUNC}"
