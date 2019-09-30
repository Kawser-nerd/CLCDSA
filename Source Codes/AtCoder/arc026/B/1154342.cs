using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;

class Prog
{
    public Prog() { }
    public static int Main()
    {
        new Prog().calc();
        return 0;
    }

    Scanner cin;

    public void calc()
    {
        cin = new Scanner();
        long N = cin.nextLong();
        long sum = 0;
        long sq = (long)Math.Sqrt(N);

        for (long l = 1; l <= sq; l++)
        {
            if (N % l == 0)
            {
                sum += l;
                sum += N / l;
            }
        }

        sum -= N;
        if (sq * sq == N) sum -= sq;

        if (sum < N) Console.WriteLine("Deficient");
        else if(sum == N) Console.WriteLine("Perfect");
        else Console.WriteLine("Abundant");

        Console.Read();
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
        return s[i++];
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