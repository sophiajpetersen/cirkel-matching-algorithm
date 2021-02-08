//
//  algorithm.h
//  Cirkel Algorithm Draft
//
//  Created by Sophia Petersen on 6/14/20.
//  Copyright © 2020 Sophia Petersen. All rights reserved.
//

#ifndef algorithm_h
#define algorithm_h

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "member.h"


using namespace std;

/**The Algorithm class is designed to encapsulate the functionality of matching Cirkel Up members
 for their montly introductions. All the Members are stored in the public vector cirkelUpMembers, and the rest
 of the functionality lives in the encapsulated functions below. 
 
 @author Sophia Petersen (sjp110 at georgetown.edu)
 @version 1.5  010/16/2020
 */


class Algorithm
{
  friend class Member;
  private:
    
  public:
    vector <Member> cirkelUpMembers;
    Member &getMember(unsigned index);
    void write(string filename) const;
    void read(string filename);
    unsigned find(string query);
    vector<Member> filter(string condition, Member current) const;
    double score(Member toCompare);
    void print() const;
    vector<Member> makeMatches(Member currentMember) const;
    void runMember(ostream &out = cout) const;
    void runBest(ostream & out = cout) const;    
    
};//Algorithm Class

#endif /* algorithm_h */
