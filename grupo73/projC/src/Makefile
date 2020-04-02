IDIR =../include
CC=gcc
CFLAGS=-Wall -g

ODIR=obj


_DEPS = AuxVendas.h clientesUtil.h produtoUtil.h stringUtils.h TestVendas.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = AuxVendas.o stringUtils.o clientesUtil.o produtoUtil.o TestVendas.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 