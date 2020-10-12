#ifndef HT_INTERNALS_H
# define HT_INTERNALS_H

# include "hashtable.h"

size_t	ht_hash(const char *key);
t_entry *ht_pair(const char *key, const char *value);

#endif