using System;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            // ?????
            String a = Console.ReadLine();

            // ?????????????
            int b = int.Parse(a.Split(' ')[0]);
            int c = int.Parse(a.Split(' ')[1]);

            String result = (b > 8 || c > 8) ? ":(" : "Yay!";

            //??
            Console.WriteLine(result);
        }
    }
}