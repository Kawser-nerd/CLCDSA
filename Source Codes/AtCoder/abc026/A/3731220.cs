using System;

namespace MaxMulti
{
    class Program
    {
        public static string Solve()
        {
            int a = int.Parse(Console.ReadLine());
            int m = a / 2;
            return (m*m).ToString();
        }

        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}