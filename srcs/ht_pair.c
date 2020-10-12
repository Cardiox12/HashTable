#include "hashtable.h"

t_entry *ht_pair(const char *key, const char *value)
{
	t_entry *entry = malloc(sizeof(entry));

	entry->key = strdup(key);
	
	if (entry->key == NULL)
	{
		free(entry);
		return (NULL);
	}

	entry->value = strdup(value);

	if (entry->value == NULL)
	{
		free(entry->key);
		free(entry);
		return (NULL);
	}

	entry->next = NULL;
	
	return (entry);
}