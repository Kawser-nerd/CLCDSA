/**
 * ST.h:
 * 
 * Manipulacao da tabela de simbolos.
 *
 * Estrutura da TST (Tenary Search Tree):
 * 
 * Foi usado a TST como tabela de simbolos para indexar 
 * os nomes dos vertices. O indice associado a cada nome
 * e' guardado no campo "index" do no correspondente 
 * a '\0' do nome.
 *
 * OBS: Codigo retirado do livro "Algorithms In C Part 5: Graph Algorithms" 
 *      de Robert Sedwick
 */

/**********************/
/* Estrutura de dados */
/**********************/

typedef struct STnode* STlink;

struct STnode
{
    int index;                /* Guarda o indice da string se d == '\0' */
    int d;                    /* Guarda um caracter */
    STlink left, right, middle;
};

/**************************/
/* Prototipo das funcoes  */
/**************************/

/**
 * Inicializa a tabela de simbolos
 */
void STinit();

/**
 * Recebe a string 'key' e devolve o indice d
 */
int STindex(char* key);

/**
 * Devolve a quantidade de simbolos existentes na tabela
 */
int STsize(void);

