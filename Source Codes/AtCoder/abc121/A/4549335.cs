using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] HW = Console.ReadLine().Split(' ');
            string[] hw = Console.ReadLine().Split(' ');

            int H = int.Parse(HW[0]);
            int W = int.Parse(HW[1]);
            int h = int.Parse(hw[0]);
            int w = int.Parse(hw[1]);

            Console.WriteLine((H - h) * (W - w));
        }  
    }
}