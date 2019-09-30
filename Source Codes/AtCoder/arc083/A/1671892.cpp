#include<iostream>
#include<vector>

using namespace std;

int a,b,c,d,e,f;

bool water[3010];
bool sugar[3010];

double getNoudo(int w,int s)
{
    return 100.0*s/(w+s);
}

int main(void)
{
    cin>>a>>b>>c>>d>>e>>f;
    for(int i = 0;i < 100;i++)
    {
        for(int j = 0;j < 100;j++)
        {
            int x = 100*a*i+100*b*j;
            if(x > f)
                continue;
            water[x] = true;
        }
    }

    for(int i = 0;i < 100;i++)
    {
        for(int j = 0;j < 100;j++)
        {
            int y = c*i+d*j;
            if(y > f)
                continue;
            sugar[y] = true;
        }
    }

    double mc = 0.0;
    int mw = a*100,ms = 0;
    for(int w = 100;w < 3000;w+= 100) {
        for(int s = 0;s < 3000 - w;s++) {
            if(water[w] == false or sugar[s] == false)
                continue;
            if(w+s > f)
                break;
            if(e*(w/100) < s)
                break;

            double temp = getNoudo(w,s);
            if(temp > mc)
            {
                mc = temp;
                mw = w;
                ms = s;
            }
        }
    }

    cout<<mw+ms<<" "<<ms<<endl;

    return 0;
}