LOCAL_DIR := $(shell pwd)
MIDDLEWARE_DIR := $(LOCAL_DIR)/../..
include $(MIDDLEWARE_DIR)/base.mak

COMPILE_ROOT := $(LOCAL_DIR)

MODNAME := mkfs
MODNAME += fsck
SUBDIRS =$(MODNAME)


all: subdirs

.PHONY: subdirs $(SUBDIRS) clean
subdirs: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) $(MFLAGS) -C $(COMPILE_ROOT)/$@

clean:
	@for MOD in $(MODNAME);do\
		cd $(COMPILE_ROOT)/$$MOD ;$(MAKE) $(MFLAGS) clean;done

install:
	@for MOD in $(MODNAME);do\
		cd $(COMPILE_ROOT)/$$MOD ;$(MAKE) $(MFLAGS) install;done
