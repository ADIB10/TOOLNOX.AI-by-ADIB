#pragma once
#include"qnpart.h"

using namespace std;

string grammer="am is are was were have been had had";
string tempc,mchat,line,rep_ch;

int SS=0,S,p[3];

void chat_reply()
{counter=0;
    file.open("chatrep.txt");
    {
        if(file.is_open())
        {
            while(getline(file,line))
            {counter++;
                if(counter==target){cout<<line<<endl;target=0;rep_ch="true";break;}
            }
        }file.close();
    }
}
void chat(string chats)
{Maxp=0;maxper=0;target=0;counter=0;SS=0;p[2]=0;
    file.open("chat.txt",ios::app);{}file.close();
    file.open("chatrep.txt",ios::app);{}file.close();

    ///cout<<chats;
    file.open("chat.txt");
    {
        if(file.is_open())
        {
            while(getline(file,line))
            {p[2]++;///cout<<line;
                for(int i=0;i<line.size();i++)
                {
                    if(line[i]==' ')
                    {p[1]++;
                    }
                }p[1]++;

                for(int i=0;i<chats.size();i++)
                {
                    if(chats[i]==' '||i==(chats.size()-1))
                    {
                    if(SS!=0){SS++;}
                    if(i==(chats.size()-1)){i++;}
                        tempc=chats.substr(SS,i-SS);
                        if(grammer.find(tempc)==string::npos)
                        {///cout<<line;
                            if(line.find(tempc)!=string::npos){p[0]++;}
                        }
                        SS=i;
                    }
                }percent=p[0]*100/p[1];
                ///cout<<percent<<p[0]<<p[1]<<p[2]<<endl;
                if(maxper<percent&&Maxp<=p[0]){target=p[2];maxper=percent;Maxp=p[0];}
                SS=0;p[0]=0;p[1]=0;
            }
        }file.close();
    }///cout<<target;

    chat_reply();
    if(rep_ch!="true")
    {
        cout<<"tell me how should i response>>";
        getline(cin,mchat);
        file.open("chatrep.txt",ios::app);
        {
            if(file.is_open())
            {
                file<<mchat<<endl;
            }file.close();
        }
    file.open("chat.txt",ios::app);
        {
            if(file.is_open())
            {
                file<<chats<<endl;
            }file.close();
        }
    }
    rep_ch="";
}
