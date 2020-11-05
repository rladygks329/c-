#include "MyHammingCode.h"
#include<iostream>
using namespace std;
// constructors
MyHammingCode::MyHammingCode ():value(0)
{
}
MyHammingCode::MyHammingCode (unsigned int val):value(val)
{
}
// utility functions
unsigned int MyHammingCode::getEncodedValue ()
{
    encodedValue = 0;
    encodedValue |= copyBits(value, 0,  1,  2);
    encodedValue |= copyBits(value, 1,  3,  4);
    encodedValue |= copyBits(value, 4,  7,  8);
    encodedValue |= copyBits(value, 11, 15, 16);

    encodedValue = setParityBit(encodedValue, 1);
    encodedValue = setParityBit(encodedValue, 2);
    encodedValue = setParityBit(encodedValue, 4);
    encodedValue = setParityBit(encodedValue, 8);
    encodedValue = setParityBit(encodedValue, 16);
    return encodedValue;
}
unsigned int MyHammingCode::getDecodedValue ()
{
    int errorPos;
    decodedValue = 0;

    errorPos = checkParityBit(value);
    if (errorPos > 0)
        value = negateBit(value, errorPos-1);
    decodedValue |= copyBits(value, 2, 1, 0);
    decodedValue |= copyBits(value, 4, 3, 1);
    decodedValue |= copyBits(value, 8, 7, 4);
    decodedValue |= copyBits(value, 16, 15, 11);
    return decodedValue;
}

/*정수n의from-번째비트부터num개의비트를
* 다른정수num의to-번째비트로복사하는함수
*/
unsigned int MyHammingCode::copyBits(unsigned int n, int from, int num, int to)
{
    unsigned int mask = 0;
    unsigned int code = 0;

    /* num 비트만큼의mask 를만듬*/
    do{
        mask <<= 1;
        mask |= 0x01;
    } while (--num);

    /* n의 from -번째비트부터 num개의 비트를 골라내어 복사함*/
    n >>= from;
    n &= mask;
    code |= n;
    code <<= to;
    return code;
}
/* 패리티비트를만드는함수*/
unsigned int MyHammingCode::setParityBit(unsigned int n, int pos)
{
    unsigned int mask[5] = { 0x55555554, 0x66666664, 0x74747470,0x7F807F00, 0x7FFF0000 };
    int count;
    unsigned int checkBits;
    switch (pos){
        case 1:
            checkBits = n & mask[0];
            break;
        case 2:
            checkBits = n & mask[1];
            break;
        case 4:
            checkBits = n & mask[2];
            break;
        case 8:
            checkBits = n & mask[3];
            break;
        case 16:
            checkBits = n & mask[4];
            break;
        }
        count = hammingWeight(checkBits);
        if (count % 2){
            n = setBit(n, pos-1);
        }
        return n;
}
/** 패리티비트를검사하는함수
* 단, 에러가발생하는경우에는한비트에서만오류가발생한것을가정하여,
* 에러가발생한비트의위치를찾아서리턴해준다.*/
unsigned int MyHammingCode::checkParityBit(unsigned int n)
{
    unsigned int result = 0;
    int p[5] = {0,0,0,0,0};
    int count = 0;
    for(int i = 1; i<32; i*=2){
        for(int j=0;j<i;j++){
            int num = 0;
            while(i+j+num <32){
                    p[count] += checkBit(n, i+j+num-1);
                    num += 2*i;
            }
        }
        count += 1;
    }
    for(int i=0;i<5;i++){
        if(p[i]%2 == 1) p[i] = 1;
        else p[i] = 0;
        cout <<p[i] <<" ";
    }
    result = p[0]+p[1]*2+p[2]*4+p[3]*8+p[4]*16;
    return result;
}
/* 정수에서비트가1인자리수의개수를계산하는함수*/
int MyHammingCode::hammingWeight(unsigned int n)
{
    int count = 0;
    unsigned int mask = 1;
    while( n != 0){
        if(n & mask)
            count ++;
        n >>= 1;
        //cout << n <<endl;
    }
    return count;
}
/* 정수의pos 자리수의비트를1로만드는함수*/
unsigned int MyHammingCode::setBit(unsigned int n, int pos)
{
    unsigned int mask = 0x01;
    mask <<= pos;
    n |= mask;
    return n;
}
/* 정수의pos 자리수의비트를0으로만드는함수*/
unsigned int MyHammingCode::clearBit(unsigned int n, int pos)
{
    unsigned int mask = 0;
    n &=  ~(mask << pos);
    return n;
}
/* 정수의pos 자리수가0인지1인지를확인하는함수*/
int MyHammingCode::checkBit(unsigned int n, int pos)
{
    unsigned int mask = 1;
    mask <<= pos;
    n &= (mask);
    //cout << "n = " <<n <<endl;
    n = ((n > 0) ? 1 : 0);
    return n;
}
/* 정수의pos 자리수를반대로만드는함수*/
unsigned int MyHammingCode::negateBit(unsigned int n, int pos)
{
    if(checkBit(n,pos)){
        n = clearBit(n,pos);
    }
    else{
        n = setBit(n,pos);
    }
    return n;
}
/* Exclusive OR 를계산하는함수*/
unsigned int MyHammingCode::_xor (unsigned int x, unsigned int y)
{
    return !x ^ !y;
}
