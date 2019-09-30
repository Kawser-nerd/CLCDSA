using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2017_0_A
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var input = Console.ReadLine().Split();
                var bits = input[0].Select(c => c == '+' ? true : false).ToArray();
                var K = int.Parse(input[1]);
                var result = 0;
                for (int i = 0; i <= bits.Length - K; i++)
                    if (!bits[i])
                    {
                        result++;
                        for (int j = i + 1; j < i + K; j++)
                            bits[j] = !bits[j];
                    }
                var good = true;
                for (int i = bits.Length - K + 1; i < bits.Length; i++)
                    if (!bits[i])
                    {
                        good = false;
                        break;
                    }
                Console.WriteLine("Case #{0}: {1}", testN, good ? result.ToString() : "IMPOSSIBLE");
            }
        }
    }
}
