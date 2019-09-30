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
        int L = cin.nextInt();

        int[] B = new int[L];
        for(int i = 0;i<L;i++)
        {
            B[i] = cin.nextInt();
        }

        int[] A = new int[L];
        A[0] = 0;

        for(int i = 0;i<L-1;i++)
        {
            A[i + 1] = A[i] ^ B[i];
        }

        if((A[L-1] ^ A[0]) == B[L-1])
        {
            for(int i = 0;i<L;i++)
            {
                Console.WriteLine(A[i]);
            }
        }
        else
        {
            Console.WriteLine(-1);
        }
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