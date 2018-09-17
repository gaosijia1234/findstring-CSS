#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

bool isValidEmailCharacter(char c)
{
  if((c >='A' && c <= 'Z') || (c >='a' && c <='z') || (c >='0' && c <='9') || c=='.' || c=='-' || c=='+')
    {
      return true;
    }
  return false;
}

int main()
{
    string inputFile;
    string outputFile;
    string inputDefault = "fileContainingEmails.txt";
    string outputDefault = "copyPasteMyEmails.txt";

    cout << "Enter input filename [default: "<< inputDefault << "]: " ;
    getline(cin, inputFile);

    //  if the input is ENTER
    if (inputFile == inputDefault || inputFile == "" || inputFile.length() == 0)
    {   inputFile=inputDefault;
        cout << "Enter output filename [default: " << outputDefault << "]: " ;
        getline(cin, outputFile);

        // if both of the answers are ENTER
        if (outputFile == outputDefault || outputFile == "" || outputFile.length() == 0)
        {   outputFile=outputDefault;
            cout << "Input file: " << inputDefault << endl;
            cout << "Output file: " << outputDefault << endl;}

        // if the input is ENTER, the output is a real text
        else
        {   cout << "Input file: " << inputDefault << endl;
            cout << "Output file: " << outputFile << endl;}
    }
    // if the input is a real text
    else
    {   cout << "Enter output filename [default: " << outputDefault << "]: " ;
        getline(cin, outputFile);

        // if the output is ENTER
        if (outputFile == outputDefault || outputFile == "" || outputFile.length() == 0)
        {   outputFile = outputDefault;
            cout << "Input file: " << inputFile << endl;
            cout << "Output file: " << outputFile << endl;}

        // if the output is a real text
        else
        {
            cout << "Input file: " << inputFile << endl;
            cout << "Output file: " << outputFile << endl;
        }

    }
    ifstream fin;
    
    fin.open("/Users/jessie_gao/Desktop/math1.txt");
    //fin.open(inputFile.c_str());
    if (!fin.good()) throw "I/O error";

    string str;
    const int EMAILNUM=2000;
    int emailNum = 0;
    string emails[EMAILNUM];

    int i = 0;
    while(true)
    {
    if(!fin.good()) break;
    getline(fin, str);
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '@')
        {
            int s = i - 1;
			int e = i + 1;
			bool hasDot = false;

            while(true)
            {
              if(s<0)
              {
                break;
              }
              if(!isValidEmailCharacter(str[s]))
              {
                break;
              }
              s--;
            }
			s++;

			while(true)
            {
                if(e >= str.length())
                {
                  break;
                }
                if(!isValidEmailCharacter(str[e]))
                {
                  break;
                }
                if(str[e]=='.')
                {
                  hasDot = true;
                }
                e++;
            }
            if (emailNum < EMAILNUM)
            {
              emails[emailNum++]=str.substr(s,e-s);
            }
        }
    }//for
   }//while

   for(int n = 0;n<emailNum;n++)
   {
     cout << emails[n] << endl;
   }
  fin.close();
}
