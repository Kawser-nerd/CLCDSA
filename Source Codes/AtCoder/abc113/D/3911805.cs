using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
using System.Globalization;
using System.Diagnostics;
using System.Threading.Tasks;



class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }


    class Shi : IComparable<Shi>
    {
        public int P;
        public int Y;
        public int ID;

        public Shi(int P, int Y, int ID)
        {
            this.P = P;
            this.Y = Y;
            this.ID = ID;
        }

        int IComparable<Shi>.CompareTo(Shi other)
        {
            if (P != other.P) return P.CompareTo(other.P);
            else return Y.CompareTo(other.Y);
        }
    }


    Scanner cin;

    long mod = 1000000007;
    int H, W, K;

    void calc()
    {
        cin = new Scanner();


        H = cin.nextInt();
        W = cin.nextInt();
        K = cin.nextInt() - 1;

        dp = new long[H, W, W];
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                for (int k = 0; k < W; k++)
                {
                    dp[i, j, k] = -1;
                }
            }
        }

        Console.WriteLine(dfs(0, 0, 0));
    }

    long[,,] dp;

    //???y????x???????????k?????????????????
    long dfs(int y, int x, int k)
    {

        if(y >= H)
        {
            if (k == K) return 1;
            else return 0;
        }
        if(x >= W - 1)
        {
            return dfs(y + 1, 0, k);
        }

        if (dp[y, x, k] != -1) return dp[y, x, k];


        //???y, ???x????????????

        long ans = 0;

        //?????
        ans += dfs(y, x + 1, k);

        //???
        int nextk = k;
        if (x == k) nextk++;
        else if (x + 1 == k) nextk--;
        ans += dfs(y, x + 2, nextk);

        ans %= mod;

        dp[y, x, k] = ans;
        return ans;
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