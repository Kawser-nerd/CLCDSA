using System;
using System.Linq;
using System.Collections;
using System.Collections.Generic;

class Program
{
    static long F(long n, long N)
    {
        if (n > N)
            return 0;
        else
        {
            string s = n.ToString();
            uint r = 0;
            for(int i = 0; i < s.Length; i++)
            {
                if (s[i] == '7')
                    r |= 1;
                if (s[i] == '5')
                    r |= 2;
                if (s[i] == '3')
                    r |= 4;
            }
            return F(10 * n + 7, N) + F(10 * n + 5, N) + F(10 * n + 3, N) + (r == 7 ? 1 : 0);
        }
    }

    public static void Main()
    {
        long N = long.Parse(Console.ReadLine());
        Console.WriteLine(F(0,N));
    }
}