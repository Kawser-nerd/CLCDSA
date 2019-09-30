using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ
{
    class Program
    {


        public static int Get(List<long> ms, long n)
        {
            long left = 0, right = ms.Min() * n;
            long middle = 0;
            while (left <= right)
            {
                middle = (left + right) / 2;
                long num = ms.Sum(t => (middle + t - 1) / t);
                long nextNum = ms.Sum(t => (middle + t)/t);
                if (num < n && nextNum >=n)
                    break;
                if (num < n)
                    left = middle + 1;
                else
                    right = middle - 1;
            }
            long finishNum = ms.Sum(t => (middle + t - 1) / t);
            n -= finishNum;
            for (int i = 0; i < ms.Count(); i++)
            {
                if (middle % ms[i] == 0)
                {
                    if (n == 1)
                        return i + 1;
                    n--;
                }
            }
            return 0;
        }


        static void Main(string[] args)
        {
            var lines = System.IO.File.ReadAllLines(@"C:\Users\Vivian\Downloads\B-large (1).in");
            using (var sw = new StreamWriter("output.txt"))
            {
                int num = int.Parse(lines[0]);
                for (int i = 1; i <= num; i++)
                {
                    long n = long.Parse(lines[2 * i - 1].Split(' ').ToArray()[1]);
                    var arr = lines[2*i].Split(' ').Select(long.Parse).ToList();
                    sw.WriteLine("Case #{0}: {1}", i, Get(arr, n));
                }
            }
        }
    }
}
