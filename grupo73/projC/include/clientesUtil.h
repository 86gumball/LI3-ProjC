typedef struct clienteBTS
{
  struct clienteBTS *menor;
  struct clienteBTS *maior;
  char code_cliente;
  short numero_identificacao;
  //short heigth; serve para usar nas rotaçoes
} *CBTS;

CBTS creatreNodeCliente (char key, short numero);

CBTS insert (char buffer, struct clienteBTS *tree, short key_num);

void chooseTree (char key, CBTS mem[], short posTable);

CBTS *catalogoClientes (CBTS *mem);