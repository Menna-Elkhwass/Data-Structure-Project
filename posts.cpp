#include "posts.h"

posts::posts()
{
    //ctor
}
string posts::postsToString()
{
    string retPostsToString = "\t\t<posts>\n";
    for (int q = 0; q < listOfPosts.size(); q++)
    {
        retPostsToString += listOfPosts[q].postToString() + "\n";
    }
    retPostsToString += "\t\t</posts>\n";
    return retPostsToString;
}
string posts::postsToJson()
{
    string jsonPosts = "\t\t\t\"posts\": [\n";
    for (int q = 0; q < listOfPosts.size(); q++)
    {
        jsonPosts += "\t\t\t\t\t\"" + listOfPosts[q].body + "\"";
        if (q != listOfPosts.size() - 1)
        {
            jsonPosts +=",\n";
        }
    }
    jsonPosts += "\n\t\t\t\t],\n";
    return jsonPosts;
}
posts::~posts()
{
    //dtor
}
