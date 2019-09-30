using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Competitive
{
    internal class Solution
    {
        public long A, B;
        public int[] AA, BB;
        public void Run()
        {
            A = Input.ReadLong();
            B = Input.ReadLong();
            if (A > B)
            {
                long tmp = A;
                A = B;
                B = tmp;
            }

            AA = new int[64];
            BB = new int[64];
            for (int i = 0; i < 63; i++)
            {
                AA[i] = (int)(A % 2);
                BB[i] = (int)(B % 2);
                A /= 2;
                B /= 2;
            }

            // ??????bit???
            int T = 63;
            {
                while (T >= 0)
                {
                    if (AA[T] == BB[T])
                    {
                        T--;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (T == -1)
            {
                Console.WriteLine(1);
                return;
            }

            // ?????????????????????
            {
                long m = 1;
                for (int i = 0; i <= T; i++)
                {
                    A += m * AA[i];
                    B += m * BB[i];
                    m *= 2;
                }
            }

            int R = T - 1;
            {
                while (R >= 0)
                {
                    if (BB[R] == 0)
                    {
                        R--;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            long l0 = A;
            long r0 = (1L << T) - 1;
            long l1 = (1L << T);
            long r1 = (1L << T) + (1L << (R + 1)) - 1;
            long l2 = (1L << T) + A;
            long r2 = (1L << (T + 1)) - 1;

            long ret;
            if (r1 < l2)
            {
                ret = (r0 - l0 + 1) + (r1 - l1 + 1) + (r2 - l2 + 1);
            }
            else
            {
                ret = (r0 - l0 + 1) + (r2 - l1 + 1);
            }

            Console.WriteLine(ret);

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