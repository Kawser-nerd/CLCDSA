using System;
using System.Linq;

namespace ABC033_B
{
    class Program
    {
        static string Solve()
        {
            int count = int.Parse(Console.ReadLine());
            string read = "";
            string[] city = new string[count];
            int[] population = new int[count];
            int total = 0;
            for (int i = 0; i < count; i++)
            {
                read = Console.ReadLine();
                city[i] = read.Split(' ')[0];
                population[i] = int.Parse(read.Split(' ')[1]);
                total += population[i];
            }
            if (total/2 < population.Max())
            {
                int index = Array.IndexOf(population, population.Max());
                return city[index];
            }
           
            return "atcoder";
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solve());
        }
    }
}