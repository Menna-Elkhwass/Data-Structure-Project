#include "follower.h"
#include<bits/stdc++.h>
using namespace std;
follower::follower()
{
    //ctor
}
    string follower::followerToString ()
    {
        return "\t\t\t<follower>\n\t\t\t\t<id>" + this->id + "</id>\n\t\t\t</follower>\n";
    }
    string follower::followerToJson()
    {
        string jsonFollower = "\t\t\t\t\t{\n\t\t\t\t\t \"id\": \"" + this->id + "\"\n\t\t\t\t\t}";
        return jsonFollower;
    }
/*follower::~follower()
{
    //dtor
}
*/
