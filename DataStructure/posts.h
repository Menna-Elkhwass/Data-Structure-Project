#ifndef POSTS_H
#define POSTS_H
#include "post.h"
using namespace std;
#include <bits/stdc++.h>

class posts
{
    public:
        vector <post> listOfPosts;
        posts();
        string postsToString();
        string postsToJson();
        virtual ~posts();
    protected:
    private:
};

#endif // POSTS_H
