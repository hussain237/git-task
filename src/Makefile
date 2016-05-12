# -*-Mode: Makefile;-*-
# vi: sw=8 ts=8 noet
# vim: sw=8 ts=8 noet

CC 	= gcc
CFLAGS 	= -Wall -O3
LDFLAGS = -lm 

#----------

EXE = nmod

OBJS = $(patsubst %.c,%.o,$(wildcard *.c))

#----------

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(LIB_DIRS) $(LLIBS)$(LDFLAGS) -o $(EXE)

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -c $<
	
#----------

clean:
	rm -f *.o *.*~ *~  $(EXE).exe 
