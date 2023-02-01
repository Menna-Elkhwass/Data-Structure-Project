#include "followers.h"
using namespace std;

followers::followers()
{
    //ctor
}
string followers::followersToString ()
{
    string retFollowers = "";
    for (int q = 0; q < listOfFollowers.size(); q++)
    {
        if(!q)
        {
            retFollowers += "\t\t<followers>\n";
        }
        retFollowers += listOfFollowers[q].followerToString();
        if (q == listOfFollowers.size() - 1)
        {
            retFollowers += "\t\t</followers>\n";
        }
    }
    return retFollowers;
}
string followers::followersToJson()
{
    string jsonFollowers = "\t\t\t\"followers\": [\n";
    for (int q = 0; q < listOfFollowers.size(); q++)
    {
        jsonFollowers += listOfFollowers[q].followerToJson();
        if (q != listOfFollowers.size() - 1)
        {
            jsonFollowers += ",\n" ;
        }
    }
    jsonFollowers += "\n\t\t\t\t]\n";
    return jsonFollowers;
}
int followers::numberOfFollowers ()
{
    return listOfFollowers.size();
}
followers::~followers()
{
    //dtor
}
