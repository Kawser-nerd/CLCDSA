using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Xml.Schema;

namespace Contest
{
    class Scanner
    {
        private string[] line = new string[0];
        private int index = 0;
        public string Next()
        {
            if (line.Length <= index)
            {
                line = Console.ReadLine().Split(' ');
                index = 0;
            }
            var res = line[index];
            index++;
            return res;
        }
        public int NextInt()
        {
            return int.Parse(Next());
        }
        public long NextLong()
        {
            return long.Parse(Next());
        }
        public ulong NextUlong()
        {
            return ulong.Parse(Next());
        }
        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }
        public int[] IntArray()
        {
            var array = Array();
            var result = new int[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
        }
        public long[] LongArray()
        {
            var array = Array();
            var result = new long[array.Length];
            for (int i = 0; i < array.Length; i++)
            {
                result[i] = long.Parse(array[i]);
            }

            return result;
        }
    }

    class Program
    {
        private int N;
        private ulong X;
        private ulong[] x;
        private ulong[] _sum;
        private ulong ans = 0;
        private void Scan()
        {
            var sc = new Scanner();
            N = sc.NextInt();
            X = sc.NextUlong();
            x = new ulong[N];
            var line = Console.ReadLine().Split(' ');
            for (uint i = 0; i < N; i++)
            {
                x[i] = ulong.Parse(line[i]);
            }
        }

        public void Solve()
        {
            Scan();
            ulong ans = ulong.MaxValue;

            _sum = new ulong[N + 1];
            for (int i = 0; i < N; i++)
            {
                _sum[i + 1] = _sum[i] + x[i];
            }
            for (int k = 1; k <= N; k++)
            {
                int b = (N + k - 1) / k;
                ulong q = X * (ulong)(N + k);
                int bb = N - 1;
                int aa = N - k;
                for (int i = 1; i <= b; i++)
                {
                    q += E(i, Sum(aa, bb));
                    aa -= k;
                    bb -= k;
                    aa = Math.Max(aa, 0);
                }
                //Console.WriteLine(q);
                ans = Math.Min(q, ans);
            }
            Console.WriteLine(ans);
        }

        private ulong E(int i, ulong x)
        {
            if (i == 1)
            {
                return x * 5;
            }
            else
            {
                return x * (ulong)(2 * i + 1);
            }
        }

        private ulong Sum(int x, int y)
        {
            return _sum[y + 1] - _sum[x];
        }



        static void Main() => new Program().Solve();
    }
}