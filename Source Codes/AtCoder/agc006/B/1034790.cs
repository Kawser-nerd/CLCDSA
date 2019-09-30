using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Text;
using System.Text.RegularExpressions;
using System.Linq;

class Magatro
{

    static void Main()
    {
        int N;
        int x;
        string[] s = Console.ReadLine().Split(' ');
        N = int.Parse(s[0]);
        x = int.Parse(s[1]);
        int l = N * 2 - 1;
        if (x == 1 || x == l)
        {
            Console.WriteLine("No");
            return;
        }
        Console.WriteLine("Yes");
        int[] ans = new int[l];
   
        if (x==2)
        {
            ans[N - 1] = 2;
            ans[N - 2] = 1;
            for(int i = 0; i < l; i++)
            {
                if (i < N - 2)
                {
                    ans[i] = i + 3;
                }
                if (i > N - 1)
                {
                    ans[i] = i + 1;
                }
            }

        }
        else
        {
            ans[N - 1] = x;
            ans[N - 2] = x + 1;
            ans[N - 3] = x - 1;
            ans[N] = x - 2;
            for(int i = 0; i < l; i++)
            {
                if ((i < N - 3 && i < x - 3) || (i > N && i > x))
                {
                    ans[i] = i+1;
                }
                if (i < N - 3 && i >= x - 3)
                {
                    ans[i] = i + 5;
                }
                if (i > N && i <= x)
                {
                    ans[i] = i - 3;
                }
            }
            
        }
        StringBuilder ss = new StringBuilder();

   for(int i = 0; i < l; i++)
        {
            ss.Append(ans[i] + "\n");
        }
        Console.Write(ss.ToString());
    }


}