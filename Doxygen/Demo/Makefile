THIS_DIR      := $(shell dirname $(abspath $(lastword $(MAKEFILE_LIST))))
SOURCE_DIR    := $(abspath $(THIS_DIR))
BUILD_DIR     := $(SOURCE_DIR)/out
BUILD_LIB_DIR := $(SOURCE_DIR)/out/.lib
BUILD_DOC_DIR := $(SOURCE_DIR)/out/.doc
RELEASE_DIR   := $(SOURCE_DIR)/out/release
TARGET_LIB    := libdemo
VERSION       := 0.0.2

CFLAGS        :=

LIB_FILES     :=
LIB_OBJS       = $(LIB_FILES:$(SOURCE_DIR)/%.c=$(BUILD_DIR)/%.o)
HEADERS_FILES := $(wildcard $(SOURCE_DIR)/include/*.h)

CFLAGS        += -I$(SOURCE_DIR)/include \
                 -I$(SOURCE_DIR)/source/conf \
                 -I$(SOURCE_DIR)/source/inc \
			     -I$(SOURCE_DIR)/source/dep

export SOURCE_DIR BUILD_DOC_DIR VERSION

include $(SOURCE_DIR)/source/module.mk

all: lib doc lib_install headers_install doc_install

lib: $(BUILD_LIB_DIR)/$(TARGET_LIB).a

doc:
	$(MAKE) -C doc doc

lib_install:
	@echo Install lib
	@mkdir -p $(RELEASE_DIR)/lib
	@cp $(BUILD_LIB_DIR)/$(TARGET_LIB).a $(RELEASE_DIR)/lib

headers_install:
	@echo Install headers
	@mkdir -p $(RELEASE_DIR)/include
	@cp $(HEADERS_FILES) $(RELEASE_DIR)/include

doc_install:
	@echo Install doc
	@mkdir -p $(RELEASE_DIR)/doc

clean:
	@echo Clean all
	@$(RM) -rf $(BUILD_DIR)

$(BUILD_LIB_DIR)/$(TARGET_LIB).a: $(LIB_OBJS)
	@echo Gen $@
	@mkdir -p $(dir $@)
	@rm -f $@
	@$(AR) -rcs $@ $(LIB_OBJS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@echo Gen $@
	@mkdir -p $(dir $@)
	@echo $(sort $(CFLAGS)) > $(basename $@)_CFLAGS;
	@$(CC) @$(basename $@)_CFLAGS -MMD -MF $(basename $@).d -c $< -o $@

.PHONY: all lib doc lib_install headers_install doc_install clean
