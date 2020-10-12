#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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

size_t	ht_hash(const char *key)
{
	size_t hash;

	for (; *key != '\0' ; key++)
		hash = (R_NUM * hash + *key) % HT_SIZE;
	return (hash);
}

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

	while (entry->next != NULL)
	{
		if (strcmp(entry->key, key) > 0)
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

	entry->next = ht_pair(key, value);
	
	return (entry->next);
}

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

int	main(void)
{
	t_ht	*ht = ht_create();

	ht_add(ht, "1", "tony");
	ht_add(ht, "2", "tonz");
	ht_add(ht, "3", "tont");
	ht_add(ht, "4", "tonu");
	ht_add(ht, "5", "toni");
	ht_add(ht, "6", "tona");
	ht_dump(ht);
	return (0);
}
