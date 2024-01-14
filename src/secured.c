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

    while (ht->next != NULL)
        ht = ht->next;
    if (ht->data && ht->code) {
        ht->next = malloc(sizeof(link_t));
        ht = ht->next;
        ht->next = NULL;
    }
    ht->data = my_strdup(value);
    ht->code = code(key, len);
    return tmp;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = ht->hash(key, ht->size);

    ht->ht[index] = insert(ht->ht[index], key, value, ht->size);
    return 0;
}

static int destroy_this(link_t *ht, int cod)
{
    link_t *tmp = ht;
    link_t *prev = NULL;
    char *res = NULL;

    while (tmp->next) {
        if (cod == tmp->code) {
            res = my_strdup(tmp->data);
            free(tmp->data);
            ht->code = NULL;
            prev->next = prev ? tmp->next : NULL;
            destroy(tmp);
            return 0;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return 0;
}

static char *serch(struct ll *ht, int cod)
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

int ht_delete(hashtable_t *ht, char *key)
{
    int cod = code(key, ht->size);
    char *res = NULL;

    for (int i = 0; ht->ht[i]; i++) {
        res = serch(ht->ht[i], cod);
        if (res)
            return destroy_this(ht->ht[i], cod);
    }
    return res;
}

char *ht_search(hashtable_t *ht, char *key)
{
    int cod = code(key, ht->size);
    char *res = NULL;

    for (int i = 0; ht->ht[i]; i++) {
        res = serch(ht->ht[i], cod);
        if (res)
            return res;
    }
    return res;
}
