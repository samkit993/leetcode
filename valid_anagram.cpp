#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t)
            return true;
        else
            return false;
}

int main(){
  cout << isAnagram("print", "tripn");
  return 0;
}
