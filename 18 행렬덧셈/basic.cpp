/****************************************************
*
* Problem:
*               행렬의 덧셈
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
using namespace std;
void setData(int **data,int row ,int column);
void viewData(int **data,int row ,int column);
void sumData(int **data, int **data1,int row,int column);
int main(void){
  int numTestcases;
  cin >>  numTestcases;
  for ( int i=0; i<numTestcases; i++){
      int row, column;
      cin >> row;
      cin >> column;

      int ** data = nullptr;
      data = new int*[row];
      for(int j =0; j<row;j++) {
        data[j] = new int[column];
      }
      int ** data1 = nullptr;
      data1 = new int*[row];
      for(int j =0; j<row;j++) {
        data1[j] = new int[column];
      }
      setData(data,row,column);
      setData(data1,row, column);
      sumData(data,data1,row,column);
      viewData(data,row,column);

      for(int j =0; j<row;j++) {
        delete[] data[j];
      }
      delete []data;
      for(int j =0; j<row;j++) {
        delete[] data1[j];
      }
      delete []data1;

  }// end for
  return 0;
}// end main
void sumData(int **data, int **data1,int row,int column){
    for(int i =0; i<row;i++)
      for(int j=0;j<column;j++){
          data[i][j] += data1[i][j];
      }
}
void setData(int **data,int row ,int column){
    for(int i =0; i<row;i++)
      for(int j=0;j<column;j++){
          cin >> data[i][j];
      }
}
void viewData(int **data,int row ,int column){
    for(int i =0; i<row;i++){
      for(int j=0;j<column;j++){
          cout << data[i][j]<<" ";
      }
      cout << endl;
  }
  //cout <<"end viewData"<< endl;
}
