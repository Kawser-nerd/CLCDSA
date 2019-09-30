using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        new Magatro().Solve();
    }
}

class Magatro
{

    private int N;
    private int cnt = 0;
    string[] x;
    public void Solve()
    {
        N = int.Parse(Console.ReadLine());
        x = new string[N];
        for (int i = 0; i < N; i++)
        {
            x[i] = Console.ReadLine();
        }
        
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(x[i][j] == 'x')
                {
                    cnt++;
                }
                if(x[i][j] == 'o')
                {
                    if (i == 0 || x[i - 1][j] != 'o')
                    {
                        cnt++;
                    }
                }
            }
        }
        Console.WriteLine(cnt);
    }
}