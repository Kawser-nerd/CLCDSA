using System;
using System.Linq;

namespace ABC86
{
    class Program
    {
        static void Main(string[] args)
        {
            var solver = new Solver();
            solver.Solve2();
        }
    }

    public class Solver
    {

        public void Solve1()
        {
            var ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
            Console.WriteLine(ab[0] * ab[1] % 2 == 0 ? "Even" : "Odd");

        }

        public void Solve2()
        {
            var ab = int.Parse(Console.ReadLine().Replace(" ", ""));

            Console.WriteLine(Math.Sqrt(ab) - (int)Math.Sqrt(ab) == 0 ? "Yes" : "No");


        }
    }
}