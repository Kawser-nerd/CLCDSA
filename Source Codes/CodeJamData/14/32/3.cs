using System;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections;
using System.Diagnostics;
using System.Numerics;
using System.Collections.Generic;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    const string inputName = @"B-large.in";
    StreamReader sr = new StreamReader(@"C:\Users\onigiri\Downloads\" + inputName);
    StreamWriter sw = new StreamWriter(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\B.txt");

    void Entry()
    {
        //C();
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            Write("Case #" + (i + 1) + ": " + res);
        }//for i
        sw.Close();
        sr.Close();
    }

    private void C()
    {
        StreamReader sw = new StreamReader(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\B1c.txt");

        StreamReader sw0 = new StreamReader(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\B1opt.txt");

        for (int i = 0; i < 100; i++)
        {
            string a = sw.ReadLine();
            string b = sw0.ReadLine();
            if (a != b)
            {
                Console.WriteLine(i);
            }//if
        }//for i
        sw.Close();
        sw0.Close();

    }

    const int mod = 1000000007;
    const int alph = 26;
    private string Solve()
    {
        int N = intRead();
        var array = strSplit(' ');
        var cnt = new int[alph, alph];
        int c = 0;
        foreach (var cur in array)
        {
            int top = 0;
            int last = cur.Length - 1;
            while (top + 1 < cur.Length && cur[top] == cur[top + 1])
            {
                top++;
            }//while
            while (last - 1 >= 0 && cur[last] == cur[last - 1])
            {
                last--;
            }//while
            if (last - top > 1 && cur[0] == cur[cur.Length - 1])
            {
                return "0";
            }//if
            for (int i = top + 1; i < last; i++)
            {
                for (int k = 0; k < array.Length; k++)
                {
                    if (c != k && array[k].Contains(cur[i]))
                    {
                        return "0";
                    }//if
                }//foreach comp
            }//for i
            if (!Check(cur))
            {
                return "0";
            }//if
            cnt[cur[0] - 'a', cur[cur.Length - 1] - 'a']++;
            c++;
        }//foreach cur
        var next = Enumerable.Repeat(-1, alph).ToArray();
        var perm = new int[alph];
        for (int i = 0; i < alph; i++)
        {
            int sum = 0;
            for (int j = 0; j < alph; j++)
            {
                if (j != i && cnt[i, j] > 0)
                {
                    next[i] = j;
                    sum += cnt[i, j];
                }//if
            }//for j
            if (sum > 1)
            {
                return "0";
            }//if
            perm[i] = cnt[i, i];
        }//for i
        for (int i = 0; i < alph; i++)
        {
            int cur = i;
            int step = 0;
            while (next[cur] >= 0)
            {
                cur = next[cur];
                step++;
                if (step > 50)
                {
                    return "0";
                }//if
            }//while
        }//for i
        var factArray = FactArray(N + 10, mod);
        long res = 1;
        for (int i = 0; i < alph; i++)
        {
            res *= factArray[perm[i]];
            res %= mod;
        }//for i
        var uf = new UnionFind(alph);
        for (int i = 0; i < next.Length; i++)
        {
            if (next[i] >= 0)
            {
                uf.Unite(i, next[i]);
            }//if
        }//for i
        int p = 0;
        var check = new bool[alph];
        for (int i = 0; i < alph; i++)
        {
            if (perm[i] == 0 && next[i] < 0)
            {
                continue;
            }//if
            if (!check[i])
            {
                p++;
                for (int j = 0; j < alph; j++)
                {
                    if (uf.Same(i, j))
                    {
                        check[j] = true;
                    }//if
                }//for j
            }//if
        }//for i
        res *= factArray[p];
        res %= mod;
        return res.ToString();
    }


    private bool Check(string str)
    {
        var used = new bool[alph];
        int p = 0;
        while (p < str.Length)
        {
            if (used[str[p] - 'a'])
            {
                return false;
            }//if
            used[str[p] - 'a'] = true;
            while (p + 1 < str.Length && str[p] == str[p + 1])
            {
                p++;
            }//while
            p++;
        }//while
        return true;
    }

    /// <summary>
    /// varified by SRM 472 DIV1 Medium TwoSidedCards
    /// varified by SRM 391 DIV1 Medium KeysInBoxes
    /// 階乗のテーブルを作る
    /// O( len )
    /// </summary>
    /// <param name="len">階乗をとる最大の値</param>
    /// <param name="mod">mod を取る値</param>
    /// <returns>階乗のテーブル</returns>
    public static long[] FactArray(int len, int mod)
    {
        long[] factrial = new long[len + 1];
        factrial[0] = 1;
        for (int i = 1; i <= len; i++)
        {
            factrial[i] = factrial[i - 1] * i % mod;
        }//for i
        return factrial;
    }//FactArray

    /// <summary>
    /// varified by SRM472 DIV1 Medium TwoSidedCards
    /// 0 : サイズを指定して初期化
    /// -1 で初期化。
    /// 初期化に O(len)
    /// 関数は平均 A^-1 (len)
    /// </summary>
    public class UnionFind
    {
        int[] parent;    //UnionFind の本体

        /// <summary>
        /// -1 で初期化
        /// O( n )
        /// </summary>
        /// <param name="len">要素の数</param>
        public UnionFind(int len)
        {
            parent = new int[len];
            for (int i = 0; i < len; i++)
                parent[i] = -1;
        }//Constractor

        /// <summary>
        /// 要素数の取得
        /// </summary>
        public int Length
        {
            get { return parent.Length; }
        }//Length

        /// <summary>
        /// 2 つの要素を繋げる
        /// O( A(n) )
        /// </summary>
        /// <param name="x">繋げられる要素</param>
        /// <param name="y">繋げる要素</param>
        /// <returns>繋げることができたかどうか</returns>
        public bool Unite(int x, int y)
        {
            x = Find(x);
            y = Find(y);
            if (x == y)
                return false;

            if (parent[y] < parent[x])    //swap
            {
                int tmp = x;
                x = y;
                y = tmp;
            }
            parent[x] += parent[y];
            parent[y] = x;
            return true;
        }//Unite

        /// <summary>
        /// 同値類の要素の親を探す
        /// O( A(n) )
        /// </summary>
        /// <param name="x">親を探す要素</param>
        /// <returns>同じ</returns>
        public int Find(int x)
        {
            if (parent[x] < 0)
                return x;
            return parent[x] = Find(parent[x]);
        }//Find

        /// <summary>
        /// 同値類かどうか
        /// O( A(n) )
        /// </summary>
        /// <param name="x">比べられる要素</param>
        /// <param name="y">比べる要素</param>
        /// <returns>true : 同値類</returns>
        public bool Same(int x, int y)
        {
            return Find(x) == Find(y);
        }//Same

        /// <summary>
        /// 同値類の数を数える
        /// O( A(n) )
        /// </summary>
        /// <param name="x">同値類を数える要素</param>
        /// <returns>同値類の数</returns>
        public int Size(int x)
        {
            return -parent[Find(x)];
        }//Size

        /// <summary>
        /// UnionFind の親（根）になっているかの判定
        /// O( 1 )
        /// </summary>
        /// <param name="x">判定するインデックス</param>
        /// <returns>true : 親</returns>
        public bool IsParent(int x)
        {
            return parent[x] < 0;
        }//IsPaarent

    }//UnonFind

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