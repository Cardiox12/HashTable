/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 23:11:43 by bbellavi          #+#    #+#             */
/*   Updated: 2020/10/14 23:53:06 by bbellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ht_internals.h"
#include "hashtable.h"

char    *ht_get(t_ht *ht, const char *key)
{
    const size_t slot = ht_hash(key);

    t_entry *entry = ht->entries[slot];

    // If entry is null, there is no found
    if (entry == NULL)
        return (NULL);

    // Otherwise, there is a result, but we must ensure that the entry
    // correspond to the right key.
    
    // If there are no next pair of key/value, and key match, then
    // we have found our value.
    if (entry->next == NULL && strcmp(key, entry->key) == 0)
        return (entry->value);
    
    while (entry != NULL)
    {
        if (strcmp(key, entry->key) == 0)
            return (entry->value);
        entry = entry->next;
    }
    return (NULL);
}