typedef struct produtoBST
{
  struct produtoBST *menor;
  struct produtoBST *maior;
  char code_produto_upper;
  char code_produto_sub;
  short numero_identificacao;
  //short heigth; serve para usar nas rotaçoes
} *PBST;

PBST creatreNodeProduto (char key[], short numero);

PBST insertP (char buffer[], struct produtoBST *tree, short key_num);

void chooseTreeP (char key[], PBST *mem[], short posTable);

PBST **catalogoProdutos (PBST **mem);
