#include "hashtable.h"

int	main(void)
{
	t_ht	*ht = ht_create();

	ht_add(ht, "1", "tony");
	ht_add(ht, "2", "tonz");
	ht_add(ht, "3", "tont");
	ht_dump(ht);
	return (0);
}
