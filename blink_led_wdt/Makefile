include ../Makefile.inc

PROG=main
OBJS=$(PROG).o
SRCS=$(PROG).c

CLEANFILES=$(PROG).elf $(OBJS)

$(PROG).elf: $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG).elf $(OBJS)
	@echo "___ [SIZE] ______________________________________________"
	$(SIZE) $@
	@echo "___ [SIZE] ______________________________________________"

$(OBJS): $(SRCS) ../Makefile.inc
	$(CC) $(CFLAGS) -c $(SRCS)

prog: $(PROG).elf
	$(MSPPROG) 'prog $(PROG).elf'

clean:
	rm -f $(CLEANFILES)
