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

    ht->hash = hash;
    ht->ht = malloc(sizeof(link_t) * len + 1);
    ht->ht[len] = NULL;
    for (int i = 0; i < len; i++) {
        ht->ht[i] = malloc(sizeof(link_t));
    }
    return ht;
}

static void destroy(link_t *ht)
{
    link_t *prev = NULL;

    while (ht->next) {
        prev = ht;
        ht = ht->next;
        free(prev);
    }
    free(ht);
}

void delete_hashtable(hashtable_t *ht)
{
    for (int i = 0; ht->ht[i]; i++) {
        destroy(ht->ht[i]);
        free(ht->ht[i]);
    }
    free(ht->ht);
    free(ht);
}

static void print(link_t *ht)
{
    link_t *tmp = ht;

    while (tmp->next && tmp->code && tmp->data) {
        my_putstr("> ");
        my_punbr(tmp->code);
        my_putstr(" - ");
        my_putstr(tmp->data);
        my_putstr("\n");
        tmp = tmp->next;
    }
}

void ht_dump(hashtable_t *ht)
{
    for (int i = 0; ht->ht[i]; i++) {
        my_putstr("[");
        my_putstr(i);
        my_putstr("]:\n");
        print(ht->ht[i]);
    }
}
