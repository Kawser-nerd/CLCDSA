using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }

    Scanner cin;
    

    void calc()
    {
        cin = new Scanner();
        int N = cin.nextInt();
        int A = cin.nextInt();
        int B = cin.nextInt();
        int FA = A;
        A ^= FA; B ^= FA;

        int BC = bitCount(B);

        if(BC % 2 == 0)
        {
            Console.WriteLine("NO");
            return;
        }

        int[] ans = new int[1 << N];
        for (int i = 0; i < (BC + 1) / 2; i++)
        {
            if (i == 0)
            {
                for (int j = 1 << (N - 1);  j < (1 << N); j++)
                {
                    ans[j] |= 1;
                }
            }
            else
            {
                int block1 = (1 << N) >> (2 * i);
                int block2 = (1 << N) >> (2 * i + 1);

                for (int j = 0; j < (1 << N) - block1 * 2; j++)
                {
                    int m = (j / block1) % 4;
                    int bit = 0;
                    if (m == 1 || m == 2) bit = 1;

                    ans[j] |= bit << (2 * i - 1);
                }

                for (int j = 0; j < (1 << N) - block1 * 2; j++)
                {
                    int m = (j / block2) % 4;
                    int bit = 0;
                    if (m == 1 || m == 2) bit = 1;

                    ans[j] |= bit << (2 * i);
                }

                for (int j = (1 << N) - block1 * 2; j < (1 << N); j++)
                {
                    int m = (j / block2) % 4;
                    int bit = 1;
                    if (m == 1 || m == 2) bit = 0;

                    ans[j] |= bit << (2 * i - 1);
                }

                for (int j = (1 << N) - block1 * 2; j < (1 << N); j++)
                {
                    int m = (j / block1) % 4;
                    int bit = 1;
                    if (m == 1 || m == 2) bit = 0;

                    ans[j] |= bit << (2 * i);
                }
            }
        }

        for (int i = BC; i < N; i++)
        {
            int block = (1 << N) >> (i + 1);
            for (int j = 0; j < (1 << N); j++)
            {
                int m = (j / block) % 4;
                int bit = 0;
                if (m == 1 || m == 2) bit = 1;

                ans[j] |= bit << i;
            }
        }

        List<int> L = new List<int>();
        for (int i = 0; i < N; i++)
        {
            if ((B >> i) % 2 == 1) L.Add(i);
        }

        for (int i = 0; i < N; i++)
        {
            if ((B >> i) % 2 == 0) L.Add(i);
        }
        

        for (int i = 0; i < (1 << N); i++)
        {
            int realAns = 0;
            for (int j = 0; j < N; j++)
            {
                if (((ans[i] >> j) & 1) == 1)
                {
                    realAns |= 1 << L[j];
                }
            }
            ans[i] = realAns;
        }

        Console.WriteLine("YES");
        for (int i = 0; i < (1 << N); i++)
        {
            Console.WriteLine(ans[i] ^ FA);
        }
    }

    int bitCount(long x)
    {
        x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555);
        x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333);
        x = (x & 0x0f0f0f0f0f0f0f0f) + (x >> 4 & 0x0f0f0f0f0f0f0f0f);
        x = (x & 0x00ff00ff00ff00ff) + (x >> 8 & 0x00ff00ff00ff00ff);
        x = (x & 0x0000ffff0000ffff) + (x >> 16 & 0x0000ffff0000ffff);
        return (int)((x & 0x00000000ffffffff) + (x >> 32 & 0x00000000ffffffff));
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
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt()
    {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0)
    {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong()
    {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0)
    {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble()
    {
        return double.Parse(next());
    }


    public double[] ArrayDouble(int N, double add = 0)
    {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++)
        {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}