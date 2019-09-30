using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

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
        public int[] IntArray()
        {
            return Array().Select(int.Parse).ToArray();
        }
        public long[] LongArray()
        {
            return Array().Select(long.Parse).ToArray();
        }
    }

    class Program
    {
        private long A, B, C;
        private const long Mod = 1000000007;
        private void Scan()
        {
            var sc = new Scanner();
            A = sc.NextLong();
            B = sc.NextLong();
            C = sc.NextLong();
        }

        public void Solve()
        {
            Scan();
            Console.WriteLine($"{Ans(A, C, B)} {Ans(A, B, C)}");
        }

        private long Ans(long a, long b, long c)
        {
            long bunsi = ((b * c) - (a * b) % Mod) % Mod;
            long bunbo = ((a * c) - (b * c) % Mod + (a * b)) % Mod;
            long gyakugen = Pow(bunbo, Mod - 2, Mod);
            return (bunsi * gyakugen) % Mod;
        }

        private long Pow(long a, long b, long mod)
        {
            long ans = 1;
            while (b > 0)
            {
                if (b % 2 == 1)
                {
                    ans *= a;
                    ans %= mod;
                }
                b /= 2;
                a *= a;
                a %= mod;
            }
            return ans;
        }

        static void Main(string[] args)
        {
            new Program().Solve();
        }
    }
}