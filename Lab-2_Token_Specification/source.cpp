#include<bits/stdc++.h>
using namespace std;

int main() {
     string s;
     set<string> key, ident, op, cons, func;

     // keys
     set<string> keys;
     keys.insert("int");
     keys.insert("for");
     keys.insert("return");

     set<string> ops;
     ops.insert("(");
     ops.insert(")");
     ops.insert("{"); ops.insert("}"); ops.insert(","); ops.insert("++"); ops.insert("="); ops.insert("<=");ops.insert(";");ops.insert("+");

     set<string> funs;
     funs.insert("main");
    map<string, int> mp;


     while(cin >> s) {
        string nw = "";
        int t = 10;

        while(s.size()) {
            //cout << s << endl;
            int yes = -1;
            for(int i = s.size() - 1; i >= 0; i--) {
                nw = s.substr(0, i + 1);
                if(keys.find(nw) != keys.end()) {
                    yes = i;
                    key.insert(nw); break;
                }
                else if(ops.find(nw) != ops.end()) {
                    yes = i;
                    op.insert(nw); break;
                }
                else if(funs.find(nw) != funs.end()) {
                    yes = i;
                    func.insert(nw); break;
                }
            }
            if(yes != -1) {
                s = s.substr(yes + 1);
            }
            if(s[0] >= '0' && s[0] <= '9') {
                string temp = "";
                for(int i = 0; i < s.size(); i++) {
                    if(s[i] >= '0' && s[i] <= '9') temp += s[i];
                    else {
                        cons.insert(temp);
                        s = s.substr(i);
                        break;
                    }
                }
            }
            else {
                string temp = "";
                for(int i = 0; i < s.size(); i++) {
                    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) temp += s[i];
                    else {
                        ident.insert(temp);
                        if(temp.size() > 0 && mp.find(temp) == mp.end()) mp[temp] = 1;
                        s = s.substr(i);
                        break;
                    }
                }
            }

        }
     }
        cout << "Keyword: ";
        for(auto it : key) cout << it << " ";
        cout << endl;
        cout << "Identifier: ";
        for(auto it : ident) cout << it << " ";
        cout << endl;
        cout << "Operator: ";
        for(auto it : op) cout << it << " ";
        cout << endl;
        cout << "Constant: ";
        for(auto it : cons) cout << it << " ";
        cout << endl;
        cout << "Function: ";
        for(auto it : func) cout << it << " ";
        cout << endl;

        cout << "Symbol Table\n";
        int indx = 0;
        for(auto it : mp) cout << indx++ << " " << it.first << endl;
}

