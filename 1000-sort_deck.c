#include "deck.h"

int _cmpstr(const char *st_1, const char *st_2);
char numerical_val(deck_node_t *card);
void sort_deck1(deck_node_t **deck_hd);
void sort_deck2(deck_node_t **deck_hd);
void sort_deck(deck_node_t **deck);

/**
 * _cmpstr - Compares two strings.
 * @st_1: The first string to be compared.
 * @st_2: The second string to be compared.
 *
 * Return: Positive byte difference if st_1 > st_2
 *         0 if st_1 == st_2
 *         Negative byte difference if st_1 < st_2
 */
int _cmpstr(const char *st_1, const char *st_2)
{
	while (*st_1 && *st_2 && *st_1 == *st_2)
	{
		st_1++;
		st_2++;
	}

	if (*st_1 != *st_2)
		return (*st_1 - *st_2);
	return (0);
}

/**
 * numerical_val - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char numerical_val(deck_node_t *card)
{
	if (_cmpstr(card->card->value, "Ace") == 0)
		return (0);
	if (_cmpstr(card->card->value, "1") == 0)
		return (1);
	if (_cmpstr(card->card->value, "2") == 0)
		return (2);
	if (_cmpstr(card->card->value, "3") == 0)
		return (3);
	if (_cmpstr(card->card->value, "4") == 0)
		return (4);
	if (_cmpstr(card->card->value, "5") == 0)
		return (5);
	if (_cmpstr(card->card->value, "6") == 0)
		return (6);
	if (_cmpstr(card->card->value, "7") == 0)
		return (7);
	if (_cmpstr(card->card->value, "8") == 0)
		return (8);
	if (_cmpstr(card->card->value, "9") == 0)
		return (9);
	if (_cmpstr(card->card->value, "10") == 0)
		return (10);
	if (_cmpstr(card->card->value, "Jack") == 0)
		return (11);
	if (_cmpstr(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_deck1 - Sort a deck of cards from spades to diamonds.
 * @deck_hd: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck1(deck_node_t **deck_hd)
{
	deck_node_t *it, *pt, *cp;

	for (it = (*deck_hd)->next; it != NULL; it = cp)
	{
		cp = it->next;
		pt = it->prev;
		while (pt != NULL && pt->card->kind > it->card->kind)
		{
			pt->next = it->next;
			if (it->next != NULL)
				it->next->prev = pt;
			it->prev = pt->prev;
			it->next = pt;
			if (pt->prev != NULL)
				pt->prev->next = it;
			else
				*deck_hd = it;
			pt->prev = it;
			pt = it->prev;
		}
	}
}

/**
 * sort_deck2 - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck_hd: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck2(deck_node_t **deck_hd)
{
	deck_node_t *it, *pt, *cmp;

	for (it = (*deck_hd)->next; it != NULL; it = cmp)
	{
		cmp = it->next;
		pt = it->prev;
		while (pt != NULL &&
		       pt->card->kind == it->card->kind &&
		       numerical_val(pt) > numerical_val(it))
		{
			pt->next = it->next;
			if (it->next != NULL)
				it->next->prev = pt;
			it->prev = pt->prev;
			it->next = pt;
			if (pt->prev != NULL)
				pt->prev->next = it;
			else
				*deck_hd = it;
			pt->prev = it;
			pt = it->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck1(deck);
	sort_deck2(deck);
}
