using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
            var N = input[0];
            var H = input[1];
            var maxA = 0;
            var thr = new int[N];

            for (int i = 0; i < N; i++)
            {
                input = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
                var a = input[0];
                var b = input[1];
                if (a > maxA) maxA = a;
                thr[i] = b;
            }

            Array.Sort(thr);
            Array.Reverse(thr);
            var cnt = 0;

            for (int i = 0; i < N; i++)
            {
                if (thr[i] > maxA)
                {
                    H -= thr[i];
                    cnt++;
                    if (H <= 0)
                    {
                        Console.WriteLine(cnt);
                        return;
                    }
                }else
                {
                    break;
                }
            }

            cnt += H / maxA;
            if (H % maxA != 0) cnt++;

            Console.WriteLine(cnt);
        }
    }
}