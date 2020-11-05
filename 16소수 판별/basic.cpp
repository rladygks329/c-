/****************************************************
*
* Problem:
*                소수
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;
bool PrimeNumber(int data);
int main(void){
  int numTestcases,data;
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      cin >>data;
      bool result = PrimeNumber(data);
      cout << result<<endl;
      //if(result) cout <<data <<endl;

  }
  return 0;
}
bool PrimeNumber(int data){
    bool result = true;
    for(int i = 2; i<=data/2;i++){
        if(data%i == 0){
            result = false;
            break;
        }
    }
    return result;
}
