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

// cleave
// Removes from current DNA strand the sequence between the end of the
// first occurrence of passed target sequence (e.g. "TTG"), through the end
// of the second occurence of the target sequence.
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
// post: ACTTGA  (ACCTTG removed)
void DNA_Strand::cleave(const string & target)
{
    int i = search(target) + target.length();
    int j = search(i, target);
    if (j != -1) {							//if statement only works when target is found.
        j += target.length();
        mySize -= (j - i);
        while (i < mySize) {
            set(myDNA[j],i);
            i++;
            j++;
        }
    }
}


// cleave with start position specified
// cleave starting from an index, returns the index after the cleaved DNA
// or -1 if no cleaving was performed
// pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG", pos = 1
// post: ACTTGA  (ACCTTG removed) and return value = 5
int DNA_Strand::cleave(size_t pos, const string & target)
{
    int i = search(pos, target);
    if (i != -1)
        i += target.length();
    int j = search(i, target);
    size_t index = i;
    if (j != -1) {							//if statement only works when target is found.
        j += target.length();
        mySize -= (j - i);
        while (i < mySize) {
            set(myDNA[j], i);
            i++;
            j++;
        }
        return index;
    }
    return -1;  
}

// cleaveAll
// Removes from current DNA strand the sequence between pairs of target
// sequence, i.e. from the end 1 through the end of 2, from the end of 3
// through the end of 4, etc, but NOT from the end of 2 through the end 3,
// or from the end of 4 through the end of 5.
// pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
// post: ACTTGGGTTGCC (ATTG and CTTG removed)
void DNA_Strand::cleaveAll(const string & target)
{
    int i = 0;
    while ( i != -1) {
        i = cleave(i, target);
    }
}

// countEnzyme
// Counts the number of occurences of a single character target sequence
// in the DNA strand.
size_t DNA_Strand::countEnzyme(char target) const
{
    size_t count = 0;
    for (size_t i = 0; i < mySize; i++) {
        if (get(i) == target) {
            count++;
        }
    }
    return count;
}


// inRange : helper function
// Returns true if index is within range, i.e., 0 <= index < mySize
// else returns false.
bool DNA_Strand::inRange (size_t index) const
{
    if (index >= mySize) {
        return false;
    }
    else {
        return true;
    }
}


