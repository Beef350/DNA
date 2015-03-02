//
//  main.cpp
//  DNA_Strand
//
//  Created by Jacoby Kang on 3/2/15.
//  Copyright (c) 2015 Jacoby Kang. All rights reserved.
//

#include "DNA_Strand.h"
#include <stdexcept>
using namespace std;

// Constructor
// Create an empty DNA_Strand.
DNA_Strand::DNA_Strand() : mySize(0)
{
}

// Constructor
// Create an initialized DNA_Strand.
// If the string ipStr is larger than MAX_DNA, then only the first MAX_DNA
// characters of ipStr are used to initialize the DNA_Strand
DNA_Strand::DNA_Strand(const string & ipStr)										//TEST FOR dna SIZE MORE THAN 50.
{
    if (ipStr.length() > MAX_DNA) {
        mySize = MAX_DNA;
    }
    else {
        mySize = ipStr.length();
    }
    
    for (size_t i = 0; i < mySize; i++) {
        myDNA[i] = ipStr[i];
    }
}


//toString
//Returns string equivalent of the DNA
string DNA_Strand::toString() const
{
    string dna = "";
    for (size_t i = 0; i < mySize; i++) {
        dna += get(i);
    }
    return dna;  // replace with your code
}


// Set an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than the
// current size of the DNA_Strand.
// Uses zero-based indexing.
void DNA_Strand::set (char new_item, size_t index)
{
    if (!inRange(index)) {
        throw std::out_of_range("index is larger than the current size of the DNA_Strand");
    }
    else {
        myDNA[index] = new_item;
    }
}

// Get an item in the DNA_Strand at location index. Throws
// <std::out_of_range> if index is out of range, i.e., larger than the
// current size of the DNA_Strand.
// Uses zero-based indexing.
char DNA_Strand::get (size_t index) const
{
    if (!inRange(index)) {
        throw std::out_of_range("index is larger than the current size of the DNA");
    }
    else {
        return myDNA[index];
    }
}


// Returns the current size of the DNA.
size_t DNA_Strand::size () const
{
    return mySize;
}


// isEqual
// Compare this DNA_Strand with s for equality. Returns true if the
// size()ís of the two DNA_Strands are equal and all the elements from 0
// .. size()-1 are equal, else false.
bool DNA_Strand::isEqual (const DNA_Strand &s) const
{
    for (size_t i = 0; i < mySize ; i++) {
        if (mySize != s.mySize || myDNA[i] != s.myDNA[i]) {
            return false;
        }
    }
    return true;
}


// search
// Look for target in current DNA strand and return index.
// Return -1 if not found.
int DNA_Strand::search(const string & target) const
{
    size_t i = 0;
    int j = -1;						//a random number assigned to j for the sake of initalization.
    while (i < mySize) {
        if (myDNA[i] == target[0]) {
            j = target.length() - 1;
            while (j>0 && myDNA[i + j] == target[j]) {
                j--;
            }
        }
        if (j == 0) {
            return i;
        }
        else {
            i++;
        }
    }
    return -1;
}

// search
// search with start position specified
// Look for target in current DNA strand and return index.
// Return -1 if not found. If pos is past end of strand, return -1.
int DNA_Strand::search(size_t pos, const string & target) const
{
    size_t i = pos;
    int j = -1;               //a number that would never be used assigned to j for the sake of initalization.
    while (i < mySize) {
        if (get(i) == target[0]) {
            j = target.length() - 1;
            while (j>0 && myDNA[i + j] == target[j]) {					//starts searching from the back of the target
                j--;
            }
        }
        if (j == 0) {
            return i;								
        }
        else {
            i++;
        }
    }
    return -1;  
}

