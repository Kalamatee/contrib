MAKE   = make
CC     = vc +aosppc
CP	   = copy
RM     = delete
MAKEDT = RX REXX:MakeDT.rexx

# Change these as required
OPTIMIZE = -O3 -size
DEBUG = 
CFLAGS = $(OPTIMIZE) $(DEBUG) -I. -Iinclude

# Flags passed to gcc during linking
LINK = $(OPTIMIZE) $(DEBUG)

# Additional linker libraries
LIBS = 

# Name of the "thing" to build
TARGET = ico.datatype
DT_DESC = ICO
VERSION = 52

# Source code files used in this project
# Add any additional files to this line

OBJS = init.o ico_class.o

# -------------------------------------------------------------
# Nothing should need changing below this line

# Rules for building
all: $(TARGET) $(DT_DESC)

$(TARGET): $(OBJS)
	$(CC) $(LINK) -final -nostdlib -o $@ $^ $(LIBS)

init.o: $(TARGET)_rev.h

$(DT_DESC): $(DT_DESC).dt
	$(MAKEDT) $< $@

.PHONY: install
install: all
	$(CP) $(TARGET) SYS:Classes/DataTypes/
	$(CP) $(DT_DESC) DEVS:DataTypes/

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS)

.PHONY: distclean
distclean:
	$(RM) $(OBJS)

.PHONY: revision
revision:
	bumprev $(VERSION) $(TARGET)
