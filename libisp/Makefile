include ../config.mk

TARGET := libisp.so
SUBLIB_DIR = ./..

commonSources:= \
	isp.c \
	isp_events/events.c \
    isp_tuning/isp_tuning.c \
    isp_manage/isp_manage.c

local_CFLAGS := \
	-I./include/V4l2Camera \
    -I./include/device \
    -I./include \
    -I./isp_dev \
    -I./isp_tuning \
    -I./

SUBDIRS = ./iniparser ./isp_cfg ./isp_dev

WHOLE_STATIC_LIB := \
	libisp_ae.a \
	libisp_af.a \
	libisp_afs.a \
	libisp_awb.a \
	libisp_base.a \
	libisp_gtm.a \
	libisp_iso.a \
	libisp_math.a \
	libisp_md.a \
	libisp_pltm.a \
	libisp_rolloff.a \
	libmatrix.a

WHOLE_DYNAMIC_LIB := \
	libisp_ae.so \
	libisp_af.so \
	libisp_afs.so \
	libisp_awb.so \
	libisp_base.so \
	libisp_gtm.so \
	libisp_iso.so \
	libisp_math.so \
	libisp_md.so \
	libisp_pltm.so \
	libisp_rolloff.so \
	libmatrix.so

OBJS = $(patsubst %.c, %.c.o, $(commonSources))

INIPARSER_TARGET := libiniparser.a
ISP_INI_TARGET := libisp_ini.so
ISP_DEV_TARGET := libisp_dev.a

WHOLE_LIB := $(WHOLE_DYNAMIC_LIB)


$(TARGET):$(OBJS) $(INIPARSER_TARGET) $(ISP_INI_TARGET) $(ISP_DEV_TARGET) $(WHOLE_LIB)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBS) $(local_CFLAGS) -o $@ $^ -fPIC -shared

$(OBJS):%.c.o:%.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(local_CFLAGS) -c $< -o $@ -fPIC

$(INIPARSER_TARGET):
	+$(MAKE) -C ./iniparser all

$(ISP_INI_TARGET):
	+$(MAKE) -C ./isp_cfg all

$(ISP_DEV_TARGET):
	+$(MAKE) -C ./isp_dev all

$(WHOLE_LIB):
	+$(MAKE) -C ./out all CPU_VARIANT="$(CPU_VARIANT)" C_LIB_TYPE="$(C_LIB_TYPE)"

all: $(TARGET)
	install -m0755 *.so $(SUBLIB_DIR)

clean:
	-$(MAKE) -C ./iniparser clean
	-$(MAKE) -C ./isp_cfg clean
	-$(MAKE) -C ./isp_dev clean
	-rm $(OBJS) $(TARGET) $(INIPARSER_TARGET) $(ISP_INI_TARGET) $(ISP_DEV_TARGET) $(WHOLE_LIB)
	-rm libiniparser.so libisp_dev.so

install:
	$(MAKE) -C ./iniparser install INSTALL_PREFIX="$(INSTALL_PREFIX)"
	$(MAKE) -C ./isp_cfg install INSTALL_PREFIX="$(INSTALL_PREFIX)"
	$(MAKE) -C ./isp_dev install INSTALL_PREFIX="$(INSTALL_PREFIX)"
	$(MAKE) -C ./out install INSTALL_PREFIX="$(INSTALL_PREFIX)" CPU_VARIANT="$(CPU_VARIANT)" C_LIB_TYPE="$(C_LIB_TYPE)"
	mkdir -p $(INSTALL_PREFIX)/usr/lib
	install -m0755 $(TARGET) $(INSTALL_PREFIX)/usr/lib
