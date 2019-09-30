using System;
using System.Collections.Generic;

class Myon
{
    int input()
    {
        return int.Parse(Console.ReadLine());
    }

    int[] inputarray()
    {
        string[] s = Console.ReadLine().Split(' ');
        int[] ret = new int[s.Length];
        for (int i = 0; i < s.Length; i++) ret[i] = int.Parse(s[i]);
        return ret;
    }

    Myon() { }
    public static void Main()
    {
        new Myon().calc();
    }

    void calc()
    {
        int lll;
        int loopmax = input();
        for (lll = 1; lll <= loopmax; lll++)
        {
            int ret = 0;
            int startb = 1;
            int timeb = 0;
            int starto = 1;
            int timeo = 0;
            string[] s = Console.ReadLine().Split(' ');
            int i;
            for (i = 1; i < s.Length; i += 2)
            {
                int num = int.Parse(s[i + 1]);
                if (s[i] == "O")
                {
                    int nexttime = Math.Max(Math.Abs(num - starto) + timeo, ret) + 1;
                    ret = nexttime;
                    timeo = nexttime;
                    starto = num;
                }
                else
                {
                    int nexttime = Math.Max(Math.Abs(num - startb) + timeb, ret) + 1;
                    ret = nexttime;
                    timeb = nexttime;
                    startb = num;
                }
            }

            Console.WriteLine("Case #{0}: {1}", lll, ret);
        }
    }
}