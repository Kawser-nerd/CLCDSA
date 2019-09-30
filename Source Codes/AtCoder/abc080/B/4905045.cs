using System;
using System.Linq;

namespace B___Harshad_Number
{
    class Program
    {
        static void Main(string[] args)
        {
            var N = Console.ReadLine();

            Console.WriteLine(int.Parse(N) % N.Select(x => int.Parse(x.ToString())).Sum() == 0 ? "Yes" : "No");
        }
    }
}