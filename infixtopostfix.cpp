#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precidence(char c){
if(c=='+'||c=='-'){
    return 1;
}
else if(c=='*'||c=='/'){
    return 2;
}
else if(c=='^'){
    return 3;
}
else{
    return -1;
}
}
void infixtopostfix(string s){
    stack<char> st;
    string result;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
            result+=c;
        }
        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(!st.empty()&&st.top()!='('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty()&&precidence(st.top())>=precidence(c)){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    cout<<result<<endl;
}