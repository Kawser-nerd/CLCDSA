using System;

namespace arc050_a
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] s = Console.ReadLine().Split();
            Console.WriteLine(s[0] == s[1].ToUpper() ? "Yes" : "No");
        }
    }
}