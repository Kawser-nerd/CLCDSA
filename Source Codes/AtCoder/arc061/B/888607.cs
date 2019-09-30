using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Text;
 
class Myon
{
    public Myon() { }
    public static int Main()
    {
        new Myon().calc();
        return 0;
    }
 
    Scanner cin;
 
    int H, W, N;
    int[] a, b;
 
    Dictionary<long, bool> dic = new Dictionary<long, bool>();
    Dictionary<long, bool> dic2 = new Dictionary<long, bool>();
 
    const int MAX = 9999999;
    bool[,] minitable = new bool[MAX, 8];
    bool[,] minitable2 = new bool[MAX, 8];
 
    long[] ans;
    public void calc()
    {
        cin = new Scanner();
        H = cin.nextInt();
        W = cin.nextInt();
        N = cin.nextInt();
        a = new int[N];
        b = new int[N];
 
        for (int i = 0; i < N; i++)
        {
            a[i] = cin.nextInt() - 1;
            b[i] = cin.nextInt() - 1;
            //dic[gethash(a[i], b[i])] = true;
            sethash(a[i], b[i]);
        }
 
        long allans = (H - 2L) * (W - 2L);
        ans = new long[10];
 
        for (int i = 0; i < N; i++)
        {
            for (int vy = -2; vy <= 0; vy++)
            {
                for (int vx = -2; vx <= 0; vx++)
                {
                    int by = a[i] + vy;
                    int bx = b[i] + vx;
                    if (!inside(by, bx)) continue;
                    if (!inside(by + 2, bx + 2)) continue;
                    if (checkhash2(by, bx)) continue;
                    int cnt = 0;
                    for (int dy = 0; dy < 3; dy++)
                    {
                        for (int dx = 0; dx < 3; dx++)
                        {
                            int y = by + dy;
                            int x = bx + dx;
                            if (checkhash(y, x)) cnt++;
                        }
                    }
                    allans--;
                    ans[cnt]++;
                    //dic2[gethash(by, bx)] = true;
                    sethash2(by, bx);
 
                }
            }
        }
        ans[0] += allans;
        for (int i = 0; i < ans.Length; i++)
        {
            Console.WriteLine(ans[i]);
        }
    }
 
    bool inside(int y, int x)
    {
        return y >= 0 && x >= 0 && y < H && x < W;
    }
 
    long[] num = new long[] { 123651, 127551, 177377, 845831, 558321, 17826, 127675, 686121 };
    long[] num2 = new long[] { 890711, 345787, 157345, 237451, 317561, 871211, 123113, 137659 };
    long[] mod = new long[] { MAX, MAX - 2, MAX - 9, MAX - 123171, MAX - 1276894, MAX - 1268576, MAX - 127866, MAX - 1276567 };
 
    long gethash(int a, int b)
    {
        return ((long)a << 31) + b;
    }
 
    void sethash(int a, int b)
    {
        for (int i = 0; i < num.Length; i++)
        {
            int minihash = (int)((a * num[i] + b * num2[i]) % mod[i]);
            minitable[minihash, i] = true;
        }
    }
 
    void sethash2(int a, int b)
    {
        for (int i = 0; i < num.Length; i++)
        {
            int minihash = (int)((a * num[i] + b * num2[i]) % mod[i]);
            minitable2[minihash, i] = true;
        }
    }
 
    bool checkhash(int a, int b)
    {
        for (int i = 0; i < num.Length; i++)
        {
            int minihash = (int)((a * num[i] + b * num2[i]) % mod[i]);
            if (!minitable[minihash, i]) return false;
        }
        return true;
    }
 
    bool checkhash2(int a, int b)
    {
        for (int i = 0; i < num.Length; i++)
        {
            int minihash = (int)((a * num[i] + b * num2[i]) % mod[i]);
            if (!minitable2[minihash, i]) return false;
        }
        return true;
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
        while (i >= s.Length)
        {
            string st = Console.ReadLine();
            while (st == "") st = Console.ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
        }
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