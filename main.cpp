#include <iostream>
#include"Name.h"
#include<map>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cctype>
#include<ctime>
#include"qnpart.h"
#include"customchat.h"
///#include<chrono>fro small animation experiment [not tried yet]
///#include<thread>
using namespace std;

string* check;///pointer
int ran_c;

int rand_num;
void rnd(int R)///random number R represents maximum range
{while(ran_c==rand_num){srand(time(0));
rand_num=(rand()%R);}ran_c=rand_num;}

string hi[3]={"hello","hi","whats up"};
string rhi[2]={"hi there","hello"};
string r_ann_hi[3]={"give me some work,please","please,enough of this hi/hello","pleas stop saying hello",};
string greatings[3]={"how are you","how is your day going","what do you want me to do today"};
string got_it[4]={"ok ok","ok i understand","ok","ok i got it"};
string rep_gor_it[3]={"ok good now command me","your AI is waiting to help you","ok give me some work to do"};
string greet_rep[5]={"good","fine","nice","well","ok"};
string greet2[3]={"its good to here that","oh thats very nice","i hope to see that reply every day"};
string greet3[3]={"i am so sorry to hear that","hai chere up bad thing do happen sometime","bad thing are temporary though"};
int annoy=-2,C=0,CC=0,NC=0,hi_check=0,good=0,bad=0;
string command[10],comnd,reply;

int main()
{

    while(int J=1)
    {C=0;CC=0;
    comnd=comment;///commend direct from the qn heder file
    if(comment.size()>0){reply="";}
        SetConsoleTextAttribute(hh,FOREGROUND_RED|FOREGROUND_INTENSITY);
        if(comment.size()<=0||comnd.size()<=0){getline(cin,comnd);}comment="";
        if(comnd[comnd.size()-1]!='.'){comnd=comnd+'.';}
        for(int i=0;i<=comnd.size();i++)///to split command in dots
        {
            if(comnd[i]=='.'&&comnd[i]!=' ')
            {
                command[C]=comnd.substr(CC,i-CC);
                CC=i;C++;
                if(C>0){CC++;}
            }
        }comnd="";
        for(int I=0;I<C;I++)///initial C=0 and for the fast array C will be 1 where it needs to be 0
        {
            //cout<<C<<command[I]<<endl;
            string S=command[I];
        for(int i=0;i<=S.size();i++){if(S[i]>=65&&S[i]<=90){S[i]=S[i]+32;}}
        command[I]=S;
        //cout<<S<<command[I].find("add");
        for(int i=0;i<3;i++)
            {
            if(command[I].find(hi[i])!=string::npos)
                {if(annoy==-2){rnd(2);reply=rhi[rand_num];rnd(3);reply=reply+"."+greatings[rand_num];hi_check=rand_num;}///random reply
                if(annoy==-1){reply="hello again";}
                if(annoy>=0){rnd(3);reply=r_ann_hi[rand_num];hi_check=-1;}
                annoy++;break;}
            }
    if(bad==1)
    {if(command[I].find("no")!=string::npos||command[I].find("fine")!=string::npos||command[I].find("good")!=string::npos)
        {
            reply="stay strong,if you ever need me i am always here.";bad=2;
        }
    }
    if(bad==1)
        {
            reply="i am not so high end enough to understand it.but i hope you feel better after sharing.";
        }
    if(command[I].find("bad")!=string::npos||command[I].find("not")!=string::npos&&good==0)///bads are here for not to collaps with oter and less data management
        {
            rnd(3);reply=greet3[rand_num]+".do you want me to listen";
            bad=1;hi_check=-1;
        }
    if(bad==0)
        {for(int i=0;i<5;i++){if(command[I].find(greet_rep[i])!=string::npos&&hi_check>=0)
        {
            ///if(command[I].find("day")!=string::npos&&hi_check==1){rnd(3);reply=greet2[rand_num];}
            if(command[I].find("day")!=string::npos&&hi_check==0){reply="i didn't ask that though good to know";}
            else if(command[I].find("i am fine")!=string::npos&&hi_check==1){reply="i didn't ask that though good to know";}
            else if(hi_check==1||hi_check==0){rnd(3);reply=greet2[rand_num];}
            hi_check=-1;
            good=1;break;
        }}}
bad=0;

    if(command[I].find("add")!=string::npos)///string::nops means not found in string
        {///cout<<"Yes";
            if(command[I].find("file")!=string::npos)
            {reply="true";
                cout<<"taking you to name enter.....\nENTER NAME=>";
                name_enter();
            }
        }

    if(command[I].find("search")!=string::npos||command[I].find("find")!=string::npos||command[I].find("look for")!=string::npos)
        {
            if(command[I].find("id")!=string::npos){id_search(command[I]);reply="true";}
            else if(command[I].find("file type")!=string::npos||command[I].find("type")!=string::npos||command[I].find("data type")!=string::npos)
            {
                data_type_search(command[I]);reply="true";
            }
            else{search_name(command[I]);reply="true";}
        }
        check=find(got_it,got_it+4,command[I]);
    if(check!=got_it+4&&hi_check==-1)
        {
            rnd(3);reply=rep_gor_it[rand_num];
        }
    if(command[I].find("what")!=string::npos||command[I][command[I].size()-1]=='?')
    {reply="true";
    if(command[I][command[I].size()-1]=='?'){command[I][command[I].size()-1]=' ';}
        q_taking(command[I]);
    }
else
    {
        chat(command[I]);
    }
if(reply!="true"&&reply.size()>0){cout<<reply<<endl;reply="";}///main reply///reply true means there is already an reply form the function



        }
    }
   /// getline(cin,comnd);

    return 0;
}
