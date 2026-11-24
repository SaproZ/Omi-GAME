#ifndef CARD_H //guard incase of duplication
#define CARD_H

#define NUM_SUITS 4 //no of suits
#define NUM_RANKS 8 // no of ranks
#define DECK_SIZE (NUM_SUITS * NUM_RANKS) //total cards 32

#define CLUBS       'C' 
#define DIAMONDS    'D'
#define HEARTS      'H'
#define SPADES      'S'

/*ranks: stored as numbers
 * Bigger number = stronger card (7 < 8 < 9 < 10 < J < Q < K < A),
 * so two ranks can be compared with plain >, < and ==.        */
#define LOWEST_RANK 7           /* 7, 8, 9 and 10 use their own number */
#define JACK        11
#define QUEEN       12
#define KING        13
#define ACE         14

typedef struct {
    char suit;      /* CLUBS, DIAMONDS, HEARTS or SPADES */
    int  rank;      /* 7 to 14                           */
} Card;                    

//prototypes of functions
void initDeck(Card deck[]); //fill deck[] array with all 32 cards in order
void shuffleDeck(Card deck[], int size); //put the cards into random order
void printCard(Card card); //print one card eg: 9H
void printDeck(Card deck[], int size); //print the deck, 8 cards
int  deckIsValid(Card deck[], int size); //check the validity of each card

#endif