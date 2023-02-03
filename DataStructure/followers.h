#ifndef FOLLOWERS_H
#define FOLLOWERS_H
#include "follower.h"
using namespace std;

class followers
{
    public:
        vector <follower> listOfFollowers;
        followers();
        string followersToString ();
        string followersToJson();
        int numberOfFollowers ();
        virtual ~followers();
};
#endif // FOLLOWERS_H
