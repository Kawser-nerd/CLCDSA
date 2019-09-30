using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static List<int> MakeACList(string s)
    {
        int len = s.Length;
        var ans = Enumerable.Repeat(0, len).ToList();
        for (int i = 0; i < len-1; i++)
        {
            var ac = 0;
            if(s[i] == 'A' && s[i+1] == 'C')
            {
                ac = 1;
            }
            ans[i + 1] = ans[i] + ac; 
        }
        return ans;
    }

    static int GetAC(List<int> aclist, int l, int r)
    {
        return aclist[r - 1] - aclist[l - 1];
    }

    static void Main(string[] args)
    {
        string nq = Console.ReadLine();
        int n = int.Parse(nq.Split(' ')[0]);
        int q = int.Parse(nq.Split(' ')[1]);
        string s = Console.ReadLine();

        var aclist = MakeACList(s);

        for (int i = 0; i < q; i++)
        {
            string lr = Console.ReadLine();
            int l = int.Parse(lr.Split(' ')[0]);
            int r = int.Parse(lr.Split(' ')[1]);
            int ans = GetAC(aclist, l, r);
            Console.WriteLine(ans);
        }
        Console.WriteLine();
        Console.ReadLine();
    }
}