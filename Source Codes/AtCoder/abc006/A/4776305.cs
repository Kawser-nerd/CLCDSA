using System;

namespace BC006_A
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            Console.WriteLine(n % 3 == 0 || n.ToString().Contains("3") ? "YES" : "NO");
        }
    }
}