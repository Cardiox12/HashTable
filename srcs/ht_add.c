#include "ht_internals.h"
#include "hashtable.h"

t_entry *ht_add(t_ht *ht, const char *key, const char *value)
{
	size_t slot = ht_hash(key);
	
	
	t_entry *entry = ht->entries[slot];

	// Check if slot is not already taken
	if (entry == NULL)
	{
		ht->entries[slot] = ht_pair(key, value);
		return (entry);
	}
	
	char *tmp_value;

    // If slot is already taken, then find the next slot with same key
	while (entry->next != NULL)
	{
		if (strcmp(entry->key, key) == 0)
		{
			tmp_value = strdup(value);

			if (entry->value == NULL)
				return (NULL);

			free(entry->value);
			entry->value = tmp_value; 
			return (entry);
		}
		entry = entry->next;
	}

    // If no slot with the current key has been found
    // then set the current slot to the current key / value pair
	entry->next = ht_pair(key, value);
	
	return (entry->next);
}