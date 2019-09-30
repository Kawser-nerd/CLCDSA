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

    class Program
    {
        private Scanner Sc;
        private int N;
        public void Solve()
        {
            Sc = new Scanner();
            N = Sc.NextInt();
            var sb = new StringBuilder();
            for (int i = 0; i < N; i++)
            {
                long a = Sc.NextLong();
                long b = Sc.NextLong();
                long c = Sc.NextLong();
                long d = Sc.NextLong();
                if (Q(a, b, c, d))
                {
                    sb.AppendLine("Yes");
                }
                else
                {
                    sb.AppendLine("No");
                }
            }
            Console.Write(sb.ToString());
        }

        public long GCD(long a, long b)
        {
            while (b > 0)
            {
                var r = b;
                b = a % b;
                a = r;
            }
            return a;
        }

        private bool Q(long a, long b, long c, long d)
        {
            if (a < b) return false;
            if (d < b) return false;
            if (c < b)
            {
                //C<(A+ND)%B??false
                //  Console.WriteLine($"{a} {b} {c} {d}");
                long gcd = GCD(b, d);
                long m = a % b;
               // Console.WriteLine(gcd);
                if (c < m) return false;
                //plus
                {

                    long def = b - m;
                    long dev;
                    if (def % gcd == 0)
                    {
                        dev = (def - gcd) / gcd;
                    }
                    else
                    {
                        dev = (def) / gcd;
                    }
                    if (c < m + dev * gcd) return false;
                }

                //minus;
                {
                    long dev;

                    dev = (m + gcd) / gcd;

                    long res = m - dev * gcd + b;
                    if (c < res) return false;
                }
            }

            return true;
        }

        static void Main() => new Program().Solve();
    }
}