#include <stdio.h>
#include "hashtable.h"

void	ht_dump(t_ht *ht)
{
	for (int i = 0 ; i < HT_SIZE ; i++)
	{
		printf("ht[%4i] = ", i);
		for (t_entry *entry = ht->entries[i] ; entry != NULL ; entry = entry->next)
			printf("('%s', '%s')", entry->key, entry->value);
		printf("\n");
	}
}