#include <iostream>
using namespace std;
bool match(string &s, string part) {
  if (s.find(part) != string::npos)
    return true;
  return false;
}
void removeOccurencesHelper(string &s, string part) {
  int index = s.find(part);
  int length = part.length();
  s.erase(s.begin() + index, s.begin() + index + length );
}
string removeOccurrences(string s, string part) {
  while (match(s, part)) {
    removeOccurencesHelper(s, part);
  }
  return s;
}
int main() {
  string s = "daabcbaabcbc";
  s = removeOccurrences(s, "abc");
  cout << s << endl;

  return 0;
}