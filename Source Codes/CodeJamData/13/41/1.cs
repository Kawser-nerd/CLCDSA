using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Diagnostics;
using System.Collections.Generic;
using System.Numerics;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    StreamReader sr = new StreamReader(@"C:\Users\user1\Downloads\A-large.in");
    StreamWriter sw = new StreamWriter(@"C:\Users\user1\Documents\Visual Studio 2012\Projects\GCJ\GCJ\A.txt");


    const long mod = 1000002013;
    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            //sw.WriteLine("Case #1:\n");
            Write("Case #" + (i + 1) + ": " + res);
        }//for i
        sw.Close();
        sr.Close();
    }

    long N;
    private string Solve()
    {
        int[] tmp = intSplit(' ');
         N = tmp[0];
        int M = tmp[1];
        long real = 0;
        List<Pair<int, int>> pair = new List<Pair<int, int>>();
        for (int i = 0; i < M; i++)
        {
            tmp = intSplit(' ');
            pair.Add(new Pair<int, int>(tmp[0]-1, -tmp[2]));
            pair.Add(new Pair<int, int>(tmp[1] - 1, tmp[2]));
            real += Calc(tmp[1] - tmp[0]) * tmp[2] % mod;
            if (real >= mod)
                real -= mod;
        }//for i
        pair.Sort();
        long res = 0;
        List<Pair<int, int>> passenger = new List<Pair<int, int>>();
        for (int i = 0; i < pair.Count; i++)
        {
            Pair<int, int> cur = pair[i];
            if (cur.second <= 0)
            {
                passenger.Add(new Pair<int, int>(cur.first, -cur.second));
            }
            else
            {
                Remove(ref passenger, ref res, cur.first, cur.second);
            }//else
        }//for i
        res %= mod;
        res += mod;
        res %= mod;

        long ans = (real - res+mod)%mod;
        ans+=mod;
        ans%=mod;

        return ans.ToString();
    }

    private void Remove(ref List<Pair<int, int>> passenger, ref long res, int time, int num)
    {
        for (int i = passenger.Count - 1; i >= 0&&num>0; i--)
        {
            int surrender = Math.Min(num, passenger[i].second);
            long diff = time - passenger[i].first;
            res += Calc(diff) * surrender % mod;
            if (res >= mod)
                res -= mod;
            num -= surrender;
            passenger[i].second -= surrender;
            if (passenger[i].second == 0)
                passenger.RemoveAt(i);
        }//forrev i
    }

    private long Calc(long diff)
    {
        long res = diff * N - (diff - 1L) * (diff) / 2;
        res %= mod;
        res += mod;
        if (res >= mod)
            res -= mod;
        return res;
    }


    /// <summary>
    /// varified by SRM 337 DIV1 Medium BuildingAdvertise
    /// varified by SRM 529 DIV1 easy KingSort
    /// varified by SRM404 DIV1 Medium KSubstring
    /// Pair クラス
    /// </summary>
    /// <typeparam name="typeFirst">０番目の要素の型</typeparam>
    /// <typeparam name="typeSecond">１番目の要素の型</typeparam>
    public class Pair<typeFirst,typeSecond> : IComparable<Pair<typeFirst, typeSecond>>
        where typeFirst : IComparable<typeFirst> where typeSecond : IComparable<typeSecond>
    {
        public typeFirst first;  //最初に比較される要素
        public typeSecond second;   //次に比較される要素

        /// <summary>
        /// コンストラクター
        /// </summary>
        /// <param name="typeFirst"></param>
        /// <param name="typeSecond"></param>
        public Pair(typeFirst first, typeSecond second)
        {
            this.first = first;
            this.second = second;
        }//Constractor

        /// <summary>
        /// ０番目の要素を比較して、次に１番目の要素を比較する
        /// </summary>
        /// <param name="other">比較するクラス</param>
        /// <returns>比較した差</returns>
        public int CompareTo(Pair<typeFirst, typeSecond> other)
        {
            int res = this.first.CompareTo(other.first);
            if (res != 0)
                return res;
            return this.second.CompareTo(other.second);
        }//CompareTo

    }//Pair


    void Write(string str)
    {
        Console.WriteLine(str);
        sw.WriteLine(str);
    }

    string strRead()
    {
        return sr.ReadLine();
    }

    int intRead()
    {
        return int.Parse(sr.ReadLine());
    }

    long longRead()
    {
        return long.Parse(sr.ReadLine());
    }

    double doubleRead()
    {
        return double.Parse(sr.ReadLine());
    }

    string[] strSplit(char c)
    {
        return sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries);
    }

    int[] intSplit(char c)
    {
        return Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
    }

    long[] longSplit(char r)
    {
        return Array.ConvertAll<string, long>(sr.ReadLine().Split(new char[] { r }, StringSplitOptions.RemoveEmptyEntries), long.Parse);
    }

    double[] doubleSplit(char c)
    {
        return Array.ConvertAll<string, double>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), double.Parse);
    }

}//ClassName