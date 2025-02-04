//
//  linear.cpp
//  linear
//
//  Created by Jeffrey Ding on 2/9/18.
//  Copyright © 2018 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

bool somePredicate(double x)
{
    return x < 0;
}

// Return false if the somePredicate function returns false for at
// least one of the array elements; return true otherwise.
bool allTrue(const double a[], int n)
{
    if (n == 0) {                   //base case
        return true;
    }
    if (!somePredicate(a[n-1])) {   //if somePredicate returns false, return false
        return false;
    }
    return allTrue(a, n-1);         //go to next recursive function
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const double a[], int n)
{
    if (n == 0) {                        //base case
        return 0;
    }
    if (!somePredicate(a[n-1])) {        //if somePredicate returns false, return 1 + next recursive function
        return 1 + countFalse(a, n-1);
    }
    else {                               //else return next recursive function
        return countFalse(a, n-1);
    }
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const double a[], int n)
{
    if (n == 0) {                           //if array is empty, return -1
        return -1;
    }
    if (!somePredicate(a[0])) {             //if element is false, return 0
        return 0;
    }
    int index = 1 + firstFalse(a+1, n-1);   //recursively tracks first false
    if (index == 0) {                       //if index is 0, return -1;
        return -1;
    }
    return index;                           //return index
}

// Return the subscript of the smallest double in the array (i.e.,
// the one whose value is <= the value of all elements).  If more
// than one element has the same smallest value, return the smallest
// subscript of such an element.  If the array has no elements to
// examine, return -1.
int indexOfMin(const double a[], int n)
{
    if (n == 0) {                           //return -1 for no elements
        return -1;
    }
    if (n == 1) {                           //return 0 for one element
        return 0;
    }
    if (a[n-1] < a[indexOfMin(a, n-1)]) {   //if the last index is less than the min Index, return the last index
        return n-1;
    }
    return indexOfMin(a, n-1);              //recursively return the min index
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
    if (n2 == 0) {      //if a2 becomes empty first, all values are in a1
        return true;
    }
    if (n1 == 0) {      //if a1 becomes empty first, all values of a2 are not in a1
        return false;
    }
    
    if (a1[0] == a2[0]) {                           //if first elements of both array are equal
        return includes(a1+1, n1-1, a2+1, n2-1);    //recursively move on to next elements
    }
    else {
        return includes(a1+1, n1-1, a2, n2);        //else move on to next element in first array
    }
}

int main()
{
    double a1[7] = { 10, 50, 40, 20, 50, 40, 30 };
    double a2[3] = { 10, 20, 20};
    cout << allTrue(a1, 7) << endl;
    cout << countFalse(a2, 3) << endl;
    cout << indexOfMin(a1, 7) << endl;
    cout << includes(a1, 7, a2, 3) << endl;
}
