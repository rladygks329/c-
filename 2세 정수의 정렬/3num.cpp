/****************************************************
*
* Problem:
*              세 정수의 정렬
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;
void sort3Integers(int a, int b, int c){
    if(a <= b){
        if(b<=c){
            cout << a << " " <<  b << " " <<  c << endl;
        }
        else{// a<b b>C
            if(a <= c)
                cout << a << " " <<  c << " " <<  b << endl;
            else//a>c ,a<b ,
                cout << c << " " <<  a << " " <<  b << endl;
        }
    }
    else{//a>b
        if(a<=c){//a<bc
            cout << b << " " <<  a << " " <<  c << endl;
        }
        else{ //a>b ,a >C
            if(b<=c){
                cout << b << " " <<  c<< " " <<  a << endl;
            }
            else{
                cout << c << " " <<  b << " " <<  a << endl;
            }
        }

    }
}

int main(void){
  int numTestcases;
  /* read the number of test cases*/
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int a,b,c;
      cin >> a >> b >>c;
      sort3Integers(a,b,c);
      }
  return 0;
}
