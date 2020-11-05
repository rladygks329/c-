/****************************************************
*
* Problem:
*                모래시계 출력하기
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
      int size,middle;
      int numOfMinus = 0;

      cin >> size;
      middle = size/2;
      for (int j = 0;j<size; j++){
          // print -
          for(int k =0; k<numOfMinus;k++){
              cout << "-"<< " ";
          }
          //print * or +
           for(int k =0; k<size-numOfMinus*2;k++){
               if((j+k+numOfMinus)%2 == 0) cout << "*" <<" ";
               else cout << "+" <<" ";
           }
           //print -
           for(int k =0; k<numOfMinus;k++){
               cout << "-"<< " ";
           }
           if(numOfMinus<middle && j <= middle) numOfMinus+=1;
           else numOfMinus -=1;

           cout << "\n";
      }
  }
  return 0;
}
