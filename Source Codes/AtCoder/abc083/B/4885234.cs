using System;
using System.Linq;

namespace B___Some_Sums
{
    class Program
    {
        static void Main(string[] args)
        {
            var N_A_B = Console.ReadLine().Split().Select(int.Parse).ToArray();
            var N = N_A_B[0];
            var A = N_A_B[1];
            var B = N_A_B[2];
            int sum = 0;

            for (int i = 1; i <= N; i++)
            {
                var res = i.ToString().ToCharArray().Select(x => int.Parse(x.ToString())).Sum();

                if (res >= A && res <= B)
                    sum += i;
            }

            Console.WriteLine(sum);
        }
    }
}