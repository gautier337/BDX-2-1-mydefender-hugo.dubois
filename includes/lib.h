/*
** EPITECH PROJECT, 2022
** header lib
** File description:
** lib
*/

#ifndef lib
    #define lib

int my_strlen (char const *str);
int my_strcmp (char const *s1, char const *s2);
char *my_strcat(char *src, char *dest);
int my_putstr (char const *str);
int my_putchar(char c);
char **str_to_array(char *string, char *seperators);
int count_sep(char *string, char *separators);
char *next_word(char *string, char *separators);
int lenght_word_in_string(char *string, char *separators);
char *forward_sentence_first_word(char *sentence, char *separators);
int count_size_argv(char **argv);
int lenght_int(int nbr);
char *int_in_string(int nbr);

#endif
