#ifndef USER_H
#define USER_H
using namespace std;
#include <bits/stdc++.h>
#include"posts.h"
#include"followers.h"
class user
{
    public:
        user();
        string id;
        string name;
        posts Posts;
        followers _followers;
        string toString();
        string userToJson ();
        virtual ~user();
    protected:
    private:
};

#endif // USER_H
