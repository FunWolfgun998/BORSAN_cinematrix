#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct prodotto
{
    char nome[50];
    int id;
    double prezzo;
    int quantita;
};
int main(void) {
    struct prodotto prodotto;
    strcpy(prodotto.nome, "Prodotto");
    prodotto.id = 1;
    prodotto.prezzo = 1.78f;
    prodotto.quantita = 1;

    printf("--- Scheda Prodotto ---\n");
    printf("Nome: %s\n", prodotto.nome);
    printf("Codice: %d\n", prodotto.id);
    printf("Prezzo: %.2f euro\n", prodotto.prezzo);
    printf("Quantita': %d unita'\n", prodotto.quantita);
    return 0;
}