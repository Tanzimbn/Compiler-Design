#include <bits/stdc++.h>

using namespace std;
#define PB push_back

vector<int> v;
map<char, int> op;

void oprt(int opt) {
	while(true) {
		int yes = 1;
		vector<int> temp;
		for(int i = 1; i < v.size(); i += 2) {
			if(v[i] != opt) {
				temp.PB(v[i - 1]); temp.PB(v[i]);
				continue;
			}
			int val;
			if(opt == 0) val = v[i - 1] + v[i + 1];
			else if(opt == 1) val = v[i - 1] - v[i + 1];
			else if(opt == 2) val = v[i - 1] / v[i + 1];
			else if(opt == 3) val = v[i - 1] * v[i + 1];
			else val = v[i - 1] % v[i + 1];
			
			temp.PB(val);
			for(int j = i + 2; j < v.size(); j++) temp.PB(v[j]);
			yes = 0;
			v = temp;
			break;
		}
		
		if(yes) break;
	}
}
void tokenise(string s) {
	
	int temp = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			temp *= 10 + (s[i] - '0');
		}
		else {
			v.push_back(temp);
			v.push_back(op[s[i]]);
		}
	}
	
	oprt(3);
	oprt(2);
	oprt(4);
	oprt(1);
	oprt(0);
	
	
}
int main() {
	
	op['+'] = 0;
	op['-'] = 1;
	op['/'] = 2;
	op['*'] = 3;
	op['%'] = 4;
	
	string s;
	cin >> s;
	
	tokenise(s);
	
}