#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct prodotto
{
    char* nome;
    int id;
    double prezzo;
    int quantita;
};

int main(void) {
    //uso un puntatore prodotto per puntare a uno spazio di memoria dove si trova la variabile
    struct prodotto* ptr_prodotto;
    //malloc(sizeof(struct prodotto)) mi da un indirizzo generico dove ha prenotato uno spazio di memoria
    // facendo il cast (struct prodotto *<-(puntatore prodotto non un prodotto effettivo)) il tipo di puntatore diventa un puntatore per il "tipo" prodotto
    ptr_prodotto = (struct prodotto *) malloc(sizeof(struct prodotto));

    if (ptr_prodotto==NULL)//malloc non assicura per certezza allocazione di memoria (es non c'è più spazio in memoria) quindi meglio fare il controllo
    {
        printf("Errore in allocazione");
        return 1;
    }
    //visto che ora quello che uso è un puntatore il simbolo -> significa chiamo il membro del valore a cui sto puntando a cui sto parlando. puntatore->valore
    //in questo caso che ho come nome un puntatore
    //puntatore->membro è esattamente identico a (*puntatore).membro.
    //in questo caso il "prodotto" è salvato il only read.questo va bene solo se lo leggi ma se lo provi a riscrivere tira tuoni.
    //ptr_prodotto->nome = "Prodotto";
    //la cosa migliore è allocare memoria e salvare l'indirizzo della memoria tenuta dal malloc nel indidirizzo di (*ptr_prodotto).nome


    //come salvare dinamicamente una stringa
    char* nome_prodotto="pane";
    //capisco quanto grande è la stringa
    int lunghezza_testo = strlen(nome_prodotto)+1;//+1 per \0
    //ottengo l'indirizzo dove è allocato lo spazio per la grandezza del testo e lo salvo sul valore.
    ptr_prodotto->nome =(char* ) malloc(sizeof (char) * lunghezza_testo);
    //ricordarsi di salvare il valore a indirizzo
    strcpy(ptr_prodotto->nome,/*indirizzo*/ nome_prodotto/*valore*/);

    char* buffer_temporaneo;
    // printf("inserire nome prodotto");
    // fgets(buffer_temporaneo, sizeof (char) * lunghezza_testo, stdin);
    // buffer_temporaneo[strcspn(buffer_temporaneo, "\n")] = '\0';
    // ptr_prodotto->nome = (char *) malloc(strlen(buffer_temporaneo) + 1);
    // strcpy(ptr_prodotto->nome, buffer_temporaneo);
    // printf("%s\n", ptr_prodotto->nome);
    printf("Inserisci il nome del prodotto: ");
    // 2. Leggo in modo sicuro l'input dell'utente nel buffer.
    //    - buffer_temporaneo: Dove salvare la stringa.
    //    - 256: La dimensione massima del buffer (non leggerà mai più di 255 caratteri).
    //    - stdin: "standard input", cioè la tastiera.
    fgets(buffer_temporaneo, 256, stdin);

    // 3. Rimuovo il carattere '\n' (a capo) che fgets lascia alla fine.
    //    strcspn cerca la prima occorrenza di '\n' e noi la sostituiamo con '\0'.
    buffer_temporaneo[strcspn(buffer_temporaneo, "\n")] = '\0';

    // 4. Ora che ho la stringa pulita, alloco la memoria ESATTA che mi serve.
    ptr_prodotto->nome = (char *) malloc(strlen(buffer_temporaneo) + 1);
    if (ptr_prodotto->nome == NULL) {
        printf("Errore allocazione nome\n");
        free(ptr_prodotto);
        return 1;
    }

    // 5. Copio la stringa dal buffer temporaneo alla memoria definitiva.
    strcpy(ptr_prodotto->nome, buffer_temporaneo);

     printf("%s\n", ptr_prodotto->nome);
    free(ptr_prodotto->nome);
    free(ptr_prodotto);
    // printf("--- Scheda Prodotto ---\n");
    // printf("Nome: %s\n", prodotto_.nome);
    // printf("Codice: %d\n", prodotto_.id);
    // printf("Prezzo: %.2f euro\n", prodotto_.prezzo);
    // printf("Quantita': %d unita'\n", prodotto_.quantita);
    return 0;
}