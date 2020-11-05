/****************************************************
*
* Problem:
*                괄호
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void){
  int numTestcases;
  cin >>  numTestcases;
  for ( int i=0; i<numTestcases; i++){
      bool balanced = false;
      string data;
      stack<char> st;
      cin >> data;
      for(int i=0;i<data.size();i++){
         if((data[i] == '{') || (data[i] == '[')  || (data[i] == '(')){
             //cout <<"push"<<endl;
              st.push(data[i]);
          }
          else if(data[i] == '}' || data[i] == ']'  || data[i] == ')'){
              if(st.empty()) {
                 // cout <<"}]) first"<<endl;
                  balanced = false;
                  break;
              }
              else{
                  if( ((st.top()=='[')&&(data[i]==']')) || ((st.top()=='{')&&(data[i]=='}')) || ((st.top()=='(')&&(data[i]==')'))){
                      //cout << st.top()<<" "<<data[i] <<endl;
                      balanced = true;
                      st.pop();
                  }
                  else break;
              }
          }
      }
      if(!st.empty()){
          balanced = false;
          //cout<<"end but not empty"<<endl;
      }
      cout << balanced<<endl;
  }
  return 0;
}
