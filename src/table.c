/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-hugo.cathelain
** File description:
** table
*/
#include "../include/secured.h"

hashtable_t *new_hashtable(int(*hash)(char *, int), int len)
{
    hashtable_t *ht = malloc(sizeof(hashtable_t));

    if (len < 1)
        return NULL;
    ht->hash = hash;
    ht->ht = malloc(sizeof(link_t) * len + 1);
    ht->ht[len] = NULL;
    ht->size = len;
    for (int i = 0; i < len; i++) {
        ht->ht[i] = malloc(sizeof(link_t));
        ht->ht[i]->next = NULL;
    }
    return ht;
}

void destroy(link_t *ht)
{
    link_t *prev = NULL;

    while (ht) {
        prev = ht;
        ht = ht->next;
        free(prev);
    }
}

void delete_hashtable(hashtable_t *ht)
{
    if (!ht)
        return;
    for (int i = 0; ht->ht[i]; i++)
        destroy(ht->ht[i]);
    free(ht->ht);
    free(ht);
}

static void print(link_t *ht)
{
    link_t *tmp = ht;

    while (tmp && tmp->code) {
        my_putstr("> ");
        my_putnbr(tmp->code);
        my_putstr(" - ");
        my_putstr(tmp->data);
        my_putstr("\n");
        tmp = tmp->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    if (!ht)
        return;
    for (int i = 0; ht->ht[i]; i++) {
        my_putstr("[");
        my_putnbr(i);
        my_putstr("]:\n");
        print(ht->ht[i]);
    }
}
