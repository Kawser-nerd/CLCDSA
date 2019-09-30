using System;
using System.Collections.Generic;
using System.Text;

namespace Codejam1
{
    class Pair : IComparable
    {
        int a, b;
        public Pair(int A, int B) { a = A; b = B; }

        public int CompareTo(object X)
        {
            Pair B = (Pair)X;
            if (a != B.a) return a - B.a;
            return b - B.b;
        }
    }

    class Program
    {

        public Dictionary<Pair, int> memo;

        public bool Happy( int x, int B ) {
            
            for (int iter = 0; iter < 10; ++iter)
            {
                int y = 0;
                while (x > 0)
                {
                    int digit = x % B;
                    x /= B;
                    y += digit * digit;
                }
                x = y;
            }
            return (x == 1);
        }

        static void Main(string[] args)
        {
            Program solution = new Program();
            solution.memo = new Dictionary<Pair, int>();

            Dictionary<string, int> memo = new Dictionary<string, int>();

            int T = Int32.Parse(Console.ReadLine());
            for (int tt = 1; tt <= T; ++tt)
            {
                int ret = 2;
                string S = Console.ReadLine();
                if (memo.ContainsKey(S))
                {
                    ret = memo[S];
                }
                else
                {
                    string[] numbers = S.Split(' ');
                    int[] a = new int[numbers.Length];
                    for (int i = 0; i < numbers.Length; ++i) a[i] = Int32.Parse(numbers[i]);

                    Array.Sort(a);
                    Array.Reverse(a);

                    int cnt = 0;                   
                    bool ok = false;
                    while (!ok)
                    {
                        ok = true;
                        foreach (int Base in a)
                        {
                            if (!solution.Happy(ret, Base)) ok = false;
                            if (!ok) break;
                            ++cnt;
                        }
                        if (ok) break;
                        ++ret;
                    }
                    memo[S] = ret;
                }
                Console.WriteLine("Case #{0}: {1}", tt, ret);
                Console.Error.WriteLine("Case #{0}: {1}", tt, ret);
            }
        }
    }
}
