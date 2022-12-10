#include "helper.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
bool isSplitterWord(const char& ch) {
return !isalpha(ch) && !isdigit(ch);
}
bool isVowel(const char& _ch) {
char ch = tolower(_ch);
return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}
std::string task(const string& s) {
std::string ans = "";
if (isVowel(s[0])) {
char ch = toupper(s[0]);
std::string str(1, ch);
ans.append(str);
}
else
ans.append(s.substr(0, 1));
for (int i = 1; i < s.size(); i++) {
if (isSplitterWord(s[i-1])) {
if (isVowel(s[i])) {
char ch = toupper(s[i]);
std::string str(1, ch);
ans.append(str);
}
else
ans.append(s.substr(i, 1));
}
else
ans.append(s.substr(i, 1));
}
return !ans.empty() ? ans : "There are no sentences of the given length in the file\n";
}
string readFile(ifstream& input) {
string s = "";
string tmpS;
while (getline(input, tmpS))
s.append(tmpS).append("\n");
return s;
}
int main() {
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
string filename;
processInputNameOfInputFile(filename);
ifstream input(filename);
cout << "Result of work:\n" << task(readFile(input));
input.close();
}
