using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace abc119a
{
    class Program
    {
        static void Main(string[] args)
        {
            if(int.Parse(Console.ReadLine().Split('/')[1]) < 5)
            {
                Console.WriteLine("Heisei");
            }
            else
            {
                Console.WriteLine("TBD");
            }

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