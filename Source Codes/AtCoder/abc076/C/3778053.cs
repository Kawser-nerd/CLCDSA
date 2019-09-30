using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Atcoder
{
    class Program
    {
        static void Main(string[] args)
        {
            #region C??
            //    var data = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    var t = data[0];
            //    var s = data[1];
            //    int[,] friens = new int[t, t];
            //    int tomo = 0;

            //    for (int i = 0; i < s; i++)
            //    {
            //        var friend = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //        friens[friend[0] - 1, friend[1] - 1] = 1;
            //        friens[friend[1] - 1, friend[0] - 1] = 1;

            //    }

            //    for (int i = 0; i < t; i++)
            //    {
            //        var x = new List<int>();
            //        var y = new List<int>();
            //        var a = new List<int>();

            //        for (int j = 0; j < t; j++)
            //        {

            //            if (friens[i, j] == 1)
            //            {
            //                x.Add(j);
            //            }

            //        }

            //        foreach (var z in x)
            //        {
            //            for (int l = 0; l < t; l++)
            //            {
            //                if (friens[z, l] == 1)
            //                {
            //                    y.Add(l);
            //                }
            //            }

            //            foreach (var m in y)
            //            {
            //                if (m != i && friens[m, i] != 1)
            //                {
            //                    a.Add(m);
            //                }
            //            }
            //        }

            //        Console.WriteLine(a.Distinct().Count());

            //    }

            //    var a = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    var b = a[0];
            //    var c = a[1];
            //    int[] d = new int[b];
            //    int[] e = new int[b];
            //    int[] f = new int[b];
            //    int tmp = 0;
            //    int tokuten = 0;

            //    for (int i = 0; i < b; i++)
            //    {
            //        var g = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //        d[i] = g[0];
            //        e[i] = g[1];
            //        f[i] = g[2];

            //    }

            //    for (int j = 1; j <= c; j++)
            //    {
            //        for (int k = 0; k < b; k++)
            //        {
            //            if (d[k] <= j && e[k] >= j)
            //            {

            //            }
            //            else
            //            {
            //                tmp += f[k];
            //            }

            //        }
            //        tokuten = Math.Max(tokuten ,tmp);
            //        tmp = 0;
            //    }

            //    Console.WriteLine(tokuten);

            //var a = int.Parse(Console.ReadLine());
            //var b = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //Dictionary<int,int> c = new Dictionary<int,int>();
            //int d = 0;

            //int cnt = 0;

            ////for (int i = 0; i < a; i++)
            ////{
            ////    c.Add(b[i], 1);
            ////}

            //for (int i = 0; i < a; i++)
            //{
            //    d = b[i];

            //    while (d % 2 == 0)
            //    {
            //        d /= 2;
            //    }

            //    if (c.ContainsKey(d))
            //    {

            //    }
            //    else
            //    {
            //        c.Add(d, 1);
            //        cnt++;
            //    }
            //}
            //Console.WriteLine(cnt);

            //var one = Array.ConvertAll(Console.ReadLine().Split(),int.Parse);
            //var N = one[0];
            //var M = one[1];
            //List<int[]> ID= new List<int[]>();
            //List<string> Out = new List<string>();
            //int cnt = 1;
            //long now = -1;

            //for (int i = 0; i < M; i++)
            //{
            //    var morethanone = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    ID.Add(morethanone);
            //}

            //var sortedID = ID.OrderBy(data => data[0]).ThenBy(data => data[1]);

            //var Rank = new Dictionary<string, int>();

            //foreach (var item in sortedID)
            //{

            //    if (now != -1 && item[0] != now)
            //    {
            //        cnt = 1;
            //    }

            //    now = item[0];
            //    Rank.Add(item[0].ToString() + item[1].ToString(), cnt);
            //    cnt++;
            //}

            //for (int i = 0; i < M; i++)
            //{
            //    var tmp = ID[i];
            //    string key = tmp[0].ToString() + tmp[1].ToString();
            //    string Output = tmp[0].ToString().PadLeft(6, '0') + Rank[key].ToString().PadLeft(6, '0');
            //    Console.WriteLine(Output);

            //}

            //var N = int.Parse(Console.ReadLine());
            //List<int[]> Z = new List<int[]>();
            //List<int[]> dis = new List<int[]>();
            //int X = 0;
            //int Y = 0;
            //int H = 0;


            //for (int i = 0; i < N; i++)
            //{
            //    var line = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //    Z.Add(line);
            //}

            //row
            //for (int i = 0; i < N; i++)
            //{
            //    var linedata = Z[i];
            //    //height
            //    for (int j = 0; j < 201; j++)
            //    {
            //        //x
            //        for (int k = 0; k < 101; k++)
            //        {
            //            for (int l = 0; l < 101; l++)
            //            {
            //                if ((j + linedata[2]) - Math.Abs(k - linedata[0]) - Math.Abs(l - linedata[1]) == linedata[2])
            //                {
            //                    X = k;
            //                    Y = l;
            //                    H = j;
            //                    dis.Add(new {x = X,y =Y, h =H});
            //                }
            //            }
            //        }
            //    }
            //}
            //var a = dis.GroupBy(n => n)
            //var b = a.OrderByDescending(n => n.cnt);

            //var a = Console.ReadLine().ToCharArray();
            //var b = Console.ReadLine().ToCharArray();

            ////char[] c = new char[a.Count()];
            ////char[] d = new char[a.Count()];
            //var c = new Dictionary<char, char>();
            //var d = new Dictionary<char, char>();

            //for (int i = 0; i < a.Count(); i++)
            //{
            //    if (!c.ContainsKey(a[i]))
            //    {
            //        c.Add(a[i], b[i]);
            //    }
            //    else if (c[a[i]] != b[i])
            //    {
            //        Console.WriteLine("No");
            //        return;
            //    }
            //}

            //for (int i = 0; i < b.Count(); i++)
            //{
            //    if (!d.ContainsKey(b[i]))
            //    {
            //        d.Add(b[i], a[i]);
            //    }
            //    else if (d[b[i]] != a[i])
            //    {
            //        Console.WriteLine("No");
            //        return;
            //    }
            //}
            //Console.WriteLine("Yes");

            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //var line2 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //int min = int.MaxValue;
            //int min2 = int.MaxValue;
            //int amari = int.MaxValue;

            //for (int i = 0; i < line1[0]; i++)
            //{
            //    if (Math.Abs(line2[i]-line1[1]) <= min)
            //    {
            //        min2 = min;
            //        min = Math.Abs(line2[i] - line1[1]);
            //    }
            //    else if (Math.Abs(line2[i] - line1[1]) < min2)
            //    {
            //        min2 = Math.Abs(line2[i] - line1[1]);
            //    }
            //}

            //if (min2 != int.MaxValue)
            //{
            //    while (amari != 0)
            //    {
            //        amari = min2 % min;
            //        min2 = min;
            //        min = amari;
            //    }
            //    Console.WriteLine(min2);
            //}
            //else
            //{
            //    Console.WriteLine(min);
            //}


            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //int N = line1[0];
            //int K = line1[1];

            //int Kgaguu = 0;
            //int amari0 = 0;


            //for (int i = 1; i <= N; i++)
            //{
            //    if (i % K == 0)
            //    {
            //        amari0++;
            //    }
            //    else if (K % 2 == 0 && i % K == K /2)
            //    {
            //        Kgaguu++;
            //    }
            //}

            //Console.WriteLine(amari0 * amari0 * amari0 + Kgaguu * Kgaguu * Kgaguu);

            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //int N = line1[0];
            //int K = line1[1];
            //var line2 = Array.ConvertAll(Console.ReadLine().Split(), long.Parse);

            //long mintmp = int.MaxValue;
            //long min = int.MaxValue;

            //for (int i = 0; i < N-K+1; i++)
            //{
            //    var left = line2[i];
            //    var right = line2[i + K - 1];

            //    mintmp = Math.Min(Math.Min(Math.Abs(left) + Math.Abs(right - left), min), Math.Abs(right) + Math.Abs(left - right));

            //    min = Math.Min(mintmp, min);
            //}

            ////for (int i = 0; i < N; i++)
            ////{
            ////    if (i != 0 || i != N-1)
            ////    {
            ////        var tmp = new node();
            ////        tmp._to1 = line2[i - 1];
            ////        tmp._to2 = line2[i + 1];
            ////        tmp.me = line2[i];
            ////        tmp.flg = false;
            ////        node.Add(tmp);
            ////    }
            ////}
            //Console.WriteLine(min);

            //var S = Console.ReadLine().ToCharArray();
            //var K = decimal.Parse(Console.ReadLine());
            //int cnt = 0;
            //bool ren = false;
            //int ans = 0;


            //for (int i = 0; i < S.Count(); i++)
            //{
            //    if (i == 0 && int.Parse(S[i].ToString()) == 1)
            //    {
            //        ren = true;
            //        cnt++;
            //        continue;
            //    }

            //    if (ren && int.Parse(S[i].ToString()) == 1)
            //    {
            //        ren = true;
            //        cnt++;
            //        continue;

            //    }

            //    if (int.Parse(S[i].ToString()) != 1)
            //    {
            //        ans = int.Parse(S[i].ToString());
            //        break;
            //    }

            //}

            //if (cnt >= K)
            //{
            //    Console.WriteLine(1);

            //}
            //else
            //{
            //    Console.WriteLine(ans);
            //}
            //Console.WriteLine(1 % -2);

            //int input = int.Parse(Console.ReadLine());

            //for (int i = 0; i < input; i++)
            //{
            //    Console.WriteLine("Hello");
            //}

            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //int N = line1[0];
            //int M = line1[1];

            //int[] tree = new int[N];
            //int min = int.MaxValue;

            //for (int i = 0; i < N; i++)
            //{
            //    tree[i] = int.Parse(Console.ReadLine());
            //}

            //var sortedTree = tree.OrderBy(n => n).ToArray();


            //for (int i = 0; i < N - K + 1; i++)
            //{
            //    min = Math.Min(sortedTree[i + K -1] - sortedTree[i], min);
            //}

            //Console.WriteLine(min);

            //var line1 = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            //int N = line1[0];
            //int M = line1[1];

            //var time1 = 1/Math.Pow(0.5, M);
            //var time2 = 100 * (N - M) * time1;

            //Console.WriteLine(time1 * 1900 * M + time2);

            //var N = int.Parse(Console.ReadLine());
            //var A = Array.ConvertAll(Console.ReadLine().Split(), long.Parse).OrderBy(n => n).ToArray();
            //var B = Array.ConvertAll(Console.ReadLine().Split(), long.Parse).OrderBy(n => n).ToArray();
            //var C = Array.ConvertAll(Console.ReadLine().Split(), long.Parse).OrderBy(n => n).ToArray();

            //long x = 0;

            //for (int i = 0; i < N; i++)
            //{
            //    var a = LowerBound(A, B[i]);
            //    var b = N - UpperBound(C, B[i]);

            //    x += a * b;
            //}
            //Console.WriteLine(x);
            #endregion

            var S = Console.ReadLine().ToCharArray().Reverse().ToArray();
            var T = Console.ReadLine().ToCharArray().Reverse().ToArray();

            var N = S.Length - 1;
            var K = T.Length - 1;

            int cnt;
            bool flg = false;

            for (int i = 0; i < N - K + 1; i++)
            {
                cnt = 0;
                for (int j = i; j <= i + K; j++)
                {
                    if (S[j] == '?' || S[j] == T[j - i])
                    {
                        cnt++;
                    }
                }

                if (cnt == K + 1)
                {
                    for (int j = i; j <= i + K; j++)
                    {
                        S[j] = T[j - i];
                        flg = true;
                    }
                    break;
                }
            }

            for (int i = 0; i < N + 1; i++)
            {
                if (S[i] == '?')
                {
                    S[i] = 'a';
                }
            }

            if (flg)
            {
                var st = new string(S.Reverse().ToArray());
                Console.WriteLine(st);
            }
            else
            {
                Console.WriteLine("UNRESTORABLE");
            }

        }

        public static long LowerBound<T>(T[] arr, long start, long end, T value, IComparer<T> comparer)
        {
            long low = start;
            long high = end;
            long mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) < 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static long LowerBound<T>(T[] arr, T value) where T : IComparable
        {
            return LowerBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }

        public static long UpperBound<T>(T[] arr, long start, long end, T value, IComparer<T> comparer)
        {
            long low = start;
            long high = end;
            long mid;
            while (low < high)
            {
                mid = ((high - low) >> 1) + low;
                if (comparer.Compare(arr[mid], value) <= 0)
                    low = mid + 1;
                else
                    high = mid;
            }
            return low;
        }

        //????????????
        public static long UpperBound<T>(T[] arr, T value)
        {
            return UpperBound(arr, 0, arr.Length, value, Comparer<T>.Default);
        }
    }

}