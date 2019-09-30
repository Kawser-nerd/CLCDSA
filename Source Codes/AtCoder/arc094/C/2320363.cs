using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;
//using System.Text;
//using System.Text.RegularExpressions;
//using System.Globalization;
//using System.Diagnostics;
using static System.Console;
//using System.Numerics;
//using static System.Math;
using pair = Pair<long, long>;

class Program
{
    static void Main()
    {
        //SetOut(new StreamWriter(OpenStandardOutput()) { AutoFlush = false });
        new Program().solve();
        Out.Flush();
    }
    Scanner cin = new Scanner();
    readonly int[] dd = { 0, 1, 0, -1, 0 }; //????
    readonly int mod = 1000000007;


    void solve()
    {
        int N = cin.nextint;
        var A = new int[N];
        var B = new int[N];
        var C = new int[N];
        var P = new pair[N];

        long min = int.MaxValue;
        bool flag = false;
        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            A[i] = cin.nextint;
            B[i] = cin.nextint;
            //C[i] = A[i] - B[i];
            //P[i] = new pair(A[i], B[i]);
            if (A[i] != B[i])
            {
                flag = true;
            }
            if(A[i] > B[i])min = Math.Min(B[i], min);
            sum += A[i];
        }
        if (flag)
        {
            WriteLine(sum - min);
        }
        else
        {
            WriteLine(0);
        }

        //long ans = 0;
        //long rem = 0;
        //Array.Sort(C, P);
        //for (int i = 0; i < N; i++)
        //{
        //    if (C[i] < 0)
        //    {
        //        ans += P[i].f;
        //        rem += -C[i];
        //    }
        //    else if (C[i] == 0)
        //    {
        //        if (rem > 0)
        //        {
        //            ans += P[i].f;
        //        }
        //    }
        //    else
        //    {
        //        if (C[i] < rem)
        //        {
        //            rem -= (P[i].f - P[i].s);
        //            ans += P[i].f;
        //        }
        //        else
        //        {
        //            //P[i].f -= rem;
        //            ans += rem;
        //            //if (P[i].f < P[i].s)
        //            //{
        //            //    rem = P[i].s - P[i].f;
        //            //    ans += P[i].f;
        //            //}
                    
        //        }
        //    }
        //    //WriteLine(ans);
        //}
        //WriteLine(ans);

    }

}


class Pair<T, U> : IComparable<Pair<T, U>> where T : IComparable<T> where U : IComparable<U>
{
    public T f;
    public U s;
    public Pair(T f, U s)
    {
        this.f = f;
        this.s = s;
    }
    public int CompareTo(Pair<T, U> a)
    {
        return f.CompareTo(a.f) != 0 ? f.CompareTo(a.f) : s.CompareTo(a.s);
    }
    public override string ToString()
    {
        return f + " " + s;
    }
}
class Scanner
{
    string[] s; int i;
    char[] cs = new char[] { ' ' };
    public Scanner() { s = new string[0]; i = 0; }
    public string[] scan { get { return ReadLine().Split(); } }
    public int[] scanint { get { return Array.ConvertAll(scan, int.Parse); } }
    public long[] scanlong { get { return Array.ConvertAll(scan, long.Parse); } }
    public double[] scandouble { get { return Array.ConvertAll(scan, double.Parse); } }
    public string next
    {
        get
        {
            if (i < s.Length) return s[i++];
            string st = ReadLine();
            while (st == "") st = ReadLine();
            s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
            i = 0;
            return next;
        }
    }
    public int nextint { get { return int.Parse(next); } }
    public long nextlong { get { return long.Parse(next); } }
    public double nextdouble { get { return double.Parse(next); } }
}