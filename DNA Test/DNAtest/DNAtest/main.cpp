//
//  main.cpp
//  DNAtest
//
//  Created by Jacoby Kang on 3/2/15.
//  Copyright (c) 2015 Jacoby Kang. All rights reserved.
//

#include <iostream>
#include "DNA_Strand.h"

using namespace std;


int main()
{
    
    cout << "this is for project" << endl;
    //Testing whether constructors properly work
    DNA_Strand dnaTest("ATGCAATGCAATGCAATGCAATGCAATGCAATGCAATGCAATGCAATGCAAAA");
    
    if (dnaTest.toString() == "ATGCAATGCAATGCAATGCAATGCAATGCAATGCAATGCAATGCAATGCAAAA") {
        //cout << "the consturctor works" << endl;
    }
    else {
        cout << "Constrcutor Test Fail" << endl;
    }

    // testing functions of the DNA_Strand class
    
    DNA_Strand dna_1, dna_2;
    //Test for size method
    if (dna_1.size() != 0) {
        cout << "Test 1 FAIL" << endl;
    }
    //else {
    //	cout << "Initial size for blank DNA is correct." << endl;
    //}

    //Test for maxSize method
    if (dna_1.maxSize() != 50) {
        cout << "Size test 2 Fail" << endl;
    }
    
    //maxSize and size on non-empty String
    DNA_Strand dna_3("ACTGACTGG");
    if (dna_3.maxSize() != 9 || dna_3.size() != 9 || dna_3.maxSize() != 9) {
        cout << "Size test 3 Fail" << endl;
    }
