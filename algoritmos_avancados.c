#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------
// Struct Sala: representa um cômodo da mansão
// -----------------------------------------------------------
typedef struct Sala {
    char nome[40];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;


// -----------------------------------------------------------
// Função: criarSala()
// Objetivo: cria uma sala dinamicamente com nome informado
// -----------------------------------------------------------
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}


// -----------------------------------------------------------
// Função: explorarSalas()
// Permite ao jogador navegar pelo mapa da mansão
// -----------------------------------------------------------
void explorarSalas(Sala *atual) {
    char escolha;

    printf("\n=== Bem-vindo à exploração da mansão! ===\n");

    while (atual != NULL) {
        // Exibe sala atual
        printf("\nVocê está em: %s\n", atual->nome);

        // Caso seja nó-folha (sem caminhos)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Este cômodo não possui mais caminhos. Fim da exploração.\n");
            return;
        }

        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL) printf(" - (e) Ir para a esquerda\n");
        if (atual->direita != NULL)  printf(" - (d) Ir para a direita\n");
        printf(" - (s) Sair da exploração\n");

        printf("Digite sua opção: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' || escolha == 'E') {
            if (atual->esquerda != NULL)
                atual = atual->esquerda;
            else
                printf("Não existe caminho à esquerda!\n");

        } else if (escolha == 'd' || escolha == 'D') {
            if (atual->direita != NULL)
                atual = atual->direita;
            else
                printf("Não existe caminho à direita!\n");

        } else if (escolha == 's' || escolha == 'S') {
            printf("Exploração encerrada pelo jogador.\n");
            return;

        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}


// -----------------------------------------------------------
// Função principal: monta o mapa e inicia a exploração
// -----------------------------------------------------------
int main() {

    // Construção manual da árvore (mapa da mansão)
    Sala *hall        = criarSala("Hall de Entrada");
    Sala *salaEstar   = criarSala("Sala de Estar");
    Sala *cozinha     = criarSala("Cozinha");
    Sala *biblioteca  = criarSala("Biblioteca");
    Sala *jardim      = criarSala("Jardim");
    Sala *quarto      = criarSala("Quarto Principal");

    // Ligações entre salas (árvore binária)
    hall->esquerda = salaEstar;
    hall->direita  = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita  = jardim;

    cozinha->direita = quarto;

    // Início da exploração
    explorarSalas(hall);

    return 0;
}
