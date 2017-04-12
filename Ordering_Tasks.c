#include <stdio.h>
#include <stdlib.h>


typedef struct Node{

  int chave, contador;
  Node* proximo;


}Node;

int main(void){

  int n, m; // n número de elementos e m número de relações de precedencia
  scanf("%d%d", &n, &m);

  Node* CB;
  CB = (Node*)malloc((n+1)*sizeof(Node));

  // Inicialização

  for(int i = 1; i <= n; i++){
    CB[i].chave = i;
    CB[i].contador = 0;
    CB[i].proximo = NULL;
  }

  int j=0, k=0;
  for(int i = 0; i < m; i++){ // Lê do teclado o par (j, k) que representa a relacao de precedencia e adiciona a lista encadeada do
    scanf("%d%d", &j, &k);    // elemento CB[j]
    if(j == 0 && k == 0)
      break;

    Node *pt; // Ponteiro temporário
    pt = (Node*)malloc(sizeof(Node));
    pt->chave = k;
    pt->proximo = CB[j].proximo; // Faz pt apontar para o prox do cabeca e o cabeca apontar para pt
    CB[j].proximo = pt;
    CB[k].contador ++;
  }
    // Execução

    int fim = 0;
    CB[0].contador = 0;

    for(int i = 1; i <= n; i++){ // Procura os elementos com contador 0 e muda a função do contador para encadear os elementos
      if(CB[i].contador == 0){   // na ordem em que vao aparecer na saida padrao
        CB[fim].contador = i;
        fim = i;
      }
    }

    int objeto = CB[0].contador; // primeiro objeto a aparacer na saida padrao será o primeiro a não possuir precedentes na busca anterior

    while(objeto != 0){      // Dessa forma garantimos que o último elemento percorrido terá o contador apontando para o 0, encerrando a saida
      printf("%d ",objeto);

      Node* pt;
      pt = CB[objeto].proximo; // Não necessita inicialização pois o lugar aonde ira apontar ja é dado por outra variavel

    // Realiza uma busca em profundidade para cada elemento que aparecer no encadeamento,
    // encerrando quando chegar ao fina da lista encadeada do elemento CB[objeto]

      while(pt != NULL){
        int indice = pt->chave; // indice é uma variavel que somente sera usada dentro do loop
        CB[indice].contador --;
        if(CB[indice].contador == 0){ // checa se chegou ao fim das precedencias de algum elemento, se sim encadeia ele pela variavel contador
          CB[fim].contador = indice;
          fim = indice;
        }
        pt = pt->proximo; // passa para o próximo elemento da lista encadeada de CB[j]
      }

      objeto = CB[objeto].contador; // finalmente passa para o próximo elemento pelo encadeamento da variavel contador
    }

    puts("");

  return 0;
}
