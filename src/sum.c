#include "sum.h"
#include <assert.h>

int sum(int a[], int n)
{
    assert(!(n < 0)); // Can't search an array of lower than 0 length
    if(n == 0){
        return 0; //Base case, we're at the end of he array, return 0 as the "sum" of nothing
    }
    else return a[n-1] + sum(a, n-1); //Recursively ask for the sum of the next number, and add it to the current
}