//
//  DNA_Strand h.h
//  DNA Test
//
//  Created by Jacoby Kang on 5/17/15.
//  Copyright (c) 2015 Jacoby Kang. All rights reserved.
//

// Description: This will be an DNA_Strand implemented with a static array of chars.


#ifndef DNA_STRAND_H
#define DNA_STRAND_H

#include <string>
using namespace std;

//Size of static DNA Array
const size_t MAX_DNA = 50;

class DNA_Strand
{
    
private:
    // Returns true if index is within range of the current DNA_Strand
    // else returns false.
    bool inRange (size_t index) const;
    
    // Current size of the DNA_Strand; i.e., how many elements of the array are
    // currently being used (since this is a partially-filled array)
    size_t mySize;
    
    // DNA_Strandís storage buffer. May only be partially filled.
    char myDNA[MAX_DNA];
    
    
public:
    // Create an empty DNA_Strand.
    DNA_Strand ();  // deafult ctor
    
    // Create an initialized DNA_Strand.
    // If the string ipStr is larger than MAX_DNA, then only the first MAX_DNA
    // characters of ipStr are used to initialize the DNA_Strand
    DNA_Strand (const string & ipStr);  // ctor that takes a string
    
    //toString
    //Returns string equivalent of the DNA
    string toString() const;
    
    // Set an item in the DNA_Strand at location index. Throws
    // <std::out_of_range> if index is out of range, i.e., larger than the
    // current size of the DNA_Strand.
    // Uses zero-based indexing.
    void set (char new_item, size_t index);
    
    // Get an item in the DNA_Strand at location index. Throws
    // <std::out_of_range> if index is out of range, i.e., larger than the
    // current size of the DNA_Strand.
    // Uses zero-based indexing.
    char get (size_t index) const;
    
    // Returns the current size of the DNA.
    size_t size () const;
    
    size_t maxSize() const;

    // Compare this DNA_Strand with s for equality. Returns true if the
    // size()ís of the two DNA_Strands are equal and all the elements from 0
    // .. size()-1 are equal, else false.
    bool isEqual(const DNA_Strand & s) const;
    
    
    // search
    // Look for target in current DNA strand and return index.
    // Return -1 if not found.
    int search(const string & target) const;
    
    // search with start position specified
    // Look for target in current DNA strand and return index.
    // Return -1 if not found. If pos is past end of strand, return -1.
    int search(size_t pos, const string & target) const;
    
    // cleave
    // Removes from current DNA strand the sequence between the end of the
    // first occurrence of passed target sequence (e.g. "TTG"), through the end
    // of the second occurence of the target sequence.
    // pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG"
    // post: ACTTGA  (ACCTTG removed)
    void cleave(const string & target);
    
    // cleave with start position specified
    // cleave starting from an index, returns the index after the cleaved DNA
    // or -1 if no cleaving was performed
    // pre: Array e.g. ACTTGACCTTGA and target e.g. "TTG", pos = 1
    // post: ACTTGA  (ACCTTG removed) and return value = 5
    int cleave(size_t pos, const string & target);
    
    // cleaveAll
    // Removes from current DNA strand the sequence between pairs of target
    // sequence, i.e. from the end 1 through the end of 2, from the end of 3
    // through the end of 4, etc, but NOT from the end of 2 through the end 3,
    // or from the end of 4 through the end of 5.
    // (Make sure that you understand the specification)
    // pre: Array e.g. ACTTGATTGGGTTGCTTGCC and target e.g. "TTG"
    // post: ACTTGGGTTGCC (ATTG and CTTG removed)
    void cleaveAll(const string & target);
    
    
    // countEnzyme
    // Counts the number of occurences of a single character target sequence
    // in the DNA strand.
    size_t countEnzyme(char target) const;
};

#endif
