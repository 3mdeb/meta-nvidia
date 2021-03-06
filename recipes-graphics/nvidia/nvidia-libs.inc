# Read this first: https://devtalk.nvidia.com/default/topic/915640/unix-graphics-announcements-and-news/multiple-glx-client-libraries-in-the-nvidia-linux-driver-installer-package/

# xorg-abi RPROVIDES are created at runtime
python populate_packages_prepend() {
    d.appendVar("RDEPENDS_xserver-xorg-video-nvidia", " xorg-abi-video-23")
}

RDEPENDS_libegl-nvidia = "libnvidia-eglcore"
RDEPENDS_libgles1-nvidia = "libgles1 libnvidia-eglcore"
RDEPENDS_libgles2-nvidia = "libgles2 libnvidia-eglcore"
RDEPENDS_xserver-xorg-video-nvidia = " \
    xserver-xorg-module-libwfb \
    "
RDEPENDS_libglx-nvidia = "libnvidia-glcore libx11 libxext libglvnd"
RDEPENDS_libnvidia-glcore = ""
RDEPENDS_libnvidia-eglcore = ""
RDEPENDS_libnvidia-ml = ""
RDEPENDS_libnvidia-fbc = "libgl libx11 libxext"
RDEPENDS_libnvidia-ifr = "libgl libx11"
RDEPENDS_libnvidia-encode = "libcuda libnvcuvid"
RDEPENDS_libnvidia-opencl = ""
RDEPENDS_libnvidia-compiler = ""
RDEPENDS_libnvidia-ptxjitcompiler = ""
RDEPENDS_libnvidia-cfg = ""
RDEPENDS_libnvidia-fatbinaryloader = ""
RDEPENDS_libnvcuvid = ""
RDEPENDS_libcuda = "libnvidia-fatbinaryloader nvidia-persistenced"
RDEPENDS_nvidia-vdpau-driver = "libvdpau libx11 libxext"
RDEPENDS_nvidia-settings = " \
    cairo \
    gdk-pixbuf \
    glib-2.0 \
    gtk+ \
    gtk+3 \
    jansson \
    pango \
    cairo \
    libx11 \
    libxxf86vm \
    "

RDEPENDS_nvidia-debugdump = ""
RDEPENDS_nvidia-smi = ""
RDEPENDS_nvidia-modprobe = ""
RDEPENDS_nvidia-xconfig = ""
RDEPENDS_nvidia-cuda-mps = ""
RDEPENDS_nvidia-persistenced = "libnvidia-cfg"

RRECOMMENDS_libcuda = "nvidia-smi nvidia-persistenced nvidia-cuda-mps"
RRECOMMENDS_nvidia-settings = "libnvidia-ml nvidia-vdpau-driver libglx-nvidia"

do_install_append() {
    ### libraries ###
    install -d ${D}${libdir}

    # libegl-nvidia
    install -m 0644 ${NVIDIA_SRC}/libEGL_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libEGL_nvidia.so.${PV} ${D}${libdir}/libEGL_nvidia.so.0

    # libgles1-nvidia
    install -m 0644 ${NVIDIA_SRC}/libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLESv1_CM_nvidia.so.${PV} ${D}${libdir}/libGLESv1_CM_nvidia.so.1

    # libgles2-nvidia
    install -m 0644 ${NVIDIA_SRC}/libGLESv2_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLESv2_nvidia.so.${PV} ${D}${libdir}/libGLESv2_nvidia.so.2

    # libglx-nvidia
    install -m 0644 ${NVIDIA_SRC}/libGLX_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_nvidia.so.0
    ln -sf libGLX_nvidia.so.${PV} ${D}${libdir}/libGLX_indirect.so.0

    # libnvidia-glcore
    install -m 0644 ${NVIDIA_SRC}/tls/libnvidia-tls.so.${PV} ${D}${libdir}/
    install -m 0644 ${NVIDIA_SRC}/libnvidia-glcore.so.${PV} ${D}${libdir}/

    # libnvidia-eglcore
    install -m 0644 ${NVIDIA_SRC}/libnvidia-eglcore.so.${PV} ${D}${libdir}/
    install -m 0644 ${NVIDIA_SRC}/libnvidia-glsi.so.${PV} ${D}${libdir}/

    # libnvidia-ml
    install -m 0644 ${NVIDIA_SRC}/libnvidia-ml.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ml.so.${PV} ${D}${libdir}/libnvidia-ml.so.1

    # libnvidia-fbc
    install -m 0644 ${NVIDIA_SRC}/libnvidia-fbc.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-fbc.so.${PV} ${D}${libdir}/libnvidia-fbc.so.1

    # libnvidia-ifr
    install -m 0644 ${NVIDIA_SRC}/libnvidia-ifr.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-ifr.so.${PV} ${D}${libdir}/libnvidia-ifr.so.1

    # libnvidia-encode
    install -m 0644 ${NVIDIA_SRC}/libnvidia-encode.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-encode.so.${PV} ${D}${libdir}/libnvidia-encode.so.1

    # libnvidia-opencl
    install -m 0644 ${NVIDIA_SRC}/libnvidia-opencl.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-opencl.so.${PV} ${D}${libdir}/libnvidia-opencl.so.1

    # libnvidia-compiler
    install -m 0644 ${NVIDIA_SRC}/libnvidia-compiler.so.${PV} ${D}${libdir}/

    # libnvidia-ptxjitcompiler
    install -m 0644 ${NVIDIA_SRC}/libnvidia-ptxjitcompiler.so.${PV} ${D}${libdir}/

    # libnvidia-cfg
    install -m 0644 ${NVIDIA_SRC}/libnvidia-cfg.so.${PV} ${D}${libdir}/
    ln -sf libnvidia-cfg.so.${PV} ${D}${libdir}/libnvidia-cfg.so.1

    # libnvidia-fatbinaryloader
    install -m 0644 ${NVIDIA_SRC}/libnvidia-fatbinaryloader.so.${PV} ${D}${libdir}/

    # libcuda
    install -m 0644 ${NVIDIA_SRC}/libcuda.so.${PV} ${D}${libdir}/
    ln -sf libcuda.so.${PV} ${D}${libdir}/libcuda.so.1

    # libnvcuvid
    install -m 0644 ${NVIDIA_SRC}/libnvcuvid.so.${PV} ${D}${libdir}/
    ln -sf libnvcuvid.so.${PV} ${D}${libdir}/libnvcuvid.so.1

    # nvidia-vdpau-driver
    install -m 0644 ${NVIDIA_SRC}/libvdpau_nvidia.so.${PV} ${D}${libdir}/
    ln -sf libvdpau_nvidia.so.${PV} ${D}${libdir}/libvdpau_nvidia.so.1

    # xserver-xorg-video-nvidia
    install -d ${D}${libdir}/xorg/modules/drivers
    install -d ${D}${libdir}/xorg/modules/extensions
    install -m 0644 ${NVIDIA_SRC}/nvidia_drv.so ${D}${libdir}/xorg/modules/drivers/
    install -m 0644 ${NVIDIA_SRC}/libglx.so.${PV} ${D}${libdir}/xorg/modules/extensions/libglx.so
    install -m 0644 ${NVIDIA_SRC}/libnvidia-wfb.so.${PV} ${D}${libdir}/xorg/modules

    ### executables ###
    install -d ${D}${bindir}

    # nvidia-settings
    install -m 755 -D ${NVIDIA_SRC}/nvidia-settings ${D}${bindir}/nvidia-settings
    install -m 0644 ${NVIDIA_SRC}/libnvidia-gtk2.so.${PV} ${D}${libdir}/
    install -m 0644 ${NVIDIA_SRC}/libnvidia-gtk3.so.${PV} ${D}${libdir}/

    # nvidia-debugdump
    install -m 755 -D ${NVIDIA_SRC}/nvidia-debugdump ${D}${bindir}/nvidia-debugdump

    # nvidia-smi
    install -m 755 -D ${NVIDIA_SRC}/nvidia-smi ${D}${bindir}/nvidia-smi

    # nvidia-modprobe
    install -m 755 -D ${NVIDIA_SRC}/nvidia-modprobe ${D}${bindir}/nvidia-modprobe

    # nvidia-xconfig
    install -m 755 -D ${NVIDIA_SRC}/nvidia-xconfig ${D}${bindir}/nvidia-xconfig

    # nvidia-cuda-mps
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-server ${D}${bindir}/nvidia-cuda-mps-server
    install -m 755 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control ${D}${bindir}/nvidia-cuda-mps-control

    # nvidia-persistenced
    install -m 755 -D ${NVIDIA_SRC}/nvidia-persistenced ${D}${bindir}/nvidia-persistenced

    ### nvidia-doc ### - it should also be split into individual -dev pkgs
    install -d ${D}${mandir}/man1

    install -d ${D}${datadir}/doc/nvidia/html
    for html_file in ${NVIDIA_SRC}/html/*.html
    do
        install -m 0644 $html_file ${D}${datadir}/doc/nvidia
    done

    install -m 0644 ${NVIDIA_SRC}/NVIDIA_Changelog ${D}${datadir}/doc/nvidia/
    install -m 0644 ${NVIDIA_SRC}/README.txt ${D}${datadir}/doc/nvidia/
    install -m 444 -D ${NVIDIA_SRC}/nvidia-settings.1.gz ${D}${mandir}/man1/nvidia-settings.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-smi.1.gz ${D}${mandir}/man1/nvidia-smi.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-xconfig.1.gz ${D}${mandir}/man1/nvidia-xconfig.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-cuda-mps-control.1.gz ${D}${mandir}/man1/nvidia-cuda-mps-control.1.gz
    install -m 444 -D ${NVIDIA_SRC}/nvidia-persistenced.1.gz ${D}${mandir}/man1/nvidia-persistenced.1.gz
}

PACKAGES =+ " \
    xserver-xorg-video-nvidia \
    libegl-nvidia \
    libglx-nvidia \
    libgles1-nvidia \
    libgles2-nvidia \
    libnvidia-glcore \
    libnvidia-eglcore \
    libnvidia-ml \
    libnvidia-fbc \
    libnvidia-ifr \
    libnvidia-encode \
    libnvidia-opencl \
    libnvidia-compiler \
    libnvidia-ptxjitcompiler \
    libnvidia-cfg \
    libnvidia-fatbinaryloader \
    libnvcuvid \
    libcuda \
    nvidia-vdpau-driver \
    nvidia-settings \
    nvidia-debugdump \
    nvidia-smi \
    nvidia-modprobe \
    nvidia-xconfig \
    nvidia-cuda-mps \
    nvidia-persistenced \
    "

do_make_scripts[noexec] = "1"

FILES_${PN} += " \
    ${libdir} \
    ${bindir} \
    "

FILES_${PN}-doc += " \
    ${mandir} \
    ${datadir}/doc/nvidia \
    "

FILES_xserver-xorg-video-nvidia += " \
    ${libdir}/xorg/modules/extensions/libglx.so \
    ${libdir}/xorg/modules/drivers/nvidia_drv.so \
    ${libdir}/xorg/modules/libnvidia-wfb.so.${PV} \
    ${sysconfdir}/nvidia-drm-outputclass.conf \
    "

FILES_libegl-nvidia = " \
    ${libdir}/libEGL_nvidia.so.${PV} \
    ${libdir}/libEGL_nvidia.so.0 \
    "

FILES_libgles1-nvidia = " \
    ${libdir}/libGLESv1_CM_nvidia.so.${PV} \
    ${libdir}/libGLESv1_CM_nvidia.so.1 \
    "

FILES_libgles2-nvidia = " \
    ${libdir}/libGLESv2_nvidia.so.${PV} \
    ${libdir}/libGLESv2_nvidia.so.2 \
    "

FILES_libglx-nvidia = " \
    ${libdir}/libGLX_nvidia.so.${PV} \
    ${libdir}/libGLX_nvidia.so.0 \
    ${libdir}/libGLX_indirect.so.0 \
    "

FILES_libnvidia-glcore = " \
    ${libdir}/libnvidia-tls.so.${PV} \
    ${libdir}/libnvidia-glcore.so.${PV} \
    "

FILES_libnvidia-eglcore = " \
    ${libdir}/libnvidia-eglcore.so.${PV} \
    ${libdir}/libnvidia-glsi.so.${PV} \
    "

FILES_libnvidia-ml = " \
    ${libdir}/libnvidia-ml.so.${PV} \
    ${libdir}/libnvidia-ml.so.1 \
    "

FILES_libnvidia-fbc = " \
    ${libdir}/libnvidia-fbc.so.${PV} \
    ${libdir}/libnvidia-fbc.so.1 \
    "

FILES_libnvidia-ifr = " \
    ${libdir}/libnvidia-ifr.so.${PV} \
    ${libdir}/libnvidia-ifr.so.1 \
    "

FILES_libnvidia-encode = " \
    ${libdir}/libnvidia-encode.so.${PV} \
    ${libdir}/libnvidia-encode.so.1 \
    "

FILES_libnvidia-opencl = " \
    ${libdir}/libnvidia-opencl.so.${PV} \
    ${libdir}/libnvidia-opencl.so.1 \
    "

FILES_libnvidia-compiler = " \
    ${libdir}/libnvidia-compiler.so.${PV} \
    "

FILES_libnvidia-ptxjitcompiler = " \
    ${libdir}/libnvidia-ptxjitcompiler.so.${PV} \
    "

FILES_libnvidia-cfg = " \
    ${libdir}/libnvidia-cfg.so.${PV} \
    ${libdir}/libnvidia-cfg.so.1 \
    "

FILES_libnvidia-fatbinaryloader = " \
    ${libdir}/libnvidia-fatbinaryloader.so.${PV} \
    "

FILES_libcuda = " \
    ${libdir}/libcuda.so.${PV} \
    ${libdir}/libcuda.so.1 \
    "

FILES_libnvcuvid = " \
    ${libdir}/libnvcuvid.so.${PV} \
    ${libdir}/libnvcuvid.so.1 \
    "

FILES_nvidia-vdpau-driver = " \
    ${libdir}/libvdpau_nvidia.so.${PV} \
    ${libdir}/libvdpau_nvidia.so.1 \
    "

FILES_nvidia-settings = " \
    ${bindir}/nvidia-settings \
    ${libdir}/libnvidia-gtk2.so.${PV} \
    ${libdir}/libnvidia-gtk3.so.${PV} \
    "

FILES_nvidia-debugdump= "${bindir}/nvidia-debugdump"
FILES_nvidia-smi= "${bindir}/nvidia-smi"
FILES_nvidia-modprobe = "${bindir}/nvidia-modprobe"
FILES_nvidia-xconfig = "${bindir}/nvidia-xconfig"
FILES_nvidia-cuda-mps= "${bindir}/nvidia-cuda-mps-control ${bindir}/nvidia-cuda-mps-server"
FILES_nvidia-persistenced = "${bindir}/nvidia-persistenced"


INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
INHIBIT_PACKAGE_STRIP = "1"
# INSANE_SKIP_libgl-nvidia_append = " ldflags"

INSANE_SKIP_${PN}_append = " ldflags already-stripped"
INSANE_SKIP_xserver-xorg-video-nvidia = "ldflags already-stripped"
INSANE_SKIP_libegl-nvidia = "ldflags already-stripped"
INSANE_SKIP_libglx-nvidia = "ldflags already-stripped"
INSANE_SKIP_libgles1-nvidia = "ldflags already-stripped"
INSANE_SKIP_libgles2-nvidia = "ldflags already-stripped"
INSANE_SKIP_libnvidia-glcore = "ldflags already-stripped"
INSANE_SKIP_libnvidia-eglcore = "ldflags already-stripped"
INSANE_SKIP_libnvidia-ml = "ldflags already-stripped"
INSANE_SKIP_libnvidia-fbc = "ldflags already-stripped"
INSANE_SKIP_libnvidia-ifr = "ldflags already-stripped"
INSANE_SKIP_libnvidia-encode = "ldflags already-stripped"
INSANE_SKIP_libnvidia-opencl = "ldflags already-stripped"
INSANE_SKIP_libnvidia-compiler = "ldflags already-stripped"
INSANE_SKIP_libnvidia-ptxjitcompiler = "ldflags already-stripped"
INSANE_SKIP_libnvidia-cfg = "ldflags already-stripped"
INSANE_SKIP_libnvidia-fatbinaryloader = "ldflags already-stripped"
INSANE_SKIP_libnvcuvid = "ldflags already-stripped"
INSANE_SKIP_libcuda = "ldflags already-stripped"
INSANE_SKIP_nvidia-vdpau-driver = "ldflags already-stripped"
INSANE_SKIP_nvidia-settings = "ldflags already-stripped"
INSANE_SKIP_nvidia-debugdump = "ldflags already-stripped"
INSANE_SKIP_nvidia-smi = "ldflags already-stripped"
INSANE_SKIP_nvidia-modprobe = "ldflags already-stripped"
INSANE_SKIP_nvidia-xconfig = "ldflags already-stripped"
INSANE_SKIP_nvidia-cuda-mps = "ldflags already-stripped"
INSANE_SKIP_nvidia-persistenced = "ldflags already-stripped"
