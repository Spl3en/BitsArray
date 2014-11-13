// --- Author : Moreau Cyril - Spl3en
#pragma once

// ---------- Includes ------------
#include "Utils/Utils.h"

// ---------- Defines -------------


// ------ Structure declaration -------
typedef struct _BitsArray
{
	byte *bits;
	int bitsCount;

}	BitsArray;



// --------- Allocators ---------

/*
 * Description 	: Allocate a new BitsArray structure.
 * Return		: A pointer to an allocated BitsArray.
 */
BitsArray *
BitsArray_new (
	unsigned char *bytes,
	int bytesLen
);

// ----------- Functions ------------

/*
 * Description : Initialize an allocated BitsArray structure.
 * BitsArray *this : An allocated BitsArray to initialize.
 * Return : true on success, false on failure.
 */
bool
BitsArray_init (
	BitsArray *this,
	unsigned char * bytes,
	int bytesLen
);

// --------- Destructors ----------

/*
 * Description : Free an allocated BitsArray structure.
 * BitsArray *this : An allocated BitsArray to free.
 */
void
BitsArray_free (
	BitsArray *this
);


