/****************************************************
*
* Problem:
*                방의 크기 구하기
*****************************************************

/****************************************************
*
* 국민대학교 소프트웨어융합대학 소프트웨어 학부 2학년
*                                                                                              20163097 김요한
*****************************************************/
#include<iostream>
#include<algorithm>
using namespace std;
void setData(int **data,int row ,int column);
void viewData(int **data,int row ,int column);
bool findSpace(int**data,int row,int column, int* roomNumber);
void RecurseExpand(int **data, int i, int j, int* roomNumber);
int main(void){
  int numTestcases;
  cin >>  numTestcases;
  for ( int i=0; i<numTestcases; i++){
      int row,column;
      int roomNumber = 1;
      cin >> column;
      cin >> row;

      int **data = nullptr;
      data = new int*[row];
      for(int j =0;j<row;j++){
          data[j] = new int[column];
      }
      for(int j=0;j<row;j++){
          for(int k=0;k<column;k++){
              data[j][k] = 0;
          }
      }
      //data in
      setData(data,row,column);
      //find space and Expand
      while(findSpace(data,row,column,&roomNumber)){
          findSpace(data,row,column,&roomNumber);
      }
      roomNumber --;
      //viewData(data, row, column);

      //make size[] and reset 0
      int *size = nullptr;
      size = new int[roomNumber];
       for(int x =0;x<roomNumber;x++){
           size[x] = 0;
       }
       //find roomsize
      for(int x =0;x<roomNumber;x++){
          for(int y =0;y<row;y++){
              for(int z =0;z<column;z++){
                  if(data[y][z]== x+1) size[x] +=1;
              }
          }
      }
      //sort and out
      sort(size, size+roomNumber);
      cout << roomNumber<<endl;
      for(int x =roomNumber-1; x >-1;x--){
          cout << size[x] << " ";
      }
      cout <<endl;
      for(int j =0; j<row ;j++) {
        delete[] data[j];
      }
      delete []data;
      delete []size;
  }
  return 0;
}
void setData(int **data,int row ,int column){
    char character;
    for(int i =0; i<row;i++)
      for(int j=0;j<column;j++){
          cin >> character;
          data[i][j] = (int)character;
      }
}
void viewData(int **data,int row ,int column){
    for(int i =0; i<row;i++){
      for(int j=0;j<column;j++){
          cout << data[i][j]<<" ";
      }
      cout << endl;
  }
}
bool findSpace(int**data,int row,int column, int* roomNumber){
    bool result = false;
    for(int i =0; i<row;i++){
      for(int j=0;j<column;j++){
          if(data[i][j] == 46) {
              data[i][j] = *roomNumber;
              RecurseExpand(data ,i,j,roomNumber);
              *roomNumber += 1;
              result = true;
              return result;
          }
      }
  }
  return result;
}
void RecurseExpand(int **data, int i, int j, int* roomNumber){
    if( (data[i][j] == *roomNumber) &&(data[i-1][j] == 46)) {
        data[i-1][j] = *roomNumber;
        RecurseExpand(data,i-1,j,roomNumber);
    }//down
    if( (data[i][j] == *roomNumber) &&(data[i+1][j] == 46)) {
        data[i+1][j] = *roomNumber;
        RecurseExpand(data,i+1,j,roomNumber);
    }//up
    if( (data[i][j] == *roomNumber) &&(data[i][j+1] == 46)) {
        data[i][j+1] = *roomNumber;
        RecurseExpand(data,i,j+1,roomNumber);
    }//right
    if( (data[i][j] == *roomNumber) &&(data[i][j-1] == 46)) {
        data[i][j-1] = *roomNumber;
        RecurseExpand(data,i,j-1,roomNumber);
    }//left
}
