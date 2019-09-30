using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.Remoting.Contexts;

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

        public string[] Array()
        {
            line = Console.ReadLine().Split(' ');
            index = line.Length;
            return line;
        }

        public int[] IntArray(int n)
        {
            var array = Array();
            var result = new int[n];
            for (int i = 0; i < n; i++)
            {
                result[i] = int.Parse(array[i]);
            }

            return result;
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

        public uint NextUint()
        {
            return uint.Parse(Next());
        }
    }

    struct SS
    {
        public string A, B;
    }

    class Program
    {
        private Scanner Sc;
        private int N;
        private string S;
        private Dictionary<SS, long> LL, RR;
        public void Solve()
        {
            Sc = new Scanner();
            N = Sc.NextInt();
            S = Sc.Next();
            string left = S.Substring(0, N);
            string right = S.Substring(N, N);
            LL = new Dictionary<SS, long>();
            RR = new Dictionary<SS, long>();
            int loop = 1 << N;
            for (int i = 0; i < loop; i++)
            {
                int cp = i;
                string la = "", lb = "", ra = "", rb = "";
                for (int j = 0; j < N; j++)
                {
                    if (cp % 2 == 0)
                    {
                        la += left[j];
                        ra = right[j] + ra;
                    }
                    else
                    {
                        lb += left[j];
                        rb = right[j] + rb;
                    }

                    cp /= 2;
                }
                var l = new SS()
                {
                    A = la,
                    B = lb
                };
                var r = new SS()
                {
                    A = ra,
                    B = rb
                };
                long o;
                LL.TryGetValue(l, out o);
                LL[l] = o + 1;
                RR.TryGetValue(r, out o);
                RR[r] = o + 1;
            }

            long ans = 0;
            foreach (var l in LL)
            {
                long o;
                RR.TryGetValue(l.Key, out o);
                ans += l.Value * o;
            }
            Console.WriteLine(ans);
        }



        static void Main() => new Program().Solve();
    }
}