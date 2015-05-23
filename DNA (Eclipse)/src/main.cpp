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
        //cout << "the constructor works" << endl;
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
    
    //handle exceptions for get method
    //handle exception for trying to get a character from an empty index.
    try {
        cout << "Expect to end with an \"out_of_range\" exception" << endl;
        cout << "The 20th character of dna is: " << dna.get(19) << endl;   // This statement will throw an exception
        cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE" << endl;
    }
    catch (std::out_of_range& excpt) {
        cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
    }
    
    //handle exception for trying to search an index that's not in the array's range. ( not completely necessary)
    try {
        cout << "Expect to end with an \"out_of_range\" exception" << endl;
        cout << "The 20th character of dna is: " << dna.get(52) << endl;   // This statement will throw an exception
        cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE" << endl;
    }
    catch (std::out_of_range& excpt) {
        cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
    }
    
    //Test set method
    dna.set('A', 1); //dna contains "ABCCTG" from above.
    if (dna.toString() == "AACCTG") {						//size should have increased by 1
        //cout << set method worked as expected"" << endl;
    }
    else {
        cout << "Test 14 Fail" << endl;
    }
    
    //handle exception for set method
    try {
        cout << "Expect to end with an \"out_of_range\" exception" << endl;
        dna.set('A', 6);													//This statement will throw an exception
        cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE" << endl;
    }
    catch (std::out_of_range& excpt) {
        cout << "Exception was properly thrown and caught :: " << excpt.what() << endl;
    }
    
    //Test for cleave method
    //cleave without starting position specified
    dna3.cleave(target);  //dna3 contains "ACTTGACTGTTG" from above.
    
    if (dna3.toString() == "ACTTG") {
        //cout << "cleave works as expected" << endl;
    }
    else {
        cout << "Test 15 Fail" << endl;
    }
    
    DNA_Strand dna4("ACTTGACTGTTG");  //new DNA
    //test whether the cleave method returns the proper index after the cleaved segment(in this case, the index is empty)
    if (dna4.cleave(1, target) == 5 && dna4.toString() == "ACTTG") {
        //cout << "cleave works as expected" << endl;
    }
    else {
        cout << "Test 16 Fail" << endl;
    }
    
    DNA_Strand dna5("ACTTGACTTGTGTTGAG"); // new DNA that would have characters left after cleaving and contains multipe targets
    if (dna5.cleave(4, target) == 10 && dna5.toString() == "ACTTGACTTGAG") {  //cleaving skips the first target
        //cout <<"cleave works as expected" << endl;
    }
    else {
        cout << "Test 17 Fail" << endl;
    }
    
    //cleaving from an out of range position
    if (dna5.cleave(30, target) == -1) {
        //cout << "cleave works" << endl;
    }
    else {
        cout << "Test 18 Fail" << endl;
    }
    
    //cleave with only one target occurence.
    DNA_Strand dna9("ACTTGACDT");
    
    //cleave when target is at the end.
    DNA_Strand dna10("ACTTDCGTTG");
    
    dna9.cleave(target);
    dna10.cleave(target);
    if (dna9.toString() != "ACTTGACDT" || dna10.toString() != "ACTTDCGTTG") {
        cout << "cleave test fail" << endl;
    }
    
    if (dna9.cleave(1, target) != -1 || dna10.cleave(1, target) != -1) {
        cout << "cleave test 2 fail" << endl;
    }
    
    //new target
    string target2 = "TAGC";
    //testing for a case when target is not contained.
    if (dna5.cleave(0, target2) == -1) {
        //cout << "cleave works" << endl;
    }
    else {
        cout << "Test 19 Fail" << endl;
    }
    //same test as the previous for the other cleave method without specified position
    DNA_Strand dna6("ATGCATGCAT");
    dna6.cleave(target2);
    if (dna6.toString() == "ATGCATGCAT") {				//dna6 should remain the same.
        //cout<<"cleave works" << endl;
    }
    else {
        cout << "Test 20 Fail" << endl;
    }
    
    
    //new dna for cleave all
    DNA_Strand dna7("ACTTGATTGGGTTGCTTGCC");
    
    //Test cleaveAll
    dna7.cleaveAll(target);			//cleaves all occurences of the target.
    if (dna7.toString() == "ACTTGGGTTGCC") {
        //cout << "cleaveAll works" << endl;
    }
    else {
        cout << "Test 21 Fail" << endl;
    }
    
    dna7.cleaveAll(target2);   //test the case when the target passed is not in the sequence.
    if (dna7.toString() == "ACTTGGGTTGCC") {    //dna7 should not have changed.
        //cout << "cleaveAll works" << endl;
    }
    else {
        cout << "Test 22 Fail" << endl;
    }
    
    //Test countEnzayme method
    if (dna7.countEnzyme("T") == 4) {
        //cout << "countEnzyme works" << endl;
    }
    else {
        cout << "Test 23 Fail" << endl;
    }
    
    DNA_Strand dna8("ACTACTACTACTA");   // no occurences of 'G'
    //test for a non-match
    
    if (dna8.countEnzyme("G") == 0) {
        //cout << "countEnzyme works" << endl;
    }
    else {
        cout << "Test 24 Fail" << endl;
    }
    //Test overloaded countEnzyme method.
    
    if (dna8.countEnzyme("ACT") != 4) {
        cout << "countEnzyme test fail" << endl;
    }
    
    //Test empty DNA too
    if (dna_2.countEnzyme("ACT") != 0) {
        cout << "coutENzyme test on empty fail" << endl;
    }
    
    //Test when no target is found.
    if (dna8.countEnzyme("ACG") != 0) {
        cout << "countEnzyme test 2 fail" << endl;
    }
    
    DNA_Strand dna12("AAAAAAAAAAAAAAAA");
    string target5 = "AAA";
    //overlapping target test.
    if (dna12.countEnzyme(target5)!= 5) {
        cout << "coutEnzyme test 3 fail" << endl;
    }
    //testing whether a lower case typo is caught, which counts as a non-match.
    if (dna8.countEnzyme("a") == 0) {
        //cout<< "target is not a proper input" <<endl;
    }
    else {
        cout << "Test 25 Fail" << endl;
    }
    
    //Testing whether an incorrect input for DNA characters is catched.
    if (dna8.countEnzyme("B") == 0) {
        //cout << "target is not a proper DNA character input << endl;
    }
    else {
        cout << "Test 26 Fail" << endl;
    }
    
    //Test grow()
    dna12.grow(60);
    if (dna12.maxSize() != 60) {
        cout << "Test Grow fail" << endl;
    }
    //searching for the previous content of DNA to ensure everything was copied properly.
    if (dna12.search("AAAAAAAAAAAAAAAA") != 0) {
        cout << "Test2 grow fail" << endl;
    }
    //Test grow on empty string
    dna_2.grow(60);
    if (dna_2.maxSize() != 60) {
        cout << "Test Grow 3 fail" << endl;
    }
    string target7 = "ACTTGA";
    DNA_Strand dna20(target7);
    string target8 = "ACCTG";
    DNA_Strand dna21(target8);
    
    //Test append() method
    dna20.append(target8);
    if (dna20.toString() != "ACTTGAACCTG") {
        cout << "Append test 1 Fail";
    }
    
    //appending with dna object that contains "ACCTG"
    dna20.append(dna21);
    if (dna20.toString() != "ACTTGAACCTGACCTG") {
        cout << "Append test 2 Fail" << endl;
    }
    
    //with empty string
    DNA_Strand dnaEmpty1;
    dnaEmpty1.append("");
    if (dnaEmpty1.toString() != "" || dnaEmpty1.size() != 0) {
        cout << "Append test 3 FAil" << endl;
    }
    
    dnaEmpty1.append("ACCTG");
    if (dnaEmpty1.toString() != "ACCTG") {
        cout << "Append test 4 Fail" << endl;
    }
    
    //with the input bigger than the arraySize;
    
    DNA_Strand dnaEmpty2;
    string target10 = "ACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGT";
    dnaEmpty2.append(target10);
    if (dnaEmpty2.toString() != "ACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGT" ||
        dnaEmpty2.size() != target10.length()) {
        cout << "Append test 5 Fail" << endl;
    }
    //with a non-empty dna
    dna21.append(target10);
    if (dna21.toString() != "ACCTGACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGTACTGT") {
        cout << "Append test 6 Fail" << endl;
    }
    
    //test Splice method.
    //with empty
    DNA_Strand dnaEmpty3;
    string targetA = "TTG";
    string insert = "TTGGGGTTG";
    if (dnaEmpty3.splice(0, targetA, insert) != -1) {
        cout << "splice test 1 fail" << endl;
    }
    if (dnaEmpty3.splice(1, "", "") != -1) {
        cout << "splice test 2 fail" << endl;
    }
    DNA_Strand dnatest("ACTTTGGACTGACTGACTTGACTG");
    DNA_Strand dnaTest2("AAAAAAAAAAAAAAAA");
    if (dnatest.splice(0, targetA, insert) != 15) {
        cout << "splice test 3 fail" << endl;
    }
    if (dnatest.toString() != "ACTTTGTTGGGGTTGACTG") {
        cout << "splice test 4 fail" << endl;
    }
    
    //two targets.
    if (dnatest.splice(4, targetA, insert) != 9+insert.length()
        || dnatest.toString() != "ACTTTGTTGTTGGGGTTGACTG") {
        cout << "splice test 5 fail" << endl;
    }
    
    string targetB = "ACTTTGTTGTTGGGGTTGACTG";
    if (dnatest.splice(0, targetB, targetB) != -1) {
        cout << "splice test 6 fail" << endl;
    }
    
    if (dnatest.splice(0, targetA, targetB) != 6 + targetB.length()
        || dnatest.toString() != "ACTTTGACTTTGTTGTTGGGGTTGACTGTTGGGGTTGACTG") {
        cout << "splice test 7 fail" << endl;
    }
    
    if (dnaTest2.splice(15, "AAA", "AAAA") != -1) {
        cout << "splice test 8 fail" << endl;
    }
    if (dnaTest2.splice(1, "AAA", "AAAA") != 8 ||dnaTest2.toString() != "AAAAAAAAAAAAAAAAA") {
        cout << "splice test 9 fail" << endl;
    }
    
    cout << "Done testing" << endl;
    cout << "Press enter to end pgm" << endl;
    char tt;
    tt = cin.get();
    
    
    return 0;
    
    
}


    
