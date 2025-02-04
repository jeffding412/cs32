//
//  tree.cpp
//  tree
//
//  Created by Jeffrey Ding on 2/12/18.
//  Copyright © 2018 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    10 50 40 20 50 40 30
// then for this value of a2     the function must return
//    10 20 40            1
//    10 40 30            2
//    20 10 40            0
//    50 40 30            3
int countIncludes(const double a1[], int n1, const double a2[], int n2)
{
    if (n2 == 0) {      //if a2 runs out, all of a2 is in a1
        return 1;
    }
    if (n1 == 0) {      //if a1 runs out before a2, a2 is not all in a1
        return 0;
    }
    
    //if the first elements are the same, recursively check the next elements and the next a1 element
    if (a1[0] == a2[0]) {
        return countIncludes(a1+1, n1-1, a2+1, n2-1) + countIncludes(a1+1, n1-1, a2, n2);
    }
    else {
        return countIncludes(a1+1, n1-1, a2, n2);   //else check the next a1 element recursively
    }
}

// Exchange two doubles
void exchange(double& x, double& y)
{
    double t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is > splitter come before all the other elements,
// and all the elements whose value is < splitter come after all
// the other elements.  Upon return, firstNotGreater is set to the
// index of the first element in the rearranged array that is
// <= splitter, or n if there is no such element, and firstLess is
// set to the index of the first element that is < splitter, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotGreater, a[i] > splitter
//   * for firstNotGreater <= i < firstLess, a[i] == splitter
//   * for firstLess <= i < n, a[i] < splitter
// All the elements > splitter end up in no particular order.
// All the elements < splitter end up in no particular order.
void split(double a[], int n, double splitter,
           int& firstNotGreater, int& firstLess)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotGreater <= firstUnknown and firstUnknown <= firstLess
    //  Every element earlier than position firstNotGreater is > splitter
    //  Every element from position firstNotGreater to firstUnknown-1 is
    //    == splitter
    //  Every element from firstUnknown to firstLess-1 is not known yet
    //  Every element at position firstLess or later is < splitter
    
    firstNotGreater = 0;
    firstLess = n;
    int firstUnknown = 0;
    while (firstUnknown < firstLess)
    {
        if (a[firstUnknown] < splitter)
        {
            firstLess--;
            exchange(a[firstUnknown], a[firstLess]);
        }
        else
        {
            if (a[firstUnknown] > splitter)
            {
                exchange(a[firstNotGreater], a[firstUnknown]);
                firstNotGreater++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] >= a[1] >= a[2] >= ... >= a[n-2] >= a[n-1]
// If n <= 1, do nothing.
void order(double a[], int n)
{
    if (n <= 1)     //base case, if n <= 1, do nothing
        return;
    
    int firstNotGreater;                                //holds index of first element not greater
    int firstLess;                                      //holds index of first element less
    split(a, n, a[n/2], firstNotGreater, firstLess);    //split array with the middle element
    order(a, firstNotGreater);                          //recursively order the first half of the array that are greater than the middle element
    order(a+firstLess, n-firstLess);                    //recursively order the second half of the array that are less than the middle element
}

int main() {
    double a1[7] = {10, 50, 40, 20, 50, 40, 30};
    double a2[3] = {10, 40, 30};
    cout << countIncludes(a1, 7, a2, 3) << endl;
    order(a1, 7);
    for (int x = 0; x < 7; x++) {
        cout << a1[x] << endl;
    }
    
}
