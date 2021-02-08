//
//  member.cpp
//  Cirkel Algorithm Draft
//
//  Created by Sophia Petersen on 6/13/20.
//  Copyright © 2020 Sophia Petersen. All rights reserved.
//

#include "member.h"

using namespace std;


//overloaded stream extraction opp
istream& operator>>( istream& in, Member& m ){
    string name;
    char spacer;
    
    getline(in, name, '/');
    if (in.good()){
        //NAME
        m.setName(name);
//        cout <<m.name <<endl;
        //GENDER
        getline(in, m.gender, '/');
//        cout <<"GENDER: " <<m.gender <<endl;
        //INDUSTRY
        getline(in, m.industries, '/');
//        cout <<"INDUSTRIES: "<< m.industries <<endl;
        //MASTERED SKILL
        getline(in, m.masteredSkill, '/');
//        cout <<"MASTERED: "<< m.masteredSkill <<endl;
        //TO LEARN
        getline(in, m.desiredSkills, '/');
//        cout <<"DESIRED: "<< m.desiredSkills <<endl;
        //NEED STATES
        getline(in, m.needStates, '/');
//        cout <<"NEED: " <<m.needStates <<endl;
        //GIVE STATES
        getline(in, m.giveStates, '/');
//        cout <<"GIVE: " <<m.giveStates <<endl;
        //HOBBIES
        getline(in, m.hobbies, '/');
//        cout <<"HOBBIES: "<<m.hobbies <<endl;
        //GENERATION
        getline(in, m.generation, '/');
//        cout <<"GENERATION: " <<m.generation <<endl;
        //AGE
        in >>m.age;
        in >>spacer;
//        cout <<"AGE: " <<m.age <<endl;
        //PAST MATCHES
        getline(in, m.pastMatches, '/');
//        cout <<"PAST: " <<m.pastMatches <<endl;
        //NEW MEMBER
          if (m.pastMatches.length() <= 1)
              m.newMember = true;
          else
              m.newMember = false;
//        cout <<"New Member? " <<m.newMember <<endl;
        //SPECIAL CONSTRAINT
        getline(in, m.constraint);
//        cout <<"Constraint? " <<m.constraint <<endl;

    }
            
    return in;
}//Overloaded Stream Extraction Opp


ostream& operator<<( ostream& out, const Member& m){
    out <<m.name << " " <<m.age <<" ";
    out <<m.generation << " " <<m.checkNewMember() <<endl;
    out <<"Industries: " <<m.industries <<endl;
    out <<"Desired Skill: " <<m.desiredSkills <<" Mastered Skill: " <<m.masteredSkill <<endl;
    out <<"Hobbies: " <<m.hobbies <<endl;
    out <<"Past Matches: " <<m.pastMatches <<endl;
    
    return out;
}

double Member::score(Member toCompare){
    double score = 0;
    //INDUSTRY
//    cout <<"Industries in common: ";
    for (unsigned i = 0; i < INDUSTRIES.size(); i++){
        if (this->industries.find(INDUSTRIES[i])!= string::npos &&
            toCompare.industries.find(INDUSTRIES[i]) != string::npos){
            score += 1;
//            cout <<INDUSTRIES[i] <<" ";
        }
    }
//    cout <<endl;
//    cout <<"Hobbies in common: ";
    for (unsigned i = 0; i < HOBBIES.size(); i++){
        if (this->hobbies.find(HOBBIES[i]) != string::npos &&
            toCompare.hobbies.find(HOBBIES[i]) != string::npos){
            score += .5;
//            cout <<HOBBIES[i] <<" ";
        }
    }
//    cout <<endl;
//    cout <<"Mastered/Desired skill pair: ";
    for (unsigned i = 0; i < SKILLS.size(); i ++){
        if (this->desiredSkills.find(SKILLS[i]) != string::npos &&
            toCompare.masteredSkill.find(SKILLS[i]) != string::npos){
            score += 3;
//            cout <<SKILLS[i] <<" ";
        }
        else if (this->masteredSkill.find(SKILLS[i]) != string::npos &&
                 toCompare.desiredSkills.find(SKILLS[i]) != string::npos){
            score += 3;
//            cout <<SKILLS[i] <<" ";
        }
    }
//    cout <<endl;
    //NEED/GIVE MATCHING
//    cout <<"Need/Give States: ";
    if (this->needStates.find("Lone Ranger") != string::npos &&
        toCompare.giveStates.find("Connector") != string::npos){
        score+=5;
//        cout <<"Lone Ranger/Connector ";
    }
    if (this->needStates.find("Lone Ranger") != string::npos &&
        (toCompare.giveStates.find("Employer") != string::npos ||
         toCompare.giveStates.find("Drinking Buddy") != string::npos)){
        score+=1;
//        cout <<"Lone Ranger/Employer & Drinking Buddy ";
    }
    if (this->needStates.find("Candidate") != string::npos &&
        toCompare.giveStates.find("Employer") != string::npos){
        score +=5;
//        cout <<"Candidate/Employer ";
    }
    if (this->needStates.find("Candidate") != string::npos &&
        (toCompare.giveStates.find("Connector") != string::npos ||
         toCompare.giveStates.find("Role Player") != string::npos)){
        score+=1;
//        cout <<"Candidate/Connector & Role Player ";
    }
    if (this->needStates.find("Pivoter") != string::npos &&
        toCompare.giveStates.find("Wise Sage") != string::npos){
        score +=5;
//        cout <<"Pivoter/Wise Sage ";
    }
    if (this->needStates.find("Pivoter") != string::npos &&
        (toCompare.giveStates.find("Connector") != string::npos ||
         toCompare.giveStates.find("Employer") != string::npos ||
         toCompare.giveStates.find("Teacher") != string::npos ||
         toCompare.giveStates.find("Problem Solver") != string::npos ||
         toCompare.giveStates.find("Role Player") != string::npos)){
        score+=1;
//        cout <<"Pivoter/Connector & Employer & Teacher & Problem Solver & Role Player ";
    }
    if (this->needStates.find("Apprentice") != string::npos &&
        toCompare.giveStates.find("Teacher") != string::npos){
        score +=5;
//        cout <<"Apprentice/Teacher ";
    }
    if (this->needStates.find("Apprentice") != string::npos &&
        (toCompare.giveStates.find("Teacher") != string::npos ||
         toCompare.giveStates.find("Problem Solver") != string::npos ||
         toCompare.giveStates.find("Connector") != string::npos)){
        score+=1;
//        cout <<"Apprentice/Teacher & Problem Solver & Connector ";
    }
    if (this->needStates.find("Networker") != string::npos &&
        toCompare.giveStates.find("Connector") != string::npos){
        score +=5;
//        cout <<"Networker & Connector ";
    }
    if (this->needStates.find("Networker") != string::npos &&
        (toCompare.giveStates.find("Drinking Buddy") != string::npos ||
         toCompare.giveStates.find("Employer") != string::npos ||
         toCompare.giveStates.find("Wise Sage") != string::npos)){
        score+=1;
//        cout <<"Networker / Drinking Buddy & Employer & Wise Sage ";
    }
    if (this->needStates.find("Generational Explorer") != string::npos &&
        toCompare.giveStates.find("Drinking Buddy") != string::npos){
        score +=5;
//        cout <<"Generational Explorer/Drinking Buddy ";
    }
    if (this->needStates.find("Generational Explorer") != string::npos &&
        (toCompare.giveStates.find("Connector") != string::npos ||
         toCompare.giveStates.find("Wise Sage") != string::npos)){
        score+=1;
//        cout <<"Generational Explorer/Connector & Wise Sage ";
    }
    if (this->needStates.find("Mentor Seeker") != string::npos &&
        toCompare.giveStates.find("Wise Sage") != string::npos){
        score +=5;
//        cout <<"Mentor Seeker/Wise Sage ";
    }
    if (this->needStates.find("Mentor Seeker") != string::npos &&
        (toCompare.giveStates.find("Teacher") != string::npos ||
         toCompare.giveStates.find("Problem Solver") != string::npos ||
         toCompare.giveStates.find("Drinking Buddy") != string::npos)){
        score+=1;
//        cout <<"Mentor Seeker/Teacher & Problem Solver & Drinking Buddy ";
    }
//    cout <<endl;
    if (this->generation == toCompare.generation)
        score = 0;
    if (this->pastMatches.find(toCompare.getName()) != string::npos)
        score = 0;
    if (this->name.find(toCompare.getName()) != string::npos)
        score = 0;
//    cout <<"Total Score: " <<score <<endl;
    return score;
}

void Member::initializeKeywords(){
    //INDUSTRIES
    INDUSTRIES.push_back("Media and advertising");
    INDUSTRIES.push_back("Health (medicine & wellness)");
    INDUSTRIES.push_back("Retail and ecommerce");
    INDUSTRIES.push_back("Manufacturing and sourcing");
    INDUSTRIES.push_back("Law");
    INDUSTRIES.push_back("Finance or accounting");
    INDUSTRIES.push_back("Fine arts or performing arts");
    INDUSTRIES.push_back("Community building");
    INDUSTRIES.push_back("Science, technology, or innovation");
    INDUSTRIES.push_back("Politics or government organization");
    INDUSTRIES.push_back("Non-profit");
    INDUSTRIES.push_back("Education");
    INDUSTRIES.push_back("Entertainment & music");
    INDUSTRIES.push_back("Fashion & beauty");
    INDUSTRIES.push_back("Hospitality or food & beverage");
    INDUSTRIES.push_back("Journalism, writing, or publishing");
    INDUSTRIES.push_back("Real estate & city planning");
    INDUSTRIES.push_back("Management consulting");
    //HOBBIES
    HOBBIES.push_back("Politics");
    HOBBIES.push_back("Environmentalism & sustainability");
    HOBBIES.push_back("Fashion & beauty trends");
    HOBBIES.push_back("Art & design");
    HOBBIES.push_back("History");
    HOBBIES.push_back("Religion or philosophy");
    HOBBIES.push_back("Cinema");
    HOBBIES.push_back("Travel");
    HOBBIES.push_back("Human psychology");
    HOBBIES.push_back("Pop culture & celebrity");
    HOBBIES.push_back("Entrepreneurship");
    HOBBIES.push_back("Personal finance");
    HOBBIES.push_back("Reading");
    HOBBIES.push_back("Writing");
    HOBBIES.push_back("Socializing or night life");
    HOBBIES.push_back("Technolgy & innovation");
    HOBBIES.push_back("Gaming");
    HOBBIES.push_back("Feminist causes");
    HOBBIES.push_back("Team sports");
    HOBBIES.push_back("Fitness & exercise");
    HOBBIES.push_back("Nutrition");
    HOBBIES.push_back("Alternative spiritualism");
    HOBBIES.push_back("Outdoor sports");
    HOBBIES.push_back("Cars");
    HOBBIES.push_back("Romance & dating");
    HOBBIES.push_back("TV");
    HOBBIES.push_back("Animals");
    HOBBIES.push_back("Nature");
    HOBBIES.push_back("Music");
    //SKILLS
    SKILLS.push_back("Advocating for yourself or for others");
    SKILLS.push_back("Art direction or graphic design");
    SKILLS.push_back("Big pircture thinking");
    SKILLS.push_back("Business Modeling");
    SKILLS.push_back("Community building and networking");
    SKILLS.push_back("Customer service");
    SKILLS.push_back("Detail-oriented thinking");
    SKILLS.push_back("Fundraising");
    SKILLS.push_back("Graphic design (conceptual or using software)");
    SKILLS.push_back("Investing (corporate or personal)");
    SKILLS.push_back("Leadership");
    SKILLS.push_back("Negotiation");
    SKILLS.push_back("Photography or video filming");
    SKILLS.push_back("Production & manufacturing");
    SKILLS.push_back("Productivity and making sh*t happen");
    SKILLS.push_back("Product management");
    SKILLS.push_back("Propelling creative inspiration");
    SKILLS.push_back("Research");
    SKILLS.push_back("Sales");
    SKILLS.push_back("Social Media");
    SKILLS.push_back("UX or web design");
    SKILLS.push_back("Writing (fiction or non-fiction)");
    //NEED STATES
    NEEDSTATES.push_back("Lone Ranger");
    NEEDSTATES.push_back("Candidate");
    NEEDSTATES.push_back("Pivoter");
    NEEDSTATES.push_back("Apprentice");
    NEEDSTATES.push_back("Networker");
    NEEDSTATES.push_back("Candidate");
    NEEDSTATES.push_back("Generational Explorer");
    NEEDSTATES.push_back("Mentor Seeker");
    //GIVE STATES
    GIVESTATES.push_back("Wise Sage");
    GIVESTATES.push_back("Teacher");
    GIVESTATES.push_back("Role Player");
    GIVESTATES.push_back("Connector");
    GIVESTATES.push_back("Problem Solver");
    GIVESTATES.push_back("Employer");
    GIVESTATES.push_back("Drinking Buddy");
}


//Default Constructor
Member::Member(){
    age = 0;
    newMember = false;
}

string Member::getName() const{
    return name;
}

void Member::setName(string name){
    this->name = name;
}

int Member::getAge() const{
    return age;
}

string Member::getCondition() const{
    return constraint;
}


bool Member::checkNewMember() const{
    return newMember;
}

string Member::getPastMatches() const{
    return pastMatches;
}

void Member::visualize(Member m1, Member m2) const{
    cout <<m1.name <<" and " <<m2.name <<endl;
    cout <<"Score: " <<m1.score(m2) <<endl;
    
    cout <<m1.name <<": " <<endl;
    cout <<"Age: " <<m1.age <<endl;
    cout <<"Industries: " <<m1.industries <<endl;
    cout <<"Mastered: " <<m1.masteredSkill <<endl;
    cout <<"To Learn: " <<m1.desiredSkills <<endl;
    cout <<"Need States: " <<m1.needStates <<endl;
    cout <<"Give States: " <<m1.giveStates <<endl;
    cout <<"Hobbies: " <<m1.hobbies <<endl;
    
    cout <<endl;
    cout <<endl;
    
    cout <<m2.name <<": " <<endl;
    cout <<"Age: " <<m2.age <<endl;
    cout <<"Industries: " <<m2.industries <<endl;
    cout <<"Mastered: " <<m2.masteredSkill <<endl;
    cout <<"To Learn: " <<m2.desiredSkills <<endl;
    cout <<"Need States: " <<m2.needStates <<endl;
    cout <<"Give States: " <<m2.giveStates <<endl;
    cout <<"Hobbies: " <<m2.hobbies <<endl;
    
    cout <<endl;
    cout <<"In Common: " <<endl;
    cout <<"Shared Industries: ";
    for (unsigned i = 0; i < INDUSTRIES.size(); i++){
        if (m1.industries.find(INDUSTRIES[i])!= string::npos &&
            m2.industries.find(INDUSTRIES[i]) != string::npos){
            cout <<INDUSTRIES[i] <<" ";
        }
    }//for
    cout <<endl;
    cout <<"Shared Hobbies: ";
    for (unsigned i = 0; i < HOBBIES.size(); i++){
        if (m1.hobbies.find(HOBBIES[i]) != string::npos &&
            m2.hobbies.find(HOBBIES[i]) != string::npos){
            cout <<HOBBIES[i] <<" ";
        }
    }
    cout <<endl;
    cout <<"Shared Skill Pairs: ";
    for (unsigned i = 0; i < SKILLS.size(); i ++){
        if (m1.desiredSkills.find(SKILLS[i]) != string::npos &&
            m2.masteredSkill.find(SKILLS[i]) != string::npos){
            cout <<SKILLS[i] <<" ";
        }
        else if (m1.masteredSkill.find(SKILLS[i]) != string::npos &&
                 m2.desiredSkills.find(SKILLS[i]) != string::npos){
            cout <<SKILLS[i] <<" ";
        }
    }
    cout <<endl;
        
}//END Fxn






