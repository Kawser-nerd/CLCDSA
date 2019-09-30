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


    int count;
    char[] car;
    Dictionary<string, char> dicc;
    Dictionary<string, char> dicr;


    void calc()
    {
        int lll;
        int loopmax = input();
        for (lll = 1; lll <= loopmax; lll++)
        {
            string[] s = Console.ReadLine().Split(' ');
            int i = 0, j;
            dicc = new Dictionary<string, char>();
            dicr = new Dictionary<string, char>();
            int n = int.Parse(s[i]); i++;
            string ss;
            for (j = 0; j < n; j++, i++)
            {
                ss = s[i];
                dicc[ss[0] + "" + ss[1]] = ss[2];
                dicc[ss[1] + "" + ss[0]] = ss[2];
            }
            n = int.Parse(s[i]); i++;
            for (j = 0; j < n; j++, i++)
            {
                ss = s[i];
                dicr[ss[0] + "" + ss[1]] = 'a';
                dicr[ss[1] + "" + ss[0]] = 'a';
            }
            n = int.Parse(s[i]); i++;
            ss = s[i];
            car = new char[1000];
            count = 0;
            for (j = 0; j < ss.Length; j++)
            {
                add(ss[j]);
            }
            string ret = "[";
            for (j = 0; j < count; j++)
            {
                ret += car[j];
                if (j != count - 1) ret += ", ";
            }
            ret += "]";
            Console.WriteLine("Case #{0}: {1}", lll, ret);
        }
    }

    void add(char c)
    {
        if (count != 0)
        {
            if (dicc.ContainsKey(car[count - 1] + "" + c))
            {
                count--;
                add(dicc[car[count] + "" + c]);
                return;
            }
            int i;
            for (i = 0; i < count; i++)
            {
                if (dicr.ContainsKey(car[i] + "" + c))
                {
                    count = 0;
                    return;
                }
            }
        }
        car[count] = c; count++; 
    }
}