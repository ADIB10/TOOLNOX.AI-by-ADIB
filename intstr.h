#pragma once
#include<vector>
#include<string>
#include<windows.h>
#include"intstr.h"

using namespace std;
HANDLE hh=GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(int X,int Y)
{
    COORD coord={X,Y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int OO,non=1,cint=0,value;
string str;
char OOO[1];
converter(int OO)
{

    if(OO==1){str=str+"1";}
    if(OO==2){str=str+"2";}
    if(OO==3){str=str+"3";}
    if(OO==4){str=str+"4";}
    if(OO==5){str=str+"5";}
    if(OO==6){str=str+"6";}
    if(OO==7){str=str+"7";}
    if(OO==8){str=str+"8";}
    if(OO==9){str=str+"9";}
    if(OO<1){str=str+"0";}
}
int_str(int value)
{
    int jjj=0,OO=0;
    str="";if(value<0){str='-';value=value*(-1);}if(value==0){str="0";}
    if(value!=0)
    {for(int i=100000000; i>0; i=i/10)
    {
        OO = value / i;
        if(OO>=1){jjj=1;}
        if(OO>=0&&jjj==1)
        {
            //cout<<OO<<endl;
            converter(OO);
            value = value - OO*i;
        }
    }
}

}
sconvert(char OOO[1])
{
    if(OOO[1]=='1'){cint = cint+(non*1);}
    if(OOO[1]=='2'){cint = cint+(non*2);}
    if(OOO[1]=='3'){cint = cint+(non*3);}
    if(OOO[1]=='4'){cint = cint+(non*4);}
    if(OOO[1]=='5'){cint = cint+(non*5);}
    if(OOO[1]=='6'){cint = cint+(non*6);}
    if(OOO[1]=='7'){cint = cint+(non*7);}
    if(OOO[1]=='8'){cint = cint+(non*8);}
    if(OOO[1]=='9'){cint = cint+(non*9);}
}
str_int(string Value)
{
    non=1;
    cint=0;
    int vsi=Value.size();
    for(int i=1;i<=vsi;i++)
    {
        if(vsi<i){break;}
        if(vsi>=i)
        {OOO[1]=Value[vsi-i];
        sconvert(OOO);
        non=non*10;
        ///cout<<'N'<<non;
        }
    }
    if(Value[0]=='-')
    {
        cint=cint*(-1);
    }
    ///cout<<'V'<<Value<<endl<<'C'<<cint<<endl;
    return cint;
    Value="";vsi=0;
}

C_to_s(string value)
{
    str="";
    for(int i=0;i<value.size();i++)
    {
        if(value[i]>=65&&value[i]<=90){value[i]=value[i]+32;}
    }str=value;
}



