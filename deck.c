/*
*deck.c
*
*   Created on: March 3, 2019
*   Author: Aurimas Pupsys
*/
#include "deck.h"

typedef struct elementas {
    TYPE sk;
    struct elementas* sekantis;
    struct elementas* atgal;
} NODE;

struct dekas {
    NODE *priekis;
    NODE *galas;
    int dydis;
};

int createDeck(DECK *Deck)
{
    DECK x = (DECK)malloc(sizeof(struct dekas));
    if (x == NULL)
    {
        return 1;
    }
    x->dydis = 0;
    *Deck = x;
    return 0;
}
bool deckEmpty(DECK Deck)
{
    if(Deck->dydis == 0) return true;
    else return false;
}
int pushTop(DECK Deck, TYPE x)
{
    if (Deck->dydis == 0)
    {
        Deck->priekis = (NODE*)malloc(sizeof(NODE));
        if (Deck->priekis == NULL)
        {
            return 1;
        }
        Deck->priekis->sk = x;
        Deck->priekis->sekantis = Deck->priekis;
        Deck->priekis->atgal = Deck->priekis;
        Deck->dydis = 1;
        Deck->galas = Deck->priekis;
        return 0;
    }
    NODE *naujas = (NODE*)malloc(sizeof(NODE));
    if (naujas == NULL)
    {
        return 1;
    }
    naujas->sk = x;
    naujas->atgal = naujas;
    naujas->sekantis = Deck->priekis;
    Deck->priekis->atgal = naujas;
    Deck->priekis = naujas;
    Deck->dydis++;
    return 0;
}
int popTop(DECK Deck, TYPE *x)
{
    if (Deck->dydis == 0)
    {
        return 1;
    }
    NODE *pagalbinis;
    *x = Deck->priekis->sk;
    pagalbinis = Deck->priekis->sekantis;
    free(Deck->priekis);
    Deck->priekis = pagalbinis;
    Deck->dydis--;
    return 0;
}
int pushBot(DECK Deck, TYPE x)
{
    if (Deck->dydis == 0)
    {
        Deck->galas = (NODE*)malloc(sizeof(NODE));
        if (Deck->galas == NULL)
        {
            return 1;
        }
        Deck->galas->sk = x;
        Deck->galas->sekantis = Deck->galas;
        Deck->galas->atgal = Deck->galas;
        Deck->dydis = 1;
        Deck->priekis = Deck->galas;
        return 0;
    }
    NODE *naujas =(NODE*)malloc(sizeof(NODE));
    if (Deck->priekis == NULL)
    {
        return 1;
    }
    naujas->sk = x;
    naujas->sekantis = naujas;
    naujas->atgal = Deck->galas;
    Deck->galas->sekantis = naujas;
    Deck->galas = naujas;
    Deck->dydis++;
    return 0;
}
int popBot(DECK Deck, TYPE *x)
{
    if (Deck->dydis == 0)
    {
        return 1;
    }
    NODE *pagalbinis;
    *x = Deck->galas->sk;
    pagalbinis = Deck->galas->atgal;
    free(Deck->galas);
    Deck->galas = pagalbinis;
    Deck->dydis--;
    return 0;
}
int lookTop(DECK Deck, TYPE *x)
{
    if (Deck->priekis == NULL)
    {
        return 1;
    }
    *x = Deck->priekis->sk;
    return 0;
}
int lookBot(DECK Deck, TYPE *x)
{
    if (Deck->galas == NULL)
    {
        return 1;
    }
    *x = Deck->galas->sk;
    return 0;
}
int countDeck(DECK Deck, TYPE *x)
{
    if (Deck == NULL)
    {
        return 1;
    }
    *x = Deck->dydis;
    return 0;
}
void deleteDeck(DECK Deck)
{
    NODE *pagalbinis;
    if (Deck->dydis != 0)
    {
        while (Deck->priekis != Deck->galas)
        {
            pagalbinis = Deck->priekis->sekantis;
            free(Deck->priekis);
            Deck->priekis = pagalbinis;
        }
        free(Deck->priekis);
    }
    free(Deck);
}
