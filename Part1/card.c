#include <stdio.h>
#include <stdlib.h> //rand()
#include "card.h" //user defined header file

#define CARDS_PER_LINE  8 //used by printDeck only

void initDeck(Card deck[])
{
    char suits[NUM_SUITS] = {CLUBS, DIAMONDS, HEARTS, SPADES};
    int index = 0;                                
    for (int s = 0; s < NUM_SUITS; s++) 
    {           
        for (int r = LOWEST_RANK; r <= ACE; r++) 
        {  
            deck[index].suit = suits[s];
            deck[index].rank = r;
            index++;
        }
    }
}
void shuffleDeck(Card deck[], int size)
{
    for (int i = size - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);       
        Card temp = deck[i];       
        deck[i]   = deck[j];
        deck[j]   = temp;
    }
}
void printCard(Card card)
{
    switch (card.rank) 
    {
        case JACK:  printf(" J"); break;
        case QUEEN: printf(" Q"); break;
        case KING:  printf(" K"); break;
        case ACE:   printf(" A"); break;
        default:    printf("%2d", card.rank); break;   
    }
    printf("%c", card.suit);
}
void printDeck(Card deck[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        printCard(deck[i]);
        printf(" ");

        if ((i + 1) % CARDS_PER_LINE == 0)
            printf("\n");                           
    }

    if (size % CARDS_PER_LINE != 0)
        printf("\n");
                       
}
int deckIsValid(Card deck[], int size)
{
    if (size != DECK_SIZE)
        return 0;                                 

    for (int i = 0; i < size; i++) 
    {
        
        if (deck[i].suit != CLUBS && deck[i].suit != DIAMONDS &&
            deck[i].suit != HEARTS && deck[i].suit != SPADES)
            return 0;

        
        if (deck[i].rank < LOWEST_RANK || deck[i].rank > ACE)
            return 0;
        

        
        for (int j = 0; j < i; j++) 
        {
            if (deck[j].suit == deck[i].suit && deck[j].rank == deck[i].rank)
                return 0;
        }
    }

    return 1;       
}