// Return false if the somePredicate function returns false for at
  // least one of the array elements; return true otherwise.
bool allTrue(const double a[], int n)
{
    if (n <= 0)
        return true;
    if ( ! somePredicate(a[0]))
        return false;
    return allTrue(a+1, n-1);
}

  // Return the number of elements in the array for which the
  // somePredicate function returns false.
int countFalse(const double a[], int n)
{
    if (n <= 0)
        return 0;
    int t = ! somePredicate(a[0]);  // 1 if false, 0 if true
    return t + countFalse(a+1, n-1);
}

  // Return the subscript of the first element in the array for which
  // the somePredicate function returns false.  If there is no such
  // element, return -1.
int firstFalse(const double a[], int n)
{
    if (n <= 0)
        return -1;
    if ( ! somePredicate(a[0]))
        return 0;
    int k = firstFalse(a+1, n-1);
    if (k == -1)
        return -1;
    return 1 + k;  // element k of "the rest of a" is element 1+k of a
}

  // Return the subscript of the smallest double in the array (i.e.,
  // the one whose value is <= the value of all elements).  If more
  // than one element has the same smallest value, return the smallest
  // subscript of such an element.  If the array has no elements to
  // examine, return -1.
int indexOfMin(const double a[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return 0;
    int k = 1 + indexOfMin(a+1, n-1);  // indexOfMin can't return -1 here
    return a[0] <= a[k] ? 0 : k;

    // Here's an alternative for the last two lines above:
    // int k = indexOfMin(a, n-1);  // indexOfMin can't return -1 here
    // return a[k] <= a[n-1] ? k : n-1;
}

  // If all n2 elements of a2 appear in the n1 element array a1, in
  // the same order (though not necessarily consecutively), then
  // return true; otherwise (i.e., if the array a1 does not include
  // a2 as a not-necessarily-contiguous subsequence), return false.
  // (Of course, if a2 is empty (i.e., n2 is 0), return true.)
  // For example, if a1 is the 7 element array
  //    10 50 40 20 50 40 30 
  // then the function should return true if a2 is
  //    50 20 30
  // or
  //    50 40 40
  // and it should return false if a2 is
  //    50 30 20
  // or
  //    10 20 20
bool includes(const double a1[], int n1, const double a2[], int n2)
{
    if (n2 <= 0)
        return true;
    if (n1 < n2)
        return false;

      // If we get here, a1 and a2 are nonempty
    if (a1[0] == a2[0])
        return includes(a1+1, n1-1, a2+1, n2-1);  // rest of a1, rest of a2
    else
        return includes(a1+1, n1-1, a2, n2);  // rest of a1, all of a2
}
