using System;
using System.Linq;

namespace practice6
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            string c = Console.ReadLine().ToString();
            string A = "5 5 7";
            string B = "5 7 5";
            string C = "7 5 5";
            if (c == A)
                Console.WriteLine("YES");
            else if (c == B)
                Console.WriteLine("YES");
            else if (c == C)
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");

        }
    }
}