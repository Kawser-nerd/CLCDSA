using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    public Program() { }


    Scanner cin;

    long[] All;
    long[] Pate;

    void myon()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        long X = cin.nextLong();

        int MaxN = 51;
        All = new long[MaxN];
        Pate = new long[MaxN];

        All[0] = 1;
        Pate[0] = 1;
        for (int i = 1; i < MaxN; i++)
        {
            All[i] = All[i - 1] * 2 + 3;
            Pate[i] = Pate[i - 1] * 2 + 1;
        }

        Console.WriteLine(dfs(N, X));
    }

    long dfs(int Level, long Remain)
    {
        if(Level == 0)
        {
            return 1;
        }

        long ans = 0;
        //?????
        if (Remain >= 1)
        {
            Remain--;
        }
        //Level X-1
        if(Remain >= 1)
        {
            //???X-1????????????????????????????
            if(Remain >= All[Level - 1])
            {
                Remain -= All[Level - 1];
                ans += Pate[Level - 1];
            }
            else
            {
                ans += dfs(Level - 1, Remain);
                Remain = 0;
            }

        }

        //???
        if (Remain >= 1)
        {
            Remain--;
            ans++;
        }

        //Level X-1

        if (Remain >= 1)
        {
            //???X-1????????????????????????????
            if (Remain >= All[Level - 1])
            {
                Remain -= All[Level - 1];
                ans += Pate[Level - 1];
            }
            else
            {
                ans += dfs(Level - 1, Remain);
                Remain = 0;
            }

        }

        //??
        if (Remain >= 1)
        {
            Remain--;
        }

        return ans;
    }

    static void Main(string[] args)
    {
        new Program().myon();
    }
}


class Scanner
{
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner()
    {
        s = new string[0];
        i = 0;
    }

    public string next()
    {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return next();
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

}