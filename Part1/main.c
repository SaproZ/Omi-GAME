#include <stdio.h>
#include <stdlib.h> //srand()  
#include <time.h> //time()
#include "card.h"

int main(void)
{
    Card deck[DECK_SIZE];
    srand(time(NULL));
    initDeck(deck);
#ifdef DEBUG
    printf("Fresh deck:\n");
    printDeck(deck, DECK_SIZE);
#endif
    shuffleDeck(deck, DECK_SIZE);
#ifdef DEBUG
    printf("\nShuffled deck:\n");
    printDeck(deck, DECK_SIZE);
#endif
    printf("\nKey: C=Clubs D=Diamonds H=Hearts S=Spades, J=Jack Q=Queen K=King A=Ace\n");
    return 0;
}