# Makefile

PANEL_VERSION ?= NOT-SET
EPD_IO ?= epd_io.h

SUPPORTED_PANEL_VERSIONS = V110_G1 V230_G2 V231_G2

.PHONY: help
help:
	@echo
	@echo Please use the platform specific targets:
	@echo
	@echo Version Setting:
	@echo '  G1 options:   PANEL_VERSION=V110_G1'
	@echo '  G2 options:   PANEL_VERSION=V230_G2  or  PANEL_VERSION=V231_G2'
	@echo
	@echo 'currently:      PANEL_VERSION=${PANEL_VERSION}'
	@echo
	@echo Custom I/O pin arrangement can be selected, add: EPD_IO=filename.h
	@echo '(the file will be taken from RaspberryPi or BeagleBone directory as appropriate)'
	@echo currently: EPD_IO=${EPD_IO}
	@echo
	@echo Raspberry Pi:
	@echo '   $(MAKE) rpi            = build all targets'
	@echo '   $(MAKE) rpi-install    = install fuse driver in PREFIX'
	@echo '   $(MAKE) rpi-T          = build only target T'
	@echo
	@echo BeagleBone
	@echo '   $(MAKE) bb             = build all targets'
	@echo '   $(MAKE) bb-install     = install fuse driver in PREFIX'
	@echo '   $(MAKE) bb-T           = build only target T'
	@echo
	@echo Edison
	@echo '   $(MAKE) edison             = build all targets'
	@echo '   $(MAKE) edison-install     = install fuse driver in PREFIX'
	@echo '   $(MAKE) edison-T           = build only target T'
	@echo
	@echo Where T is one of:
	@echo '    all install remove clean'
	@echo '    epd_test gpio_test epd_fuse'
	@echo
	@echo Notes:
	@echo 1. the default install PREFIX=/usr
	@echo 2. if not root must use sudo when installing
	@echo

.PHONY: all
all: help

.PHONY: version-error
version-error:
	@echo
	@echo "ERROR:  PANEL_VERSION='${PANEL_VERSION}' is incorrect"
	@echo
	@echo please set to one of:
	@echo
	@for v in ${SUPPORTED_PANEL_VERSIONS} ; \
	 do \
	   echo "  PANEL_VERSION='$${v}'" ; \
	 done
	@echo
	@echo For more information, run:
	@echo
	@echo '  $(MAKE) help'
	@echo

.PHONY: version-check
version-check:
	@flag= ; \
	 for v in ${SUPPORTED_PANEL_VERSIONS} ; \
	 do \
	   [ X"$${v}" = X"${PANEL_VERSION}" ] && flag=x ; \
	 done ; \
	 [ -z "$${flag}" ] && $(MAKE) version-error && false || true


# Raspberry Pi targets
# --------------------

.PHONY: rpi raspberrypi
rpi raspberrypi: version-check
	$(MAKE) PLATFORM=../RaspberryPi PANEL_VERSION="${PANEL_VERSION}" EPD_IO="${EPD_IO}" -C driver-common

rpi-%: version-check
	$(MAKE) PLATFORM=../RaspberryPi PANEL_VERSION="${PANEL_VERSION}" EPD_IO="${EPD_IO}" -C driver-common $*


# BeagleBone Black targets
# ------------------------

.PHONY: bb beaglebone
bb beaglebone: version-check
	$(MAKE) PLATFORM=../BeagleBone PANEL_VERSION="${PANEL_VERSION}" EPD_IO="${EPD_IO}" -C driver-common

bb-%: version-check
	$(MAKE) PLATFORM=../BeagleBone PANEL_VERSION="${PANEL_VERSION}" EPD_IO="${EPD_IO}" -C driver-common $*
	
# Edison targets
# ------------------------

.PHONY: edison
edison: version-check
	$(MAKE) PLATFORM=../Edison PANEL_VERSION="${PANEL_VERSION}" EPD_IO="${EPD_IO}" -C driver-common

edison-%: version-check
	$(MAKE) PLATFORM=../Edison PANEL_VERSION="${PANEL_VERSION}" EPD_IO="${EPD_IO}" -C driver-common $*
