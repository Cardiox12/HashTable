#include "hashtable.h"

t_ht	*ht_create(void)
{
	t_ht *ht;

	ht = malloc(sizeof(ht));
	if (ht == NULL)
		return (NULL);
	
	ht->entries = malloc(sizeof(t_entry*) * HT_SIZE);

	if (ht->entries == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (int i = 0 ; i < HT_SIZE ; i++)
		ht->entries[i] = NULL;
	return (ht);
}