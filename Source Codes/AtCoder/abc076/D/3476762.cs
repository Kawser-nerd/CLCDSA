using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public int N;
        public int[] T, V;
        public long MOD = 1000000007;

        public void Run()
        {
            N = Input.ReadInt();
            T = Input.ReadIntArray();
            V = Input.ReadIntArray();
            int[] S = new int[N+1];

            for (int a = 0; a <= N; a++)
            {
                S[a] = 1000000;
            }

            for (int a = 0; a <= N; a++)
            {
                if (a == 0 || a == N) S[a] = 0;
                else
                {
                    S[a] = Math.Min(S[a], S[a-1] + T[a-1]);
                    S[a] = Math.Min(S[a], V[a]);
                    S[a] = Math.Min(S[a], V[a-1]);
                }
            }
            for (int a = N; a >= 0; a--)
            {
                if (a == 0 || a == N) S[a] = 0;
                else
                {
                    S[a] = Math.Min(S[a], S[a + 1] + T[a]);
                    S[a] = Math.Min(S[a], V[a]);
                    S[a] = Math.Min(S[a], V[a - 1]);
                }
            }

            double ret = 0;
            for (int i = 0; i < N; i++)
            {
                ret += area(V[i], T[i], S[i], S[i + 1]);
            }
            Console.Error.WriteLine(string.Join(", ", S));
            Console.WriteLine(ret);
        }

        public double area(int v, int t, int s, int e)
        {
            double mx = Math.Min((s + e + t) / 2.0, v);
            double a = mx - s;
            double c = mx - e;
            double b = t - a - c;

            double ret = 0;
            ret += a * (s + mx) / 2.0;
            ret += b * mx;
            ret += c * (e + mx) / 2.0;
            return ret;
        }
    }

    // libs ----------
    

    // common ----------

    internal static class Input
    {
        public static string ReadString()
        {
            string line = Console.ReadLine();
            return line;
        }

        public static int ReadInt()
        {
            string line = Console.ReadLine();
            return int.Parse(line);
        }

        public static int[] ReadIntArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(int.Parse).ToArray();            
        }

        public static long ReadLong()
        {
            string line = Console.ReadLine();
            return long.Parse(line);
        }

        public static long[] ReadLongArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(long.Parse).ToArray();
        }

        public static double[] ReadDoubleArray()
        {
            string line = Console.ReadLine();
            return line.Split(' ').Select(double.Parse).ToArray();
        }
    }
    
    internal class Program
    {
        public static void Main(string[] args)
        {
            var s = new Solution();
            s.Run();
        }
    }
}