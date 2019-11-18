-include config.mk

TARGET := libAWIspApi.so
LIBS :=

INSTALL_PREFIX = $(shell pwd)

commonSources:= \
	AWIspApi.c

local_CFLAGS := \
	-I./libisp/include/V4l2Camera \
    -I./libisp/include/device \
    -I./libisp/include \
    -I./libisp/isp_dev \
    -I./libisp/isp_tuning \
    -I./libisp \
    -I./


OBJS = $(patsubst %.c, %.c.o, $(commonSources))

$(TARGET):$(OBJS) libisp.so libisp_ini.so
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(local_CFLAGS) -o $@ $^ -fPIC -shared

libisp.so:
	+$(MAKE) -C ./libisp all CPU_VARIANT="$(CPU_VARIANT)" C_LIB_TYPE="$(C_LIB_TYPE)"

#libisp_ini.so:
#	+$(MAKE) -C ./libisp/isp_cfg all

$(OBJS):%.c.o:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(local_CFLAGS) -c $< -o $@ -fPIC

all: $(TARGET)

clean:
	-$(MAKE) -C ./libisp clean
	-rm $(OBJS) $(TARGET)
	-rm *.so

install:
	$(MAKE) -C ./libisp install INSTALL_PREFIX="$(INSTALL_PREFIX)"
	mkdir -p $(INSTALL_PREFIX)/usr/lib
	install -m0755 $(TARGET) $(INSTALL_PREFIX)/usr/lib
	mkdir -p $(INSTALL_PREFIX)/usr/include
	cp -r ./*.h  $(INSTALL_PREFIX)/usr/include
