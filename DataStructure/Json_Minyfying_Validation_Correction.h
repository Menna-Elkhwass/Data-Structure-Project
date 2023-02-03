#ifndef JSON_MINYFYING_VALIDATION_CORRECTION_H
#define JSON_MINYFYING_VALIDATION_CORRECTION_H
#include "user.h"
#include <string>
#include <QMainWindow>
using namespace std;
void mutual (string ID1, string ID2, string inputXML, string mutualOutput);
void correct (string inputXML, string afterCorrection);
void suggest(string ID, string inputXML, string suggestOutput);
void toJson(string inputXML, string jsonOutput);
void maxi_number_of_followers (string inputXML, string maxFollowers);
void mostConnected(string inputXML, string MostConnected);
string textOfTag(string tag);
string isValid (string inputXML);
void minify(string inputXML, string afterMinifying);
void find_post(string word,string input,string output);

#endif // JSON_MINYFYING_VALIDATION_CORRECTION_H
