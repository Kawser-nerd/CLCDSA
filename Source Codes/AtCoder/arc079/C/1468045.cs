using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
//using System.Numerics;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";


    void Solve()
    {



        long N = cin.Nextint;
        var A = cin.Scanlong;
        long ans = 0;
        while (true)
        {
            long tmp = 0;
            for (int i = 0; i < N; i++)
            {
                tmp += A[i] / N;
            }
            if (tmp == 0) break;
            ans += tmp;
            for (int i = 0; i < N; i++)
            {
                A[i] = A[i] % N + (tmp - A[i] / N);
            }
        }
        WriteLine(ans);


        /*for (int i = 0; i < N; i++)
        {
            M[A[i] % N]++;
            cnt += A[i] / N;
        }

        for (int i = 0; i < N; i++)
        {
            cnt += 
        }*/

        /*Array.Sort(A);
        Array.Reverse(A);

        //????
        long K = (A[0] - (N - 1)) * N;
        WriteLine(K + " " + K / N);

        long D = K / N;


        long cnt = 0;

        for (int i = 0; i < N; i++)
        {
            if (A[0] == A[i]) continue;

            long t = (A[0] - A[i]) / N + 1;
            long d = (A[i] + D) / N - (A[i] + D) / N;
            WriteLine(t - d);

            K -= Math.Min(t - d, D);
        }

        WriteLine(K);

        for (int i = 0; i < N; i++)
        {
            cnt += A[i] / N;

        }*/

    }

}

class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] Scan { get { return ReadLine().Split(); } }
    public int[] Scanint { get { return Array.ConvertAll(Scan, int.Parse); } }
    public long[] Scanlong { get { return Array.ConvertAll(Scan, long.Parse); } }
    public double[] Scandouble { get { return Array.ConvertAll(Scan, double.Parse); } }
    public string Next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return Next;
        }
    }
    public int Nextint { get { return int.Parse(Next); } }
    public long Nextlong { get { return long.Parse(Next); } }
    public double Nextdouble { get { return double.Parse(Next); } }
}