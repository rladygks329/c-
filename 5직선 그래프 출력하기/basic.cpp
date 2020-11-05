/****************************************************
*
* Problem:
*                직선그래프만들기기
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;

int main(void){
  int numTestcases;
  /* read the number of test cases*/
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int input,middle ;
      cin >> input;
      middle = input/2;
      for(int j=0; j<input; j++){
          for(int k=0; k<input;k++){
              if( j==middle && k ==middle){
                  cout << "O";
              }
              else if(j ==middle || k== middle){
                  if( j == middle) cout << "+";
                  else cout  << "I";
              }
              else if( j+k ==2*middle) cout << "*";
              else cout << ".";
                }
      cout << endl;
        }
    }
  return 0;
}
