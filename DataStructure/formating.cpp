#include "formating.h"
#include <string>
#include <stack>
#include <QString>
#include <fstream>
#include <iostream>
using namespace std;

string remove_space(string s)
{
    auto pos = s.find_first_not_of(' ');
    auto Trimmed = s.substr(pos != std::string::npos ? pos : 0);
    return s;

}

bool findInOneLine(string s)
{
    int c=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='<')
            c++;
    }
    if(c==1)
        return 0;
    else
        return 1;


}
string printsp(int n,string st)
{

    while(n!=0)
    {
        st+=" ";
        n--;
    }
    return st;
}

 void formating(string unformated ,string formated)
 {
     struct my_xml
     {
         QString s;
         int space;
     };
     string l="";
     string g,st="";
     int i=0;
     my_xml line;
     stack <my_xml> tags;
     ifstream input;
     ofstream output;
     input.open(unformated,ios::in);
     output.open(formated,ios::out);
     if(input.is_open()&&output.is_open())
     {

        while(getline(input,l))
        {
            g=remove_space(l);
            if(g[0]=='<')
            {

                if(g[1]=='/')     //close tag
                {
                    output<<printsp(tags.top().space,st)<<g<<endl;
                    tags.pop();

                }
                else                   //open tag
                {

                    if(!tags.empty())
                        i=tags.top().space+4;

                    if(!findInOneLine(g))
                    {
                        line.s=g[i];
                        line.space=i;
                        tags.push(line);

                    }


                }

            }
            else
            {
                 output<<printsp(tags.top().space+4,st)<<g<<endl;


            }



        }

     }
     input.close();
     output.close();





 }
