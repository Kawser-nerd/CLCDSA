using System;
using System.Linq;

namespace ABC085_D
{
    class Program
    {
        static void Main(string[] args)
        {
            var NH = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var N = NH[0];
            var H = NH[1];
            var k = new int[2];
            var a = new int[N];
            var b = new int[N];

            for (int i = 0; i < N; i++)
            {
                k = Console.ReadLine().Split().Select(int.Parse).ToArray();
                a[i] = k[0];
                b[i] = k[1];
            }

            var ma = a.Max();
            var cnt = 0;
            foreach (var x in b.Where(x => x > ma).OrderByDescending(x => x))
            {
                H -= x;
                cnt++;
                if (H <= 0) break;
            }

            Console.WriteLine(cnt += H <= 0 ? 0 : (H / ma + (H % ma == 0 ? 0 : 1)));
        }
    }
}