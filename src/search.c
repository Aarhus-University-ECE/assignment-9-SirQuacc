#include "search.h"
#include <stdbool.h>
#include <assert.h>

bool search(int a[], int n, int x)
{
    assert(!(n < 0)); // Can't search an array of lower than 0 length
    if(n == 0){ //Base case, if we're beyond the array, element x wasn't in there,
        return false;
    }
    if(x == a[n-1]){ //Recusively check with linear search if x is equal to any element in the array of length n.
        return true;
    } else return search(a, n-1, x);
}