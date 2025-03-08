#include<bits/stdc++.h>
using    namespace std;
#define ll long long

void prnt(string match, stack<char> tmp1, stack<char> tmp2) {
    cout << left << setw(8) << match;
        
    string temp = "";
        while(!tmp1.empty())
        {
            auto ch=tmp1.top();
            temp.push_back(ch);
            tmp1.pop();
        }
        cout << left << setw(8) << temp;
        
        temp = "";
        while(!tmp2.empty())
        {
            auto ch=tmp2.top();
            temp.push_back(ch);
            tmp2.pop();
        }
        cout << left << setw(8) << temp;
        
}
int main()
{
    ll m;
    map<char,map<char,string>>mp;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        char first,sec;
        string s;
        cin>>first>>sec>>s;
        mp[first][sec]=s;
    }
    
    string input,match,st;
    cin>>input;
    
    stack<char> s1,s2;
    for(int i=input.size()-1;i>=0;i--) s2.push(input[i]);
    
    s1.push('$');
    s1.push('E');
    
    cout << left << setw(8) << "Matched";
    cout << left << setw(8) << "Stack";
    cout << left << setw(8) << "input";
    cout << left << setw(8) << "Action";
    cout << endl;
    
    while(1)
    {
        prnt(match, s1, s2);
        
        if(s1.size()==1&&s2.size()==1&&s1.top()==s2.top())
        {
            cout<<endl<<endl;
            cout<<"Accepted!!!"<<endl;
            break;
        }
        
        char ch1=s1.top();
        char ch2=s2.top();
        
        if(ch1==ch2)
        {
            cout<<"match: "<<ch1<<endl;
            match.push_back(ch1);
            s1.pop();
            s2.pop();
            continue;
        }
        
        if(mp[ch1][ch2].size()==0)
        {
            cout<<endl;
            cout<<"Rejected!!!"<<endl;
            return 0;
        }
        
        s1.pop();
        string str=mp[ch1][ch2];
        cout<<"Output: "<<ch1<<" --> "<<str<<endl;
        
        if(str=="0")continue; // epsilon
        
        for(int i=str.size()-1;i>=0;i--)s1.push(str[i]);
    }
 
}