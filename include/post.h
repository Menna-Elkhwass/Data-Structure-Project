#ifndef POST_H
#define POST_H
#include <bits/stdc++.h>
using namespace std;

class post
{
    public:
        post();
        string body;
        vector <string>listOfTopics;
        string postToString ();
        virtual ~post();
};

#endif // POST_H
