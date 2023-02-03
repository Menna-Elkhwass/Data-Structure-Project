#include "post.h"
#include <bits/stdc++.h>
using namespace std;

post::post()
{
    //ctor
}
string post::postToString ()
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

post::~post()
{
    //dtor
}
