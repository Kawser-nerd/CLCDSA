using System;

namespace A___HEX
{
    class Program
    {
        static void Main(string[] args)
        {
            var X_Y = Console.ReadLine().Split();
            var X = X_Y[0];
            var Y = X_Y[1];

            if (string.Compare(X, Y) == 0)
                Console.WriteLine("=");
            else if (string.Compare(X, Y) > 0)
                Console.WriteLine(">");
            else
                Console.WriteLine("<");
        }
    }
}