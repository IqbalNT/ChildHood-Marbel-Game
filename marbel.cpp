 #include<iostream>
#include<conio.h>
#include<cstdio>
#include<windows.h>

using namespace std;
bool gamelost;
class marbel
{
public:

//bool gamelost;
    const int width=20;
    const int height=20;
    int x,y,p,q,marbelx,marbely,marbelp,marbelq,marbelr,marbels,marbela,marbelb,marbelc,marbeld,score=0;
    enum target {STOP=0,LEFT,RIGHT,TOP};
    target tar;

    void inti()
    {
        gamelost=false;
        tar=STOP;
        // p=(width/2)+7;
        //q=(height/2)+7;
        x=(width/2);
        y=(height/2)+7;
        marbelx=rand() % 15;
        marbely=rand() % 15;
        marbelp= rand() % 15;
        marbelq=rand() % 15;
        marbelr=rand() % 15;
        marbels=rand() % 15;
        marbela=rand() % 15;
        marbelb=rand() % 15;
        marbelc=rand() % 15;
        marbeld=rand() % 15;

    }
    void screen()
    {
        system("cls");
        //cout << endl;
        cout  << " \t";
        for(int i=0; i<width+5; i++)
            cout  << "*";
        cout << endl;
        for(int i=0,s=0,u=0,a=0,b=0; i<height; i++,s++,u++,a++,b++)
        {
            //int f=1,g=1;
            for(int j=0,t=0,v=0,c=0,d=0; j<width; j++,t++,v++,c++,d++)
            {
                //z:
                if(j==0)
                    cout << "\t*";
                if(i==y && j==x)
                    cout <<"@";
                else if(i== marbely && j==marbelx)
                {
                    cout << "M";
                    //cout <<"M";
                }
                else if(s== marbelq && t==marbelp)
                {
                    cout << "M";
                    //cout <<"M";
                }
                else if(a== marbelb && c==marbela)
                {
                    cout << "M";
                    //cout <<"M";
                }
                else if(b== marbeld && d==marbelc)
                {
                    cout << "M";
                    //cout <<"M";
                }
                 else if(u== marbels && v==marbelr)
                {
                    cout << "N";
                    //cout <<"M";
                }

                else
                    cout << " ";
                if(j==width-1)
                {
                    cout << "\t*";
                }
            }
            cout << endl;
        }
        cout  << "\t";
        for(int i=0; i<width+5; i++)
            cout << "*";
        cout << endl;

    }
    void put()
    {
        if(_kbhit())
        {
            switch(_getch())
            {
            case '1' :
            {
                tar = LEFT;
                break;
            }

            case '3' :
                tar=RIGHT;
                break;
            case'5' :
                tar=TOP;
                break;
            case'a' :
            {

                gamelost=true;
                break;
            }

            }
        }
    }
    void throwh()
    {
        switch(tar)
        {

        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case TOP:
            y--;
            break;

        default :
            break;
        }
        if(x==marbelx && y==marbely || x==marbelp && y==marbelq || x==marbela && y==marbelb || x==marbelc && y==marbeld  )
        {
            score=score+2;
            marbelx=rand() % 15;
            marbely=rand() % 15;
            marbelp= rand() % 15;
            marbelq=rand() % 15;
            marbela=rand() % 15;
            marbelb=rand() % 15;
            marbelc=rand() % 15;
            marbeld=rand() % 15;
            marbelr=rand() % 15;
            marbels=rand() % 15;
            //int i=0,j=0;
            inti();


        }
        else if(x==marbelr && y==marbels)
        {
             score=score-2;
            marbelx=rand() % 15;
            marbely=rand() % 15;
            marbelp= rand() % 15;
            marbelq=rand() % 15;
            marbela=rand() % 15;
            marbelb=rand() % 15;
            marbelc=rand() % 15;
            marbeld=rand() % 15;
            marbelr=rand() % 15;
            marbels=rand() % 15;
            //int i=0,j=0;
            inti();
        }
        cout <<"SCORE :" <<score<<endl;
        cout <<"Press a for Exit "<<endl;


    }
};
int main()
{
    marbel m;
    int choice=0;
    while(choice!=3)
    {
    cout <<"\t\tEnter the option from below :"<<endl;
    cout <<"\t\t\t1.Play "<<endl;
    cout <<"\t\t\t2.Help "<<endl;
    cout <<"\t\t\t3.Exit "<<endl;
    cin >> choice;
    switch(choice)
    {
    case 1 :
        m.inti();
        //screen();
        while(!gamelost)
        {
            m.screen();
            m.put();
            m.throwh();
            Sleep(100);
            Sleep(100);
        }
        break;
    case 2 :
        cout <<"press 1 for left "<<endl;
        cout <<"press 3 for right "<<endl;
        cout <<"press 5 for up "<<endl;
        cout <<"press 3 for Exit "<<endl;
        break;
    case 3:
        break;

    }

    }
    return 0;
}
