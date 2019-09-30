using System;
using static System.Console;

namespace C_
{
    class Program
    {
        static void Main(string[] args)
        {
            int H1 = int.Parse(ReadLine());
            int H2 = int.Parse(ReadLine());

            WriteLine(H1 - H2);
        }
    }
}