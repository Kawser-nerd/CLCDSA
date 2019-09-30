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
        string S = cin.next();
        string T = cin.next();

        int start = Math.Max(0, S.Length - T.Length);

        int Ans = S.Length + T.Length;
        for (int i = start; i < S.Length; i++)
        {
            bool flag = true;

            for (int j = i; j < S.Length; j++)
            {
                if(S[j] != T[j - i])
                {
                    flag = false;
                    break;
                }
            }

            if (flag) Ans = Math.Min(Ans, i + T.Length);
        }

        Console.WriteLine(Ans);
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