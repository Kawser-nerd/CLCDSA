using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Globalization;
using System.Diagnostics;
using static System.Console;
using Pair = System.Collections.Generic.KeyValuePair<int, int>;
 
class Program
{
    static void Main()
    {
        SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().Solve();
        Out.Flush();
    }
    
    Scanner cin = new Scanner();
    Random rnd = new Random();
    Stopwatch sw = new Stopwatch();
    readonly int[] dd = { 0, 1, 0, -1, 0 };
    readonly int mod = 1000000007;
    readonly string alfa = "abcdefghijklmnopqrstuvwxyz";
 
    int N, K;
    int[] A;
    void Solve()
    {
       N = cin.Nextint;
       K = cin.Nextint;
       A = cin.Scanint;
       Array.Sort(A);
       int ans = 0;
       //if(N >400 || K > 400)return;
       for (int i = 0; i < N; i++)
       {
            if(A[i] >= K)continue;
            int cnt = 0;
            bool flag = true;
           for (int j = N - 1; j >= 0; j--)
            {
                if(i == j)continue;
                if(cnt + A[j] >= K)continue;
                if(cnt + A[j] + A[i] >= K)
                {
                    flag = false;
                    break;
                }
                cnt+=A[j];
            }
            if(flag)
            {
                ans++;
            }
       }
       WriteLine(ans);


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