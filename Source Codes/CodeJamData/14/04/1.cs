using System;
using System.Collections.Generic;
using System.Linq;

class Myon
{
    public Myon() { }
    public static void Main()
    {
        new Myon().run2();
    }

    Scanner cin;
    public void run2()
    {
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);
            //Console.WriteLine("Case #{0}:", i + 1);

            run();
        }
    }


    void run()
    {
        int N = cin.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        for (int i = 0; i < N; i++)
        {
            A[i] = (int)(cin.nextDouble() * 100000 + 0.5);
        }
        for (int i = 0; i < N; i++)
        {
            B[i] = (int)(cin.nextDouble() * 100000 + 0.5);
        }
        Array.Sort(A);
        Array.Sort(B);
        int retA = 0;
        int retB = 0;
        for (int i = 0; i < N; i++)
        {
            bool flag = true;
            for (int j = 0; j < N - i; j++)
            {
                if (A[i + j] <= B[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                retA = N - i;
                break;
            }
        }

        int t = 0;
        for (int i = 0; i < N; i++)
        {
            if (B[i] > A[t]) t++;
        }
        retB = N - t;

        Console.WriteLine("{0} {1}", retA, retB);
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
        s = Console.ReadLine().Split(cs, StringSplitOptions.RemoveEmptyEntries);
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
