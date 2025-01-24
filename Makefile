#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************
#******************************************************************************
# Makefile done by Pablo Rodriguez, Colombia - Bogotá - January 2025
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. 
#
#*****************************************************************************
#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#		* <FILE>.i    - Builds <FILE>.i preprocessor file
#		* <FILE>.asm  - Builds <FILE>.asm assembly file
#		* <FILE>.d    - Builds <FILE>.d dependency file
#		* <FILE>.o    - Builds <FILE>.o object file
#		* compile-all - Builds all source files 
#		* build       - Builds and links all source files
#		* clean		  - Removes all generated files
#
# Platform Overrides:

#		PLATFORM - Can be MSP432 or HOST
#		CC	     - Compiler
#		LD		 - Linker
#		CFLAGS   - Compiler flags depend of PLATFORM selection
#		SOURCES  - C files depend of PLATFORM selection
# 		LDFLAGS  - Linker flags depend of PLATFORM selection
#		OBJ_DUMP - objdump tool depend of PLATFORM selection
#		SIZE_CC  - Size tool depend of PLATFORM selection
#
#------------------------------------------------------------------------------

# Include sources and include files
include sources.mk

# --------------Platform Overrides--------------------
#-----General Variables ------------------------------------

CPU =cortex-m4
ARCH =arm
SPECS =nosys.specs
LINKER_FILE =msp432p401r.lds
TARGET =c1m4


PLATFORM = MSP432
SOURCES = $(SOURCES_MSP432)

# Check what platform is selected ?
ifeq ($(PLATFORM),HOST)

CC =gcc 
LD =ld
# Plataform Specific Flags
CFLAGS = -DHOST
SOURCES = $(SOURCES_HOST)
LDFLAGS =-Wl,-Map=$(TARGET).map
OBJ_DUMP = objdump --disassemble
SIZE_CC =size
endif

ifeq ($(PLATFORM),MSP432)

CC =arm-none-eabi-gcc 
LD =arm-none-eabi-ld
# Plataform Specific Flags
CFLAGS =-DMSP432 -mcpu=$(CPU) -m$(ARCH) -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
SOURCES = $(SOURCES_MSP432)
LDFLAGS =-Wl,-Map=$(TARGET).map -T ../$(LINKER_FILE)
OBJ_DUMP = arm-none-eabi-objdump --disassemble
SIZE_CC =arm-none-eabi-size
endif

# ---------------------FLAGS ---------------------------
CPPFLAGS =-g -O0 -std=c99 -Wall -Werror $(INCLUDES_DIR)


OBJS = $(SOURCES:.c=.o)
ASSE = $(SOURCES:.c=.asm)
PREP = $(SOURCES:.c=.i)
DEPD = $(SOURCES:.c=.d)

# ---------------------------Build process

.PHONY: build
build: all
#-------------------------------------------------------------
.PHONY: all
all: $(TARGET).out
	

$(TARGET).out: $(OBJS)
	make $(PREP)
	make $(ASSE)
	make $(DEPD)
	$(CC) $(CPPFLAGS) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $@
#Size in general
	$(SIZE_CC) -Btd $@ 
#Size in hex
#	$(SIZE_CC) -Bx $@ 
#Size in decimal
#	$(SIZE_CC) -Ad $@ 
# All memory
	$(SIZE_CC) -Atd $@ 
#---Dump
	$(OBJ_DUMP) $(OBJS) > $(TARGET).dump
#-------------------------------------------------------------------
.PHONY: compile-all
compile-all: $(OBJS)
	make $(OBJS)
#---Dump
	$(OBJ_DUMP) $(OBJS) > $@.dump
#----------------------------------------------------------------
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(ASSE) $(PREP) $(DEPD) *.dump

# -----------------------Automatic Variables
#*********************************************

#----Preprocessor files
%.i: %.c
	$(CC) $(CPPFLAGS) -E $< $(CFLAGS) -o $@
#----Assembly files
%.asm: %.c
	$(CC) $(CPPFLAGS) -S $< $(CFLAGS) -o $@	
#----Dependency files
%.d: %.c
	$(CC) $(CPPFLAGS) -M $< $(CFLAGS) -o $@
#----Object files
%.o: %.c
	$(CC) $(CPPFLAGS) -c $< $(CFLAGS) -o $@
	

