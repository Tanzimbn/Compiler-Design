#include <bits/stdc++.h>

using namespace std;

vector<int> v;
map<char, int> op;


string tostring(int val) {
  string temp = "";
  temp = to_string(val);
  return temp;
}

void prnt(string s, int l, int r) {
    cout << s.substr(1, l);
    for(int i = 0; i < v.size(); i++) {
      if(i % 2 == 0) cout << v[i];
      else {
        for(auto it : op) {
          if(it.second == v[i]) cout << it.first;
        }
      }
    }
    cout << s.substr(r, s.size() - r-1) << endl;
}
void oprt(string s, int l, int r, int opt) {
  while(true) {
    int yes = 1;
    vector<int> temp;
    for(int i = 1; i < v.size(); i += 2) {
      if(v[i] != opt) {
        temp.push_back(v[i - 1]); temp.push_back(v[i]);
        continue;
      }
      int val;
      if(opt == 0) val = v[i - 1] + v[i + 1];
      else if(opt == 1) val = v[i - 1] - v[i + 1];
      else if(opt == 2) val = v[i - 1] / v[i + 1];
      else if(opt == 3) val = v[i - 1] * v[i + 1];
      else val = v[i - 1] % v[i + 1];
      
      temp.push_back(val);
      for(int j = i + 2; j < v.size(); j++) temp.push_back(v[j]);
      yes = 0;
      v = temp;
      break;
    }
    
    if(yes) break;
    
    prnt(s, l, r);
  }
}
string tokenise(string s, int l, int r) {
  v.clear();
  int temp = 0;
  for(int i = l + 1; i < r; i++) {
    if(s[i] >= '0' && s[i] <= '9') {
      temp = temp*10 + (s[i] - '0');
    }
    else {
      v.push_back(temp);
      v.push_back(op[s[i]]);
      temp = 0;
    }
  }
  v.push_back(temp);
  
  oprt(s, l, r, 3);
  oprt(s, l, r, 2);
  oprt(s, l, r, 4);
  oprt(s, l, r, 1);
  oprt(s, l, r, 0);
  
  string nw = s.substr(0, l) + tostring(v[0]) + s.substr(r + 1);
  return nw;
}
int main() {
  
  op['+'] = 0;
  op['-'] = 1;
  op['/'] = 2;
  op['*'] = 3;
  op['%'] = 4;
  
  string s;
  cin >> s;
  
  cout << s << endl;
  s = "(" + s + ")";
  while(true) {
    int l = 0, r = -1;
    for(int i = 1; i < s.size(); i++) {
      if(s[i] == '(') l = i;
      if(s[i] == ')') {
        r = i; break;
      }
    }  
    if(r == -1) break;
    s = tokenise(s, l, r);
  }
}