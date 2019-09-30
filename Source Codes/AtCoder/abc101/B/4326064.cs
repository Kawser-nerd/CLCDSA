using System;
using System.Linq;

namespace B.Digit_Sums
{
    class Program
    {
        static void Main(string[] args)
        {
            var S = Console.ReadLine().ToCharArray();

            Console.WriteLine(int.Parse(new string(S)) % S.Select(x => int.Parse(x.ToString())).Sum() == 0 ? "Yes" : "No");
        }
    }
}