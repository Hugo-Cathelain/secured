/*
** EPITECH PROJECT, 2024
** B-CPE-110-LYN-1-1-secured-hugo.cathelain
** File description:
** secured
*/

#ifndef SECURED_H_
    #define SECURED_H_

    #define NULL 0

    #include <stdlib.h>
    #include <stdio.h>

typedef struct ll {
    int code;
    char *data;
    struct ll *next;
} link_t;

typedef struct {
    int (*hash)(char *, int);
    link_t **ht;
    int size;
} hashtable_t;

// Hash function
int hash(char *key, int len);

// Create destroy table
hashtable_t *new_hashtable(int(*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
void destroy(link_t *ht);

// Handle table
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);

// Shared functions
int my_strlen(char *str);
void my_putstr(char *str);
char *my_strdup(char *str);
void my_putnbr(int number);
void my_putchar(char ch);

int shell(void);

#endif /* !SECURED_H_ */
