using System;

namespace Multi3_or_Division2
{
    class Program
    {
        public static string Solve()
        {
            Console.ReadLine();
            string inputCON = Console.ReadLine();

            int count = 0;

            foreach (var item in inputCON.Split(' '))
            {
                for (int a = int.Parse(item); a % 2 == 0; a /= 2)
                {
                    count++;
                }
            }

            return count.ToString();
        }

        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}