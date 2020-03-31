IDIR =../include
CC=gcc
CFLAGS=-Wall -g

ODIR=obj


_DEPS = AuxVendas.h TestClientes.h TestProdutos.h stringUtils.h TestVendas.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = AuxVendas.o TestClientes.o TestProdutos.o stringUtils.o TestVendas.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 