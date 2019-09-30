using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abs118b
{
    class Program
    {
        static void Main(string[] args)
        {
            var nm = ReadIntList();
            var n = nm[0];
            var m = nm[1];
            var suki = Enumerable.Range(1, 30).ToList();
            for (int i = 0; i < n; i++)
            {
                var ka = ReadIntList();
                suki = suki.FindAll(_ => ka.Skip(1).Contains(_));
            }
            Console.WriteLine(suki.Count());
#if DEBUG
            Console.ReadKey();
#endif
        }

        private static bool IsRange(int a, int from, int to) => (from <= a && a <= to);
        private static int ReadInt() => int.Parse(Console.ReadLine());
        private static List<int> ReadIntList() => Console.ReadLine().Split(' ').Select(_ => int.Parse(_)).ToList();
        private static List<int> Int2Digits(int a) => a.ToString().ToCharArray().Select(_ => int.Parse(_.ToString())).ToList();
    }
}