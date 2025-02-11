#include <bits/stdc++.h>
using namespace std;

map<string, vector<string> > mp; // store the productions of each non-terminal
map<string, int> vis; // check if the string is visited or not

// check if the character is terminal or not
bool isterminal(char ch) {
  return ch >= 'a' && ch <= 'z';
}

// check if the string S can be converted to string T or not
bool check(string s, string t) {
  if(vis[s]) return false;
  vis[s] = true;
  
  bool ans = false;
  int non_terminal = 0;
  for(auto it : s) {
    if(!isterminal(it)) non_terminal++;
  }
  
  if(s == t) return true;
  if(s.size() - non_terminal > t.size()) return false;
  
  for(int i = 0; i < s.size() && ans == false; i++) {
    if(isterminal(s[i])) {
      if(s[i] != t[i]) return false;
      continue;
    }
    for(auto it : mp[s.substr(i, 1)]) {
      string newString = s.substr(0, i);
      newString += it;
      newString += s.substr(i + 1);
      ans |= check(newString, t);
      if(ans) break; 
    }
    break;
  }
  
  return ans;
}

int main() {
  
  int number_of_productions;
  cin >> number_of_productions;
  
  mp.clear();
  getchar();
  
  while(number_of_productions--) {
    string s;
    getline(cin, s);
    vector<string> v;
    
    // split the string into tokens
    string temp = "";
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == ' ') {
        if(temp == "e") temp = ""; // if the token is epsilon, then ignore it
        v.push_back(temp);
        temp = "";    
      }
      else temp += s[i];
    }
    if(temp == "e") temp = "";
    v.push_back(temp);
    
    for(int i = 1; i < v.size(); i++) mp[v[0]].push_back(v[i]);
  }
  
  int tc; // number of test cases
  cin >> tc;
  while(tc--) {
    vis.clear();
    string t;
    cin >> t;
    
    // check if string T is accepted or not
    if(check("S", t)) cout << "Accepted\n";
    else cout << "Rejected\n";
  }
}
