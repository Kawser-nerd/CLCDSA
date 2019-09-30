using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public string S;
        public int N;
        public long MOD = 1000000007;

        public void Run()
        {
            S = Console.ReadLine();
            N = S.Length;

            int count = Math.Max(CheckCenter('0'), CheckCenter('1'));
            Console.WriteLine((N + count) / 2);
        }


        public int CheckCenter(char c)
        {
            int count = 0;
            if (N % 2 == 0)
            {
                int l = N / 2 - 1;
                int r = N / 2;
                while (true)
                {
                    if (S[l] == c && S[r] == c)
                    {
                        count += 2;
                        l--;
                        r++;
                    }
                    else
                    {
                        return count;
                    }

                    if (l < 0) return count;
                }
            }
            else
            {
                int l = N / 2;
                int r = N / 2;
                while (true)
                {
                    if (S[l] == c && S[r] == c)
                    {
                        count += (l == r ? 1 : 2);
                        l--;
                        r++;
                       
                    }
                    else
                    {
                        return count;
                    }
                    if (l < 0) return count;
                }
            }

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