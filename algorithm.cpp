//
//  algorithm.cpp
//  Cirkel Algorithm Draft
//
//  Created by Sophia Petersen on 6/14/20.
//  Copyright © 2020 Sophia Petersen. All rights reserved.
//

#include "algorithm.h"


using namespace std;


void Algorithm::read(string filename){
    ifstream inFile;
    
    inFile.open(filename.c_str());
    if (!inFile)
        throw logic_error("File Failed to Open");
    else{
        Member newMember;
        while (inFile >> newMember)
            cirkelUpMembers.push_back(newMember);
    }
    
    inFile.close();
}//READ

void Algorithm::write(string filename) const{
    ofstream outFile;
    outFile.open(filename.c_str());
    
    for (unsigned i = 0; i < cirkelUpMembers.size(); i++)
        outFile <<cirkelUpMembers[i] <<endl;
    
    outFile.close();
}//WRITE


void Algorithm::print() const{
    for (unsigned i = 0; i < cirkelUpMembers.size(); i++)
        cout <<cirkelUpMembers[i] <<endl;
}

Member& Algorithm::getMember(unsigned index){
    return cirkelUpMembers[index];
}

unsigned Algorithm::find(string name){
    Member toReturn;
    for (unsigned i = 0; i < cirkelUpMembers.size(); i++){
        if (cirkelUpMembers[i].getName() == name){
            return i;
        }
    }
    return -1;
}

vector<Member> Algorithm::filter(string condition, Member current) const{
    vector<Member> passingMembers = cirkelUpMembers;
    for (unsigned i = 0; i < passingMembers.size(); i++){
        if (current.checkNewMember() && passingMembers[i].checkNewMember())
            passingMembers.erase(passingMembers.begin()+i);
        if (abs(current.getAge()-passingMembers[i].getAge()) <= 8)
            passingMembers.erase(passingMembers.begin()+i);
        if (current.getName() == passingMembers[i].getName())
            passingMembers.erase(passingMembers.begin()+i);
    }
    return passingMembers;
}


vector<Member> Algorithm::makeMatches(Member currentMember) const{
    vector <Member> matches;
    vector <Member> toScore = filter(currentMember.getCondition(), currentMember);
//    vector <Member> toScore = cirkelUpMembers;
//    for (unsigned i = 0; i < toScore.size(); i++){
//        double test = toScore[i].score(currentMember);
//        matches.push_back(test);
//    }
//    SORTING ALGORITHM
    for (unsigned i = 0; i < toScore.size()-1; i++){
        for (unsigned j = 1; j < toScore.size()-i; j++){
            if (toScore[j-1].score(currentMember) < toScore[j].score(currentMember)){
                    Member temp = toScore[j];
                    toScore[j] = toScore[j-1];
                    toScore[j-1] = temp;
                }//if
            }//for
        }//for
    matches.push_back(toScore[0]);
    matches.push_back(toScore[1]);
    matches.push_back(toScore[2]);
    return matches;
}

void Algorithm::runMember(ostream &out) const{
    for (unsigned i = 0; i < cirkelUpMembers.size(); i++){
        Member current = cirkelUpMembers[i];
        out <<"Matches for ";
        out <<current.getName() <<": ";
        vector <Member> matches = this->makeMatches(current);
        for (unsigned j = 0; j < 3; j++){
            out <<matches[j].getName() <<" ";
            out <<matches[j].score(current) <<", ";
        }
        out <<endl;
    }
}

void Algorithm::runBest(ostream & out) const{
    vector<Member> current = cirkelUpMembers;
    unsigned best = 0;
    unsigned roundCount = 1;
    unsigned member1 = 0;
    unsigned member2 = 0;
    Member temp1;
    Member temp2;
    while (roundCount <10){
        for (unsigned i = 0; i < current.size()-1; i ++){
            if (current[i].score(current[i+1]) > best){
                best = temp1.score(temp2);
                temp1 = current[i];
                temp2 = current[i+1];
                member1 = i;
                member2 = i+1;
            }
        }//outer for
        current.erase(current.begin()+member1);
        current.erase(current.begin()+member2);
        out << "Match " <<roundCount <<": ";
        out <<temp1.getName() <<" and ";
        out <<temp2.getName() <<"   ";
        out <<"Score: " <<best <<endl;
        roundCount++;
    }//while
}


