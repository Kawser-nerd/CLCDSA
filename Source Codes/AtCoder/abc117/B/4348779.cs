using System;
using System.Linq;

namespace AtCoder.ABC117
{
    public class A
    {
        public static void Solve()
        {

        }    
    }
    public class B
    {
        public static void Solve()
        {
            int N = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split().Select(int.Parse).ToArray();

            if (a.Max() < a.Sum()-a.Max())
            {
                Console.WriteLine("Yes");
            }
            else
            {
                Console.WriteLine("No");

            }
        }    
    }
}

namespace AtCoder {
    class Program
    {
        static void Main(string[] args)
        {
            ABC117.B.Solve();
        }
    }
}