#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class follower
{
public:
    string id;
    string followerToString ()
    {
        return "\t\t\t<follower>\n\t\t\t\t<id>" + this->id + "</id>\n\t\t\t</follower>\n";
    }
    string followerToJson()
    {
        string jsonFollower = "\t\t\t\t\t{\n\t\t\t\t\t \"id\": \"" + this->id + "\"\n\t\t\t\t\t}";
        return jsonFollower;
    }
};
class followers
{
public:
    vector <follower> listOfFollowers;
    string followersToString ()
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
    string followersToJson()
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
        for (int q = 0; q < listOfPosts.size(); q++)
        {
            retPostsToString += listOfPosts[q].postToString() + "\n";
        }
        retPostsToString += "\t\t</posts>\n";
        return retPostsToString;
    }
    string postsToJson()
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
    string userToJson ()
    {
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
    string usersToString ()
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
    string usersToJson ()
    {
        string jsonUsers = "{\n\t\"users\": [\n";
        for (int q = 0; q <listOfUsers.size(); q++)
        {
            jsonUsers += listOfUsers[q].userToJson() + "\n";
        }
        jsonUsers += "\t\t]\n}";
        return jsonUsers;
    }
};
string fileIn = "unFormatted_XMLFile.xml";
string read(string input_file)
{
    ifstream fin;
    ofstream fout;
    fin.open(input_file.c_str(), ios::out);
    string _read = "", _line;
    // ifstream in("unFormatted_XMLFile.xml");
    while (getline(fin,_line))
    {
        for (int i = 0; i < _line.size(); i++)
        {
            _read += _line[i];
        }
    }
    fin.close();
    return _read;
}
string extract (string sub)
{
    // cout << sub << "\n";
    string takeData = "";
    int i;
    for (i = 0; i < sub.size() && sub[i] != '<'; i++)
    {
        takeData += sub[i];
    }
    while(takeData[0] == ' ')
    {
        // remove spaces from beginning of string
        takeData = takeData.substr(1);
    }

    while(takeData[takeData.size() - 1] == ' ')
    {
        // remove spaces from end of string
        takeData = takeData.substr(0, takeData.size() - 1);
    }
    // cout<< "extracted data: " << takeData << endl;
    return takeData;
}
post solveForSinglePost (string subXML)
{
    post new_post;
    // cout << "The subXML for a single post: " << subXML << endl;
    size_t startName = subXML.find("<body>");
    size_t EName = subXML.find("</body>");
    if (startName != string::npos)
    {
        //   cout << "found a start body" << endl;
        new_post.body = extract(subXML.substr(startName + 6));
    }
    else if (EName != string::npos)
    {
        //  cout << "found a closing body tag" << endl;
        size_t wrongTagStart = subXML.find("<");
        if (wrongTagStart < EName)
        {
            // cout << "there exists a wrong opening body" << endl;
            size_t  endOfWrongTag = subXML.find(">", wrongTagStart);
            // cout << "End of body is found and the sub XML to extract is: "<< subXML.substr(endOfWrongTag + 1) << endl;
            new_post.body = extract(subXML.substr(endOfWrongTag + 1));
        }
        else
        {
            //   cout << "there doesn't exist an opening body" << endl;
            //    cout << "End of body is found and the sub XML to extract is: "<< subXML.substr(0, EName - 6) << endl;
            new_post.body = extract(subXML); // if no open tag then it is missing so take data from beginning
        }
    }
    // cout << "topics STEP: .." << endl;
    subXML = subXML.substr(EName + 7);
    //cout << subXML << endl;
    startName = subXML.find("<topics>");
    EName = subXML.find("</topics>");
    if (startName != string::npos || (EName != string::npos))
    {
        // cout << "YESSSSSS\nwe're working on: "<< subXML << endl;
        string newTopic = "";
        size_t topicBegin = subXML.find("<topic>");
        size_t topicEnd = subXML.find("</topic>");
        while ((topicBegin != string::npos) || (topicEnd != string::npos))
        {
            if (topicBegin != string::npos && (topicEnd != string::npos)&& topicBegin < topicEnd )
            {
                //    cout << "topic found at: " << subXML.substr(topicBegin + 7, topicEnd - topicBegin - 7) << endl;
                newTopic = extract(subXML.substr(topicBegin + 7, topicEnd - topicBegin - 7));
                topicBegin = subXML.find("<topic>", topicBegin + 7);
                topicEnd = subXML.find("</topic>", topicEnd + 7);
            }
            else if (topicBegin != string::npos && (topicEnd != string::npos)&& topicBegin > topicEnd )
            {
                // found an end but mismatches the found start = no start only end
                newTopic = extract(subXML.substr(EName + 9, topicEnd - 7)); // This assumes there is a </topics>
                topicEnd = subXML.find("</topic>", topicEnd + 7);
            }
            else if (topicBegin != string::npos)
            {
                newTopic = extract(subXML.substr(topicBegin + 7));
                topicBegin = subXML.find("<topic>", topicBegin + 7);
            }
            else if (topicEnd != string::npos)
            {
                //      cout <<"unknown behavior at: 4 "<< endl;
                size_t opening = subXML.find("<", startName + 1); // this assumes there's a <topics>
                if(opening == topicEnd)   // no <topic> tag, only </topic>
                {
                    size_t lastClosing = subXML.find(">"); // from beginning of subXML
                    newTopic = extract(subXML.substr(lastClosing + 1, topicEnd));
                }
                else
                {
                    size_t tagEnd = subXML.find(">", opening); // after opening bracket
                    newTopic = extract(subXML.substr(tagEnd+1, topicEnd));
                }
                topicEnd = subXML.find("</topic>", topicEnd + 8);

            }
            //   cout << "new topic is " << newTopic << endl;
            new_post.listOfTopics.push_back(newTopic);
        }
    }
    return new_post;
}
follower solveForSingleFollower (string subXML)
{
    follower new_follower;
    // cout << "The subXML for single follower: " << subXML << endl;
    size_t startName = subXML.find("<id>");
    size_t EName = subXML.find("</id>");
    if (startName != string::npos)
    {
        new_follower.id = extract(subXML.substr(startName + 4));
    }
    else if (EName != string::npos)
    {
        size_t wrongTagStart = subXML.find("<");

        if (wrongTagStart < EName)
        {
            size_t  endOfWrongTag = subXML.find(">", wrongTagStart);
            new_follower.id = extract(subXML.substr(endOfWrongTag + 1));
        }
        else
        {
            new_follower.id = extract(subXML); // if no open tag then it is missing so take data from beginning
        }
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
        if (start != string::npos && (End != string::npos) && start < End)
        {
            //  cout << "2 post tags " << endl;
            postsOfUser.listOfPosts.push_back(solveForSinglePost(subXML.substr(start + 6, End - start - 6)));
            start = subXML.find("<post>",start + 6);
            End = subXML.find("</post>", End + 6);
        }
        else if (start != string::npos && (End != string::npos) && start > End)
        {

            postsOfUser.listOfPosts.push_back(solveForSinglePost(subXML.substr(0, End - 6)));
            End = subXML.find("</post>", End + 6);
        }
        else if (start != string::npos && End == string::npos)
        {
            postsOfUser.listOfPosts.push_back(solveForSinglePost(subXML.substr(start + 6)));
            start = subXML.find("<post>", start + 6);
        }
        else if (End != string::npos && start > subXML.size() - 1)
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
        if (start != string::npos && (End != string::npos) && start < End)
        {
            followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML.substr(start + 10, End - start - 10)));
            start = subXML.find("<follower>", start + 10);
            End = subXML.find("</follower>", End + 10);
        }
        else if (start != string::npos && End != string::npos && start > End)
        {
            size_t wrongTagStart = subXML.find("<");
            string tagBeforeId = subXML.substr(wrongTagStart,4);
            //  cout <<"tag before id: "<< tagBeforeId << endl;
            if (wrongTagStart < End && tagBeforeId != "<id>" && tagBeforeId != "</id")
            {
                // cout << "mismatching follower start" << endl;
                size_t  endOfWrongTag = subXML.find(">", wrongTagStart);
                followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML.substr(endOfWrongTag + 1)));
                End = subXML.find("</follower>", End + 10);
            }
            else
            {
                //  cout <<"missing start of a follower: "<< endl;
                // cout<< "our start is: " << subXML.substr(0, End - 10) << "\n end - 10 = " << End - 10 << endl;
                followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML.substr(0, End)));
                //followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML));
                End = subXML.find("</follower>", End + 10);
            }
        }
        else if(start != string::npos && End == string::npos )
        {
            followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML.substr(start + 10)));
            start = subXML.find("<follower>", start + 10);
        }
        else if (End != string::npos && start > subXML.size() - 1)
        {
            followersOfUser.listOfFollowers.push_back(solveForSingleFollower(subXML.substr(0, End - 10)));
            End = subXML.find("</follower>", End + 10);
        }

    }
    return followersOfUser;
}
user solveForSingleUser (string subXML)
{
    //  cout << "for single user " << subXML << endl;
    user new_user;
    size_t start = subXML.find("<id>");
    size_t idClosing = subXML.find("</id>");
    if (start != string::npos && idClosing != string::npos && start < idClosing)
    {
        // the opening id tag exists
        // take the id data starting from end bracket of opening id until the beginning of the next bracket
        new_user.id = extract(subXML.substr(start + 4));
    }
    else if (start != string::npos && idClosing != string::npos && start > idClosing)
    {
        size_t wrongTagStart = subXML.find("<");
        if (wrongTagStart < idClosing)
        {
            size_t  endOfWrongTag = subXML.find(">", wrongTagStart);
            new_user.id = extract(subXML.substr(endOfWrongTag + 1));
        }
        else
        {
            new_user.id = extract(subXML);
        }
    }
    else if (idClosing != string::npos && (start > subXML.size() - 1))
    {
        // if no open tag for id
        // take id from start of sub_xml until the closing id tag
        new_user.id = extract(subXML);
    }
    /* take the name data */
    size_t startName = subXML.find("<name>");
    size_t EName = subXML.find("</name>");
    if (startName != string::npos && EName != string::npos && startName < EName)
    {
        //cout << "start name exists for user: " << new_user.id << endl;
        new_user.name = extract(subXML.substr(startName + 6));
    }

    // missing start
    else if ( EName != string::npos && (startName > subXML.size() - 1))
    {
        size_t wrongTagStart = subXML.find("<",idClosing + 5);
        // cout <<"wrong start name = "<< wrongTagStart << endl;
        if (wrongTagStart < EName)
        {
            //         cout << "found a wrong tag" << endl;
            // there is a wrong tag
            // find its end '>' and start to take the data
            size_t  endOfWrongTag = subXML.find(">",wrongTagStart);
            //start = subXML.find("<user>", start + 6)
            new_user.name = extract(subXML.substr(endOfWrongTag + 1));
        }
        else
        {
            new_user.name = extract(subXML.substr(idClosing + 5));
        }
    }
    // missing End
    else if ( startName != string::npos && (EName > subXML.size() - 1))
    {
        new_user.name = extract(subXML.substr(startName + 6));
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
        size_t wrongTagStart = subXML.find("<", EName + 7);
        if (wrongTagStart < EPosts)
        {
            size_t  endOfWrongTag = subXML.find(">", wrongTagStart);
            new_user.Posts = solveForListOfPosts(subXML.substr(endOfWrongTag + 1));
        }
        else
        {
            new_user.Posts = solveForListOfPosts(subXML.substr(EName + 7)); // start from end of name tag
        }
    }


    size_t startf = subXML.find("<followers>");
    size_t Ef = subXML.find("</followers>");
    //  cout << "we find followers tag in: " << subXML << endl;
    // cout << "startf = " << startf << "Ef = " << Ef << endl;
    if ((startf != string::npos) && (Ef != string::npos))
    {
        //   cout << "start and End followers found" << endl;
        new_user._followers = solveForListOfFollowers(subXML.substr(startf + 11, Ef - startf - 11));
    }
    else if (startf != string::npos)
    {
        //  cout << "no End followers found" << endl;
        new_user._followers = solveForListOfFollowers(subXML.substr(startf + 11));
    }
    else if (Ef != string::npos)
    {
        //  cout << "no start followers found" << endl;
        size_t wrongTagStart = subXML.find("<", EPosts + 8);
        if (wrongTagStart < EPosts)
        {
            size_t  endOfWrongTag = subXML.find(">",wrongTagStart);
            new_user._followers = solveForListOfFollowers(subXML.substr(endOfWrongTag + 1));
        }
        else
        {
            new_user._followers = solveForListOfFollowers(subXML.substr(EPosts + 8, Ef - 11)); // start from end of posts tag
        }
    }
    return new_user;
}
users solveForListOfUsers (string subXML)
{
    // cout << "for list of users our start is: \n" << subXML << endl;
    users root;
    size_t start = subXML.find("<user>");
    size_t End = subXML.find("</user>");
    while (start != string::npos || (End != string::npos))
    {
        if (start != string::npos && End != string::npos && start < End)
        {
            //  cout << "There's start and end user" << endl;
            root.listOfUsers.push_back(solveForSingleUser(subXML.substr(start + 6, End - start - 6)));
            start = subXML.find("<user>", start + 6);
            End = subXML.find("</user>", End + 6);
        }
        else if (start != string::npos && End != string::npos && start > End)
        {
            root.listOfUsers.push_back(solveForSingleUser(subXML.substr(0, End - 6)));
            End = subXML.find("</user>", End + 6);
        }
        else if (start != string::npos && (End > subXML.size() - 1))
        {
            root.listOfUsers.push_back(solveForSingleUser(subXML.substr(start + 6)));
            start = subXML.find("<user>", start + 6);
        }
        else if  (End != string::npos && start > subXML.size() - 1)
        {
            // cout  << "wrong start followers name!!" << endl;
            root.listOfUsers.push_back(solveForSingleUser(subXML.substr(0, End - 6)));
            End = subXML.find("</user>", End + 6);
        }
    }
    return root;
}
users readAndCorrect (string inputXML)
{
    string allXML = read(inputXML);
    users XMLroot;
    size_t start = allXML.find("<users>");
    size_t End = allXML.find("</users>");
    //cout << "start = " << start <<" End = " << End << endl;
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
void correct (string inputXML, string afterCorrection)
{
    ofstream fout(afterCorrection.c_str(),ios::binary);
    users allUsers = readAndCorrect(inputXML);
    string correctedXML = allUsers.usersToString();
    fout.write(correctedXML.c_str(), sizeof(char)*correctedXML.size());
    fout.close();
    // string JsonXML = allUsers.usersToJson();
    cout << correctedXML<< "\n" << endl;
    // cout << JsonXML << endl;
}
void toJson(string inputXML, string jsonOutput)
{
    ofstream fout(jsonOutput.c_str(),ios::binary);
    users allUsers = readAndCorrect(inputXML);
    string JsonXML = allUsers.usersToJson();
    cout << JsonXML << endl;
    fout.write(JsonXML.c_str(), sizeof(char)*JsonXML.size());
    fout.close();
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

string isValid (string inputXML)
{
    ifstream fin;
    ofstream fout;
    fin.open(inputXML.c_str(), ios::out);
    string line;
    vector <string> stringVector;
    //ifstream in("unFormatted_XMLFile.xml");

    while (getline(fin,line))
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
    string errorTag = "";
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
                return "Invalid\n" + cur;
                valid = false;
                break;
            }
        }
        else if((opens.empty())&& (stringVector[i][1] == '/'))
        {
            return "Invalid\n" + stringVector[i];
            valid = false;
            break;
        }
    }
    if ((!valid) || (!opens.empty()))
    {
        return "Invalid\n" + errorTag;
    }
    else
    {
        return "Valid";
    }
    /*  for (int i = 0; i < stringVector.size(); i++) {
             cout << "cur line is " << stringVector[i] << endl;
         }*/
}
string minify(string inputXML, string afterMinifying)
{
    ifstream fin;
    ofstream fout;
    fin.open(inputXML.c_str(), ios::out);
    string _read = "", _line = "";
    while (getline(fin,_line))
    {
        for (int i = 0; i < _line.size(); i++)
        {
            if (_line[i] == ' ')
            {
                //cout <<"space" << endl;
                continue;
            }
            _read += _line[i];
        }
    }
    fin.close();
    return _read;
}

int main()
{
    correct("unFormatted_XMLFile.xml","");
    cout << isValid("unFormatted_XMLFile.xml") << endl;
    /*if (isValid("unFormatted_XMLFile.xml"))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout <<"invalid" << endl;
    }*/
    toJson("unFormatted_XMLFile.xml","");
    string mini = minify("sample.xml","");
    cout << "minifying \n" << mini << endl;
}
