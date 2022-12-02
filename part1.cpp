/*#include "stdafx.h"
#include <tchar.h>

#using <mscorlib.dll>
#using <System.xml.dll>

using namespace System;
using namespace System::Xml;

void _tmain(void)
{
    XmlTextReader* reader = new XmlTextReader ("sample.xml");

    while (reader->Read())
    {
        switch (reader->NodeType)
        {
            case XmlNodeType::Element: // The node is an element.
                Console::Write("<{0}", reader->Name);

                while (reader->MoveToNextAttribute()) // Read the attributes.
                    Console::Write(" {0}='{1}'", reader->Name, reader->Value);
                Console::WriteLine(">");
                break;
            case XmlNodeType::Text: //Display the text in each element.
                Console::WriteLine (reader->Value);
                break;
            case XmlNodeType::EndElement: //Display the end of the element.
                Console::Write("</{0}", reader->Name);
                Console::WriteLine(">");
                break;
        }
    }
    Console::ReadLine();
}*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
//#include <msxml4.h>
#import <msxml6.dll> named_guids
using namespace MSXML2;
//#include "msxml6.h"
#include<msxml3.dll>
//#include <MsXml.h>
using namespace std;
int main()
{
    string line;
    ifstream in("sample.xml");
    vector <string> stringVector;
    while (getline(in,line))
    {
        string currentLine = "";
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != '<'){continue;/* skip spaces and text*/}

                while (line[i] != '>')
                {
                    currentLine += line[i++];
                }
                 if (line[i] == '>') {
                    currentLine += line[i++];
                    stringVector.push_back(currentLine);
                    currentLine = "";
                 }
        }
    }
        for (int i = 0; i < stringVector.size(); i++) {
            cout << "cur line is " << stringVector[i] << endl;
        }
}
