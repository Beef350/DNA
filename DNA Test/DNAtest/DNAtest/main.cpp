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
    }
    //test isEqual with non-empty DNA with different values.
    DNA_Strand dna_4("ACTTGGATTGTTGA");
    
    if (!dna.isEqual(dna_4)) {
        //cout << "isEqual works" << endl;
    }
    else {
        cout << "isEqual test fail" << endl;
    }
    
    //create another non-empty DNA that isn't equal to the first one
    ipStr = "ACTTGACTGTTG";
    DNA_Strand dna3(ipStr);
    
    //Test isEqual with another non-empty DNA that isn't equal to the first one
    if (!dna.isEqual(dna3)) {
        //cout<<"result for isEqual with another non-empty DNA is as expected" <<endl;
    }
    else {
        cout << "Test 8 Fail" << endl;
    }
    //done with isEqual testing
    
    //empty DNA and non-empty
    if (dna_2.isEqual(dna3)) {
        cout << "isEqual Test faul" << endl;
    }
    
    //start testing search
    //define target to be searched
    string target = "TTG";
    string target3 = "TTGTTGTTGTTGTTGTTGAC";
    
    //test the search method in dna that contains target
    //start position not specified
    if (dna3.search(target) == 2) {
        //cout<< "search works as expected" <<endl;
    }
    else {
        cout << "Test 9 Fail" << endl;
    }
    
    //start position specified
    if (dna3.search(4, target) == 9) {   // start position after the first occurence of the target
        //cout << "search works as expected" << endl;
    }
    else {
        cout << "Test 10 Fail" << endl;
    }
    //test the search methods with target length larger than the dna.
    if (dna3.search(target3) == -1) {
        //cout<< "search works" << endl;
    }
    else {
        cout << "new search test fail" << endl;
    }
    
    if (dna3.search(3, target3) == -1) {
        //cout<< "search works" << endl;
    }
    else {
        cout << "new search test 2 fail" << endl;
    }
    
    //search empty target
    if (dna3.search(0, "") != -1) {
        cout << "empty search test fail" << endl;
    }
    //test the search method in dna that does not contain the target
    if (dna.search(target) == -1) {							//start position unspecified
        //cout<< "search works as exptected" <<endl;
    }
    else {
        cout << "Test 11 Fail" << endl;
    }
    if (dna.search(3, target) == -1) {						//search with start position specified.
        //cout<< "search works as expected" << endl;
    }
    else {
        cout << "Test 12 Fail" << endl;
    }
    
    //Test get method
    if (dna.get(1) == 'B') {		//dna contains "ABCCTG" from above.
        //cout<< "get method works as expected" << endl;
    }
    else {
        cout << "Test 13 Fail" << endl;
    }
    