CC = gcc
CFlags = -Wall -g

TestVendas: TestVendas.o AuxVendas.o TestProdutos.o TestClientes.o 
	cc -o TestVendas TestVendas.o AuxVendas.o TestProdutos.o TestClientes.o

TestVendas.o: TestVendas.c TestProdutos.h TestClientes.h AuxVendas.h

AuxVendas.o: AuxVendas.c AuxVendas.h

TestProdutos.o: TestProdutos.c TestProdutos.h

TestClientes.o: TestClientes.c TestClientes.h

clean:
	rm -f TestVendas *.o
