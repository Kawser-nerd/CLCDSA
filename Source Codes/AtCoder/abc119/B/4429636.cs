using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc119b
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = ReadInt();
            var ans = 0.0;

            for(var i = 0; i < N; i++)
            {
                var xu = Console.ReadLine().Split();
                if(xu[1] == "JPY")
                {
                    ans += double.Parse(xu[0]);
                }
                else if (xu[1] == "BTC")
                {
                    ans += double.Parse(xu[0]) * 380000.0;
                }
            }
            
            Console.WriteLine(ans);
#if DEBUG
            Console.ReadKey();
#endif
        }

        double BTC2JPY(double btc) => btc * 380000.0;

        private static bool IsRange(int a, int from, int to) => (from <= a && a <= to);
        private static int ReadInt() => int.Parse(Console.ReadLine());
        private static List<int> ReadIntList() => Console.ReadLine().Split().Select(int.Parse).ToList();
        private static double ReadDouble() => double.Parse(Console.ReadLine());
        private static List<double> ReadDoubleList() => Console.ReadLine().Split().Select(double.Parse).ToList();
        private static List<int> Int2Digits(int a) => a.ToString().ToCharArray().Select(_ => int.Parse(_.ToString())).ToList();
    }
}