
TARGET = game.elf
OBJS = game.o romdisk.o class/player.o class/drawable.o class/entity.o 
KOS_ROMDISK_DIR = romdisk

all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

KOS_LOCAL_CFLAGS = -I$(KOS_BASE)/addons/zlib
	
clean: rm-elf
	-rm -f $(OBJS)
	
rm-elf:
	-rm -f $(TARGET) romdisk.*

$(TARGET): $(OBJS) 
	kos-c++ -o $(TARGET) $(OBJS) -lpng -lz

wfont.o: wfont.bin
	$(KOS_BASE)/utils/bin2o/bin2o wfont.bin wfont wfont.o

run: $(TARGET)
	$(KOS_LOADER) $(TARGET)

dist: $(TARGET)
	-rm -f $(OBJS) romdisk_boot.img
	$(KOS_STRIP) $(TARGET)


