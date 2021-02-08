//
//  main.cpp
//  CirkelAlgoDraft
//
//  Created by Sophia Petersen on 6/16/20.
//  Copyright © 2020 Sophia Petersen. All rights reserved.
//

#include <iostream>
#include "main.h"

using namespace std;

int main(int argc, const char * argv[]) {
        try {
            //DO NOT EDIT BELOW LINES
            string filestem = argv[1];
            Algorithm a1;
            a1.read(filestem);
            for (unsigned i = 0; i < a1.cirkelUpMembers.size(); i++){
                a1.cirkelUpMembers[i].initializeKeywords();
            }
            //BEST MATCH FORMAT
            //*Do Not Run this format unless you input correct file*
//            a1.runBest();
            //SUGGESTION FORMAT
//            a1.runMember();
            //VISUALIZATION
            Member m1 = a1.cirkelUpMembers[a1.find("Peter Bossio")];
            Member m2 = a1.cirkelUpMembers[a1.find("Chris Markley")];
            m1.visualize(m1, m2);

            cout <<"PASS" <<endl;
        
        } catch (invalid_argument &e) {
            cout <<"Fail invalid arg " <<e.what() <<endl;
        }
        catch (logic_error &e){
            cout <<"Fail logic error" <<e.what() <<endl;
        }
        catch (...){
            cout <<"Fail unkown error" <<endl;
        }
        
        return 0;
    }

