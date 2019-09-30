using System;

namespace ABC030_A
{
    class Program
    {
        static string Solve()
        {
            string input = Console.ReadLine();

            double avgTAKAHASHI = double.Parse(input.Split(' ')[1]) / double.Parse(input.Split(' ')[0]);
            double avgAOKI = double.Parse(input.Split(' ')[3]) / double.Parse(input.Split(' ')[2]);

            if (avgTAKAHASHI.Equals(avgAOKI))
            {
                return "DRAW";
            }
            else if (avgTAKAHASHI > avgAOKI)
            {
                return "TAKAHASHI";
            }
            else
            {
                return "AOKI";
            }
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}