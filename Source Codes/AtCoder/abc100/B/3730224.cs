using System;

namespace Ringo_sFavoriteNumbers
{
    class Program
    {
        public static string Solve()
        {
            string input = Console.ReadLine();
            int D = int.Parse(input.Split()[0]);
            int N = int.Parse(input.Split()[1]);

            double hentai = Math.Pow(100, D);

            if (N == 100)
            {
                N++;
            }
            return (hentai * N).ToString();
        }

        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}