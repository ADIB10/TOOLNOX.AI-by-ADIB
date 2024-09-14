#pragma once
#include<string>
#include<fstream>
#include<bits/stdc++.h>
#include"intstr.h"
using namespace std;

string nam,nam1,s;
fstream file;
int id,n=0,detect=0,serial=0;

fstream& GotoLine(fstream& file, unsigned int num){
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}
void name_enter()
{
    file.open("name.txt");
    {
        if(file.is_open())
        {
            while(getline(file,nam1))
            {
                nam=nam1;
            }
            if(nam.size()==0){id=100;}
            else{id=str_int(nam.substr(0,3))+1;}
        }file.close();
    }
    int_str(id);
    s=str;
    cin>>nam;
    nam=s+"#"+nam;
    n=nam.find(".")+1;
    if(n==0){nam=nam+".folder";cout<<"AUTOMATICALLY SAVED AS FOLDER...\n";}
    file.open("name.txt", ios::app);
    {

        if(file.is_open())
        {
            file<<nam<<endl;
        }
        file.close();
    }

}
/**void name_search()
{
    cin>>nam;
    file.open("name.txt");
    {
        if(file.is_open())
        {
            while(getline(file,nam1))//reading line by line till end
            {

                ///cout<<n<<nam1.substr(4,n-1-4)<<endl<<nam1.substr(4,nam1.size()-4);
                n=nam1.find(".")+1;// find . position
                if(nam==nam1.substr(4,nam1.size()-4)||nam==nam1.substr(4,n-1-4))
                {detect=1;

                    cout<<"NAME:"<<nam1.substr(4,nam1.size()-4)<<endl;
                    cout<<"SEARCHING ID:"<<nam1.substr(0,3)<<endl<<n<<endl;
                    cout<<"DATA TYPE:"<<nam1.substr(n,nam1.size()-n)<<endl;
                    break;
                }
            }

        }file.close();

    }if(detect==0){cout<<"INFORMATIONT ERROR\n";}
}**/

void search_name(string NAM)
{
    file.open("name.txt");
    {
        if(file.is_open())
        {
            while(getline(file,nam1))//reading line by line till end
            {
                n=nam1.find(".")+1;// find . position
                if(NAM.find(nam1.substr(4,n-1-4))!=string::npos)
                {
                    {detect=1;
                    cout<<"NAME:"<<nam1.substr(4,nam1.size()-4)<<endl;
                    cout<<"SEARCHING ID:"<<nam1.substr(0,3)<<endl;
                    cout<<"DATA TYPE:"<<nam1.substr(n,nam1.size()-n)<<endl;
                    break;
                }
            }

        }file.close();

    }
    }if(detect==0){cout<<"INFORMATIONT ERROR\n";}detect=0;
}
void data_type_search(string NAM)
{
    char sing=' ';
    for(int i=1;i<=NAM.size();i++)
    {
        if(NAM[i]!='a'){if(NAM[i+1]==' '||NAM[i+1]=='\0'){if(NAM[i-1]==' '||NAM[i-1]=='.'){sing=NAM[i];}}}
    }//cout<<sing;
    file.open("name.txt");
    {
        if(file.is_open())
        {
    while(getline(file,nam1))
        {
            n=nam1.find(".")+1;
            ///cout<<NAM;
            ///cout<<nam1.substr(n,nam1.size()-n)<<endl;
            if(sing==' ')
            {if(NAM.find(nam1.substr(n,nam1.size()-n))!=string::npos&&nam1.substr(n,nam1.size()-n).size()>1)
            {serial++;
                cout<<serial<<":"<<nam1.substr(4,nam1.size()-4)<<endl;
            }}
            else
            {
                if(nam1[nam1.size()-1]==sing&&nam1[nam1.size()-2]=='.')
                {serial++;
                    cout<<serial<<":"<<nam1.substr(4,nam1.size()-4)<<endl;
                }
            }
        }
}file.close();
}if(serial==0){cout<<"INFORMATIONT ERROR\n";}serial=0;
}
void id_search(string NAM)
{
    file.open("name.txt");
    {
        if(file.is_open())
        {
            while(getline(file,nam1))//reading line by line till end
            {
                // find . position
                if(NAM.find(nam1.substr(0,3))!=string::npos)
                {
                    {detect=1;
                    cout<<"NAME:"<<nam1.substr(4,nam1.size()-4)<<endl;
                    cout<<"SEARCHING ID:"<<nam1.substr(0,3)<<endl;
                    cout<<"DATA TYPE:"<<nam1.substr(n,nam1.size()-n)<<endl;
                    break;
                }
            }

        }file.close();

    }
    }if(detect==0){cout<<"INFORMATIONT ERROR\n";}detect=0;
}
