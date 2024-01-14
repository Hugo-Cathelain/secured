/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-hugo.cathelain
** File description:
** secured
*/
#include "../include/secured.h"

int hash(char *key, int len)
{
    int hash_value;

    while (*key) {
        hash_value = (hash_value * 31) + *key;
        key++;
    }
    return ((hash_value % len + len) % len);
}

static int code(char *key, int len)
{
    int code = 0;

    while (*key) {
        code = (code * 31) + key;
        key++;
    }
    return (code % len + len);
}

static link_t *insert(link_t *ht, char *key, char *value, int len)
{
    link_t *tmp = ht;

    while (tmp->next != NULL)
        tmp = tmp->next;
    if (tmp->data && tmp->code) {
        tmp->next = malloc(sizeof(link_t));
        tmp = tmp->next;
        tmp->next = NULL;
    }
    tmp->data = my_strdup(value);
    tmp->code = code(key, len);
    return ht;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = ht->hash(key, ht->size);

    ht->ht[index] = insert(ht->ht[index], key, value, ht->size);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    return 0;
}

static char *search(link_t *ht, int cod)
{
    link_t *tmp = ht;
    char *res = NULL;

    while (tmp->next) {
        if (cod == tmp->code) {
            res = my_strdup(tmp->data);
            return res;
        }
        tmp = tmp->next;
    }
    return res;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int cod = code(key, ht->size);
    char *res = NULL;

    for (int i = 0; ht->ht[i]; i++) {
        res = search(ht->ht[i], cod);
        if (res)
            return res;
    }
    return res;
}
