/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-hugo.cathelain
** File description:
** secured
*/
#include "../include/secured.h"

int hash(char *key, int len)
{
    int hash_value = 31;

    if (len < 1 || key == NULL)
        return NULL;
    while (*key) {
        hash_value = hash_value << (*key % 7);
        hash_value = ((hash_value * (31 * *key + len)) / *key) + *key * *key;
        key++;
    }
    if (hash_value < 0)
        hash_value *= -1;
    return (hash_value);
}

static link_t *insert(link_t *ht, int shah, char *value, int len)
{
    link_t *tmp = ht;

    while (ht->next != NULL)
        ht = ht->next;
    if (ht->data && ht->code) {
        ht->next = malloc(sizeof(link_t));
        ht = ht->next;
        ht->next = NULL;
    }
    ht->data = my_strdup(value);
    ht->code = shah;
    return tmp;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index;
    int sz;

    if (!ht || key == NULL || value == NULL)
        return 84;
    index = ht->hash(key, ht->size) % ht->size;
    sz = ht->size;
    ht->ht[index] = insert(ht->ht[index], ht->hash(key, sz), value, ht->size);
    return 0;
}

static link_t *cut_that(link_t *ht, link_t *prev, link_t *tmp, int cod)
{
    while (tmp) {
        if (cod == tmp->code) {
            free(tmp->data);
            prev->next = tmp->next;
            free(tmp);
            return ht;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return ht;
}

static link_t *destroy_this(link_t *ht, int cod)
{
    link_t *tmp = ht;
    link_t *prev = NULL;

    if (cod == tmp->code) {
        if (!ht->next) {
            ht->next = malloc(sizeof(link_t));
            ht->next->code = 0;
            ht->next->data = NULL;
        }
        ht = ht->next;
        free(tmp->data);
        free(tmp);
        return ht;
    }
    return cut_that(ht, prev, tmp, cod);
}

static char *serch(struct ll *ht, int cod)
{
    link_t *tmp = ht;
    char *res = NULL;

    while (tmp) {
        if (cod == tmp->code) {
            res = my_strdup(tmp->data);
            return res;
        }
        tmp = tmp->next;
    }
    return res;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int cod;
    char *res = NULL;

    if (key == NULL || !ht)
        return 84;
    cod = ht->hash(key, ht->size);
    for (int i = 0; ht->ht[i]; i++) {
        res = serch(ht->ht[i], cod);
        if (res) {
            ht->ht[i] = destroy_this(ht->ht[i], cod);
            return 0;
        }
    }
    return 0;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int cod;
    char *res = NULL;

    if (key == NULL || !ht)
        return NULL;
    cod = ht->hash(key, ht->size);
    for (int i = 0; ht->ht[i]; i++) {
        res = serch(ht->ht[i], cod);
        if (res)
            return res;
    }
    return res;
}
