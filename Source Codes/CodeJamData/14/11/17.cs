//#define ONLINE_JUDGE
#define DEBUG

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Program
{

    static int tests = 3;

#if (ONLINE_JUDGE)
    static TextReader r = Console.In;
    static TextWriter w = Console.Out;
#else
    static string path = @"C:\Y\Prog\GoogleCodeJam\01\";
    static string answerFile = "0{0}Answer.txt";
    static string resultFile = "0{0}Result.txt";
    static string sourceFile = "0{0}Source.txt";

    static TextReader r;
    static TextWriter w;
#endif

    static void Main(string[] args)
    {
        for (int i = 1; i <= tests; i++)
        {
#if (!ONLINE_JUDGE)
            r = new StreamReader(string.Format(path + sourceFile, i));
            w = new StreamWriter(string.Format(path + resultFile, i), false);
#endif
            int cases = Convert.ToInt32(r.ReadLine());
            for (int j = 0; j < cases; j++)
                solve(j+1);
#if (!ONLINE_JUDGE)
            w.Flush(); w.Close();
            Console.WriteLine("CASE: {0}", i);
            string answer = File.ReadAllText(string.Format(path + answerFile, i));
            string result = File.ReadAllText(string.Format(path + resultFile, i));
            if (answer != result)
            {
                Console.WriteLine("FAIL:");
                Console.WriteLine("Result" + Environment.NewLine + result);
                Console.WriteLine("Answer" + Environment.NewLine + answer);
            }
            else
                Console.WriteLine("OK");
#endif
        }
    }


    public static long getLong(string s)
    {
        long res = 0;
        long cur = (1 << (s.Length-1));
        foreach (char c in s)
        {
            if (c == '1') res += cur;
            cur /= 2;
        }
        return res;
    }
    public static void solve(int cs)
    {
        string[] b = r.ReadLine().Split(' ');
        int n = Convert.ToInt32(b[0]);
        int L = Convert.ToInt32(b[1]);

        long[] f0 = new long[n];
        long[] d = new long[n];
        
        b = r.ReadLine().Split(' ');    
        for (int j = 0; j <= n - 1; j++)
            f0[j] = getLong(b[j]);
        b = r.ReadLine().Split(' ');        
        for (int j = 0; j <= n - 1; j++)
            d[j] = getLong(b[j]);
        
        long[] f = new long[n];
        
        Array.Sort(d);
        int best = int.MaxValue;
        for (long i = 0; i < (1<<L) ; i++)
        {

            for (int j = 0; j <= n - 1; j++)
                f[j] = f0[j];

            int cur = 0;
            for (int p = 0; p <= n - 1; p++)
            {
                for (int j = 0; j <= L - 1; j++)
                {
                    if ((i & (1 << j)) > 0)
                    {
                        cur++;
                        f[p] = (f[p] & (~(1 << j))) + (((f[p] & (1 << j)) > 0) ? 0 : (1 << j));
                    }
                }
            }
            cur = cur / n;
            Array.Sort(f);
            bool good = true;
            for (int j = 0; j <= n - 1; j++)
                if (f[j] != d[j])
                {
                    good = false;
                    break;
                }
            if (good && cur < best) best = cur;
        }

        if (best == int.MaxValue)
            w.WriteLine("Case #{0}: NOT POSSIBLE", cs);
        else
            w.WriteLine("Case #{0}: {1}", cs, best); 
    }
}