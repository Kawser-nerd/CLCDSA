using System;

namespace AtCoderConsole
{
    class Program
    {
        static void Main(string[] args)
        {
            // ??????1???
            string input = Console.ReadLine();

            // A,B,C,D?????
            double a = Double.Parse(input.Split(' ')[0]);
            double b = Double.Parse(input.Split(' ')[1]);
            double c = Double.Parse(input.Split(' ')[2]);
            double d = Double.Parse(input.Split(' ')[3]);

            string output;

            if(b / a == d / c)
            {
                output = "DRAW";
            }
            else if(b / a > d / c)
            {
                output = "TAKAHASHI";
            }
            else
            {
                output = "AOKI";
            }

            // ???????
            Console.WriteLine(output);
        }
    }
}