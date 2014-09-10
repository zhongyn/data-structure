#ifndef DYN_ARR_DICT_H
#define DYN_ARR_DICT_H 

#ifndef KEYTYPE
#define KEYTYPE char*
#endif

#ifndef VALUETYPE
#define VALUETYPE double
#endif

struct association
{
	KEYTYPE key;
	VALUETYPE value;
};

#define TYPE struct association*

#include "dynArr.h"

VALUETYPE dynArrDictGet(DynArr *v, KEYTYPE key);
void dynArrDictPut(DynArr *v, KEYTYPE key, VALUETYPE value);
int dynArrDictContainsKey(DynArr *v, KEYTYPE key);
void dynArrDictRemoveKey(DynArr *v, KEYTYPE key);


#endif