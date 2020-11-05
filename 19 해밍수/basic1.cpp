/****************************************************
*
* Problem:
*                해밍수
*****************************************************
/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;
int min(int **data, int index,int current_number);
int main(void){
  int numTestcases;
  cin >>  numTestcases;

  for ( int i=0; i<numTestcases; i++){
      int data;
      cin >> data;
      int **hm_number = nullptr;
      hm_number = new int*[data];
      for(int j=0;j<data;j++){
          hm_number[j] = new int[3];
      }
      int index = 0;
      int current_number = 1;
      while(index < data-1){
          hm_number[index][0] = current_number *2;
          hm_number[index][1] = current_number *3;
          hm_number[index][2] = current_number *5;
          current_number = min(hm_number, index, current_number);
          index ++;
      }
      cout << current_number <<endl;

      for( int j =0; j<data; j++){
          delete[] hm_number[j];
      }
      delete hm_number;
  }//end for
  return 0;
}//end main

int min(int **data, int index, int current_number){
    int min = data[index][2];
    for(int i =0;i<=index;i++){
        for(int j =0;j<3; j++){
            if((data[i][j] > current_number) && (data[i][j] <min)){
                min = data[i][j];
            }
        }
    }
    return min;
}
