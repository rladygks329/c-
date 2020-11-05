/****************************************************
*
* Problem:
*                수직 수평 성분의 교차차
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;
// verti == return1 hori == 0
int verticalCheck(int a[4]){
    if(a[0] == a[2]) return 1;
    else return 0;
}
int min(int a, int b){
    if( a > b) return b;
    else return a;
}
int max(int a, int b){
    if( a < b) return b;
    else return a;
}
int main(void){
  int numTestcases;
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int dot[2][4] = {0};
      for(int j =0;j<2;j++){
          for(int k =0;k<4;k++){
              cin >> dot[j][k];
          }
      }// end input

      //dot is vertical
      if(verticalCheck(dot[0])){
          int x = dot[0][0];
          int y_min = min(dot[0][1] ,dot[0][3]);
          int y_max = max(dot[0][1] ,dot[0][3]);

          int y = dot[1][1];
          int x_min = min(dot[1][0],dot[1][2]);
          int x_max = max(dot[1][0],dot[1][2]);

          if( (x_min <=x) && ( x <=x_max) ){
              if( ( y_min <=y) && (y<= y_max) ){
                  if( y_min == y || y_max == y || x_max == x || x_min ==x)
                    cout << 2 << endl;
                else
                    cout << 1<< endl;
              }
              else cout <<0<< endl;
          }
          else cout << 0<< endl;
      }
      else{//horti  1==3
          int y = dot[0][1];
          int x_min = min(dot[0][0],dot[0][2]);
          int x_max = max(dot[0][0],dot[0][2]);
          int x = dot[1][0];
          int y_min = min(dot[1][1] ,dot[1][3]);
          int y_max = max(dot[1][1] ,dot[1][3]);
          if( (x_min <=x) && ( x <=x_max) ){
              if( ( y_min <=y) && (y<= y_max) ){
                  if( y_min == y || y_max == y || x_max == x || x_min ==x)
                    cout << 2<< endl;
                else
                    cout << 1<< endl;
              }
              else cout <<0<< endl;
          }
          else cout << 0<< endl;
      }//end if
  }//end for
  return 0;
}
