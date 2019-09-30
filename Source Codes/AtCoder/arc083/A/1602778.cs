using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    private int A,B,C,D,E,F;
    private void Scan()
    {
        var l=Console.ReadLine().Split(' ');
        A=int.Parse(l[0])*100;
        B=int.Parse(l[1])*100;
        C=int.Parse(l[2]);
        D=int.Parse(l[3]);
        E=int.Parse(l[4]);
        F=int.Parse(l[5]);
    }
    
    
    
    public void Solve()
    {
        Scan();
        var water=new bool[F+1];
        water[0]=true;
        var sugar=new bool[F+1];
        sugar[0]=true;
        for(int i=0;i<=F;i++)
        {
            if(water[i])
            {
                if(i+A<=F)
                {
                    water[i+A]=true;
                }
                if(i+B<=F)
                {
                    water[i+B]=true;
                }
            }
            if(sugar[i])
            {
                if(i+C<=F)
                {
                    sugar[i+C]=true;
                }
                if(i+D<=F)
                {
                    sugar[i+D]=true;
                }
            }
        }
        double max=-1;
        int ansA=-1,ansB=-1;
        double maxN=(double)E/(100+E);
        for(int i=A;i<=F;i++)
        {
            if(!water[i])continue;
            for(int j=F-i;j>=0;j--)
            {
                if(sugar[j])
                {
                    double n=(double)j/(j+i);
                    if(n>maxN)continue;
                    if(max<n)
                    {
                        ansA=j+i;
                        ansB=j;
                        max=n;
                    }
                }
            }
        }
        Console.WriteLine($"{ansA} {ansB}");
    } 
    
    static void Main()
    {
        new Program().Solve();
    }
}