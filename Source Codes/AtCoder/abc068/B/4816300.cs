using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using static System.Console;
using static System.Math;


namespace AtCodeeeer
{
    class AtCOOOOOOOOOOOder
    {
        static void Main(string[] args)
        {
            int N = int.Parse(ReadLine());
            int ans = 0;int Ans = 1;

            for (int i = 1; i <= N; i++)
            {
                int a = i;
                int cnt = 0;
                while (true)
                {
                    if (a % 2 == 0)
                    {
                        a /= 2;
                        cnt++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (cnt>ans)
                {
                    ans = cnt;
                    Ans = i;
                }
            }
            WriteLine(Ans);
        }
    }
}