#include "main.h"

/**
 * bfree - frees a pointer and NULLS the address
 * @ptr: address of the pointer to free
 *
 * Returnn: 1 if frred, otherwise 0
 */
int bfree(void _ptr)
{
	if (_ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
