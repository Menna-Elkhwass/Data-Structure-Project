#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;
class follower
{
public:
    string id;
    string followerToString () {
    return "\t\t\t<follower>\n\t\t\t\t<id>" + this->id + "</id>\n\t\t\t</follower>\n";
    }
    string followerToJson() {
     string jsonFollower = "\t\t\t\t\t{\n\t\t\t\t\t \"id\": \"" + this->id + "\"\n\t\t\t\t\t}";
     return jsonFollower;
    }
};
class followers
{
public:
    vector <follower> listOfFollowers;
    string followersToString () {
        string retFollowers = "";
        for (int q = 0; q < listOfFollowers.size(); q++) {
            if(!q) {
                retFollowers += "\t\t<followers>\n";
            }
            retFollowers += listOfFollowers[q].followerToString();
            if (q == listOfFollowers.size() - 1) {
                retFollowers += "\t\t</followers>\n";
            }
        }
        return retFollowers;
    }
    string followersToJson() {
        string jsonFollowers = "\t\t\t\"followers\": [\n";
        for (int q = 0; q < listOfFollowers.size(); q++) {
            jsonFollowers += listOfFollowers[q].followerToJson();
            if (q != listOfFollowers.size() - 1) {
               jsonFollowers += ",\n" ;
            }
        }
        jsonFollowers += "\n\t\t\t\t]\n";
        return jsonFollowers;
    }
};
class post
{
public:
    string body;
    vector <string>listOfTopics;
    string postToString ()
    {
        string retPost = "";
        retPost += "\t\t\t<post>\n\t\t\t\t<body>" + this->body + "</body>\n";
        for (int q = 0; q < listOfTopics.size(); q++)
        {
            if (!q)
            {
                retPost += "\t\t\t\t<topics>\n";
            }
            retPost += "\t\t\t\t\t<topic>" + listOfTopics[q] + "</topic>\n";
            if (q == listOfTopics.size() - 1)
            {
                retPost += "\t\t\t\t</topics>\n\t\t\t</post>";
            }
        }
        return retPost;
    }

};
class posts
{
public:
    vector <post> listOfPosts;
    string postsToString()
    {
     string retPostsToString = "\t\t<posts>\n";
     for (int q = 0; q < listOfPosts.size(); q++) {
        retPostsToString += listOfPosts[q].postToString() + "\n";
     }
     retPostsToString += "\t\t</posts>\n";
     return retPostsToString;
    }
    string postsToJson() {
     string jsonPosts = "\t\t\t\"posts\": [\n";
     for (int q = 0; q < listOfPosts.size(); q++) {
        jsonPosts += "\t\t\t\t\t\"" + listOfPosts[q].body + "\"";
        if (q != listOfPosts.size() - 1) {
            jsonPosts +=",\n";
        }
     }
     jsonPosts += "\n\t\t\t\t],\n";
     return jsonPosts;
    }
};
class user
{
public:
    string id;
    string name;
    posts Posts;
    followers _followers;
    string toString()
    {
        string userTOString = "";
        userTOString += "\t<user>\n\t\t<id>" + this->id + "</id>\n" + "\t\t<name>" + this->name + "</name>\n";
        userTOString += Posts.postsToString();
        userTOString += _followers.followersToString();
        userTOString += "\t</user>\n";
        return userTOString;
    }
    string userToJson () {
    string jsonUser = "\t\t\"user\": {\n\t\t\t\"id\": \"" + this->id + "\",\n\t\t\t\"name\": \"" + this->name + "\",\n";
    jsonUser += Posts.postsToJson();
    jsonUser += _followers.followersToJson();
    jsonUser += "\t\t\t}";
    return jsonUser;
    }
};
class users
{
public:
    vector <user> listOfUsers;
    string usersToString () {
        string retUsers = "";
        for (int q = 0; q < listOfUsers.size(); q++) {
            if (!q) {
                retUsers += "<users>\n";
            }
            retUsers += listOfUsers[q].toString();
            if (q == listOfUsers.size() - 1) {
                retUsers += "</users>\n";
            }
        }
        return retUsers;
    }
    string usersToJson () {
        string jsonUsers = "{\n\t\"users\": [\n";
        for (int q = 0; q <listOfUsers.size(); q++) {
            jsonUsers += listOfUsers[q].userToJson() + "\n";
        }
        jsonUsers += "\t\t]\n}";
        return jsonUsers;
    }
};
string minify()
{
    string _read = "", _line;
    ifstream in("sample.xml");
    while (getline(in,_line))
    {
        for (int i = 0; i < _line.size(); i++)
        {
            if (_line[i] == ' ')
            {
                continue;
            }
            _read += _line[i];
        }
    }
    return _read;
}
int previous_position;
string extract (string sub)
{
    //cout << sub << "\n";
    string takeData = "";
    int i;
    for (i = 0; i < sub.size() && sub[i] != '<'; i++)
    {
        takeData += sub[i];
    }
    previous_position = i;
    // cout << takeData << endl;
    return takeData;
}
post solveForSinglePost (string subXML)
{
    post new_post;
    size_t startName = subXML.find("<body>");
    size_t EName = subXML.find("</body>");
    if (startName != string::npos)
    {
        new_post.body = extract(subXML.substr(startName + 6));
    }
    else if (EName != string::npos)
    {
        new_post.body = extract(subXML.substr(0, EName - 6)); // if no open tag then it is missing so take data from beginning
    }
    startName = subXML.find("<topics>");
    EName = subXML.find("</topics>");
    if (startName != string::npos || (EName != string::npos))
    {
        string newTopic = "";
        size_t topicStart = subXML.find("<topic>");
        size_t topicEnd = subXML.find("</topic>");
        while ((topicStart != string::npos) || (topicEnd != string::npos))
        {
            if (topicStart != string::npos && (topicEnd != string::npos))
            {
                newTopic = extract(subXML.substr(topicStart + 7, topicEnd - topicStart - 7));
                topicStart = subXML.find("<topic>", topicStart + 7);
                topicEnd = subXML.find("<topic>", topicEnd + 7);
            }
            else if (topicStart != string::npos)
            {
                newTopic = extract(subXML.substr(topicStart + 7));
                topicStart = subXML.find("<topic>", topicStart + 7);
            }
            else if (topicEnd != string::npos)
            {
                newTopic = extract(subXML.substr(0, topicEnd - 7));
                topicEnd = subXML.find("</topic>", topicEnd + 7);
            }
            //   cout << "new topic is " << newTopic << endl;
            new_post.listOfTopics.push_back(newTopic);
            if (topicStart == string::npos && (topicEnd == string::npos))
            {
                break;
            }
        }
    }
    return new_post;
}
follower solveForSingleFollower (string subXML)
{
    follower new_follower;
    size_t startName = subXML.find("<id>");
    size_t EName = subXML.find("</id>");
    if (startName != string::npos)
    {
        new_follower.id = extract(subXML.substr(startName + 4));
    }
    else if (EName != string::npos)
    {
        new_follower.id = extract(subXML); // if no open tag then it is missing so take data from beginning
    }
    return new_follower;
}
posts solveForListOfPosts (string subXML)
{
    posts postsOfUser;
    // cout << "after posts tag " << subXML << endl;// mbyd5ol4 hena
    size_t start = subXML.find("<post>");
    size_t End = subXML.find("</post>");
    while (start != string::npos || (End != string::npos))
    {
        if (start != string::npos && (End != string::npos))
        {
            postsOfUser.listOfPosts.push_back(solveForSinglePost(subXML.substr(start + 6, End - start - 6)));
            start = subXML.find("<post>",start + 6);
            End = subXML.find("</post>", End + 6);
        }
        else if (start != string::npos)
        {
            postsOfUser.listOfPosts.push_back(solveForSinglePost(subXML.substr(start + 6)));
            start = subXML.find("<post>", start + 6);
        }
        else if (End != string::npos)
        {
            postsOfUser.listOfPosts.push_back(solveForSinglePost(subXML.substr(0, End - 6)));
            End = subXML.find("</post>", End + 6);

        }

    }
    return postsOfUser;
}
followers solveForListOfFollowers(string subXML)
{
    followers followersOfUser;
    size_t start = subXML.find("<follower>");
    size_t End = subXML.find("</follower>");
    while (start != string::npos || (End != string::npos))
    {
        if (start != string::npos && (End != string::npos)) {
           followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML.substr(start + 10, End - start - 10)));
           start = subXML.find("<follower>", start + 10);
           End = subXML.find("</follower>", End + 10);
        }
        else if(start != string::npos)
        {
           followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML.substr(start + 10)));
           start = subXML.find("<follower>", start + 10);
        }
        else if (End != string::npos)
        {
           followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML.substr(0, End - 10)));
           End = subXML.find("</follower>", End + 10);
        }

    }
    return followersOfUser;
}
user solveForSingleUser (string subXML)
{
    user new_user;
    size_t start = subXML.find("<id>");
    size_t E = subXML.find("</id>");
    if (start != string::npos)
    {
        // the opening id tag exists
        // take the id data starting from end bracket of opening id until the beginning of the next bracket
        new_user.id = extract(subXML.substr(start + 4));
    }
    else if (E != string::npos)
    {
        // if no open tag for id
        // take id from start of sub_xml until the closing id tag
        new_user.id = extract(subXML);
    }
    /* take the name data */
    size_t startName = subXML.find("<name>");
    size_t EName = subXML.find("</name>");
    if (startName != string::npos)
    {
        new_user.name = extract(subXML.substr(startName + 6));
    }
    else if (EName != string::npos)
    {
        new_user.name = extract(subXML.substr(E + 5));// start of name data begins from end of closing id
    }
    // solve for followers and posts
    size_t startPosts = subXML.find("<posts>");
    size_t EPosts = subXML.find("</posts>");
    if ((startPosts != string::npos) && (EPosts != string::npos))
    {
        //  cout <<"closing is"<< subXML[EName] << subXML[EName+1] << subXML[EName+2] << subXML[EName+3] << subXML[EName+4] <<  subXML[EName+5]<< subXML[EName+6] << subXML[EName+7]<<endl;
        new_user.Posts = solveForListOfPosts(subXML.substr(startPosts + 7, EPosts - startPosts - 7));
    }
    else if (startPosts != string::npos)
    {
        // if the user has posts
        new_user.Posts = solveForListOfPosts(subXML.substr(startPosts + 7));
    }
    else if (EPosts != string::npos)
    {
        new_user.Posts = solveForListOfPosts(subXML.substr(EName + 7)); // start from end of name tag
    }
    size_t startf = subXML.find("<followers>");
    size_t Ef = subXML.find("</followers>");
    if ((startf != string::npos) && (Ef != string::npos))
    {
        new_user._followers = solveForListOfFollowers(subXML.substr(startf + 11, Ef - startf - 11));
    }
    else if (startf != string::npos)
    {
        new_user._followers = solveForListOfFollowers(subXML.substr(startf + 11));
    }
    else if (EName != string::npos)
    {
        new_user._followers = solveForListOfFollowers(subXML.substr(EPosts + 8, Ef - 11)); // start from end of posts tag
    }
    return new_user;
}
users solveForListOfUsers (string subXML)
{
    users root;
    size_t start = subXML.find("<user>");
    size_t End = subXML.find("</user>");
    while (start != string::npos || (End != string::npos))
    {
        if (start != string::npos && (End != string::npos))
        {
            root.listOfUsers.push_back(solveForSingleUser(subXML.substr(start + 6, End - start - 6)));
            start = subXML.find("<user>", start + 6);
            End = subXML.find("</user>", End + 6);
        }
        else if (start != string::npos)
        {
            root.listOfUsers.push_back(solveForSingleUser(subXML.substr(start + 6)));
            start = subXML.find("<user>", start + 6);
        }
        else if (End != string::npos)
        {
            root.listOfUsers.push_back(solveForSingleUser(subXML.substr(0, End - 6)));
            End = subXML.find("</user>", End + 6);
        }
    }
    return root;
}
users readAndCorrect ()
{
    string allXML = minify();
    users XMLroot;
    size_t start = allXML.find("<users>");
    size_t End = allXML.find("</users>");
    if (start != string::npos &&  (End != string::npos))
    {
        XMLroot = solveForListOfUsers(allXML.substr(start + 7, End - start- 7));
    }
    else if (start != string::npos)
    {
        XMLroot = solveForListOfUsers(allXML.substr(start + 7));
    }
    else if (End != string::npos)
    {
        XMLroot = solveForListOfUsers(allXML.substr(0,End - 7));
    }
    return XMLroot;
}
void print ()
{
    users allUsers = readAndCorrect();
    string correctedXML = allUsers.usersToString();
    string JsonXML = allUsers.usersToJson();
    cout << correctedXML<< "\n" << endl;
    cout << JsonXML << endl;
}
string textOfTag(string tag)
{
    string text = "";
    for (int i = 0; i < tag.size(); i++)
    {
        if ( (tag[i] >= 'a' && tag[i] <= 'z') || (tag[i] >= 'A' && tag[i] <= 'Z') )
        {
            text += tag[i];
        }
    }
    return text;
}

bool isValid ()
{
    string line;
    vector <string> stringVector;
    ifstream in("sample.xml");

    while (getline(in,line))
    {
        string currentLine = "";
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != '<')
            {
                continue;  //skip spaces and text

            }

            while (line[i] != '>')
            {
                currentLine += line[i++];
            }
            if (line[i] == '>')
            {
                currentLine += line[i];
                stringVector.push_back(currentLine);
                currentLine = "";
            }
        }
    }
    stack <string> opens ;
    bool valid = true;
    for (int i = 0; i < stringVector.size(); i++)
    {
        if (stringVector[i][1] != '/' )
        {
            // open bracket
            opens.push(stringVector[i]);
            // cout << stringVector[i] << endl;
        }
        else if ((!opens.empty())&& (stringVector[i][1] == '/'))
        {
            string cur = opens.top();
            if (textOfTag(cur) == textOfTag(stringVector[i]))
            {
                opens.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }
        else if((opens.empty())&& (stringVector[i][1] == '/'))
        {
            valid = false;
            break;
        }
    }
    if ((!valid) || (!opens.empty()))
    {
        return false;
    }
    else
    {
        return true;
    }
    /*  for (int i = 0; i < stringVector.size(); i++) {
             cout << "cur line is " << stringVector[i] << endl;
         }*/
}

int main()
{
    print();

    if (isValid())
    {
        cout << "valid" << endl;
    }
    else
    {
        cout <<"invalid" << endl;
    }

    string mini = minify();
    cout << "minifying \n" << mini << endl;
}
