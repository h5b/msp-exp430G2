CC	= msp430-gcc
OBJCOPY	= msp430-objcopy
OBJDUMP	= msp430-objdump
SIZE	= msp430-size --target=elf32-msp430
MCU	= msp430g2452

MSPPROG = mspdebug rf2500

# Level of Optimization
OPT = s

CFLAGS += -mmcu=$(MCU) -O$(OPT)
CFLAGS += -Werror -Wextra
CFLAGS += -Wall -Wcast-align -Wimplicit
CFLAGS += -Wpointer-arith -Wswitch
CFLAGS += -Wredundant-decls -Wreturn-type
CFLAGS += -Wshadow -Wunused
CFLAGS += -fno-builtin
CFLAGS += -funsigned-char
CFLAGS += -funsigned-bitfields
CFLAGS += -fpack-struct
