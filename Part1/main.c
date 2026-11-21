#include <stdio.h>
#include <stdlib.h>  
#include <time.h>       
#include "card.h"

int main(void)
{
    Card deck[DECK_SIZE];
    srand(time(NULL));
    initDeck(deck);
    printf("Fresh deck:\n");
    printDeck(deck, DECK_SIZE);
    shuffleDeck(deck, DECK_SIZE);
    printf("\nShuffled deck:\n");
    printDeck(deck, DECK_SIZE);
    printf("\nKey: C=Clubs D=Diamonds H=Hearts S=Spades, J=Jack Q=Queen K=King A=Ace\n");
    return 0;
}