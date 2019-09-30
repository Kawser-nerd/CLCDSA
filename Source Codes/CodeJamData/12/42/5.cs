using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
public class MyonBBB
{
    StreamReader sr;
    StreamWriter sw;

    static void Main()
    {
        new MyonBBB().EntryBBB();
    }

    void SolveBBB()
    {
        int N; int W; int L;
        int[] array = Array.ConvertAll<string, int>(stringRead().ToString().Split(' '), int.Parse);
        N = array[0];
        W = array[1];
        L = array[2];

        Pair<long, int>[] pair = new Pair<long, int>[N];
        array = Array.ConvertAll<string, int>(stringRead().ToString().Split(' '), int.Parse);        
        for (int i = 0; i < N; i++)
        {
            pair[i] = new Pair<long, int>(array[i], i);
        }//for i
        Array.Sort(pair);
        Array.Reverse(pair);

        XorShift rand = new XorShift();
        for (int i = 0; i < 1000; i++)
        {
            rand.Next(3);
        }//for i


        List<Triplet<long, long, int>> tri = new List<Triplet<long, long, int>>();  //x,y,index
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
            {
                tri.Add(new Triplet<long, long, int>(0, 0, pair[i].second));
            }
            else
            {
                while (true)
                {
                    long nx = rand.Next(W);
                    long ny = rand.Next(L);
                    int j = 0;
                    for (; j < tri.Count; j++)
                    {
                        if (Bad(tri[j].first, tri[j].second, nx, ny, array[tri[j].third] + pair[i].first))
                            break;
                    }//for j
                    if (j == tri.Count)
                    {
                        tri.Add(new Triplet<long, long, int>(nx, ny, pair[i].second));
                        break;
                    }
                }
            }
        }//for i

        long[] rx = new long[N];
        long[] ry = new long[N];
        for (int i = 0; i < N; i++)
        {
            rx[tri[i].third] = tri[i].first;
            ry[tri[i].third] = tri[i].second;
        }//for i

        StringBuilder res = new StringBuilder();
        for (int i = 0; i < N; i++)
        {
            if(i!=0)
                res.Append(" ");
            res.Append(rx[i] + " " + ry[i]);
        }//for i
        WriteLine(res);
    }

    private bool Bad(long x, long y, long nx, long ny, long r)
    {
        if ((x - nx) * (x - nx) + (y - ny) * (y - ny) < r * r)
            return true;
        return false;
    }


    /// <summary>
    /// 擬似乱数生成機
    /// </summary>
    public class XorShift
    {
        const int mask = int.MaxValue;
        int x = 123456789;
        int y = 362436069;
        int z = 521288629;
        int w = 88675123;
        int t; int r;

        /// <summary>
        /// 次の乱数を求める
        /// </summary>
        /// <param name="n">排他的上限</param>
        /// <returns>乱数</returns>
        public int Next(int n)
        {
            t = x ^ (x << 11);
            x = y;
            y = z;
            z = w;
            w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
            r = ((w & mask)>>3) % n;
            return r;
        }//Next

    }//XorShift

    /// <summary>
    /// varified by SRM 529 DIV1 easy KingSort
    /// Triplet クラス
    /// </summary>
    /// <typeparam name="typeFirst">０番目の要素の型</typeparam>
    /// <typeparam name="typeSecond">１番目の要素の型</typeparam>
    /// <typeparam name="typeThird">2番目の要素の型</typeparam>
    public class Triplet<typeFirst,typeSecond,typeThird>
       : IComparable<Triplet<typeFirst, typeSecond, typeThird>>
        where typeFirst : IComparable<typeFirst> where typeSecond : IComparable<typeSecond> where typeThird : IComparable<typeThird>
    {
        public typeFirst first;  //最初に比較される要素
        public typeSecond second;   //次に比較される要素
        public typeThird third; //その次に比較される要素

        /// <summary>
        /// コンストラクター
        /// </summary>
        /// <param name="typeFirst"></param>
        /// <param name="typeSecond"></param>
        /// <param name="typeThird"></param>
        public Triplet(typeFirst first, typeSecond second, typeThird third)
        {
            this.first = first;
            this.second = second;
            this.third = third;
        }//Constractor

        /// <summary>
        /// first,second,third の順で比較する
        /// </summary>
        /// <param name="other">比較するクラス</param>
        /// <returns>比較した差</returns>
        public int CompareTo(Triplet<typeFirst, typeSecond, typeThird> other)
        {
            int res = this.first.CompareTo(other.first);
            if (res != 0)
                return res;
            res = this.second.CompareTo(other.second);
            if (res != 0)
                return res;
            return this.third.CompareTo(other.third);
        }//CompareTo

    }//Triplet


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

    void EntryBBB()
    {
        sr = new StreamReader(@"C:\Users\user1\Downloads\B-large.in");
        sw = new StreamWriter(@"C:\Users\user1\Downloads\WriteBBB.txt");

        int rep = intRead();
        for (int i = 0; i < rep; i++)
        {
            sw.Write("Case #{0}: ", i + 1);
            Console.Write("Case #{0}: ", i + 1);
            SolveBBB();
        }//for i

        sw.Close();
        sr.Close();
    }

    string stringRead()
    { return sr.ReadLine(); }

    int intRead()
    { return int.Parse(sr.ReadLine()); }

    long longRead()
    { return long.Parse(sr.ReadLine()); }

    string[] stringSplit(char a)
    { return sr.ReadLine().Split(a); }

    int[] intSplit(char a)
    { return Array.ConvertAll<string, int>(sr.ReadLine().Split(a), int.Parse); }

    long[] longSplit(char a)
    { return Array.ConvertAll<string, long>(sr.ReadLine().Split(a), long.Parse); }

    void WriteLine<T>(T str)
    {
        Console.WriteLine(str.ToString());
        sw.WriteLine(str.ToString());
    }

}