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
        init();
        cin = new Scanner();
        int T = cin.nextInt();
        for (int i = 0; i < T; i++)
        {
            Console.Write("Case #{0}: ", i + 1);

            run();
        }
    }


    void init()
    {
        
    }


    void run()
    {
        int B = cin.nextInt();
        long N = cin.nextInt();

        int[] M = new int[B];
        for (int i = 0; i < B; i++)
        {
            M[i] = cin.nextInt();
        }
        if (N <= B)
        {
            Console.WriteLine(N);
            return;
        }
        long low = 0;
        long high = (long)1e15;
        while (high - low > 1)
        {
            long mid = (low + high) / 2;
            long count = 0;
            for (int i = 0; i < B; i++)
            {
                count += (mid / M[i]) + 1;
            }
            if (count >= N) high = mid;
            else low = mid;
        }
        for (int i = 0; i < B; i++)
        {
            N -= (low / M[i]) + 1;
        }
        for (int i = 0; i < B; i++)
        {
            if (high % M[i] == 0)
            {
                if (N == 1) Console.WriteLine(i + 1);
                N--;
            }
        }
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
