#include<iostream>
#include<algorithm>
using namespace std;
void setData(char ** data,int width,int height);
void viewData(char ** data,int width,int height);
bool findSpace(char ** data,int width,int height,int*index,int* index1, int* num);
void ExpandSpace(char **data,int index,int index1,int* size);
int main(void){
    int numTestcases;
    cin >> numTestcases;
    for(int i = 0; i<numTestcases;i++){
        int width,height;
        cin >> width;
        cin >> height;
        char **data =nullptr;
        data = new char*[height];
        for(int j=0; j<height;j++){
            data[j] = new char[width];
        }
        setData(data,height,width);
        //viewData(data, height, width);

        int size_of_rooms[100] = {0};
        int number_of_rooms = 0;
        int index(0),index1(0);
        int *a = &number_of_rooms;
        int *b = &index;
        int *c = &index1;

        while(findSpace(data,height,width,b,c,a)){
            int *p = &size_of_rooms[number_of_rooms];
            ExpandSpace(data,index,index1,p);
        }
        sort(size_of_rooms, size_of_rooms+number_of_rooms+1);
        cout <<number_of_rooms;
        cout << endl;

        for(int j = number_of_rooms;j >0;j--){
            cout << size_of_rooms[j]+1 << " ";
        }
        cout <<endl;

        for(int j=0; j<height;j++){
            delete[] data[j];
        }
        delete[] data;
    }
    return 0;
}
void setData(char ** data,int width,int height){
    char c;
    for(int i =0;i<width;i++){
        for(int j=0;j<height;j++){
            cin >> c;
            data[i][j] = c;
        }
    }
}
void viewData(char ** data,int width,int height){
    for(int i =0;i<width;i++){
        for(int j=0;j<height;j++){
            cout <<data[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool findSpace(char ** data,int width,int height,int*index,int* index1, int* num){
    bool result = false;
    for(int i =0;i<width;i++){
        for(int j=0;j<height;j++){
            if(data[i][j] == '.'){
                data[i][j] = 'a';
                *num += 1;
                *index = i;
                *index1 =j;
                result  = true;
                return result;
            }
        }
    }
    return result;
}
void ExpandSpace(char **data,int index,int index1,int* size){
    if(data[index-1][index1] == '.'){
        data[index-1][index1] ='a';
        *size +=1;
        ExpandSpace(data,index-1,index1,size);
    } //down
    if(data[index+1][index1] == '.'){
        data[index+1][index1] ='a';
        *size +=1;
        ExpandSpace(data,index+1,index1,size);
    }//up
    if(data[index][index1-1] == '.'){
        data[index][index1-1] ='a';
        *size +=1;
        ExpandSpace(data,index,index1-1,size);
    }//left
    if(data[index][index1+1] == '.'){
        data[index][index1+1] ='a';
        *size +=1;
        ExpandSpace(data,index,index1+1,size);
    }//right
}
