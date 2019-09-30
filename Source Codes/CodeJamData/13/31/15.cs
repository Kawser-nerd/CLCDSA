using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

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
        s = Console.ReadLine().Split(cs); //, StringSplitOptions.RemoveEmptyEntries);
        i = 0;
        return s[i++];
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }

    public int nextInt()
    {
        return int.Parse(next());
    }

    public long nextLong()
    {
        return long.Parse(next());
    }
}

class Solver
{
    Scanner cin;

    int[] powers= new int[1001];

    void SolveAll()
    {
        for (int i = 1; i <= 1000; i++)
            powers[i] = i * i;

        cin = new Scanner();
        int T = cin.nextInt();
        for (int c = 1; c <= T; c++)
        {
            Console.Write("Case #{0}: ", c);
            SolveCase(c, T);
            Console.Out.Flush();
        }
    }

    public static void Main()
    {
        Console.SetIn(new StreamReader("al.in"));
        Console.SetOut(new StreamWriter("al.out"));
        (new Solver()).SolveAll();
    }

    void SolveCase(int c, int T)
    {
        string name = cin.next();
        long n = cin.nextLong();

        long nvalue = 0;
        long nConsec = 0;
        long lastConsecStart = -1;
        for (int pos = 0; pos < name.Length; pos++)
        {
            if (!isConso(name[pos]))
            {
                nConsec = 0;
                continue;
            }
            
            nConsec++;

            if (nConsec == n)
            {
                long startConsec = pos - nConsec + 1;
                long nBeforeIncSelf = startConsec + 1 - (lastConsecStart + 1);
                long nAfter = name.Length - pos - 1;
                nvalue += nBeforeIncSelf + nAfter;
                if (nBeforeIncSelf > 1)
                    nvalue += (nBeforeIncSelf - 1) * nAfter;
                
                lastConsecStart = startConsec;
                nConsec--;
            }
        }

        Console.WriteLine(nvalue);
    }

    bool isConso(char c)
    {
        return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
    }
}

