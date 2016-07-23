export COG_VERSION=V2
export PANEL_VERSION=V230_G2
export LDFLAGS=-lmraa

/etc/init.d/epd-fuse stop
make edison-clean
make edison
make edison-install

/etc/init.d/epd-fuse start

cat /dev/epd/panel
python /opt/puzzlebox/deja/deja_hardware/deja_hardware/test_eink.py
