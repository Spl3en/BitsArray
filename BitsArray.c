#include "BitsArray.h"
#include <stdlib.h>

// ---------- Debugging -------------
#define __DEBUG_OBJECT__ "BitsArray"
#include "dbg/dbg.h"

/*
 * Description 	: Allocate a new BitsArray structure.
 * Return		: A pointer to an allocated BitsArray.
 */
BitsArray *
BitsArray_new (
	byte *bytes,
	int bytesLen
) {
	BitsArray *this;

	if ((this = calloc (1, sizeof(BitsArray))) == NULL)
		return NULL;

	if (!BitsArray_init (this, bytes, bytesLen)) {
		BitsArray_free (this);
		return NULL;
	}

	return this;
}


/*
 * Description : Initialize an allocated BitsArray structure.
 * BitsArray *this : An allocated BitsArray to initialize.
 * Return : true on success, false on failure.
 */
bool
BitsArray_init (
	BitsArray *this,
	byte * bytes,
	int bytesLen
) {
	this->bitsCount = 0;
	this->bits = calloc (1, sizeof (byte) * bytesLen * 8);

    for (int i = 0; i < bytesLen; i++) {
        for (int j = 0 ; j < 8; j++) {
            this->bits[this->bitsCount++] = (bytes[i] & (1 << j)) >> j;
        }
    }

	return true;
}


/*
 * Description : Free an allocated BitsArray structure.
 * BitsArray *this : An allocated BitsArray to free.
 */
void
BitsArray_free (
	BitsArray *this
) {
	if (this != NULL)
	{
		free (this->bits);
		free (this);
	}
}

