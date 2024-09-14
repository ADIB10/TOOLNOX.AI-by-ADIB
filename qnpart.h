#pragma once
#include<algorithm>
#include<cstdlib>
#include<string>
#include"Name.h"
#include"intstr.h"
string ques,ques1[100],Line,comment,back_up,ans;
int Q,QQ;
float percent,Maxp=0,maxper=0,PP[3]={0},target,counter=0;
using namespace std;

void data_enter()
{
    file.open("database.txt",ios::app);
    {
        if(file.is_open())
        {
            file<<ques<<endl;
        }file.close();
    }
    file.open("databaseans.txt",ios::app);
    {
        if(file.is_open())
        {
            getline(cin,comment);
            file<<comment<<endl;
        }file.close();
    }cout<<"your ans of this question is recoded\n";
}

void data_replace()
{///cout<<target<<endl;
    cout<<"desirable ans>>";
    getline(cin,ans);
    file.open("databaseans.txt");
    {
        if(file.is_open())
            while(getline(file,Line)){
                {counter++;
                    if(counter!=target){back_up=back_up+Line+"\n";}
                    if(counter==target){back_up=back_up+ans+"\n";}
                }
        }file.close();
    }///cout<<counter<<endl;
    counter=0;
    file.open("databaseans.txt",ios::out);
    {
        if(file.is_open())
        {
            file<<back_up;
        }file.close();
    }back_up="";
    cout<<"the ans of the given question is replaced\n";
}
void q_taking(string q)
{Q=0;QQ=0;Maxp=0;maxper=0;target=0;counter=0;
    ques=q;
    C_to_s(ques);
    ques=str;
    for(int i=0;i<ques.size();i++)
    {
       if(ques[i]==' '||i==(ques.size()-1))
       {if(i==(ques.size()-1)){i++;}///to get the last word
           ques1[Q]=ques.substr(QQ,i-QQ);
           Q++;QQ=i;
           if(Q>0){QQ++;}
       }
    }
    file.open("database.txt");
    {
        if(file.is_open())
        {
            while(getline(file,Line))
            {PP[1]=0;PP[2]=0;PP[0]++;
                for(int i=0;i<Line.size();i++)
                {
                    if(Line[i]==' '){PP[2]++;}
                }PP[2]++;
                for(int i=0;i<Q;i++)
                {
                    if(Line.find(ques1[i])!=string::npos)
                        {///cout<<ques1[i]<<endl<<Line<<endl;
                            PP[1]++;
                        }
                }
                percent=(PP[1]/PP[2])*100;
                ///cout<<PP[1]<<" "<<PP[2]<<endl;
                if(PP[1]>Maxp||PP[1]==Maxp&&percent>maxper)
                {
                        Maxp=PP[1];maxper=percent;target=PP[0];
                }
            }
        }file.close();
    }///cout<<target;
    file.open("database.txt");
    {
        if(file.is_open())
        {
            while(getline(file,Line))
            {counter++;

                    if(counter==target){cout<<"your question might be>> "<<Line<<endl;break;}
            }
        }file.close();
    }counter=0;
    file.open("databaseans.txt");
    {
        if(file.is_open())
        {
            while(getline(file,Line))
            {counter++;

                    if(counter==target){cout<<"ans from the current database>> "<<Line<<endl;counter=0;target=0;break;}
            }
        }file.close();
    }
    cout<<"is it the ans your looking for\n";
    getline(cin,comment);
    if(comment.find("no")!=string::npos||comment.find("not")!=string::npos||comment.find("nope")!=string::npos)
    {
        cout<<"do you want to REPLACE or ADD>>";
        getline(cin,comment);
        if(comment.find("add")!=string::npos){data_enter();}
        if(comment.find("replace")!=string::npos){data_replace();}
    comment="";}
    else if(comment.find("yes")!=string::npos){cout<<"it is my pleasure to help you whit your question...\n";comment="";}
    PP[1]=0;PP[2]=0;PP[0]=0;Maxp=0;maxper=0;
}
