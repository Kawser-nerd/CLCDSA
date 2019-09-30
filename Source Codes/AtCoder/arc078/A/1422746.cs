using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace ConsoleApplication1.CodeForces
{
    class _4032
    {
        private static int Next()
        {
            int c;
            int res = 0;
            do
            {
                c = reader.Read();
                if (c == -1)
                    return res;
            } while (c < '0' || c > '9');
            res = c - '0';
            while (true)
            {
                c = reader.Read();
                if (c < '0' || c > '9')
                    return res;
                res *= 10;
                res += c - '0';
            }
        }
        private static readonly StreamReader reader = new StreamReader(Console.OpenStandardInput(1024 * 10), Encoding.ASCII, false, 1024 * 10);
        private static readonly StreamWriter writer = new StreamWriter(Console.OpenStandardOutput(1024 * 10), Encoding.ASCII, 1024 * 10);

        class Node : IComparable
        {
            public long X { get; set; }
            public long Y { get; set; }
            public int CompareTo(object obj)
            {
                if (this.Y > ((Node)obj).Y)
                {
                    return 1;
                }
                if (this.Y == ((Node)obj).Y)
                {
                    return 0;
                }
                return -1;
            }
        }
        public static string ReverseString(string s)
        {
            char[] arr = s.ToCharArray();
            Array.Reverse(arr);
            return new string(arr);
        }
        static void Main(String[] args)
        {
            var n = int.Parse(Console.ReadLine().TrimEnd());
            var data = Console.ReadLine().TrimEnd().Split(' ').Select(long.Parse).ToList();
            var sum = data.Sum();
            long sum1 = 0;
            long min = long.MaxValue;
            for(var i = 0; i < n-1; i++)
            {
                sum1 += data[i];
                long sum2 = sum - sum1;
                var res = sum1 - sum2;
                min = Math.Min(Math.Abs(res), min);
            }
            

            Console.WriteLine(min);
        }
    }
}