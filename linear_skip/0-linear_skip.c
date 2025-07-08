#include "search.h"
#include <stdio.h>

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = NULL, *max_express = NULL;
	char *outputf_checked = "Value checked at index [%ld] = [%d]\n";
	char *outputf_found = "Value found between indexes [%ld] and [%ld]\n";

	if (!list)
		return (NULL);

	tmp = list;
	tmp = tmp->express;
	while (tmp->express)
	{
		printf(outputf_checked, tmp->index,
			   tmp->n);

		if (tmp->express->n > value)
		{
			max_express = tmp->express;
			
			printf(outputf_checked, max_express->index, max_express->n);

			printf(outputf_found, tmp->index,
				   max_express->index);
			while (tmp->index < max_express->index)
			{
				printf(outputf_checked, tmp->index, tmp->n);

				if (tmp->n == value)
					return (tmp);

				tmp = tmp->next;
			}
		}

		tmp = tmp->express;
	}

}
