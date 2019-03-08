#include "deck.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    DECK dekas;
    int x, y;
    createDeck(&dekas);
    y = pushTop(dekas, 5);
    printf("%d \n", y);
    popTop(dekas, &x);
    printf("%d \n", x);
    y = popTop(dekas, &x);
    printf("%d \n", x);
    printf("%d \n", y);
    pushBot(dekas, 7);
    pushTop(dekas, 23);
    pushBot(dekas, 96);
    popTop(dekas, &x);
    pushBot(dekas, 10);
    popBot(dekas, &x);
    countDeck(dekas, &x);
    printf("%d \n", x);
    while (deckEmpty(dekas) == false)
    {
        popTop(dekas, &x);
        printf("%d \n", x);
    }
    deleteDeck(dekas);
}
