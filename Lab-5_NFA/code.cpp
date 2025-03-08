#include<bits/stdc++.h>
using namespace std;

map<string, vector<pair<char, string> > > nfa;
map<string, int> isfinal;
map<pair<int, string>, int> visited;

bool check(int pos, string cur, string sample)
{
    if(visited[{pos, cur}]) return false;
    visited[{pos, cur}] = 1;
    
    if(pos == sample.size())
    {
        if(isfinal[cur]) return true;
        for(auto it : nfa[cur])
        {
            if(it.first == 'E' && check(pos, it.second, sample)) return true;
        }
        return false;
    }

    bool found = false;
    for(auto it : nfa[cur])
    {
        if(sample[pos] == it.first)
        {
            found |= check(pos + 1, it.second, sample);
        }
        else if(it.first == 'E') {
            found |= check(pos, it.second, sample);    
        }
    }
    return found;
}
int main()
{
    cout << "Enter the initial state: ";
    string init_state; cin >> init_state;

    cout << "Enter the number of final states: ";
    int p; cin >> p;
    for(int i = 1; i <= p; i++)
    {
        string x; cin >> x;
        isfinal[x] = 1;
    }
    
    int transition; cin >> transition;
    for(int i = 0; i < transition; i++)
    {
        string u, v; 
        char ch;
        cin >> u >> ch >> v;
        nfa[u].push_back({ch, v});
    }
    int t; cin >> t;
    while(t--)
    {
        string sample; cin >> sample;
        if(check(0, init_state, sample)) cout << "Accepted" << endl;
        else cout << "Rejected" << endl;
    }
}