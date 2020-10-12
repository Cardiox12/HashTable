#ifndef HASHTABLE
# define HASHTABLE

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

# define HT_SIZE 10
# define R_NUM 31

typedef struct entry_t {
	char *key;
	char *value;
	struct entry_t *next;
}	t_entry;

typedef struct {
	t_entry **entries;
}	t_ht;

t_entry *ht_add(t_ht *ht, const char *key, const char *value);
t_ht	*ht_create(void);
void	ht_dump(t_ht *ht);

#endif
