//
//  member.h
//  Cirkel Algorithm Draft
//
//  Created by Sophia Petersen on 6/10/20.
//  Copyright © 2020 Sophia Petersen. All rights reserved.
//

#ifndef member_h
#define member_h

#include <iostream>
#include <vector>

using namespace std;

/**The Member class is designed to store CIRKEL UP members and all of their
 information in a helpful way. Data fields include Name, Birth Year, Generation, and other
 match preferences and restrictions for each person.
 
 @author Sophia Petersen (sjp110 at georgetown.edu)
 @version 1.5  10/16/2020
 */

class Member
{
  friend istream& operator>>( istream& in, Member& m );
  friend ostream& operator<<( ostream& out, const Member& m );

  private:
    /*first and last name of this member*/
    string name;
    /*age of this member*/
    int age;
    /*whether or not this member is in first month of membership*/
    bool newMember;
    /*generation that this member belongs to*/
    string generation;
    /*gender of this member*/
    string gender;
    /*all masteredSkills of this member, up to 3*/
    string masteredSkill;
    /*all desired skills of this member, up to 3*/
    string desiredSkills;
    /*need states of this member, up to 5*/
    string needStates;
    /*give states of this member, up to 5*/
    string giveStates;
    /*IDs of all the members this member has previously matched with*/
    string pastMatches;
    /*industries this member has experience in, up to 3*/
    string industries;
    /*hobbies of this member, can be many*/
    string hobbies;
    /*special matching rule for this member*/
    string constraint;
    vector <string> INDUSTRIES;
    vector <string> HOBBIES;
    vector <string> SKILLS;
    vector <string> NEEDSTATES;
    vector <string> GIVESTATES;

  public:
    Member();
    void initializeKeywords();
    string getName() const;
    void setName(string name);
    int getAge() const;
    string getCondition() const;
    bool checkNewMember() const;
    double score(Member toCompare);
    string getPastMatches() const;
    void visualize (Member m1, Member m2) const;
    
    
};//Member Class

#endif /* member_h */
