/****************************************************
*
* Problem:
*                 사각형과 점과의 거리
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
int AbsoluteValue(int value){
    if(value<0) value *= -1;
    return value;
}
int Euclideandistance(int x1,int y1,int x2,int y2){
    int d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return d;
}
//직각
int Rectilineardistance(int x1,int y1,int x2,int y2){
    int x = AbsoluteValue(x1-x2);
    int y = AbsoluteValue(y1- y2);
    return x+y;
}
#include<iostream>
using namespace std;

int main(void){
  int numTestcases;
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int x,x1,x2,y,y1,y2;
      int dis_r,dis_e;
      cin >> x1;
      cin >> y1;
      cin >> x2;
      cin >> y2;
      cin >> x;
      cin >> y;

      if(x<x1){
          if(y <y1){
              dis_r = Rectilineardistance(x,y,x1,y1);
              dis_e = Euclideandistance(x,y,x1,y1);
          }
          else if((y1<=y) && (y<=y2)){
              dis_r = x1-x;
              dis_e = dis_r *dis_r;
          }
          else{
              dis_r = Rectilineardistance(x,y,x1,y2);
              dis_e = Euclideandistance(x,y,x1,y2);
          }
      }
      else if((x1<=x) && (x<=x2)){
          if(y <y1){
              dis_r = y1-y;
              dis_e = dis_r *dis_r;
          }
          else if((y1<=y) && (y<=y2)){
              dis_r = 0;
              dis_e = 0;
          }
          else{
              dis_r = y-y2;
              dis_e = dis_r *dis_r;
          }
      }
      else{
          if(y <y1){
              dis_r = Rectilineardistance(x,y,x2,y1);
              dis_e = Euclideandistance(x,y,x2,y1);
          }
          else if((y1<=y) && (y<=y2)){
              dis_r = x-x2;
              dis_e = dis_r *dis_r;
          }
          else{
              dis_r = Rectilineardistance(x,y,x2,y2);
              dis_e = Euclideandistance(x,y,x2,y2);
          }
      }
      cout << dis_e << " " << dis_r << endl;
  }
  return 0;
}
