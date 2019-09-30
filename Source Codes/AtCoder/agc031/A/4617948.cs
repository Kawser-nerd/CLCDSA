using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static void Main()
    {
        Console.WriteLine(Solve());
        return;

    }

    public static string Solve()
    {
        long MOD = 1000000007;
        long ans = 0;

        int N = ReadInt();
        string S = Read();

        int[] cnt = new int[27];
        for(int i=0;i<N;i++)
        {
            cnt[S[i] - 'a']++;
        }
        //Console.WriteLine(string.Join(", ",cnt));
        ans = 1;
        for(int i=0;i<27;i++)
        {
            ans = (ans * (cnt[i] + 1)) % MOD;
        }
        ans--;
        return ans.ToString();
    }

    private static string Read() { return Console.ReadLine(); }
    private static int ReadInt() { return int.Parse(Read()); }
    private static long ReadLong() { return long.Parse(Read()); }
    private static double ReadDouble() { return double.Parse(Read()); }
    private static int[] ReadInts() { return Array.ConvertAll(Read().Split(), int.Parse); }
    private static long[] ReadLongs() { return Array.ConvertAll(Read().Split(), long.Parse); }
    private static double[] ReadDoubles() { return Array.ConvertAll(Read().Split(), double.Parse); }
}