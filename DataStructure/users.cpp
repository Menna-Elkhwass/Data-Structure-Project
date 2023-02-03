#include "users.h"
using namespace std;
users::users()
{
    //ctor
}
string users::usersToString ()
{
    string retUsers = "";
    for (int q = 0; q < listOfUsers.size(); q++)
    {
        if (!q)
        {
            retUsers += "<users>\n";
        }
        retUsers += listOfUsers[q].toString();
        if (q == listOfUsers.size() - 1)
        {
            retUsers += "</users>\n";
        }
    }
    return retUsers;
}
string users::usersToJson ()
{
    string jsonUsers = "{\n\t\"users\": [\n";
    for (int q = 0; q <listOfUsers.size(); q++)
    {
        jsonUsers += listOfUsers[q].userToJson() + "\n";
    }
    jsonUsers += "\t\t]\n}";
    return jsonUsers;
}
user users::userWithMaxFollowers()
{
    user maxFUser;
    int maxi = INT_MIN;
    for (int q = 0; q < listOfUsers.size(); q++)
    {
        if (listOfUsers[q]._followers.numberOfFollowers() > maxi)
        {
            maxi = listOfUsers[q]._followers.numberOfFollowers();
            maxFUser = listOfUsers[q];
        }
    }
    return maxFUser;
}
void users::buildFollowersList()
{
    for (int q = 0; q <listOfUsers.size(); q++)
    {
        stringstream user_Id (listOfUsers[q].id);
        int uId = 0;
        user_Id >> uId;
        for (int k = 0; k < listOfUsers[q]._followers.listOfFollowers.size(); k++)
        {
            stringstream follower_Id(listOfUsers[q]._followers.listOfFollowers[k].id);
            int fId = 0;
            follower_Id >> fId ;
            followersOfID[uId].push_back(fId);
        }
    }
}
users::~users()
{
    //dtor
}
