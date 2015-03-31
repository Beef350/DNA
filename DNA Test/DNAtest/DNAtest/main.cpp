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

    if (!dna_1.isEqual(dna_2)) {
        cout << "Test 2 FAIL" << endl;
    }
    //else {
    //	cout << "Equal test works on two blank DNA." << endl;
    //}
    
    if (!dna_2.isEqual(dna_1)) {
        cout << "Test 3 FAIL" << endl;
    }
    //else {
    //	cout << "Equal test is reflective." << endl;
    //}
    
    // create a non-empty DNA
    string ipStr = "ABCCTG";
    DNA_Strand dna(ipStr);
    
    //toString should return the contents as a string
    if (dna.toString() == ipStr) {
        //cout<<"Result for toString is as expected"<<endl;
    }
    else {
        cout << "Test 4 FAIL." << endl;
    }

    //test size for non-empty string
    if (dna.size() == 6) {
        //cout<< "Result for size is as expected"<<endl;
    }
    else {
        cout << "Test 5 Fail." << endl;
    }
    
    
    //Test for Assignment operator
    dna_1 = dna_3;
    if (dna_1.toString() != "ACTGACTGG" || dna_1.maxSize() != 9) {
        cout << "Assignment Operator test fail" << endl;
    }
    
    //create another non-empty DNA
    DNA_Strand dna2(ipStr);
    
    // Test isEqual for non-empty DNA
    if (dna.isEqual(dna2)) {
        // cout<< "Result for isEqual is as expected"<<endl;
    }
    else {
        cout << "Test 6 Fail" << endl;
    }
    
    // Test isEqual with empty DNA as well
    if (!dna.isEqual(dna_1)) {
        //cout<< "Result for isEqual dna_1  is as expected"<<endl;
    }
    else {
        cout << "Test 7 Fail" << endl;
1