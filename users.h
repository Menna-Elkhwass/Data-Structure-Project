#ifndef USERS_H
#define USERS_H
#include<bits/stdc++.h>
#include "user.h"

using namespace std;
class users
{
    public:
        vector <user> listOfUsers;
        vector <int> followersOfID[50];
        users();
        string usersToString ();
        string usersToJson ();
        user userWithMaxFollowers();
        void buildFollowersList();
        virtual ~users();

};

#endif // USERS_H

