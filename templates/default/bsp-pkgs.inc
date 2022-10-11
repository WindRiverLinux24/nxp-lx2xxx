IMAGE_INSTALL += "i2c-tools"
IMAGE_INSTALL += "can-utils"
IMAGE_INSTALL += " iproute2"

# Install NXP userspace utility
IMAGE_INSTALL += " \
   ${@nxp_supported_archs(["aarch64"], "ceetm", "", d)} \
   ${@nxp_supported_archs(["aarch64"], "dce", "", d)} \
   ${@nxp_supported_archs(["aarch64"], "restool", "", d)} \
"

def nxp_supported_archs(checkarch, truevalue, falsevalue, d):
    """
    nxp sets COMPATIBLE_HOST to aarch64, but no arm, so there would be
    errors when build with multilib, use
    IMAGE_INSTALL_append_aarch64 = "nxp" doesn't work either since
    multilib.bbclass doesn't change DEFAULTTUNE for image recipe, and
    it's the way the system is designed, so use a function to fix the
    problem and it can be removed once nxp supports both aarch64 and arm.
    """
    mlprefix =  d.getVar('MLPREFIX', True)
    if mlprefix:
        variant = d.getVar("BBEXTENDVARIANT", True)
        newtune = d.getVar("DEFAULTTUNE_" + "virtclass-multilib-" + variant, False)
        if newtune in checkarch:
            return truevalue
    elif d.getVar('TARGET_ARCH', True) in checkarch:
            return truevalue

    return falsevalue
