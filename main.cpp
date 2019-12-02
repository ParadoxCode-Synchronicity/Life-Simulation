#include <bits/stdc++.h>
#include <list>

using namespace std;

class species {
public:
    int vision ,stamina,a1=10,food;
    pair<int,int> coord ;
    species()
    {
        vision = 5;
        stamina = 50;
        coord = make_pair(0,0);
        food = 0;
    }
    species(int v , int s)
    {
        vision = v ;
        stamina = s ;
        cout << vision << stamina ;
    }
};

list <species> skills;
int t=50,x,a,y,c=1;

class environment {
    int population=1,food=400,size=100;
    int location[102][102];

public :
    //int** location = new int* [size+5];
    environment ()
    {
        /*cout << "Enter population and food amount" << endl ;
        cin >> population >> food ;
        cout << "Enter Vision" << endl;
        cin >> vision ;*/
        for(int i=1;i<=population;i++)
        {
            species s;
            skills.push_back(s);
        }
        //for(int i=0;i<size+5;i++)
            //location[i] = new int[size+5];
        day();
    }
   void day();
};

void environment::day()
{
    srand(time(NULL));
    for(int i=0;i<size+2;i++)
    {
        for(int j=0;j<size+2;j++)
            location[i][j]=0;
    }
    while(food--)
    {
        location[rand()%size+1][rand()%size+1]=1;
    }
    /*for(int i=0;i<size+2;i++)
    {
        for(int j=0;j<size+2;j++)
            cout << location[i][j] << " ";
        cout << endl ;
    }*/
    x =1;
    for(list<species>::iterator i = skills.begin();i!=skills.end();i++,x++)
        {
           switch(x)
           {
           case 1 :
                (*i).coord =  make_pair(0,rand()%size+1);
                break;
           case 2 :
                (*i).coord =  make_pair(size+1,rand()%size+1);
                break;
           case 3 :
                (*i).coord =  make_pair(rand()%size+1,0);
                break;
           case 4 :
                (*i).coord =  make_pair(rand()%size+1,size+1);
                break;
           }
           if(x==4)
            {
                x=0;
            }
        }
    /*for(list<species>::iterator i = skills.begin();i!=skills.end();i++)
    {
        cout<<((*i).coord).first << " " << ((*i).coord).second  << " ";
    }*/
    while(t--)
    {
        for(list<species>::iterator i = skills.begin();i!=skills.end();i++)
        {
            cout << endl ;
            x = ((*i).coord).first ;
            y = ((*i).coord).second ;
            cout << x << " " << y << " " ;
            while(true)
            {
            a  = rand()%7;
            if((a+4)%8!=(*i).a1)
            {
            switch(a)
            {
            case 1 :
                if(--y>0)
                {
                    (*i).a1=(a+4)%8;
                    --((*i).coord).second;
                }
                break;
            case 2 :
                if(--y>0&&++x<size+1)
                {
                    (*i).a1=(a+4)%8;
                    ++((*i).coord).first;
                    --((*i).coord).second;
                }
                break;
            case 3 :
                if(++x<size+1)
                {
                    (*i).a1=(a+4)%8;
                    ++((*i).coord).first;
                }
                break ;
            case 4 :
                if(++x<size+1&&++y<size+1)
                {
                    (*i).a1=(a+4)%8;
                    ++((*i).coord).first;
                    ++((*i).coord).second;
                }
                break;
            case 5:
                if(++y<size+1)
                {
                    (*i).a1=(a+4)%8;
                    ++((*i).coord).second;
                }
                break;
            case 6 :
                if(++y<size+1&&--x>0)
                {
                    (*i).a1=(a+4)%8;
                    --((*i).coord).first;
                    ++((*i).coord).second;
                }
                break;
            case 7 :
                if(--x>0)
                {
                    (*i).a1=(a+4)%8;
                    --((*i).coord).first;
                }
                break;
            case 0 :
                if(--y>0&&--x>0)
                {
                    (*i).a1=(a+4)%8;
                    --((*i).coord).first;
                    --((*i).coord).second;
                }
                break;
            }
            if((a+4)%8==(*i).a1)
                break;
            }
            }
        cout << x << " " << y << " ";
        if(location[x][y]==1)
        {
            ++(*i).food ;
            //cout << c++;
            //cout << ++(*i).food << endl;
            location[x][y]=0;
        }
        --(*i).stamina ;
        //if((*i).stamina == 0 && (*i).food == 0)
        //{
            //skills.erase(i);
            //i--;
        // }
        }
    }
    //for(list<species>::iterator i = skills.begin();i!=skills.end();i++)
        //cout << (*i).food << " " ;
}

int main()
{
    environment obj1 ;
    srand(time(NULL));
    return 0 ;
}
