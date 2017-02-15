#

CROSS_COMPILE := $(DEB_HOST_GNU_TYPE)-

txt2mac : main.c
	$(CROSS_COMPILE)gcc -Wall -Os -o $@ $<

