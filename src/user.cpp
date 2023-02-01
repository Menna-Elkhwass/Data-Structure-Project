#include "user.h"
using namespace std;
#include <bits/stdc++.h>

user::user()
{
    //ctor
}
 string user::toString()
    {
        string userTOString = "";
        userTOString += "\t<user>\n\t\t<id>" + this->id + "</id>\n" + "\t\t<name>" + this->name + "</name>\n";
        userTOString += Posts.postsToString();
        userTOString += _followers.followersToString();
        userTOString += "\t</user>\n";
        return userTOString;
    }
    string user::userToJson ()
    {
        string jsonUser = "\t\t\"user\": {\n\t\t\t\"id\": \"" + this->id + "\",\n\t\t\t\"name\": \"" + this->name + "\",\n";
        jsonUser += Posts.postsToJson();
        jsonUser += _followers.followersToJson();
        jsonUser += "\t\t\t}";
        return jsonUser;
    }

user::~user()
{
    //dtor
}
