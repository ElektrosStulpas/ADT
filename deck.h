/*
*deck.c
*
*   Created on: March 3, 2019
*   Author: Aurimas Pupsys
*/
#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <stdlib.h>
#include <stdbool.h>
typedef int TYPE;
typedef struct dekas *DECK;

int createDeck(DECK *Deck);/* Used to create a deck ADT. If fails create deck, returns 1, else, 0.*/
bool deckEmpty(DECK Deck);/* Used to check if the deck ADT is empty. Useful when you want to print out the ADT.*/
int pushTop(DECK Deck, TYPE x);/* Used to insert an element to the top of the ADT. If it fails to push the element, returns 1, else, 0.*/
int popTop(DECK Deck, TYPE *x);/* Used to take out an element from the top of the ADT. If the deck is empty, returns 1, else 0.*/
int pushBot(DECK Deck, TYPE x);/* Used to insert an element to the bottom of the ADT. If it fails to push the element, returns 1, else, 0.*/
int popBot(DECK Deck, TYPE *x);/* Used to take out an element from the bottom of the ADT. If the deck is empty, returns 1, else 0.*/
int lookTop(DECK Deck, TYPE *x);/* Used to check what the element at the top of the ADT is. If the deck is empty, returns 1, else 0.*/
int lookBot(DECK Deck, TYPE *x);/* Used to check what the element at the bottom of the ADT is. If the deck is empty, returns 1, else 0.*/
int countDeck(DECK Deck, TYPE *x);/* Used to check the number of elements currently in the ADT. If the deck is empty, returns 1, else 0.*/
void deleteDeck(DECK Deck);/* Used to delete the deck when you finish working with it.*/
#endif /* DECK_H_INCLUDED*/
