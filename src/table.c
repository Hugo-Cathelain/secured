/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-hugo.cathelain
** File description:
** table
*/
#include "../include/secured.h"

hashtable_t *new_hashtable(int(*hash)(char *, int), int len)
{
    hashtable_t *ht = NULL;
    hashtable_t *begin = ht;

    ht->next = NULL;
    for (int i = 0; i < len; i++) {
        ht = malloc(sizeof(hashtable_t));
        ht = ht->next;
        ht->next = NULL;
    }
    return begin;
}

void delete_hashtable(hashtable_t *ht)
{
    hashtable_t *prev = NULL;

    while (ht->next) {
        prev = ht;
        ht = ht->next;
        prev->next = NULL;
        free(prev->data);
    }
    ht->next = NULL;
    free(ht->data);
}

void ht_dump(hashtable_t *ht)
{
    int i = 0;

    if (!ht)
        return;
    for (int i = 0; ht->next != 0; i++) {
        my_putstr("[");
        my_putstr(i);
        my_putstr("]:\n");
        if (ht->hash) {
            my_putstr("> ");
            my_putstr(ht->hash);
            my_putstr(" - ");
            my_putstr(ht->data);
            my_putstr("\n");
        ht = ht->next;
        }
    }
}
