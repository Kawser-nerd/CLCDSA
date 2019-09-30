using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long K;

        public void Run()
        {
            {
                K = Input.ReadLong();
            }

            long x = 1;
            long inc = 1;
            while (K > 0)
            {
                bool flg = true;
                long s = Calc(x);

                for (long i = 1; i <= 10; i++)
                {
                    long xi = x + i * inc;
                    long si = Calc(xi);
                    if (x * si > s * xi)
                    {
                        flg = false;
                        break;
                    }
                }

                if (flg)
                {
                    Console.WriteLine(x);
                    K--;
                    x += inc;
                }
                else
                {
                    x -= inc;
                    inc *= 10;
                    x += inc;
                }
            }

        }

        public long Calc(long x)
        {
            long ret = 0;
            while (x > 0)
            {
                ret += x % 10;
                x /= 10;
            }

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