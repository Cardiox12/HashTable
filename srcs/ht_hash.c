#include "hashtable.h"

size_t	ht_hash(const char *key)
{
	size_t hash;

	for (; *key != '\0' ; key++)
		hash = (R_NUM * hash + *key) % HT_SIZE;
	return (hash);
}