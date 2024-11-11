COMPATIBLE_MACHINE:nxp-lx2xxx = "nxp-lx2xxx"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"
SRC_URI:nxp-lx2xxx = "git://github.com/nxp-qoriq/dpdk;protocol=https;nobranch=1"
SRC_URI:append:nxp-lx2xxx = " \
            file://0001-meson.build-march-and-mcpu-already-passed-by-Yocto.patch \
"

MESON_BUILDTYPE:nxp-lx2xxx = "release"

PACKAGECONFIG:append:nxp-lx2xxx ??= "openssl"
PACKAGECONFIG[openssl] = ",,openssl"

DPDK_EXAMPLES:nxp-lx2xxx = "all"
EXTRA_OEMESON:append:nxp-lx2xxx = " \
		-Doptimization=3 \
		--cross-file ${S}/config/arm/arm64_poky_linux_gcc \
		-Denable_driver_sdk=true \
		${@bb.utils.contains('DISTRO_FEATURES', 'vpp', '-Dc_args="-Ofast -fPIC -ftls-model=local-dynamic"', '', d)} \
"

RDEPENDS:${PN}:append:nxp-lx2xxx = " bash python3-pyelftools"
RDEPENDS:${PN}:remove:nxp-lx2xxx = "kernel-module-dpdk-extras"
DEPENDS:nxp-lx2xxx = "python3-pyelftools-native"

inherit pkgconfig
